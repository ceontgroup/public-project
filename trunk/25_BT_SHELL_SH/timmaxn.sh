#! /bin/bash
echo "Chuong trinh tim so lon nhat cua n so"
if [ $# -eq 0 ]
then
	echo "Khong co so nao duoc nhap"
else
	max=$1
	echo $#
	while [ $# -eq 0 ]
	do
		$ds="$ds $1"
		shift
	done
	echo $ds
	for i in $ds
	do
		if [ $max -lt $i ]
		then
			$max=$i
		fi
	done
	echo "Gia tri lon nhat la: $max"
fi
exit 0
