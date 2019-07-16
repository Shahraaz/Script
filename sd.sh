IFS= read -r -p "Enter Commit Message: " commit_message
CommitGlobal.sh "$commit_message"
wget --tries=1 http://172.16.24.1:1000/logout?/
wget --tries=1 http://192.168.41.1:1000/logout?/
wget --tries=1 http://192.168.5.1:1000/logout?/
rm logout@%2F
shutdown -s -t 0