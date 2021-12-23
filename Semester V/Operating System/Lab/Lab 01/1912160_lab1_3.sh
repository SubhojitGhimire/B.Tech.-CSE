# Q.3. Write a sed command that swaps the first and second words in each line in a file.

# $touch 1912160_L1Q3.sh

echo "Enter file name where the swap operation is to be performed: "
read fileName
sed 's/\([^ ]*\) *\([^ ]*\)/ \2 \1/g' $fileName

# $chmod +x 1912160_L1Q3.sh
# $./1912160_L1Q3.sh
