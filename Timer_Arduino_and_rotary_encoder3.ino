

//Designed by Stoica Tudor 08.2019.  Rew 09.2019
//"Programable Timer" with manny embdeded programs.
// Display program and remain time in minutes.Max 999 minutes.
// Rotary encoder.

// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
// LiquidCrystal (RS, E, D4,D5,D6,D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int n=0;// time in seconds
int r1=0;//rest1
int r2=0;
byte np; //nr. of program
byte zm=0;//minutesX10
byte m=0;//minutes
byte zs=0;//secX10
byte s=0;//sec.
byte md=3;// modulo and number total of programs(in this case,3)
int counter;



void setup() {
   lcd.begin(16, 2);
   pinMode(A3, INPUT_PULLUP);//button "Memory" to ground
   pinMode(A2, INPUT_PULLUP);//SW Left to ground
   pinMode(A1, INPUT_PULLUP);//Rot enc B to ground
   pinMode(A0, INPUT_PULLUP);//Rot enc A to ground
   pinMode(9, OUTPUT);// OUT relay
   pinMode(10, OUTPUT);// OUT buzzer
 
     // welcome message
  lcd.clear();
  lcd.display();
 lcd.print("    HELLO !");
  digitalWrite(10,HIGH);//beep to start
   delay(1000);
   digitalWrite(10,LOW);
    }

void loop() {
  counter=0;
  lcd.clear();//  preset progrm routine
  lcd.print("  Push Start P1");
  lcd.setCursor(0,1); 
   lcd.print("Rotary Select Pr");
  do{ //choose progr
  np=roTen(); 
  switch(np) {
    case 0:
   lcd.clear();
   lcd.print("P1 Dough:45min");
    break;
    case 1:
   lcd.clear();
   lcd.print("P2 Dough:55min");
    break;
   case 2:
   lcd.clear();
   lcd.print("P3 Dough:65min");
    break;
  }
   }while(digitalRead(A2)==HIGH);//"Left" button
  delay(10);    //out of set routine and Start timer


  //executing time program; in case is described each program
   switch(np) {
    case 0:
    n=2700;// 45minX60=2700s
   fTime(2,30);
    fTime(3,30);
     fTime(5,60);
    fTime(10,60);
    fTime(60,5);
  break;
   case 1:
   n=3300;
    fTime(2,30);
    fTime(3,30);
     fTime(5,60);
    fTime(10,60);
    fTime(60,10);
    break;
     case 2:
     n=3900;
      fTime(2,30);
    fTime(3,30);
     fTime(5,60);
    fTime(10,60);
    fTime(60,15);
  break;
 }  
   
   digitalWrite(10,HIGH);//beep to end
   delay(2000);
   digitalWrite(10,LOW);
}
    
 byte roTen(){ // Rotary encoder routine 
 
 while(digitalRead(A2) &digitalRead(A1) & digitalRead(A0)==1);
 
 if(digitalRead(A2)==0){
  return counter;
   }
   switch(digitalRead(A0)) {
    case HIGH:
    while(digitalRead(A0)==0);
    while(digitalRead(A1)==0);
    counter ++;
     counter=counter%md;
    break;
    case LOW:
   while(digitalRead(A1)==0);
   while(digitalRead(A0)==0);
   counter --;
   if(counter==-1){//left begin with md-1
    counter=md-1;
    } 
     counter=abs(counter)%md; 
  break;
 }
   return counter;
   }    

                                                               
  void fTime(int ns,byte nc){// time function with parameters  ns= nr. seconds
                              //nc number of cycles
    for(int j=0 ; j<nc ; j++){
     digitalWrite(9,HIGH);
     for(int i=0 ;i< ns ; i++){
    
       while(millis() % 1000 != 0);// Time Base, 1s.
      n=n-1;
   zm=n/600;
   r1=n%600;
   m=r1/60;
   r2=r1%60;
   zs=r2/10;
   s=r2%10;
   lcdpr();
     }
    digitalWrite(9,LOW); 
    for(int k=0 ;k< ns ; k ++){
     
       while(millis() % 1000 != 0);// Time Base, 1s.
           n=n-1;
   zm=n/600;
   r1=n%600;
   m=r1/60;
   r2=r1%60;
   zs=r2/10;
   s=r2%10;
   lcdpr();
     } 
  }
  }
  
  void lcdpr(){ //lcd print routine
  lcd.setCursor(1,1); 
  lcd.print("Remain ");
  lcd.print(zm);
  lcd.print(m);
  lcd.print("m");
  lcd.print(zs);
  lcd.print(s);
  lcd.print("s");
   }
   
   
   
