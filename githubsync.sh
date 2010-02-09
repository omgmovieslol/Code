#!/bin/sh

printf "Adding files to index..."
git add *
git commit -m "Automatic Push - `date +%c`"
printf "Pushing..."
git push origin master
printf "Completed."

