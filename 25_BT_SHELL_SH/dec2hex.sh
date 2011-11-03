#! /bin/sh

echo "Chuong trinh chuyen tu thap phan sang bat phan"
echo "N= "
read n
bit=0
while [ $n -ne 0 ];do
	bit=$(($n%16))
	case $bit in 
		"10" ) hex="A$hex" ;;
		"11" ) hex="B$hex" ;;
		"12" ) hex="C$hex" ;;
		"13" ) hex="D$hex" ;;
		"14" ) hex="E$hex" ;;
		"15" ) hex="F$hex" ;;
		* )	hex="$bit$hex" ;;
	esac
	n=$(($n/16))
done
	hex="0x$hex"
if [ $bit -ne 0 ];then
	echo "$n = $hex"
else
	echo "$n = 0"
fi
exit 0
