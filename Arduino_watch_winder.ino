#include <Stepper.h>  
#define STEPS 64  //定義步進馬達每圈的步數  
  
//steps:代表馬達轉完一圈需要多少步數。如果馬達上有標示每步的度數，  
//將360除以這個角度，就可以得到所需要的步數(例如：360/5.6=64)。(int)  

Stepper stepper(STEPS, 9, 8, 7, 6); 

int Turn_Right_Test=2000;  //Define turn Right cycle while start, 2000= 1cycle) 
int Turn_Left_Test=-2000;  //Define turn Left cycle while start, -2000= -1cycle)
long Turn_Right=50000;     //Define turn Right cycle , 2000= 1cycle), set 50000=300sec 
long Turn_Left=-50000;     //Define turn Left cycle , -2000= -1cycle),set 50000=300sec 
long Delay_Time=3600000;   //Idle 3Hour, Let system IDLE 1hour(3600000)/ 3hours (10800000)

const int LED_Test=3;          //Set LED1 on Pin3
const int LED_Running=4;       //Set LED2 on Pin4
const int LED_Finish=5;        //Set LED3 on Pin5

void setup()  
{  
stepper.setSpeed(150);          // 將馬達的速度設定成150RPM Range:90~160  
pinMode(LED_Test,OUTPUT);       // Set Status LED1
pinMode(LED_Running,OUTPUT);    // Set Status LED2
pinMode(LED_Finish,OUTPUT);     // Set Status LED3

digitalWrite(LED_Test,LOW);     // Set Status LED1 OFF
digitalWrite(LED_Running,LOW);  // Set Status LED2 OFF
digitalWrite(LED_Finish,LOW);   // Set Status LED3 OFF
}  
  
void loop()  
{  
// ************* Testing ********************
stepper.step(1000);//正轉
delay(500);
stepper.step(-1000);//反轉
delay(500);

digitalWrite(LED_Test,HIGH);
stepper.step(Turn_Right_Test);//正轉
delay(1000);  

digitalWrite(LED_Test,LOW);
stepper.step(Turn_Left_Test);//反轉  
delay(1000);  

digitalWrite(LED_Test,HIGH);
//********************************************

  int count=20; // run 20 cycles, about 1hour, 1 cycle=3min
  while(count>0)
    {   
     digitalWrite(LED_Running,HIGH);
     delay(300);     
     stepper.step(Turn_Right);//正轉  
     digitalWrite(LED_Running,LOW);
     delay(5000); 
     
     digitalWrite(LED_Running,HIGH);
     delay(300); 
     stepper.step(Turn_Left);//反轉
     digitalWrite(LED_Running,LOW); 
     delay(300);

    count=count-1;
    }  
    
    digitalWrite(LED_Finish,HIGH); // Finish status LED
    delay(Delay_Time); // Let system idle... 
    
    //Reset LEDs staus
    digitalWrite(LED_Test,LOW);     // Set Status LED1 OFF
    digitalWrite(LED_Running,LOW);  // Set Status LED2 OFF  
}
