import discord
from discord.ext import commands
from sys import path

path.insert(1, "./Data")
from Data.get_data import get_data
from Data.load import load


client = commands.Bot(command_prefix="ss.", intents=discord.Intents.all())
client.remove_command('help')


load(client)
client.run(get_data()["token"])