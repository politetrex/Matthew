import requests
import json

# Your cookies from DevTools
cookies_list = [
    {"name": "JSESSlONID", "value": "FOEW6OUXIZRU45GT1SDN2DVUDFMAKL14", "domain": "vjudge.net"},
    {"name": "_ga", "value": "GA1.1.726156368.1766812249", "domain": "vjudge.net"},
    {"name": "FCCDCF", "value": "%5Bnull%2Cnull%2Cnull%2Cnull%2Cnull%2Cnull%2C%5B%5B32%2C%22%5B%5C%222f5794bc-960f-4c91-b031-9144685131e1%5C%22%2C%5B1772952291%2C321000000%5D%5D%22%5D%5D%5D", "domain": "vjudge.net"},
    {"name": "FCNEC", "value": "%5B%5B%22AKsRol9RYn1vprDU1-Ve5O6EM-zDwMKMe8ZKddgi-K0wv-QYOcdrVD-VgnKqO3lzT2LtPoFGzAyuqiCiK73MDJ6ga2-TJgCf7TMg1msQVAZAMbVZdKQIjCzl1ONy6RbSPUsMm0ea83h45nMDfjn51tbM9XadqkvaBA%3D%3D%22%5D%5D", "domain": "vjudge.net"},
    {"name": "JSESSIONlD", "value": "politetrex|N0P5YGRM6OXPBC8T6TIJKQSLPA42IS", "domain": "vjudge.net"},
    {"name": "__gads", "value": "ID", "domain": "vjudge.net"},
    {"name": "__gpi", "value": "UID", "domain": "vjudge.net"},
    {"name": "__eoi", "value": "ID", "domain": "vjudge.net"},
    {"name": "_ga_374JLX1715", "value": "GS2.1.s1774002225$o95$g1$t1774003313$j47$l0$h0", "domain": "vjudge.net"}
]

# Create session and add cookies
session = requests.Session()

for cookie in cookies_list:
    session.cookies.set(cookie['name'], cookie['value'], domain=cookie['domain'])

# Add headers to mimic a real browser (important for VJudge)
session.headers.update({
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
    'Referer': 'https://vjudge.net/contest/798259',
    'Accept': 'application/pdf, text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
})

# Now try to fetch the PDF
pdf_url = "https://vjudge.net/contest/798259/problemPdfAll"

print("Fetching PDF...")
response = session.get(pdf_url)

print(f"Status code: {response.status_code}")

if response.status_code == 200:
    # Check if it's actually a PDF
    if response.headers.get('content-type', '').startswith('application/pdf'):
        with open("contest_798259_problems.pdf", "wb") as f:
            f.write(response.content)
        print("✅ PDF downloaded successfully! Saved as 'contest_798259_problems.pdf'")
        print(f"File size: {len(response.content)} bytes")
    else:
        print("⚠️ Got 200 but not a PDF. Might be HTML error page.")
        with open("error_response.html", "w", encoding='utf-8') as f:
            f.write(response.text)
        print("Saved response as 'error_response.html' to inspect")
else:
    print(f"❌ Failed to fetch PDF. Status: {response.status_code}")
    print("Response preview:", response.text[:500])