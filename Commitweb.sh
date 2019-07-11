commit_message='0'
if [ -z "$1" ]
then
    commit_message='webCommit'
else
    commit_message=$1
fi
cd C:/\Users/\Sheraaz/\Desktop/\WebDevelopment
Commit.sh $commit_message