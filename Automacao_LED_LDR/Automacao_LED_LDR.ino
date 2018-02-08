#define LDR A3
#define led 8

float luminosidade;
float amostra;

void setup()
{
Serial.begin(9600);

pinMode(led,OUTPUT);
digitalWrite(led,LOW);

}

void loop()
{
amostra = 0;

for(int i = 0;i<100;i++)
{
  luminosidade = analogRead(LDR);
  luminosidade = (luminosidade / 1024)*100;
  
  amostra = amostra + luminosidade;

}

amostra = amostra/100;

Serial.print("Luminosidade =  ");
Serial.print(amostra,0);
Serial.print("%\n");

if(amostra < 30)
digitalWrite(led,HIGH);
else
digitalWrite(led,LOW);

delay(250);

}
