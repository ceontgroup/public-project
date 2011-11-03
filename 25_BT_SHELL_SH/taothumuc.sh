#! /bin/sh
num=0
if [ $# -gt 0 ]
then
	while [ $num -ne 1000 ]
	do
		mkdir -p $1
		cd $1
		num=$(($num+1))
	done
fi
exit 0
