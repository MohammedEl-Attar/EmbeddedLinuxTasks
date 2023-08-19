import requests

url = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
print(url.json()['bpi']['USD'])