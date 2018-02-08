#define carroVERDE 2
#define carroAMARELO 3
#define carroVERMELHO 4

#define pedestreVERDE 11
#define pedestreVERMELHO 12
#define botao 8

void setup()
{
  pinMode(carroVERDE,OUTPUT);
  pinMode(carroAMARELO,OUTPUT);
  pinMode(carroVERMELHO,OUTPUT);
  pinMode(pedestreVERDE,OUTPUT);
  pinMode(pedestreVERMELHO,OUTPUT);
  
  pinMode(botao,INPUT_PULLUP);
  
  digitalWrite(carroVERDE,LOW);
  digitalWrite(carroAMARELO,LOW);
  digitalWrite(carroVERMELHO,LOW);
  digitalWrite(pedestreVERDE,LOW);
  digitalWrite(pedestreVERMELHO,LOW);
  
}

void loop()
{
  while(digitalRead(botao)){
  digitalWrite(carroVERDE,HIGH);
  digitalWrite(pedestreVERMELHO,HIGH);
  }
  
  delay(6000);
  
  digitalWrite(carroVERDE,LOW);
  digitalWrite(carroAMARELO,HIGH);
  
  delay(3000);
  
  digitalWrite(carroAMARELO,LOW);
  digitalWrite(carroVERMELHO,HIGH);
  
  delay(1000);
  
  digitalWrite(pedestreVERMELHO,LOW);
  digitalWrite(pedestreVERDE,HIGH);
  
  delay(7000);
  
  digitalWrite(pedestreVERDE,LOW);
  
  //pisca o led vermelho do pedestre
  for(int i = 0;i < 10;i++)
  {
    digitalWrite(pedestreVERMELHO,!(digitalRead(pedestreVERMELHO)));
    delay(500);
  }
  
  delay(1000);
  
  digitalWrite(pedestreVERMELHO,HIGH);
  digitalWrite(carroVERMELHO,LOW);
  
  

}
