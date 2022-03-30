import os
from termcolor import colored


def load_commands(client, l_coms):
    for filename in os.listdir('./Commands'):
        if filename.endswith('.py'):
            client.load_extension('Commands.{}'.format(filename[:-3]))
            l_coms += 1

def load_events(client, l_evs):    
    for filename in os.listdir('./Events'):
        if filename.endswith('.py'):
            client.load_extension('Events.{}'.format(filename[:-3]))
            l_evs += 1

def load(client):
    l_coms = 0  # loaded commands
    l_evs = 0  # loaded events
    load_commands(client, l_coms)
    load_events(client, l_evs)
