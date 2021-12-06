#include<lpc21xx.h> 
void delay(unsigned int c) 
	{unsigned int a; 
for(a=1;a<=40000;a++);
} 
	int main()
	{ 
		PINSEL0=0x00000000; 
		PINSEL1=0x00000000; 
		PINSEL2=0x00000000; 
		IO0DIR|=0xffffffff; 
		IO1DIR = ~(0x00010000); 
		while(1) 
			{ 
				unsigned long int j;
				int i,a[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
				// int i,a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90} anode type 
				int b[]={0x6F,0x7F,0x07,0x7D,0x6D,0x66,0x4F,0x5B,0x06,0x3F}; 
				if(IO1PIN & (0x00010000))
					{ 
						for(j=0;j<10;j++)
						{ 
							IO0SET=IO0SET|a[j];
	
	for(i=0;i<10;i++) 
	{
	IO0SET= IO0SET|(a[i]<<8);
	delay(20000); 
	IO0CLR= IO0CLR|(a[i]<<8);
	} IO0CLR=a[j]; } 
	} 
					else {
						for(j=0;j<10;j++) 
						{ 
							IO0SET=IO0SET|b[j];
	for(i=0;i<10;i++) 
	{
	IO0SET= IO0SET|(b[i]<<8); 
	delay(20000);
	IO0CLR= IO0CLR|(b[i]<<8);
	} 
	IO0CLR=b[j];
	}
	}
	}
	}