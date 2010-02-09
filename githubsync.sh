#!/bin/sh

# automatically adds and syncs everything in this folder
# uses this crontab entry
# */5 * * * *  cd /home/james/Dropbox/code/ && ./githubsync.sh 

printf "Adding files to index..."
git add *
git commit -m "Automatic Push - `date +%c`"
printf "Pushing..."
git push origin master
printf "Completed."

