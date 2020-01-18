IFS= read -r -p "Enter Commit Message: " commit_message
cd /home/shahraaz/Documents/CP
Commit.sh "$commit_message"
cd /home/shahraaz/bin
Commit.sh "$commit_message"
cd /home/shahraaz/Documents/Java
Commit.sh "$commit_message"
