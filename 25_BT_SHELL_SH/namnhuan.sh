#! /bin/sh
check(){
local n=$1
if [ $(($n%400)) -eq 0 ];then
	return 1
fi
if [ $(($n%4)) -eq 0 ] && [ $(($n%100)) -ne 0 ];then
	return 1
fi
return 0
}

echo "Chuong trinh kiem tra nam nhuan"
echo "Nhap mot nam bat ky n= ?"
read nam
$(check $nam)
if [ $? -eq 1 ];then
	echo "$nam la nam nhuan"
else
	echo "$nam khong phai nam nhuan"
fi
exit 0
