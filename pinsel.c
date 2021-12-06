#include <LPC21XX.h> //reg file

void dealy();
int main(){
	PINSEL0=0X00000000;
	IO0DIR=0X00000002;
	if((IO0PIN & 0X01)==0X01){
		IO0SET |= (1<<1);
		delay();
	}
	else{
		IO0CLR|=(1<<1);
		delay();
	}
	return 0;
}
void delay(){
	for(int i=0; i<30000; i++);
}