#! /bin/bash
echo "Chuong trinh tim so lon nhat cua n so"
if [ $# -eq 0 ]
then
	echo "Khong co so nao duoc nhap"
else
	max=$1
	while [ $# -ne 0 ]
	do
		ds="$1 $ds"
		shift
	done
	for i in $ds
	do
		if [ $max -le $i ]
		then
			max=$i
		fi
	done
	echo "Gia tri lon nhat la: $max"
fi
exit 0
