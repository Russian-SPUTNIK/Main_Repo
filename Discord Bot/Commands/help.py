import discord
from discord.ext import commands


class Help(commands.Cog):
    def __init__(self, client):
        self.client = client

    @commands.command(name="help", aliases=['h', 'H'])
    async def help(self, ctx):
        embed = discord.Embed(
            title="Help",
            description="**```Hello, I am Spacy and I will provide you information about:```**",
            color=discord.Color.dark_blue()
        ).set_author(name=ctx.author, icon_url=ctx.author.avatar_url
        ).add_field(name="Personal Data", value=":thermometer: Body temperature\n:anatomical_heart: BPM (Beats Per Minutes)", inline=True
        ).add_field(name="Environment Data", value=":thermometer: Ambient temperature\n:dash: Atmospheric pressure\n:droplet: Humidity\n:sunny: Light", inline=True)

        return await ctx.send(embed=embed)


def setup(client):
    client.add_cog(Help(client))