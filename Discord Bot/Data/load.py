import os
from termcolor import colored


def load_commands(client, l_coms):
    print(colored("===================", "red") + "COMMANDS" + colored("========================", "red"))

    for filename in os.listdir('./Commands'):
        if filename.endswith('.py'):
            client.load_extension('Commands.{}'.format(filename[:-3]))
            print(colored("> ", "magenta") + colored("'{}'".format(filename[:-3]), 'green') + colored(" is loaded!", "magenta"))
            l_coms += 1
    
    if l_coms == 0: print(colored(text="- None!", color="magenta"))
    else: print(colored("\n- Loaded Commands: ", "magenta") + colored("{}".format(l_coms), "green"))


def load_events(client, l_evs):
    print(colored("===================", "red") + "EVENTS" + colored("=========================", "red"))
    
    for filename in os.listdir('./Events'):
        if filename.endswith('.py'):
            client.load_extension('Events.{}'.format(filename[:-3]))
            print(colored("> ", "magenta") + colored("'{}'".format(filename[:-3]), 'green') + colored(" is loaded!", "magenta"))
            l_evs += 1
    
    if l_evs == 0: print(colored(text="None!", color="magenta"))
    else: print(colored("\n- Loaded Events: ", "magenta") + colored("{}".format(l_evs), "green"))


def load(client):
    l_coms = 0  # loaded commands
    l_evs = 0  # loaded events
    load_commands(client, l_coms)
    load_events(client, l_evs)