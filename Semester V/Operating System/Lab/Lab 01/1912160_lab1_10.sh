# 1912160_L01Q10.sh

# Q.10. Write a shell script that deletes all lines containing a specified word in one or more files supplied as arguments to it.

# $nano L01Q10.sh

echo "Enter Word for which the lines are to be deleted: "
read word
echo "$word containing lines will be deleted, wherever applicable"
for fileName in *
do
	if [[ $fileName != *.sh ]]
	then
		echo "File Name: "$fileName
		grep -iv $word $fileName > "temp"$fileName
		rm $fileName
		mv "temp"$fileName $fileName
		
	fi
done

# $chmod +x L01Q10.sh
# $./L01Q10.sh
