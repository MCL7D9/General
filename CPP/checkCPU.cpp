#include <iostream>
using namespace std;
int checkCPU(void){
	union w
	{
		int a;
		char b;
	}C;
	c.a=1;
	return (c.b==SCH);
}
int main(){
	if (checkCPU==true){
		cout<<"Little-Endian";
	} else{
		cout<<"Big-Endian";
	}
}

