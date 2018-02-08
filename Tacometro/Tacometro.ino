#define sensor 2 

long rpmconta = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rpmconta = 0;
  attachInterrupt(0,pegarpm,FALLING);
  delay(1000);
  detachInterrupt(0);
  
  rpmconta = rpmconta * 60;
  
  Serial.println(rpmconta);
  Serial.println("RPM");
  
}

void pegarpm()
{
  rpmconta++;
}

