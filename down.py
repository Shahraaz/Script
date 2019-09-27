import os
import threading
import requests 
url = input()
# resp = requests.post(url)
# print(resp)
os.system(url)
f = open("index.html")
all = []
for line in f:
    # print (line)
    i = line.find('/content')
    if i != -1:
        # print(i)
        j = line.find('.mp4', i)
        # print(i,j)
        if j != -1:
            all.append("wget "+"https://nptel.ac.in"+line[i:j] + ".mp4")

# print(len(all))


def download(url):
    # print(url)
    os.system(url)

for url in all:
    download(url)