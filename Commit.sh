#!/bin/bash
commit_message='0'
if [ -z "$1" ]
then
    commit_message='Auto Commit'
else
    commit_message=$1
fi
echo $commit_message
direct='0'
if [ -z "$2" ]
then
    direct=$(pwd)
else
    direct=$2
fi
cd $direct
git add --all
if [ $? -eq 0 ]
then
    git commit -m "$(date +"%a, %b %d %H:%M") $commit_message"
    git push -u origin master
else
    folder=$(ls $2)
    for f in $folder
    do	if [ -d $f ]
        then
            cd $f
            ls .git
            if [ $? -eq 1 ]
            then
                cd ..
            else
                git add --all
                git commit -m "$(date +"%a, %b %d %H:%M") $commit_message"
                git push -u origin master
                cd ..
            fi
        fi
    done
fi