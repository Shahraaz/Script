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

url = "http://detectportal.firefox.com/status.txt"
resp = requests.get(url)
if resp.url == url:
    print("Already logged in")
    sys.stdout.flush()
    str = input("Logout?(y/n) ")
    if str[0] == 'y' or str[0] == 'Y':
        f = open("Url.txt", "r")
        server_ip = f.readline()
        f.close()
        print("Trying out the url " + server_ip)
        requests.get(server_ip+"logout?a")
        sys.stdout.flush()
        resp = requests.get(url)
    else:
        sys.exit()

if resp.url == url:
    print("Try manually")
    sys.exit()

print(resp.url)
sys.stdout.flush()


def login():
    url = "http://detectportal.firefox.com/status.txt"
    resp = requests.get(url)
    server_url = resp.url
    i = server_url.find("fgtauth")
    if i == -1:
        sys.exit()
    server_ip = server_url[0:i]
    login_page = requests.get(server_url).text
    start_text = "name=\"magic\" value=\""
    i = login_page.find(start_text) + len(start_text)
    j = login_page.find("\"", i)
    if i == -1 or j == -1:
        sys.exit()
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
        now = datetime.now()
        print(USER, PASS, "Falied")
        print(now.strftime("%d-%m %H:%M:%S"))
        sys.stdout.flush()
        return False, False
    # print("Logged in to Server: ", server_ip)
    now = datetime.now()
    print(USER, PASS, "Success")
    print(now.strftime("%d-%m %H:%M:%S"))
    sys.stdout.flush()
    f = open("Url.txt", "w")
    f.write(server_ip)
    f.write("\n")
    f.write(keepalive_url)
    f.close()
    return server_ip, keepalive_url


def keepalive(keepalive_url):
    if keepalive_url == False:
        return
    print("Keepalive...")
    sys.stdout.flush()
    requests.get(keepalive_url)


def logout(server_ip):
    if server_ip == False:
        return
    print("Logged Out")
    sys.stdout.flush()
    requests.get(server_ip+"logout?a")


try:
    while True:
        i = random.randrange(0, len(CRED), 1)
        data = CRED[i].split()
        USER = data[0]
        PASS = data[1]
        server_url, keepalive_url = login()
        if server_url:
            sleep(2000)
            logout(server_url)
except KeyboardInterrupt:
    str = input("Do you want to run Commiter?(y/n) ")
    str2 = input("Do you want to shutdown?(y/n) ")
    if str == "" or str[0] == 'y' or str[0] == 'Y':
        os.system("globalCommit.sh")
    print("Bbye")
    sys.stdout.flush()
    logout(server_url)
    if str2 == "" or str2[0] == 'y' or str2[0] == 'Y':
        os.system("poweroff")
    
