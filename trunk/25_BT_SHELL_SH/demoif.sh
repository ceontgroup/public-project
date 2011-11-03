#! /bin/bash
echo "Chuong trinh demo cach su dung lenh if else"
echo "Nhap mot so duong bat ky"
read n
if [ $n -lt 0 ]; then
	echo "So vua nhap khong hop le "
elif [ $n -le 10 ];then
	echo "So vua nhap thuoc khoang [0..10]"
elif [ $n -le 20];then
	echo "So vua nhap thuoc khoang [10..20]"
fi
exit 0
