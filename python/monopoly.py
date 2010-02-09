#!/usr/bin/env python


import random


# Bank values
bank = 15140 # standard monopoly start value
retention = .1 # amount they have to keep / not loan out

# Loans
loanrate = .1
loanpayment = .01
loancreditlimit = 40000

# Investments
bankrate = .05



# Utility bills
utilities = 10 # dollars per turn


# 
players = []


numofplayers = int(input('Number of players: '))

for x in range(numofplayers):
    players.append(input('Player name: '))

random.shuffle(players)

while 1:
    print bank
    
    for p in players:
        print players
        
    