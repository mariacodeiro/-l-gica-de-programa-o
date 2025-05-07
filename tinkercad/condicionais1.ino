// C++ code
//variaveis 
int idade = 15;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Idade: " + String(idade) );
  
  if( idade >= 16 ){//se retornar verdadeiro - losango sim
    Serial.println("voto obrigatorio");
    
  } else {//falso - Iosangolo nao
    
    Serial.println("sem idade para votar");
      
      delay(2000);
  }
  } 
    
    
