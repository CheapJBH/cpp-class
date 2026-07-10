import requests
import time

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36',
    'referer': 'http://movie.mtime.com/'
}

for num in range(1, 6):
    params = {
        "tt": str(int(time.time() * 1000)),
        "movieId": "251525",
        "pageIndex": str(num),
        "pageSize": "20",
        "orderType": "1"
    }

    try:
        res = requests.get(
            'http://front-gateway.mtime.com/library/movie/comment.api',
            params=params,
            headers=headers,
            timeout=10
        )
        res.raise_for_status()
        data = res.json()
        
        comment_list = data.get('data', {}).get('list', [])
        if not comment_list:
            print(f"第{num}页没有评论或接口返回异常。")
        for i in comment_list:
            print("用户：", i.get('nickname', '未知'))
            print("评论：", i.get('content', '无内容'))
            print()
    except Exception as e:
        print(f"第{num}页请求或解析失败，错误：{e}")
        print("返回内容：", res.text if 'res' in locals() else '无响应')
    time.sleep(1)