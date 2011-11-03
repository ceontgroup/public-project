#! /bin/bash
echo "Kiem tra so chinh phuong"
echo "Nhap mot so duong bat ky"
read n
if [ $n -lt 0 ]; then
	echo "So vua nhap qua nho!"
else
	h=$((1+$n/2))
	i=0
	while [ $i -le $h ]; do
		temp=$(($i\*$i))
		i=$(($i+1))
		if [ $temp -eq $n ]; then
			break
		fi
	done
	if [ $temp -eq $n ]; then
		echo "$n la so chinh phuong"
	else
		echo "$n khong phai la so chinh phuong"
	fi
fi
exit 0
