// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("--- PROGRAMA JOGO DE DADOS ---");
  Serial.println(" ");
  Serial.println(" ");
  
  //PEDIR O PALPITE DO USUARIO
  Serial.println("digite um palpite de 1 a 6");
  while(! Serial.available());
  int palpite = Serial.parseInt();
  
  //sortear o dado
  int numeroSorteado = random(1, 200);//gera um numero aleatorio entre 1 e 6
  
  
  //mostrar o resultado
  Serial.println("seu palpite: " + String(palpite));
  Serial.println("numero do dado: " + String(numeroSorteado));
  
  if(palpite == numeroSorteado)
  {
    Serial.println("parabens, voce acertou!");
  }else {
   Serial.println("que pena, tente outra vez!");
  }
  
  delay(1000);
}
  
  
