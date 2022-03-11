import json

def get_data():
    with open('Data/config.json', 'r') as file:
        return json.load(file)