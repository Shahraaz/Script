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
a = True
b = False
while a:
    try:
        resp = requests.get(url)
        if resp.url == url:
            print("Already logged in")
            sys.stdout.flush()
            str = input("Logout?(y/n) ")
            print(str)
            if len(str) == 0 or str[0] == 'y' or str[0] == 'Y':
                f = open("Url.txt", "r")
                server_ip = f.readline()
                f.close()
                print("Trying out the url " + server_ip)
                requests.get(server_ip+"logout?a")
                sys.stdout.flush()
                resp = requests.get(url)
            elif str[0] == 'n' or str[0] == 'N':
                a = False
                b = True
        if resp.url == url:
            print("Try manually")
            # sys.exit()
        else:
            a = False
    except KeyboardInterrupt:
        print("You raised an exception")
        sys.exit()
    except:
        print("Network Error\n")    

if b:
    sys.exit()

print(resp.url)
sys.stdout.flush()


def login():
    url = "http://detectportal.firefox.com/status.txt"
    resp = requests.get(url,timeout=10)
    # print("req End")
    server_url = resp.url
    i = server_url.find("fgtauth")
    if i == -1:
        sys.exit()
    # print("Fetch i j strat")
    server_ip = server_url[0:i]
    login_page = requests.get(server_url).text
    start_text = "name=\"magic\" value=\""
    i = login_page.find(start_text) + len(start_text)
    j = login_page.find("\"", i)
    # print("Fetch i j end")
    if i == -1 or j == -1:
        sys.exit()
    magic = login_page[i:j]
    # print("Login Attempt")
    resp = requests.post(server_ip, data={
        "magic": magic,
        "username": USER,
        "password": PASS
    },timeout=10)
    # print("Login Attempt Finished")
    i = resp.text.find(server_ip+"keepalive")
    j = resp.text.find("\"", i)
    keepalive_url = resp.text[i:j]
    if i == -1 or j == -1:
        print(USER, PASS, "Failed")
        sys.stdout.flush()
        return False, False
    # print("Logged in to Server: ", server_ip)
    now = datetime.now()
    print(USER, PASS, "Success")
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
    # print("Logout Start")
    if server_ip == False:
        return
    print("Logged Out")
    sys.stdout.flush()
    requests.get(server_ip+"logout?a",timeout=10)


while True:
    try:
        while True:
            i = random.randrange(0, len(CRED), 1)
            data = CRED[i].split()
            USER = data[0]
            PASS = data[1]
            server_url, keepalive_url = login()
            print("Time Stamp")
            now = datetime.now()
            print(now.strftime("%d-%m %H:%M:%S"))
            sys.stdout.flush()
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
        sys.exit()
    except:
        print("Error\n")
        sleep(10)
