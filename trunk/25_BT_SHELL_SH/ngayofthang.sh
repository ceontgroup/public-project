#! /bin/sh
checknamnhuan(){
local n=$1
if [ $(($n%400)) -eq 0 ];then
	return 1
fi
if [ $(($n%4)) -eq 0 ] && [ $(($n%100)) -ne 0 ];then
	return 1
fi
return 0
}

echo "Chuong trinh in ra so ngay cua mot thang"
echo "Thang = ?"
read thang
echo "Nam = ?"
read nam
if [ $thang -eq 1 ] || [ $thang -eq 3 ] || [ $thang -eq 5 ] || [ $thang -eq 7 ] || [ $thang -eq 8 ] || [ $thang -eq 10 ] || [ $thang -eq 12 ];then
	echo "So ngay cua thang $thang nam $nam la 31 ngay"
elif [ $thang -eq 2 ];then
	$(checknamnhuan $nam)
	songay=$((28+$?))
	echo "So ngay cua thang $thang nam $nam la $songay ngay"
else
	echo "So ngay cua thang $thang nam $nam la 30 ngay"
fi
exit 0
