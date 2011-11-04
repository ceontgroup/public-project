#! /bin/bash

echo "Chuong trinh kiem tra so hanh phuc"
echo "Nhap vao mot so duong bat ky : "
read n
count=0
tem=$n
while [ $tem -ne 0 ];do
	d=$(($tem%10))
	list="$list $d"
	count=$(($count+1))
	tem=$(($tem/10))
done
if [ $(($count%2)) -eq 1 ];then
	echo "$n khong phai la so hanh phuc"
else
	h=$(($count/2))
	for i in $list;do
		if [ $h -gt 0 ];then
			left=$(($left+$i))
		else
			right=$(($right+$i))
		fi
		h=$(($h-1))
	done
	if [ $right -eq $left ];then
		echo "$n la so hanh phuc"
	else
		echo "$n khong phai so hanh phuc"
	fi
fi
exit 0
