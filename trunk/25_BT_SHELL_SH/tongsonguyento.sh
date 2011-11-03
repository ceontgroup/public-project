#! /bin/bash
check(){
local n=$1
if [ $n -lt 2 ]
then
	return 0
else
	local i=2
	local m=$(($n/2))
	while [ $i -le $m ]
	do
		local stop=$(($n%$i))
		if [ $stop -eq 0 ] 
		then
			break
		else
			i=$(($i+1))
		fi
	done
	if [ $i -le $m ]
	then
		return 0
	else
		return 1
	fi
fi
}

echo "Chuong trinh tinh tong cac so nguyen to tu 1 den N"
echo "Nhap n ="
read n
i=2
while [ $i -le $n ]
do
	$(check $i)
	if [ $? -eq 1 ]
	then
		tong=$(($tong+$i))
	fi
	i=$(($i+1))	
done
echo "Tong cac so nguyen to la <= $n la: $tong "
exit 0
