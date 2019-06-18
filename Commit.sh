#!/bin/bash
commit_message='0'
if [ -z "$1" ]
then
	commit_message='Bash_Auto_Commit'
else
	commit_message=$1
fi
dt=$(date '+%d/%m/%Y %H:%M:%S');
commit_message= "$commit_message $dt"
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
	git commit -m $commit_message
	git push -u origin master
fi

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
			git commit -m $commit_message
			git push -u origin master
			cd ..
		fi
	fi
done
