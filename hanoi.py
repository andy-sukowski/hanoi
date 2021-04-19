# See LICENSE file for copyright and license details.

import sys

# move n-th disk from `frm` to `to`
def move(n, frm, to, via):
    if n > 0:
        move(n - 1, frm, via, to)
        print('{0}: {1} → {2}'.format(n, frm, to))
        move(n - 1, via, to, frm)

inp = input('Number of disks: ')
if not inp.isdigit() or inp == '0':
    sys.exit('Error: invalid input')
n = int(inp)

move(n, 'a', 'c', 'b');
