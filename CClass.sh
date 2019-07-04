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
cat C:/\Script_Folder/\TClass.cpp >> a.cpp
cp a.cpp b.cpp
cp a.cpp c.cpp
cp a.cpp extra.cpp
code .
