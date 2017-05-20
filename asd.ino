#include <Thread.h>
#include <ThreadController.h>

int ledVerde1 =  10; //atribui o pino 10 a variável ledPin 
int ledVerde2 =  7; //atribui o pino 13 a variável ledPin 
int ledAm1 =  9; //atribui o pino 13 a variável ledPin 
int ledAm2 =  6; //atribui o pino 13 a variável ledPin 
int ledVerm1 =  8; //atribui o pino 13 a variável ledPin 
int ledVerm2 =  5; //atribui o pino 13 a variável ledPin 
int dado; //variável que receberá os dados da porta serial
Thread threadControllerSemaforo = Thread();
ThreadController controll = ThreadController();

  void SemaforoController(){
   if(Serial.available() > 0){ //verifica se existe comunicação com a porta serial
      dado = Serial.read();//lê os dados da porta serial
      switch(dado){
        case 1:
           digitalWrite(ledVerde1,HIGH); 
           digitalWrite(ledVerm2,HIGH); 
           digitalWrite(ledVerde2,LOW); 
           digitalWrite(ledAm1,LOW); 
           digitalWrite(ledAm2,LOW); 
           digitalWrite(ledVerm1,LOW); 
        break;
        case 2:
           digitalWrite(ledVerde1,LOW);  
           digitalWrite(ledAm1,HIGH); 
           digitalWrite(ledVerm1,LOW); 
         break;
         case 3:
           digitalWrite(ledVerde2,LOW);  
           digitalWrite(ledAm2,HIGH); 
           digitalWrite(ledVerm2,LOW); 
          break;
         case 4:
           digitalWrite(ledVerde1,LOW); 
           digitalWrite(ledVerm2,HIGH);  
           digitalWrite(ledAm1,LOW); 
           digitalWrite(ledAm2,LOW); 
           digitalWrite(ledVerde2,LOW);
           digitalWrite(ledVerm1,HIGH);
         break;
         case 5: 
           digitalWrite(ledVerde1,LOW); 
           digitalWrite(ledVerm2,LOW);  
           digitalWrite(ledAm1,LOW); 
           digitalWrite(ledAm2,LOW); 
           digitalWrite(ledVerde2,HIGH);
           digitalWrite(ledVerm1,HIGH); 
         break;
    }
  }
 }
void setup(){
   Serial.begin(9600);//frequência da porta serial
   pinMode(ledVerde1,OUTPUT); //define o pino o ledPin como saída
   pinMode(ledVerde2,OUTPUT); //define o pino o ledPin como saída
   pinMode(ledAm1,OUTPUT); //define o pino o ledPin como saída
   pinMode(ledAm2,OUTPUT); //define o pino o ledPin como saída
   pinMode(ledVerm1,OUTPUT); //define o pino o ledPin como saída
   pinMode(ledVerm2,OUTPUT); //define o pino o ledPin como saída
   threadControllerSemaforo.onRun(SemaforoController);
   controll.add(&threadControllerSemaforo);
}
 
void loop(){
 controll.run();
}
