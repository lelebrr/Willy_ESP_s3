import urllib.request
import re

urls = [
    "https://pt.aliexpress.com/item/4001021044000.html",
    "https://pt.aliexpress.com/item/1005006382050284.html",
    "https://pt.aliexpress.com/item/32714713175.html",
    "https://pt.aliexpress.com/item/1005006317323517.html",
    "https://pt.aliexpress.com/item/1005006179466246.html",
    "https://pt.aliexpress.com/item/1005006582698705.html",
    "https://pt.aliexpress.com/item/1005005699882165.html",
    "https://pt.aliexpress.com/item/1005007175919889.html",
    "https://pt.aliexpress.com/item/1005006049733130.html",
    "https://pt.aliexpress.com/item/1005004921253170.html",
    "https://pt.aliexpress.com/item/1005005975338275.html",
    "https://pt.aliexpress.com/item/1005007051434528.html",
    "https://pt.aliexpress.com/item/1005008633633718.html",
    "https://pt.aliexpress.com/item/1005005200440286.html",
    "https://pt.aliexpress.com/item/1005007143596890.html",
    "https://pt.aliexpress.com/item/32560280169.html",
    "https://pt.aliexpress.com/item/1005005377729431.html"
]

req_headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

with open("ali_titles_utf8.txt", "w", encoding="utf-8") as f:
    for url in urls:
        f.write(f"URL: {url}\n")
        try:
            req = urllib.request.Request(url, headers=req_headers)
            with urllib.request.urlopen(req, timeout=10) as response:
                html = response.read().decode('utf-8', errors='ignore')
                og_match = re.search(r'<meta\s+property=["\']og:title["\']\s+content=["\'](.*?)["\']', html, re.IGNORECASE)
                og_title = og_match.group(1) if og_match else "No og:title found"
                f.write(f"OG Title: {og_title}\n")
        except Exception as e:
            f.write(f"Error: {e}\n")
        f.write("-" * 50 + "\n")
