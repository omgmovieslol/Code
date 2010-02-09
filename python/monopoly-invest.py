#!/usr/bin/env python


rate = .10
dividends = .0000

# creditlimit = 20000

turns = 0

print """Monopoly Investments

Rate: %.3f 
Dividends: %.3f 
""" % (rate * 100, dividends * 100)


investment = float(input('Enter investment amount: '))

while investment > 0:
    print """Current investment: %.2f
Interest: %.2f
Dividend: %.2f
Next round: %.2f

Negative, take out. Positive, invest more. 0 = nothing.

""" % (investment, investment*rate, investment*dividends, investment + investment*rate + investment*dividends)
    paid = ''
    while(paid == '' or investment + paid < 0):
        inp = str(input('Action: '))
        #if not inp.isint():
        #    paid = ''
        #else:
        paid = int(inp)
    if paid < 0:
        investment += paid
        investment = investment + investment*rate + investment*dividends
    else:
        investment = investment + investment*rate + investment*dividends
        investment += paid
    
    
    
    
