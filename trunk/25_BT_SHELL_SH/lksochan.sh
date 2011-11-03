#! /bin/bash
check(){
n=$1
return $(($n%2))
}
echo "Chuong trinh liet ke so chan tu 1 den N"
echo "Nhap n ="
read n
if [ $n -lt 1 ]
then
	echo "So n nhap vao qua nho"
else
	i=1
	while [ $i -le $n ]
	do
		$(check $i)
		if [ $? -eq 0 ]
		then
			ds="$ds $i"
		fi
		i=$(($i+1))
	done
	echo "Danh sach so chan: "
	echo $ds
fi
exit 0
