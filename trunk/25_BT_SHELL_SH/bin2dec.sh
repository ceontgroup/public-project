#! /bin/sh
luythua(){
#x^y
local x=$1
local y=$2
local gt=1
while [ $y -ne 0 ];do
	gt=$(($gt\*$x))
	y=$(($y-1))
done
echo $gt
return 0
}
chuyen(){
local n=$1
local bit=0
local count=0
local tem=$n
local dec=0
while [ $n -ne 0 ];do
	local bit=$(($n%10))
	if [ $bit -gt 1 ];then
		return 0
	fi
	n=$(($n/10))
	lt=$(luythua 2 $count)
	lt=$(($bit\*$lt))
	dec=$(($dec+$lt))	
	count=$(($count+1))
done
echo "$tem = $dec"
return 1
}
echo "Chuong trinh chuyen tu nhi phan sang thap phan"
echo "N= "
read n
msg=$(chuyen $n)
if [ $? -eq 0 ];then
	echo "So nhap vao khong hop le"
else
	echo $msg
fi
exit 0
