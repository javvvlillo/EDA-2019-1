import os

def print_logo():
    with open(os.path.abspath('../../Utils')+'/edalogo.txt', 'r') as file:
        for line in file:
            print(line, end='')
