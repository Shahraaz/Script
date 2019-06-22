import requests
r = requests.get('https://gstatic.com/generate_204', verify=False)
print r.url
