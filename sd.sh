commitMessage = '0'
if [ -z "$1" ]
then
	commit_message='commitBeforeShutdown'
else
	commit_message=$1
fi
cd C:/\Users/\Sheraaz/\Desktop/\Competitive_programming
Commit.sh $commit_message
cd C:/\Users/\Sheraaz/\Desktop/\WebDevelopment
Commit.sh $commit_message
cd C:/\Script_Folder
wget http://172.16.12.1:1000/logout?/
rm logout@%2F
shutdown -s -t 0
