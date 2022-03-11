import discord
from discord.ext import commands
import requests

from sys import path
path.insert(1, "../Data")
from Data.get_data import get_data


class Send_Info(commands.Cog):
    def __init__(self, client):
        self.client = client
        self.channel_id = "951818732827717672"
        self.url = f"https://discord.com/api/v9/channels/{self.channel_id}/messages"
    
    @commands.command(name="si", aliases=['send info'])
    async def send_info(self, ctx):
        # payload = {
        #     'content': ':pizza: random shit sent by discord request :pizza:' 
        # }

        # header = {
        #     'authorization': 'NjgyNjUzOTA5NjU5MDI1NDMw._Vq98WjxrWEwIVg52YgQfNUybEs'
        # }

        # r = requests.post(url=self.url, data=payload, headers=header)
        # print(r.status_code)
        # print(self.client.user.avatar_url)
        pass


def setup(client):
    client.add_cog(Send_Info(client))