#! /bin/sh

echo "Chuong trinh in ra so dao nguoc cua mot so"
echo "N= "
read n
bit=0
tem=n
while [ $n -ne 0 ];do
	bit=$(($n%10))
	dec="$dec$bit"
	n=$(($n/10))
done
	echo "So dao nguoc cua $tem = $dec"
exit 0
