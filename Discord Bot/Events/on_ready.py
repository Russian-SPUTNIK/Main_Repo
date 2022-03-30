import discord
from discord.ext import commands, tasks
from termcolor import colored
from itertools import cycle
import datetime


class On_Ready(commands.Cog):
    def __init__(self, client):
        self.client = client
        self.cur_status = cycle([
            "“If you wish to make an apple pie from scratch, you must first invent the universe.”",
            "“We are like butterflies who flutter for a day and think it is forever.”",
            "“We make our world significant by the courage of our questions and the depth of our answers.”",
            "“Books break the shackles of time, proof that humans can work magic.”"
        ])
    
    @tasks.loop(seconds=30)
    async def change_status(self):
        await self.client.change_presence(status=discord.Status.online, activity=discord.Game(next(self.cur_status)))

    async def message(self):
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
        self.change_status.start()
        await self.message()


def setup(client):
    client.add_cog(On_Ready(client))
