#! /bin/bash
check(){
n=$1
count=0
tem=$n
while [ $tem -ne 0 ];do
	d=$(($tem%10))
	list="$list $d"
	count=$(($count+1))
	tem=$(($tem/10))
done
if [ $(($count%2)) -eq 1 ];then
	return 0
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
		return 1
	else
		return 0
	fi
fi
}
echo "Chuong trinh liet ke cac so hanh phuc tu 1 den N"
echo "Nhap vao mot so duong bat ky : "
read n
if [ $n -lt 10 ];then
	echo "$n qua nho !!"
else
	i=0
	while [ $i -le $n ];do
		$(check $i)
		if [ $? -eq 1 ];then
			ds="$ds $i"
		fi
		i=$(($i+1))		
	done
	echo "Danh sach cac so hanh phuc: $ds"
fi
exit 0
exit 0
