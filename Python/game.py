"""
特性：
 - 可选图片与音效（缺失时自动回退到绘制与静音）
 - 爆炸动画与音效
 - 玩家生命（Lives）与 UI 显示
 - 掉落道具（额外生命、速射）
 - 难度随分数上升（敌人生成频率与速度增加）
 - 开始菜单、重试与退出控制

运行：
  pip install pygame
  python game.py

按键：←/→ 或 A/D 移动，空格 开火，R 重试，Q 或 ESC 退出。
"""

import os
import pygame
import random
import sys
import time

# 窗口设置
WIDTH, HEIGHT = 480, 700
FPS = 60

# 颜色
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (220, 50, 50)
GREEN = (60, 179, 113)
BLUE = (65, 105, 225)
YELLOW = (255, 215, 0)

ASSETS_PATH = os.path.join(os.path.dirname(__file__), 'assets')

# 资源加载工具（优雅回退）
def load_image(name, scale=None):
    path = os.path.join(ASSETS_PATH, name)
    try:
        img = pygame.image.load(path).convert_alpha()
        if scale:
            img = pygame.transform.smoothscale(img, scale)
        return img
    except Exception:
        return None


def load_sound(name):
    path = os.path.join(ASSETS_PATH, name)
    try:
        return pygame.mixer.Sound(path)
    except Exception:
        return None

class Player(pygame.sprite.Sprite):
    def __init__(self, img=None):
        super().__init__()
        self.base_img = img
        if self.base_img:
            self.image = self.base_img.copy()
        else:
            self.image = pygame.Surface((50, 38), pygame.SRCALPHA)
            pygame.draw.polygon(self.image, BLUE, [(0,38),(25,0),(50,38)])
        self.rect = self.image.get_rect()
        self.rect.centerx = WIDTH // 2
        self.rect.bottom = HEIGHT - 10
        self.speedx = 0
        self.shoot_delay = 250  # ms
        self.last_shot = 0
        self.lives = 3
        self.rapid_fire = False
        self.rapid_end_time = 0

    def update(self):
        keys = pygame.key.get_pressed()
        self.speedx = 0
        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            self.speedx = -6
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            self.speedx = 6
        self.rect.x += self.speedx
        if self.rect.left < 0:
            self.rect.left = 0
        if self.rect.right > WIDTH:
            self.rect.right = WIDTH

        # 速射道具到期
        if self.rapid_fire and pygame.time.get_ticks() > self.rapid_end_time:
            self.rapid_fire = False
            self.shoot_delay = 250

    def shoot(self, now, bullets_group, all_sprites, bullet_img=None, shoot_sound=None):
        delay = 100 if self.rapid_fire else self.shoot_delay
        if now - self.last_shot >= delay:
            self.last_shot = now
            bimg = bullet_img
            bullet = Bullet(self.rect.centerx, self.rect.top, img=bimg)
            all_sprites.add(bullet)
            bullets_group.add(bullet)
            if shoot_sound:
                try:
                    shoot_sound.play()
                except Exception:
                    pass

class Bullet(pygame.sprite.Sprite):
    def __init__(self, x, y, img=None):
        super().__init__()
        if img:
            self.image = img
        else:
            self.image = pygame.Surface((4, 12))
            self.image.fill(YELLOW)
        self.rect = self.image.get_rect()
        self.rect.centerx = x
        self.rect.bottom = y
        self.speedy = -10

    def update(self):
        self.rect.y += self.speedy
        if self.rect.bottom < 0:
            self.kill()

class Enemy(pygame.sprite.Sprite):
    def __init__(self, img=None, speed_range=(2,5)):
        super().__init__()
        self.img = img
        if self.img:
            self.image = self.img.copy()
        else:
            w = random.randint(30, 50)
            h = random.randint(20, 40)
            self.image = pygame.Surface((w, h))
            self.image.fill(RED)
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(0, WIDTH - self.rect.width)
        self.rect.y = -self.rect.height
        self.speedy = random.randint(*speed_range)
        self.speedx = random.choice([-1, 0, 1])

    def update(self):
        self.rect.y += self.speedy
        self.rect.x += self.speedx
        if self.rect.top > HEIGHT:
            self.kill()
        if self.rect.left < 0:
            self.rect.left = 0
            self.speedx *= -1
        if self.rect.right > WIDTH:
            self.rect.right = WIDTH
            self.speedx *= -1

class Explosion(pygame.sprite.Sprite):
    def __init__(self, center, frames=None, sound=None):
        super().__init__()
        self.frames = frames
        self.frame_index = 0
        self.last_update = pygame.time.get_ticks()
        self.frame_rate = 50
        self.sound = sound
        if self.sound:
            try:
                self.sound.play()
            except Exception:
                pass

        if self.frames:
            self.image = self.frames[0]
            self.rect = self.image.get_rect()
            self.rect.center = center
        else:
            # 回退：画圆并放大
            self.image = pygame.Surface((30, 30), pygame.SRCALPHA)
            pygame.draw.circle(self.image, YELLOW, (15,15), 15)
            self.rect = self.image.get_rect()
            self.rect.center = center
            self.grow = 1

    def update(self):
        now = pygame.time.get_ticks()
        if self.frames:
            if now - self.last_update > self.frame_rate:
                self.last_update = now
                self.frame_index += 1
                if self.frame_index == len(self.frames):
                    self.kill()
                else:
                    self.image = self.frames[self.frame_index]
                    center = self.rect.center
                    self.rect = self.image.get_rect()
                    self.rect.center = center
        else:
            # 放大并淡出（保留中心点）
            self.grow += 1
            size = int(30 * self.grow)
            surf = pygame.Surface((size, size), pygame.SRCALPHA)
            pygame.draw.circle(surf, (255, 180, 0, max(0, 255 - self.grow*10)), (size//2, size//2), size//2)
            # 记住之前中心点，避免新 rect 默认中心为 (0,0)
            old_center = self.rect.center
            self.image = surf
            self.rect = self.image.get_rect()
            self.rect.center = old_center
            if self.grow > 8:
                self.kill()

class PowerUp(pygame.sprite.Sprite):
    def __init__(self, center, kind='life', img=None):
        super().__init__()
        self.kind = kind
        if img:
            self.image = img
        else:
            self.image = pygame.Surface((20, 20), pygame.SRCALPHA)
            color = GREEN if kind == 'life' else BLUE
            pygame.draw.circle(self.image, color, (10,10), 10)
        self.rect = self.image.get_rect()
        self.rect.center = center
        self.speedy = 3

    def update(self):
        self.rect.y += self.speedy
        if self.rect.top > HEIGHT:
            self.kill()

def get_font(size):
    """尝试匹配常见的中文/Unicode 字体，失败则回退到默认字体。"""
    candidates = ['Microsoft YaHei', 'SimHei', 'SimSun', 'Arial Unicode MS', 'Noto Sans CJK SC', 'Arial']
    for name in candidates:
        path = pygame.font.match_font(name)
        if path:
            try:
                return pygame.font.Font(path, size)
            except Exception:
                continue
    return pygame.font.SysFont(None, size)


def draw_text(surf, text, size, x, y, color=WHITE):
    font = get_font(size)
    try:
        text_surface = font.render(text, True, color)
    except Exception:
        # 回退：用 ASCII 版本（把非 ASCII 替换为空格）以保证至少能看到英文提示
        safe = ''.join(ch if ord(ch) < 128 else ' ' for ch in text)
        text_surface = pygame.font.SysFont(None, size).render(safe, True, color)
    text_rect = text_surface.get_rect()
    text_rect.midtop = (x, y)
    surf.blit(text_surface, text_rect)


def draw_lives(surf, x, y, lives):
    for i in range(lives):
        pygame.draw.polygon(surf, BLUE, [(x + i*20, y+14),(x+8 + i*20, y),(x+16 + i*20, y+14)])


def show_start_screen(screen):
    screen.fill(BLACK)
    draw_text(screen, "简单飞机大战（增强版）", 36, WIDTH//2, HEIGHT//4, YELLOW)
    # 同时显示中文和英文提示，避免系统字体不支持中文导致显示方框
    draw_text(screen, "按 空格 开始", 24, WIDTH//2, HEIGHT//2 - 10, WHITE)
    draw_text(screen, "Press SPACE to start", 20, WIDTH//2, HEIGHT//2 + 20, WHITE)
    draw_text(screen, "←/→ 或 A/D 移动, 空格 开火", 20, WIDTH//2, HEIGHT//2 + 60, GREEN)
    draw_text(screen, "←/→ or A/D move, Space to fire", 18, WIDTH//2, HEIGHT//2 + 100, GREEN)
    pygame.display.flip()


def show_game_over(screen, score):
    screen.fill(BLACK)
    draw_text(screen, "游戏结束", 48, WIDTH//2, HEIGHT//3, RED)
    draw_text(screen, f"得分: {score}", 36, WIDTH//2, HEIGHT//2, WHITE)
    draw_text(screen, "按 R 重试, Q 或 ESC 退出", 24, WIDTH//2, HEIGHT//2 + 60, GREEN)
    pygame.display.flip()


def main():
    pygame.init()
    try:
        pygame.mixer.init()
    except Exception:
        pass

    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("简单飞机大战")
    clock = pygame.time.Clock()

    # 尝试加载可选资源
    player_img = load_image('player.png', (50,38))
    enemy_img = load_image('enemy.png')
    bullet_img = load_image('bullet.png')
    explosion_frames = []
    # 试着加载 explosion/ 下的帧
    for i in range(1, 10):
        f = load_image(f'explosion{i}.png')
        if f:
            explosion_frames.append(f)
    shoot_sound = load_sound('shoot.wav')
    explosion_sound = load_sound('explosion.wav')
    try:
        bg_music_path = os.path.join(ASSETS_PATH, 'bg_music.mp3')
        if os.path.exists(bg_music_path):
            pygame.mixer.music.load(bg_music_path)
            pygame.mixer.music.set_volume(0.3)
            pygame.mixer.music.play(-1)
    except Exception:
        pass

    # 组
    all_sprites = pygame.sprite.Group()
    enemies = pygame.sprite.Group()
    bullets = pygame.sprite.Group()
    explosions = pygame.sprite.Group()
    powerups = pygame.sprite.Group()

    player = Player(img=player_img)
    all_sprites.add(player)

    score = 0
    level = 1
    enemy_timer = 800
    enemy_speed_range = (2, 4)

    ENEMY_EVENT = pygame.USEREVENT + 1
    pygame.time.set_timer(ENEMY_EVENT, enemy_timer)

    running = True
    game_started = False
    game_over = False

    show_start_screen(screen)

    while running:
        now = pygame.time.get_ticks()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == ENEMY_EVENT and game_started and not game_over:
                e = Enemy(img=enemy_img, speed_range=enemy_speed_range)
                all_sprites.add(e)
                enemies.add(e)
            elif event.type == pygame.KEYDOWN:
                if not game_started:
                    if event.key == pygame.K_SPACE:
                        game_started = True
                        game_over = False
                        score = 0
                        level = 1
                        enemy_timer = 800
                        enemy_speed_range = (2, 4)
                        pygame.time.set_timer(ENEMY_EVENT, enemy_timer)
                        for s in all_sprites: s.kill()
                        for g in (enemies, bullets, explosions, powerups): g.empty()
                        player = Player(img=player_img)
                        all_sprites.add(player)
                else:
                    if event.key == pygame.K_SPACE and not game_over:
                        player.shoot(now, bullets, all_sprites, bullet_img=bullet_img, shoot_sound=shoot_sound)
                    if game_over:
                        if event.key == pygame.K_r:
                            # 重启
                            game_started = False
                            show_start_screen(screen)
                        if event.key == pygame.K_q or event.key == pygame.K_ESCAPE:
                            running = False

        if game_started and not game_over:
            all_sprites.update()
            explosions.update()
            powerups.update()

            # 子弹与敌人碰撞
            hits = pygame.sprite.groupcollide(enemies, bullets, True, True)
            if hits:
                for hit in hits:
                    # 爆炸动画
                    exp = Explosion(hit.rect.center, frames=explosion_frames if explosion_frames else None, sound=explosion_sound)
                    all_sprites.add(exp)
                    explosions.add(exp)
                    # 掉落道具概率
                    if random.random() < 0.12:
                        kind = 'life' if random.random() < 0.5 else 'rapid'
                        pu = PowerUp(hit.rect.center, kind, img=None)
                        all_sprites.add(pu)
                        powerups.add(pu)
                score += sum(len(v) for v in hits.values())

            # 玩家与道具碰撞
            p_hits = pygame.sprite.spritecollide(player, powerups, True)
            for pu in p_hits:
                if pu.kind == 'life':
                    player.lives += 1
                elif pu.kind == 'rapid':
                    player.rapid_fire = True
                    player.rapid_end_time = pygame.time.get_ticks() + 7000
                    player.shoot_delay = 100

            # 敌人与玩家碰撞
            if pygame.sprite.spritecollideany(player, enemies):
                player.lives -= 1
                # 清除一个敌人（简单处理）
                collided = pygame.sprite.spritecollide(player, enemies, True)
                exp = Explosion(player.rect.center, frames=explosion_frames if explosion_frames else None, sound=explosion_sound)
                all_sprites.add(exp)
                explosions.add(exp)
                if player.lives <= 0:
                    game_over = True

            # 难度提升（基于分数）
            new_level = 1 + score // 10
            if new_level != level:
                level = new_level
                # 加快生成速率与敌人速度
                enemy_timer = max(200, 800 - (level-1)*60)
                enemy_speed_range = (2 + level//2, 4 + level)
                pygame.time.set_timer(ENEMY_EVENT, enemy_timer)

        # 绘制
        screen.fill((12, 12, 22))
        all_sprites.draw(screen)
        # 显示分数、生命、关卡
        draw_text(screen, f"得分: {score}", 24, WIDTH//2, 10)
        draw_text(screen, f"关卡: {level}", 18, WIDTH - 50, 10)
        draw_lives(screen, 10, 10, player.lives)

        if not game_started:
            # start 显示在 show_start_screen
            pass
        elif game_over:
            show_game_over(screen, score)
        else:
            pygame.display.flip()

        clock.tick(FPS)

    pygame.quit()
    sys.exit()

if __name__ == '__main__':
    main()
