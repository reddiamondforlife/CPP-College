#include <iostream>
#include "limits.h"
void int2bin(int x,int d){
	char buffer[33];
	int index=0;
	for (;d>0;d--){
		buffer[index++]='0'+ (x&1);
		x>>=1;
	}
	while(index >0)printf("%c", buffer[--index]);
	printf("B");
	return;
}
int main(int argc, char** argv) {


	int nummer1=INT_MAX;
	int nummer2=INT_MAX+1;
	int2bin(nummer1,nummer2);
	std::cout << "\nHere is the decimal number: \n";
	std::cout << nummer1<<"\n"<< nummer2;
	
	return 0;
}
