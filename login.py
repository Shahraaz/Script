import requests
import sys
import os
import random
from time import sleep
from datetime import datetime
random.seed(datetime.now())

f = open("success.txt", "r")
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
    server_ip = server_url[0:i]
    sys.stdout.flush()
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
        return False, False
    print("Logged in to Server: ", server_ip)
    print(USER, PASS)
    sys.stdout.flush()
    f = open("Url.txt", "w")
    f.write(server_ip)
    f.write("\n")
    f.write(keepalive_url)
    f.close()
    i = resp.text.find("Firewall authentication failed. Please try again.")
    return server_ip, keepalive_url


def keepalive(keepalive_url):
    if keepalive_url == None:
        return
    print("Keepalive...")
    sys.stdout.flush()
    requests.get(keepalive_url)


def logout(server_ip):
    if server_ip == None:
        return
    print(server_ip)
    sys.stdout.flush()
    str1 = input("Do you want to shutdown?(y/n) ")
    str = input("Do you want to run Commiter?(y/n) ")
    if str[0] == 'y' or str[0] == 'Y':
        os.system("commitGlobal.sh")
    requests.get(server_ip+"logout?a")
    print("Bbye")
    sys.stdout.flush()
    if str1[0] == 'y' or str1[0] == 'Y':
        os.system("shutdown -s -t 0")


try:
    while True:
        i = random.randrange(0, len(CRED), 1)
        print(i,len(CRED))
        data = CRED[i].split()
        USER = data[0]
        PASS = data[1]
        server_url, keepalive_url = login()
        if server_url:
            while True:
                sleep(2000)
                keepalive(keepalive_url)
except KeyboardInterrupt:
    logout(server_url)
