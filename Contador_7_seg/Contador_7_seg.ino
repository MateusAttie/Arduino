#define CONTAR 8
#define MODO 9

byte tabela_7_seg[16]={
B01111110,
B00001100,
B10110110,
B10011110,
B11001100,
B11011010,
B11111010,
B00001110,
B11111110,
B11001110,
B11101110,
B11111000,
B01110010,
B10111100,
B11110010,
B11100010
};
int contagem = 9,inc_dec = 1;

void setup()
{
DDRD = B11111110;
pinMode(CONTAR,INPUT);
pinMode(MODO,INPUT);
}

void loop()
{
if(digitalRead(CONTAR)==LOW){
  contagem += inc_dec;
  if(contagem < 0)
  {
  contagem = 15;
  }
  if(contagem > 15)
  {
  contagem = 0;
  }
while (digitalRead(CONTAR)==LOW){

}

}
if(digitalRead(MODO)==LOW)
{
inc_dec = inc_dec*(-1);

while(digitalRead(MODO)==LOW){

}

}

PORTD = tabela_7_seg[contagem];
delay(100);

}
