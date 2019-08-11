import requests
import sys
import os
from time import sleep

f = open("certificate.txt", "r")
USER = f.readline()
USER = USER[:-1]
PASS = f.readline()
PASS = PASS[:-1]
f.close()

url = "http://detectportal.firefox.com/status.txt"
resp = requests.get(url)
server_url = resp.url
i = server_url.find("fgtauth")
server_ip = server_url[0:i]
login_page = requests.get(server_url).text
start_text = "name=\"magic\" value=\""
i = login_page.find(start_text) + len(start_text)
j = login_page.find("\"", i)
magic = login_page[i:j]
resp = requests.post(server_ip, data={
    "magic": magic,
    "username": USER,
    "password": PASS
})
i = resp.text.find(server_ip+"keepalive")
j = resp.text.find("\"", i)
keepalive_url = resp.text[i:j]
if i == -1:
    i = resp.text.find("Firewall authentication failed")
    # print(resp.text)
    if i == -1:
        f = open("overLimit.txt", "a+")
        f.write(USER)
        f.write(' ')
        f.write(PASS)
        f.write('\n')
        print(USER, PASS, "OverLimit or Falied")
        f.close()
else:
    f = open("success.txt", "a+")
    f.write(USER)
    f.write(' ')
    f.write(PASS)
    f.write('\n')
    print(USER,PASS,"Success")
    f.close()
    requests.get(server_ip+"logout?a")
