#!/usr/bin/env python3

import json
import os
import re

expr = re.compile('\s+(?P<commits>\d+)\s(?P<name>.*)\s<(?P<email>.*@.*)>')
gitlog = os.popen("git shortlog -sne")

names = dict()

for line in gitlog:
    match = expr.match(line)
    if match:
        c = match.groupdict()
    n = c['name']
    e = c['email']

    if n not in names:
        names[n] = {
            'name': n, # for JSON later
            'email': [], 
            'commits': int(c['commits'])
        }
    else:
        names[n]['commits'] += int(c['commits'])

    if not e.endswith("@users.noreply.github.com"):
        names[n]['email'].append(e)

contact_list = json.dumps(list(names.values()), ensure_ascii=False, indent=2)

f = open('Root/res/contacts.json', 'w')
f.write(contact_list)
f.close()

gitlog.close()
