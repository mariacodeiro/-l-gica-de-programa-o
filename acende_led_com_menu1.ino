// C++ code
//
int ledVerde = 13;
int ledVermelho = 8;
int ledAmarelo =  2;
int escolhaDoLed;

void setup()
{ Serial.begin(9600);

 pinMode(ledVerde, OUTPUT);
 pinMode(ledVermelho, OUTPUT);
 pinMode(ledAmarelo, OUTPUT);


 do{
   Serial.println("digite uma das operacoes");
   Serial.println(" 1 Ligar Led Verde");
   Serial.println(" 2 Desligar Led Verde");
   Serial.println(" 3 Ligar Led Amarelo");
   Serial.println(" 4 Ligar Led Vermelho ");
   Serial.println(" 5 Desligar Led Vermelho");
   Serial.println(" 6 Ligar Todos os Leds");
   Serial.println(" 7 Desligar Todos os Leds");
   Serial.println(" 8 Sair");
   while(!Serial.available()){}
   escolhaDoLed = Serial.parseInt();


   switch(escolhaDoLed){
     case 1:
     digitalWrite(ledVerde, HIGH);
     break;

     case 2:
     digitalWrite(ledVerde, LOW);
     break;

     case 3:
     digitalWrite(ledAmarelo, HIGH);
     break;

     case 4:
     digitalWrite(ledVermelho, HIGH);
     break;


     case 5:
     digitalWrite(ledVermelho, LOW);
     break;


     case 6:
     digitalWrite(ledVerde, HIGH);
     digitalWrite(ledVermelho, HIGH);
     digitalWrite(ledAmarelo, HIGH);
     break;


     case 7:
     digitalWrite(ledVerde, LOW);
     digitalWrite(ledVermelho, LOW);
     digitalWrite(ledAmarelo, LOW);
     break;


     case 8:
     Serial.println("Ate breve!");
       break;

     default:
     Serial.println("Erro, tente novamente/=.");}
   } while( escolhaDoLed != 8);
  }

 void loop()
 {
   //sem instrucoes
 }