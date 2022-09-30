#include <LiquidCrystal_I2C.h>
#include <math.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int d=0;
float analogPin = A0;
float val = 0;
float a = 0;
float b = 0;
float c = 0;
float f=0;
float g=0;
float e = 0;
int cont = 0;
void setup() {
Serial.begin(9600);
}

void loop() {
val = analogRead(analogPin);

a = (val/205);
Serial.println(a);
b = (a/1.52)-1.51;
b = b/1.255;
if(b>1){
  b=1;
}
if(b<-1){
  b=-1;
}
c = (asin(b)/2);
c = (c*180)/M_PI;

//Serial.println(c);

if( -44.39<c && c<0 && cont==0){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("El angulo es"); // Mensaje a despegar
  lcd.setCursor(5,1);
  lcd.print(-c+e); // Mensaje a despegar
    if(c < -42){
    cont = 1;
    
    }
    /*if(-0.1<c && c<0.1){
   e=180;
   cont=1;
   }*/
   }

if( -44.39<c && c<0 && cont==1){

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("El angulo es"); // Mensaje a despegar
  lcd.setCursor(5,1);
  lcd.print(c+90+e); // Mensaje a despegar
    if(-0.1<c && c<0.1){
    cont = 2;
   }
    /*if(c < -44){
    cont = 0;
    }*/   
  }
if( 0<c && c<44.39 && cont==2){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("El angulo es"); // Mensaje a despegar
  lcd.setCursor(5,1);
  lcd.print(90+c+e); // Mensaje a despegar
    if(30<c && c<45){
      cont=3;
    }
    /*if(-0.1<c && c<0.1){
    cont = 1;
   }*/
  }
  
if( 0<c && c<44.39 && cont==3){
  f = 45-c;
  g = 135+f+e;
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("El angulo es"); // Mensaje a despegar
  lcd.setCursor(5,1);
  lcd.print(g); // Mensaje a despegar
    if(-0.1<c && c<0.1 && e==0){
    cont = 0;
    e=180;
   }
   if((g)>358.8)
   {
    e=0;
    cont=0;
   }
  }
}
