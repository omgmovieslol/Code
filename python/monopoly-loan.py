#!/usr/bin/env python


rate = .15
payment = .05

creditlimit = 40000

turns = 0

print """Monopoly Loans

Rate: %.3f 
Payment Amount: %.3f 
""" % (rate * 100, payment * 100)

loan = creditlimit + 1

while loan > creditlimit:
    loan = float(input('Enter loan amount: '))

while loan > 0:
    loan = loan + loan*rate
    print """Current loan: %.2f
Amount due: %.2f

Use negative amount to take out more

""" % (loan, loan*payment)
    paid = 0
    while(paid == 0 or not ( (paid < 0  and not(loan - paid + loan*payment > creditlimit)) or paid >= loan*payment)):
        paid = int(input('Payment: '))
    if paid < 0:
        loan = loan - paid + loan*payment
    else:
        loan = loan - paid
    
