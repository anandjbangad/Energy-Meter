#include<reg51.h>
#include<intrins.h>
           #define lcdport P2
             
             sbit rs=P3^5;
             sbit rw=P3^6;
             sbit en=P3^7;
             sbit led=P1^7;
             sbit pulse=P3^2;
             int k,p;
            unsigned int count=0;
						unsigned int mod = 0;
            unsigned int digit[5];
						unsigned int counter=0;
            
						unsigned int price1 = 0;
						unsigned int price2 = 0;
						unsigned int rupee[5];
						void price(unsigned int);
            void lcdcmd(char);
            void lcdint();
            void lcddata(char);
            void lcdstring(char *);
            void delay(unsigned int);
            unsigned char str1[]="WatHr 000";
            unsigned char str2[]="Price";
            void convert(unsigned int);
            void ldelay(unsigned int);
            
            void main()
            {
        lcdint();
        led=0;
        pulse=1;
        lcdstring(str1);
        delay(1000);
        lcdcmd(0xC0);
        lcdstring(str2);
        delay(1000);
				IE = 0x81;
			
        while(1);
						}
						void inter(void) interrupt 0
						{
	
        lcdcmd(0x87);
        led=1;
        ldelay(10);
        count=count+1;
				
				mod = count%11;
					if(mod ==0)
					{
						   
						   counter = counter + 1;
							 convert(counter);
						   price(counter);
					}

					
         }					

						void price(unsigned int value)
			{
				lcdcmd(0xC6);
				if(value % 25 ==0)
				{
					price1 = price1 + 1;
					price2=price1;
					for(k=0;k<=2;k++)
   {
        
		   rupee[k]=price2%10;
        price2=price2/10;
        }  
        for(p=2;p>=0;p--)
        {
       lcddata(rupee[p]+48);
        
        ldelay(1);
        }
					
							
			}
		}
		
        
          void convert(unsigned int value)
           {


      led=0;      
  for(k=0;k<=2;k++)
  {
        digit[k]=value%10;
        value=value/10;
        }  
        for(p=2;p>=0;p--)
        {
       lcddata(digit[p]+48);
        
        ldelay(1);
        }
       
        ldelay(10);
        }
           
            
             void delay(unsigned int x)
           {
        unsigned int i;
        for(i=0;i<x;i++);
      }
           
           void lcdint()
          {
         lcdcmd(0x38);
        delay(500);
         lcdcmd(0x01);
         delay(500);
         lcdcmd(0x0c);
         delay(500);
         lcdcmd(0x80);
         delay(500);
   lcdcmd(0x0e);
         delay(500);
    }
 
         void lcdcmd(char value)
          {
         lcdport = value;
         rw=0;
         rs=0;
         en=1;
         delay(500);
         en=0;
       }
            
            
           void lcdstring(char *p)
           {
         while(*p!='\0')
          {
            lcddata(*p);
            delay(2000);
            p++;
          }
      }
           
           
           void lcddata(char value)
           {
         lcdport=value;
         rs=1;
         rw=0;
         en=1; 
         delay(500);
         en=0;
       }
          void ldelay(unsigned int x)
          {
               unsigned int i,j;
           for (i=0;i<=x;i++)
           for (j=0;j<=1275;j++);
       }