/*=================================
4-Wire Touchscreen controller with touch sense
and resoultion mapping by Aftermathx25
based on code for 4-Wire Touch screen
interfacing with Arduino
from
blog.circuits4you.com
www.circuits4you.com
=================================*/

#define X1 A0
#define X2 A2
#define Y2 A3
#define Y1 A1

#define Xresolution 100
#define Yresolution 100

#define correctX 64
#define correctY 150

#define maxX 900
#define maxY 750

int oX,oY,X,Y,offX,offY, rawX, rawY, state;

void setup()
{
   Serial.begin(9600);
}




void loop()
{
  pinMode(X1, OUTPUT);
  digitalWrite(X1, LOW);
  pinMode(X2, INPUT);
  digitalWrite(X2, LOW);
  pinMode(Y1, INPUT);
  digitalWrite(Y1, LOW);
  pinMode(Y2, INPUT_PULLUP);

  state = digitalRead(Y2);

  if(state == LOW)
  {

     pinMode(Y1,INPUT);
     pinMode(Y2,INPUT);
     digitalWrite(Y2,LOW);
     pinMode(X1,OUTPUT);
     digitalWrite(X1,HIGH);
     pinMode(X2,OUTPUT);
     digitalWrite(X2,LOW);
     rawX = abs(analogRead(Y1)- correctX);

     X = map(rawX, 0, maxX, 0, Xresolution);

     pinMode(X1,INPUT);
     pinMode(X2,INPUT);
     digitalWrite(X2,LOW);
     pinMode(Y1,OUTPUT);
     digitalWrite(Y1,HIGH);
     pinMode(Y2,OUTPUT);
     digitalWrite(Y2,LOW);
     rawY = abs(analogRead(X1) - correctY);

     Y = map(rawY, 0, maxY, 0, Yresolution);

   Serial.print("X = ");
   Serial.print(X);
   Serial.print(" Y = ");
   Serial.println(Y);

    pinMode(X1, OUTPUT);
    digitalWrite(X1, LOW);
    pinMode(X2, INPUT);
    digitalWrite(X2, LOW);
    pinMode(Y1, INPUT);
    digitalWrite(Y1, LOW);
    pinMode(Y2, INPUT_PULLUP);

     while(digitalRead(Y2) == LOW)
     {
      delay(10);
     }

     delay(200);
  }

}
