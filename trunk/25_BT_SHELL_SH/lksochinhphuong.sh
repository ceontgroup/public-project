#! /bin/bash
check(){
local h=$((1+$1/2))
local i=0
while [ $i -le $h ]; do
	local temp=$(($i\*$i))
	i=$(($i+1))
	if [ $temp -eq $1 ]; then
		return 1
	fi
done
return 0
}
echo "Liet ke so chinh phuong tu 0 den n"
echo "Nhap mot so duong bat ky"
read n
if [ $n -lt 0 ]; then
	echo "So vua nhap qua nho!"
else	
	i=0
	while [ $i -le $n ]; do
		$(check $i)
		if [ $? -eq 1 ]; then
			ds="$ds $i"
		fi
		i=$(($i+1))
	done
	echo "Danh sach so chinh phuong: $ds"
fi
exit 0
