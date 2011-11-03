#! /bin/bash
echo "Chuong trinh kiem tra so nguyen to"
echo "Moi nhap so nguyen n"
read n
if [ $n -lt 2 ]
then
	echo "$n khong phai la so nguyen to"
else
	i=2
	m=$(($n/2))
	while [ $i -le $m ]
	do
		stop=$(($n%$i))
		if [ $stop -eq 0 ] 
		then
			break
		else
			i=$(($i+1))
		fi
	done
	if [ $i -le $m ]
	then
		echo "$n khong phai so nguyen to"
	else
		echo "$n la so nguyen to"
	fi
fi
exit 0
