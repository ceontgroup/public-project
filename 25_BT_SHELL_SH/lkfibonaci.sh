#! /bin/sh
echo "Chuong trinh liet ke day so fibonaci tu 1 den N"
echo "N = ?"
read n
a=1
b=1
ds=1
if [ $n -le 0 ]; then
	echo "So nhap vao qua nho"
else
	while [ $b -le $n ];do		
		tem=$b
		b=$(($b+$a))
		a=$tem
		ds="$ds $a"
	done
	echo "Danh sach so fibonaci <= $n"
	echo $ds
fi
exit 0
