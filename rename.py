# coding=utf-8
import os
import re

basedir = '.'
if __name__ == '__main__':
    regex = re.compile(r'\d{3}\..*?')
    dirs = os.listdir(basedir)
    for name in dirs:
        if regex.match(name):
            os.renames(os.path.join(basedir, name), os.path.join(basedir, name[4:]))
