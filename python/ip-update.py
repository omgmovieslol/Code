#!/usr/bin/env python


computer = 'james-desktop' # name of computer

url = 'http://xrho.com/computers.php?id=%s&ip=[ip]' % computer # update url
update = '3600'  # update time in seconds

import urllib
from time import sleep


