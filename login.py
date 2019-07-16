import requests
import sys
import os
from time import sleep

f = open("certificate.txt", "r")
USER = f.readline()
USER = USER[:-1]
PASS = f.readline()
PASS = PASS[:-1]


def login():
    url = "http://detectportal.firefox.com/status.txt"
    resp = requests.get(url)
    if resp.url == url:
        print("Already logged in")
        return None, None
    server_url = resp.url
    i = server_url.find("fgtauth")
    server_ip = server_url[0:i]
    print("Logged in to Server: ", server_ip)

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
    return server_ip, keepalive_url


def keepalive(keepalive_url):
    print("Keepalive...")
    if keepalive_url == None:
        return
    requests.get(keepalive_url)


def logout(server_ip):
    print(server_ip)
    if server_ip == None:
        return
    print("Bbye")
    os.system("commitGlobal.sh")
    requests.get(server_ip+"logout?a")


try:
    server_url, keepalive_url = login()
    while True:
        sleep(2000)
        keepalive(keepalive_url)
except KeyboardInterrupt:
    logout(server_url)
