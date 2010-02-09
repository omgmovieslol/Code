#! /usr/bin/env python

computer = 'james-desktop'

loc = 'http://ip.xrho.com/update.php'

import socket
from time import sleep
import urllib

def getip():
  s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  s.connect(("gmail.com", 80))
  return s.getsockname()[0]


while 1:
 # try:
  urllib.urlopen('%s?comp=%s&ip=%s' % (loc, computer, getip()))
 # except:
 #   pass
  sleep(30*60)
