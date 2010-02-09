#!/usr/bin/env python


# wordpress domain
autopost = True  # set to False to disable it
wordpress = 'http://lolvids.com/wordpress/'


useragent = "Mozilla/5.0 (compatible) Firefox"

socialurls = [
    'http://www.reddit.com/r/videos/.rss',
#    'http://feeds.digg.com/digg/videos/popular.rss',
    
]

titlesdone = [ ]



import urllib, urllib2
import feedparser
from time import sleep

def req(url):
    global useragent
    r = urllib2.Request(url, None, {'User-agent': useragent})
    return urllib2.urlopen(r).read()

def parselink(link):
    if not link.startswith('http://'):
        return None
    
    host = link.split('/')[2]
    
    if 'digg.com' in host:
        r = req(link)
        l = r.split('s.prop19 = \'')[1]
        l = l.split("'")[0]
        return parselink(link)
    elif 'reddit.com' in host:
        pass
    
    #video sites
    
    elif 'youtube.com' in host:
        r = req(link)
        l = r.split("var embedUrl = '")[1]
        l = l.split("';")[0]
        return '<object width="425" height="344"><param name="movie" value="$url$"></param><param name="allowFullScreen" value="true"></param><param name="allowscriptaccess" value="always"></param><embed src="$url$" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="425" height="344"></embed></object>'.replace('$url$', l)
    
    elif 'metacafe.com' in host:
        try:
            vid = link.split('/')[4:5]
            vid ='http://www.metacafe.com/fplayer/%s/%s.swf' % (vid[0], vid[1])
            return '<embed src="$url$" width="400" height="345" wmode="transparent" pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash"> </embed>' % (vid)
        except:
            return None
    
    
    # try catch embeded videos on other sites
    
    else:
        r = req(link)
        
        # try youtube link search
        l = r.split('<a href="http://www.youtube.com/watch')
        if len(l) > 1:
            l = l[1].split('"')[0]
            return parselink('http://www.youtube.com/watch%s' % l)
        
        
        return None
    

#while 1:
for social in socialurls:
    feed = feedparser.parse(social)
    for item in feed.entries:
        title = item.title
        link = item.link
        
        if 'reddit.com' in social:
            content = item.description
            content = content.split('>[link]<')[0]
            content = content.split('"')[-2:-1][0]
            parselink(content)
        else:  
            # get feed information
            parselink(link)
        
        
        print title
        #print link
    
#    sleep(15*60)