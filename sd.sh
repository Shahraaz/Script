commit_message='0'
if [ -z "$1" ]
then
	commit_message='commitBeforeShutdown'
else
	commit_message=$1
fi
CommitGlobal.sh $commit_message
if [ -z "$2" ]
then
	wget http://172.16.12.1:1000/logout?/
	wget http://192.168.41.1:1000/logout?/
	rm logout@%2F
	shutdown -s -t 0
else
	wget http://172.16.12.1:1000/logout?/
	wget http://192.168.41.1:1000/logout?/
	rm logout@%2F
fi
