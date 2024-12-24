#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int unosUgla1;
int unosUgla2;
int unosUgla3;
int unosUgla4;
int trugao1=0;
int trugao2=0;
int trugao3=0;
int trugao4=0;

int n = 0;

bool start = true;

int putanja[10][4];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
    Serial.println("Pocetak");

  servo1.attach(9); //ruka
    servo2.attach(10); //ispruzanje
      servo3.attach(5);  //gore dole
        servo4.attach(6);  //okretanje
}

void loop() {
  // put your main code here, to run repeatedly:
servo1.write(0); //
  servo2.write(0);
    servo3.write(0);
      servo4.write(0);
delay(2000);

while(start){
  if(Serial.available()>0){
    char unos = Serial.read(); //koristiti coolterm
    switch(unos){
      case 'a': // a i d za kretanje servo motora 4

        if(unosUgla4<180){
          unosUgla4 = unosUgla4+1;
          servo4.write(unosUgla4);
          Serial.println(unosUgla4);
        }
        else{
          Serial.println("Max limit");
        }

        break;

      case 'd':

        if(unosUgla4>0){
          unosUgla4 = unosUgla4-1;
          servo4.write(unosUgla4);
          Serial.println(unosUgla4);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;


      case 'w': // w i s za kretanje servo motora 3

        if(unosUgla3>0){
          unosUgla3 = unosUgla3-1;
          servo3.write(unosUgla3);
          Serial.println(unosUgla3);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;

      case 's':

        if(unosUgla3<180){
          unosUgla3 = unosUgla3+1;
          servo3.write(unosUgla3);
          Serial.println(unosUgla3);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;

      case 'k': // k i j za kretanje servo motora 2

        if(unosUgla2<180){
          unosUgla2 = unosUgla2+1;
          servo2.write(unosUgla2);
          Serial.println(unosUgla2);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;

      case 'j':

        if(unosUgla2>0){
          unosUgla2 = unosUgla2-1;
          servo2.write(unosUgla2);
          Serial.println(unosUgla2);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;
      
      case 'o': // o i p za kretanje servo motora 1

        if(unosUgla1<180){
          unosUgla1 = unosUgla1+1;
          servo1.write(unosUgla1);
          Serial.println(unosUgla1);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;

      case 'p':

        if(unosUgla1>0){
          unosUgla1 = unosUgla1-1;
          servo1.write(unosUgla1);
          Serial.println(unosUgla1);
        }
        else{
          Serial.println("minimum dostignut");
        }
        
        break;
      
      case '0': //cuvanje trenutne pozicije
        if(n<10){
          int uglovi[4]={unosUgla1,unosUgla2,unosUgla3,unosUgla4};
          for(int j=0;j<4;j++){
            putanja[n][j]=uglovi[j];
          }
          
          Serial.println("------");
          Serial.println(n);
          Serial.println("------");
          Serial.println(putanja[n][0]);
          Serial.println(putanja[n][1]);
          Serial.println(putanja[n][2]);
          Serial.println(putanja[n][3]);
          Serial.println("-----");
          n++;
        }
        else{
          Serial.println("Prekoracenje");
        }
          break;
      case 'n': // kretanje po cuvanim pozicijama

        for (int i = 0; i < n; i++) {
          for (int j = 0; j < 4; j++) {
            switch (j) {
              case 0:
                if(trugao1 < putanja[i][j]){
                  while(trugao1!=putanja[i][j]){
                    servo1.write(trugao1);
                    trugao1++;
                    Serial.println(trugao1);
                    delay(40);
                  }
                }else{
                  while(trugao1!=putanja[i][j]){
                    servo1.write(trugao1);
                    trugao1--;
                    Serial.println("ddd");
                    delay(40);
                  }
                }
                break;

              case 1:
                 if(trugao2 < putanja[i][j]){
                  while(trugao2!=putanja[i][j]){
                    servo2.write(trugao2);
                    trugao2++;
                    delay(40);
                  }
                }else{
                  while(trugao2!=putanja[i][j]){
                    servo2.write(trugao2);
                    trugao2--;
                    delay(50);
                  }
                }
                break;

              case 2:

               if(trugao3 < putanja[i][j]){
                  while(trugao3!=putanja[i][j]){
                    servo3.write(trugao3);
                    trugao3++;
                    delay(50);
                  }
                }else{
                  while(trugao3!=putanja[i][j]){
                    servo3.write(trugao3);
                    trugao3--;
                    delay(50);
                  }
                }
                break;

              case 3:
               if(trugao4 < putanja[i][j]){
                  while(trugao4!=putanja[i][j]){
                    servo4.write(trugao4);
                    trugao4++;
                    delay(50);
                  }
                }else{
                  while(trugao4!=putanja[i][j]){
                    servo4.write(trugao4);
                    trugao4--;
                    delay(50);
                  }
                }
                break;
            }
          Serial.println("done");
          }
        }
        break;

      case 'r': //reset, postavljane na pocetnu poziciju
        unosUgla1=0;
        unosUgla2=0;
        unosUgla3=0;
        unosUgla4=0;
        servo1.write(unosUgla1);
        servo2.write(unosUgla2);
        servo3.write(unosUgla3);
        servo4.write(unosUgla4);
        break;
}
}
}

delay(2000);

}