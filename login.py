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


def login():
    url = "http://detectportal.firefox.com/status.txt"
    resp = requests.get(url)
    if resp.url == url:
        print("Already logged in")
        sys.stdout.flush()
        return None, None
    server_url = resp.url
    i = server_url.find("fgtauth")
    server_ip = server_url[0:i]
    print("Logged in to Server: ", server_ip)
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
    f = open("Url.txt", "w")
    f.write(server_ip)
    f.write("\n")
    f.write(keepalive_url)
    f.close()
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
    str = input("Do you want to run Commiter\n")
    if str[0] == 'y' or str[0] == 'Y':
        os.system("commitGlobal.sh")
    requests.get(server_ip+"logout?a")
    print("Bbye")
    sys.stdout.flush()
    os.system("shutdown -s -t 0")


try:
    server_url, keepalive_url = login()
    while True:
        sleep(2000)
        keepalive(keepalive_url)
except KeyboardInterrupt:
    logout(server_url)
