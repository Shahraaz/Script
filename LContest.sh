#!/bin/bash
Contest_Name='0'
if [ -z "$1" ]
then
	Contest_Name='UnNamedContest'
else
	Contest_Name=$1
fi
direct='0'
if [ -z "$2" ]
then
	direct=$(pwd)
else
	direct=$2
fi
cd $direct
mkdir $Contest_Name
cd $Contest_Name
touch a.cpp
> a.cpp
cat /home/shahraaz/bin/LClass.cpp >> a.cpp
cp a.cpp b.cpp
cp a.cpp c.cpp
cp a.cpp d.cpp
cp a.cpp extra.cpp
cp -r /home/shahraaz/bin/.vscode .vscode
code .
code d.cpp
code c.cpp
code b.cpp
code a.cpp