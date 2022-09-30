#include <LiquidCrystal_I2C.h>
#include <math.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int d=0;
float analogPin = A0;
float foto = A1;
float fot = A2;
float fo = A3;
float ff = A4;
float val = 0;
float a = 0;
float b = 0;
float c = 0;
float f=0;
float g=0;
float e = 0;
float foto1;
float foto2;
float foto3;
float foto4;
int cont = 0;
int aux=0;
void setup() {
Serial.begin(9600);
}

void loop() {
val = analogRead(analogPin); //Se lee el voltaje de salida del circuito de acondicionamiento.
foto1 = analogRead(foto);
foto2 = analogRead(fot);
foto3 = analogRead(fo);
foto4 = analogRead(ff);
foto1 = (foto1/205);
foto2 = (foto2/205);
foto3 = (foto3/205);
foto4 = (foto4/205);
a = (val/205); // El valor leído por el Arduino se pasa a v.
b = (a/1.52)-1.51; // Se quita de la ecuación la ganancia y el DC puesto en el acondicionamiento. 
b = b/1.29; // Se halló la constante K práctica para quitarla de la ecuación. Es ligeramente distinta a la teórica.
if(b>1){     
  b=1;
}
if(b<-1){
  b=-1;
}         // Estos 2 if acotan el resultado de b para que al arcoseno no le entre un resultado mayor a ± 1. 
c = (asin(b)/2); // Se hace el último despeje de la ecuación para hallar el ángulo.
c = (c*180)/M_PI; // Se pasa a grados el ángulo.

aux=analogRead(foto);
 if(aux < analogRead(foto))
 {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("El angulo es"); // Mensaje a despegar
    lcd.setCursor(5,1);
  lcd.print(-c); // Mensaje a despegar
  
    if (analogRead(foto)>4 && analogRead(foto)< 5 )
  {
    Serial.println("hola");
    }
 }

/*if(foto1>0 && foto1<2.5 && foto2>2.4 && foto2<2.6 && foto3>2.4 && foto3<2.6 && foto4>2.4 && foto4<2.6){ // Se observa si el ángulo está en el segundo cuadrante con el contador (45°-90°).
  Serial.println(c+90+e);
  }
if(foto1>2.4 && foto1<2.6 && foto2>2.5 && foto2<5 && foto3>2.4 && foto3<2.6 && foto4>2.4 && foto4<2.6){ // Se observa si el ángulo está en el tercer cuadrante con el contador (90°-135°).
   Serial.println(90+c+e);
  }
  
if(foto1>2.4 && foto1<2.6 && foto2>0 && foto2<2.5 && foto3>2.4 && foto3<2.6 && foto4>2.4 && foto4<2.6 ){ // Se observa si el ángulo está en el tercer cuadrante con el contador (90°-135°).
  f = 45-c;
  g = 135+f+e;
  Serial.println(g);
}

if(foto3>2.5 && foto3<5 && foto2>2.4 && foto2<2.6 && foto1>2.4 && foto1<2.6 && foto4>2.4 && foto4<2.6 ){ // Se observa si el ángulo está en el primer cuadrante con el contador (0°-45°).
   e = 180;
   Serial.println(-c+e);  
   }

if(foto3>0 && foto3<2.5 && foto2>2.4 && foto2<2.6 && foto1>2.4 && foto1<2.6 && foto4>2.4 && foto4<2.6){ // Se observa si el ángulo está en el segundo cuadrante con el contador (45°-90°).
  Serial.println(c+90+e);
  }
  
if(foto4>2.4 && foto4<2.6 && foto2>2.5 && foto2<5 && foto3>2.4 && foto3<2.6 && foto1>2.4 && foto1<2.6){ // Se observa si el ángulo está en el tercer cuadrante con el contador (90°-135°).
   Serial.println(90+c+e);
  }
  
if(foto4>2.4 && foto4<2.6 && foto2>0 && foto2<2.5 && foto3>2.4 && foto3<2.6 && foto1>2.4 && foto1<2.6 ){ // Se observa si el ángulo está en el tercer cuadrante con el contador (90°-135°).
  f = 45-c;
  g = 135+f+e;
  Serial.println(g);
}*/
}
