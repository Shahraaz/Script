commit_message='0'
if [ -z "$1" ]
then
	commit_message='globalCommit'
else
	commit_message=$1
fi
cd C:/\Users/\Sheraaz/\Desktop/\Competitive_programming
Commit.sh $commit_message
cd C:/\Users/\Sheraaz/\Desktop/\WebDevelopment
Commit.sh $commit_message
cd C:/\Script_Folder
Commit.sh $commit_message