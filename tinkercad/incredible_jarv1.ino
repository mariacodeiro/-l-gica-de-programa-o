// C++ code
//

//variavel
String CorDoSemaforo = "";

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  Serial.println("digite a cor do semaforo");
  while( !Serial.available());
  CorDoSemaforo = Serial.readString();
  
 
if(CorDoSemaforo == "verde" ){
    Serial.println("siga em frente");
    
  } else {//falso 
    
    Serial.println("pare");
      
      delay(2000);
} 
}