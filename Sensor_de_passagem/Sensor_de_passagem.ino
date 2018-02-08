#define sensor 4
#define LED 13

void setup()
{
  pinMode(sensor,INPUT);
  
}

void loop()
{
  if(digitalRead(sensor))digitalWrite(LED,HIGH);
  
  else digitalWrite(LED,LOW);
}
