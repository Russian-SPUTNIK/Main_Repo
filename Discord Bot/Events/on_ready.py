import discord
from discord.ext import commands
from termcolor import colored
import datetime


class On_Ready(commands.Cog):
    def __init__(self, client):
        self.client = client

    async def message(self):
        print(colored("===================", "red") + "BOT" + colored("============================", "red"))
        print(colored('Bot ', "magenta") + colored('{0.user}'.format(self.client), "red") + colored(' is ready!', "magenta"))
        print(colored("==================================================", "red"))

        embed = discord.Embed(
            title=f"{self.client.user.name} is online!",
            description="**Date** :alarm_clock:```{}```".format(datetime.datetime.now().strftime("%a, %#d %B %Y, %I:%M:%S %p, UTC")),
            color=discord.Color.dark_blue()
        ).set_thumbnail(url=self.client.user.avatar_url)

        guild = discord.utils.get(self.client.guilds, id=940677040674332722) # in J.A.R.V.I.S. HQ
        if guild:
            channel = discord.utils.get(guild.channels, id=951818732827717672) # online channel
            return await channel.send(embed=embed)

    @commands.Cog.listener()
    async def on_ready(self):
        await self.message()


def setup(client):
    client.add_cog(On_Ready(client))