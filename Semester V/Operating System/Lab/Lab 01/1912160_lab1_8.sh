# Q.8. Write a shell script that determines the period for which a specified user is working on the system.

# nano 1912160_L1Q8.sh

echo "Enter Login Username: "
read User
last $User

# $chmod +x 1912160_L1Q8.sh
# $./1912160_L1Q8.sh
