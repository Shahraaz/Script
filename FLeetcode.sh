#!/bin/bash
File_Name='0'
if [ -z "$1" ]
then
    File_Name='UnNamedFile.cpp'
else
    File_Name=$1
fi
direct='0'
if [ -z "$2" ]
then
    direct=$(pwd)
else
    direct=$2
fi
cd $direct
touch $File_Name
> $File_Name
cat C:/\Script_Folder/\LClass.cpp >> $File_Name
code $File_Name