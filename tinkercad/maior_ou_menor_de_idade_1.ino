//Maior de 18 "maior de idade"
//Menor de 18 "menor de idade"

//variaveis 
int idade = 0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("digite sua idade");
  while( !Serial.available());
  idade = Serial.parseInt();
  
  if( idade >= 18 ){//
    Serial.println("maior de idade");
    
  } else {//falso 
    
    Serial.println("Menor de idade");
      
      delay(2000);
  
  }
}