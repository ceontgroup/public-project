#! /bin/sh

echo "Chuong trinh chuyen tu thap phan sang bat phan"
echo "N= "
read n
bit=0
tem=$n
while [ $n -ne 0 ];do
	bit=$(($n%8))
	oct="$bit$oct"
	n=$(($n/8))
done
	oct="0$oct"
if [ $bit -ne 0 ];then
	echo "$tem = $oct"
else
	echo "$tem = 0"
fi
exit 0
