# Q.7. Write a shell script that takes a command-line argument and reports on whether it is a directory, a file, or something else.

# nano 1912160_L1Q7.sh

echo "Enter File Name: "
read fileName
if [ -f $fileName ]
then
	echo $fileName "is a file"
elif [ -d $fileName ]
then
	echo $fileName "is a directory"
else
	echo $fileName "is something else"
fi

# $chmod +x 1912160_L1Q7.sh
# $./1912160_L1Q7.sh
