#!/usr/bin/python3
#
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
#
# Generates unicode casefold code
#

with open('data/CaseFolding.txt','r') as f:
    lines = f.readlines()

print('//SPDX-License-Identifier: LGPL-2.1-or-later\n')
print('/* Generated file, do not touch! */\n')
print('#include "libutfcase.h"\n')
print('uint32_t lu_casefold_simple(uint32_t cp)\n{')
print('\tswitch (cp) {')

folding_table = []

for line in lines:
    if (line[0] == '#'):
        continue;
    if (not line.strip()):
        continue;

    line = line.split('#')
    desc = line[1].strip()
    data = (line[0].strip().split(';'))

    fin = int(data[0], 16);
    ftype = data[1].strip()
    fout = [int(i, 16) for i in data[2].strip().split(' ')]

    folding_table.append([fin, ftype, fout, desc])

for i in folding_table:
    if (i[1] != 'F' and i[1] != 'T'):
        print('\t/* ' + i[3] + ' */')
        print('\tcase ' + hex(i[0]) + ':')
        print('\t\treturn ' + hex(i[2][0]) + ';')

print('\tdefault:\n\t\treturn cp;')
print('\t}\n}\n')

print('int lu_casefold(uint32_t cp, uint32_t *res)\n{')
print('\tswitch (cp) {')

for i in folding_table:
    if (i[1] == 'F'):
        print('\t/* ' + i[3] + ' */')
        print('\tcase ' + hex(i[0]) + ':')
        for j in i[2]:
            print('\t\t*(res++) = ' + hex(j) + ';')
        print('\t\treturn ' + str(len(i[2])) + ';');
print('\t}\n')
print('\t*res = lu_casefold_simple(cp);')
print('\treturn 1;')
print('}')
