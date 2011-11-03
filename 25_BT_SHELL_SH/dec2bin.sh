#! /bin/sh

echo "Chuong trinh chuyen tu thap phan sang nhi phan"
echo "N= "
read n
bit=0
while [ $n -ne 0 ];do
	bit=$(($n%2))
	bin="$bit$bin"
	n=$(($n/2))
done
	bin="$bin"b
if [ $bit -ne 0 ];then
	echo "$n = $bin"
else
	echo "$n = 0 b"
fi
exit 0
