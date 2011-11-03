// Class automatically generated by Dev-C++ New Class wizard

#include "binary.h" // class's header file
#include <string.h>
#include <assert.h>
#include <math.h>
// class constructor
binary::binary(int n):size(MAXBIT)
{	
	realSize=0;
	int _n= n<0 ? -n-1: n;
	bit = new char[size];
	for (int i=0;i<size;i++){
		if (n>=0) bit[i]=(_n%2)+48;
		else bit[i]= ((_n%2)>0) ? 48 : 1+48;
		_n=_n/2;
		}
	realSize=RealSize();
}
binary::binary(const char *s):size(MAXBIT){
	realSize=0;
	bit=new char[size];
	for(int i=0;i<size;i++) bit[i]='0';
	for(int i=strlen(s)-1;i>=0;i--)
			if (s[strlen(s)-i-1]=='0'||s[strlen(s)-i-1]=='1')
				bit[i]=s[strlen(s)-i-1];
			else break;
	for(int i=size-1;i>=0;i--)
		if (bit[i]=='1') break;
		else realSize++;
	realSize=RealSize();
	}
binary::binary(const binary &obj):size(obj.size){
	bit=new char[size];
	realSize=obj.realSize;
	for(int i=0;i<size;i++) bit[i]=obj.bit[i];
	};
// class destructor
binary::~binary()
{
	delete [] bit;
}
int binary::RealSize(){
	int count=0;
	for(int i=size-1;i>=0;i--)
		if (bit[i]=='1') break;
		else count++;
	return size-count;	
	};
ostream &operator<<(ostream &os,const binary &obj){
	if (obj.realSize<1) os<<'0';
	for(int i=obj.realSize-1;i>=0;i--) os<<obj.bit[i];
	return os;
	};
istream &operator>>(istream &is,binary &obj){
	char tem[obj.size];
	is.getline(tem,obj.size);
	obj=binary(tem);
	return is;
	};
const binary &binary::operator=(const binary &obj){
	if (this==&obj) return *this;
	if (obj.realSize>size) realSize=size;
	else realSize=obj.realSize;
	for(int i=0;i<size;i++)
		if (i<realSize) bit[i]=obj.bit[i];
		else bit[i]='0';
	};
binary::operator int()const{
	int dec=0,sign=1;
	binary tem=*this;
	if (bit[size-1]=='1'){ //if not unsigned then 
		sign=-1;
		~tem;
		tem.realSize=tem.RealSize();// update real size
		tem=tem + (binary)1;
		tem.realSize=tem.RealSize();// update real size		
		}
	for(int i=0;i<tem.size;i++) 
		dec+=(tem.bit[i]-48)*(int)pow(2,i);	
	return sign*dec;
	};
binary binary::operator+(const binary &obj)const{
	binary tem;
	int m=0;
	for (int i=0;i<tem.size;i++){
		tem[i]=(bit[i]+obj[i]+m)%2 + 48;
		m=((bit[i]+obj[i]+m)/2)%2;
		}
	tem.realSize=tem.RealSize();
	return tem;
	};
binary binary::operator-(const binary &obj)const{
	binary tem=~obj + binary(1);
	return (*this+tem);
	};
binary binary::operator*(const binary &obj)const{
	binary c=*this,d=obj;
	int sign=0;
	if ((c[c.size-1]-48) ^ (d[d.size-1]-48)) {c=~c + binary(1);sign++;};
	if (c[c.size-1]=='1'){
		c=~c+ binary(1);
		d=~d+ binary(1);
		}
	while (d>>1){
		if (d[0]=='0'){
			d=d>>1;
			c=c<<1;
			}
		else{
			c=c<<1;
			c=c+(*this);
			d=d>>1;
			}
		}
	if (sign) c=~c + binary(1);
	c.realSize=	c.RealSize();
	return c;
	};
binary binary::operator/(const binary &obj)const{
	binary c=*this,d=obj,e;
	int sign=0;
	if ((c[c.size-1]-48) ^ (d[d.size-1]-48)) {c=~c + binary(1);sign++;};
	if (c[c.size-1]=='1'){
		c=~c+ binary(1);
		d=~d+ binary(1);
		}
	while (c>=d){
		c=c-d;
		e=e+binary(1);			
		}
	if (sign) e=~e + binary(1);
	e.realSize=	e.RealSize();
	return e;
	};
binary binary::operator&(const binary &obj)const{
	binary tem;
	for (int i=0;i<tem.size;i++) tem.bit[i]=(bit[i]-48) & (obj[i]-48);
	tem.realSize=tem.RealSize();
	return tem;
	};
binary binary::operator|(const binary &obj)const{
	binary tem;
	for (int i=0;i<tem.size;i++) tem.bit[i]=(bit[i]-48) | (obj[i]-48);
	tem.realSize=tem.RealSize();
	return tem;
	};
binary binary::operator^(const binary &obj)const{
	binary c;
	for (int i=0;i<size;i++) c[i]=48 + ((bit[i]-48)^(obj[i]-48));
	c.realSize=	c.RealSize();
	return c;
	};
binary binary::operator~(void){
	for (int i=0;i<size;i++) 
		if (bit[i]=='0') bit[i]='1';
		else bit[i]='0';
	realSize=RealSize();
		return *this;
	};
binary binary::operator<<(int n) const{
	binary a=*this;
	for(int i=size-1;i>=0;i--) 
		if (i-n>=0) a.bit[i]=a.bit[i-n];
		else a.bit[i]='0';
	a.realSize=a.RealSize();
	return a;
	};
binary binary::operator>>(int n) const{
	binary a=*this;
	a.realSize=realSize-n;
	for(int i=0;i<size;i++)
		if ((i+n)<size) a.bit[i]=a.bit[i+n];
		else a.bit[i]=a.bit[size-1];
	return a;
	};
char &binary::operator[](int p) const{
	return bit[p];
	};
