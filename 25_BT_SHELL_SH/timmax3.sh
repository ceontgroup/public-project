#! /bin/bash
echo "Chuong trinh tim so lon nhat trong 3 so"
echo "Nhap a"
read a
echo "Nhap b"
read b
echo "Nhap c"
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
	echo "$a la so lon nhat"
elif [ $b -gt $c ] && [ $b -gt $a ]
then 
	echo "$b la so lon nhat"
else
	echo "$c la so lon nhat"
fi
exit 0
