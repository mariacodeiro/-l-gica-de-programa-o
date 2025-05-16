int EscolhaDaOperacao;
float resultado; //ira guardar o resultado do calculo da respectiva operacao

void somar(float numero1Param, float numero2Param = 0){
  resultado = numero1Param + numero2Param;
  Serial.println("o resultado da soma foi:" + String(resultado)); //concatenano
}

void dividir(float numero1Param, float numero2Param = 0){
  resultado = numero1Param / numero2Param;
  Serial.println("o resultado da divisao foi:" + String(resultado)); //concatenano
}

void subtrair(float numero1Param, float numero2Param = 0){
  resultado = numero1Param - numero2Param;
  Serial.println("o resultado da subtracao foi:" + String(resultado)); //concatenano
}

void multiplicar(float numero1Param, float numero2Param = 0){
  resultado = numero1Param * numero2Param;
  Serial.println("o resultado da multiplicacao foi:" + String(resultado)); //concatenano
}


void setup()
{
 Serial.begin(9600);
  
  int contador = 0; //variavel inicializador do 'do while'
  float numero1; //variavel local
  float numero2;
  
 
  do{
    Serial.println("bem vindo(a) a calculadora inteligente\n");
    Serial.println("Escolha uma das opcoes:");
    Serial.println("1 - somar");
    Serial.println("2 - dividir");
    Serial.println("3 - subtrair");
    Serial.println("4 - multiplicar");
    while(!Serial.available()){}
    EscolhaDaOperacao = Serial.parseInt();
    
    
    
    
   Serial.println("para conseguirmos fazer a operacao matematica, precisamos que voce digite 2 numeros");
   Serial.println("digite o 1o numero:");
   while(!Serial.available()){}
   numero1 = Serial.parseFloat();
    
   Serial.println("agora, digite o 2o numero:");
   while(!Serial.available()){}
   numero2 = Serial.parseFloat();
    
    //if(escolhaDaOperacao = 1else if){}
    //else if (escolhaDaOperacao == 2){}
    
    switch(EscolhaDaOperacao){
      case 1://somar
      somar(numero1, numero2);
       //float retornoFuncaoSomar;
        //retornoFuncaoSomar = somar(numero1, numero2);
       break;
      
      case 2:// divisao
      dividir(numero1, numero2);
      
      
       case 3:
      subtrair(numero1, numero2);
       //resultado = numero1 - numero2;
      // Serial.println("o resultado da subtracao foi:" + String(resultado)); //concatenano
        break;
      
      case 4:
      multiplicar(numero1, numero2);
      //resultado = numero1 * numero2;
      //Serial.println("o resultado da subtracao foi:" + String(resultado)); //concatenano
      break;
      
      default:
       Serial.println("opcao invalida! Escolha uma opcao do 1 ao 4. ;");
      
  }     
      Serial.println("voce deseja voltar ao menu? Digite sim ou nao.");
      while(!Serial.available()){}
      //contador = Serial.parseFloat();
    
      if(Serial.readString()== "sim"){
      contador = 1;
        
     }
    else{
     contador = 1;
      
      Serial.println("ate breve.");
      Serial.println("caso queira voltar ao menu, reinicie o programa ;)");
    }
      
     
 }   
 while(contador != 0);
   
}

void loop()
{
 //sem instrucoes 
}