#!/usr/bin/python3

import os
import sys

extention = ['cpp']

def create(path):
    os.makedirs(path, exist_ok=True)
    for i in extention:
        print("Creating file: " + path + "/sol." + i)
        with open(path + '/sol.' + i, 'w') as fp:
            pass

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: create.py path")
        sys.exit(1)
    else:
        print("Creating path: " + sys.argv[1])
        create(sys.argv[1])