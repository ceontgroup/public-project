#! /bin/bash
echo "Chuong trinh demo cach su dung lenh case"
echo "Nhap mot so duong bat ky tu 2 den 8"
read n
case $n in
	"2" ) echo "Thu 2";;
	"3" ) echo "Thu 3";;
	"4" ) echo "Thu 4";;
	"5" ) echo "Thu 5";;
	"6" ) echo "Thu 6";;
	"7" ) echo "Thu 7";;
	"8" ) echo "Chu nhat";;
	* )	echo "So vua nhap khong hop le";;
esac
exit 0
