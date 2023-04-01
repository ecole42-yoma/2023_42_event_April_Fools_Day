#!/usr/bin/env python3

import requests
# Enter the name of a Pokemon: Pikachu
# Name: Pikachu
# Abilities:
# - Static
# - Lightning-rod

name = input("Enter the name of a Pokemon: ")
name_save = name.strip()
name = name.strip().lower()

url = "https://pokeapi.co/api/v2/pokemon/" + name

response = requests.get(url)
if (response.status_code != 200):
	print("Error: Could not find a Pokemon: {}".format(name_save))
	exit()
data = response.json()

print("Name:", name_save)
print("Abilities:")
for ability in data['abilities']:
	temp = ability['ability']['name']
	temp = temp.lower()
	front = temp[0]
	front = front.upper()
	temp = front + temp[1:]
	print("- {}".format(temp))
