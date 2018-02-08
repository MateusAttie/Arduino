
#define RED_RGB 9
#define GREEN_RGB 10
#define BLUE_RGB 11
#define pot A0
#define RED_botao 2
#define GREEN_botao 3
#define BLUE_botao 4

int valor_RED = 0;
int valor_GREEN = 0;
int valor_BLUE = 0;

void setup()
{
pinMode(RED_botao,INPUT_PULLUP);
pinMode(GREEN_botao,INPUT_PULLUP);
pinMode(BLUE_botao,INPUT_PULLUP);
}


void loop()
{
while(!(digitalRead(RED_botao)))
{
valor_RED = map(analogRead(pot),0,1023,0,255);
analogWrite(RED_RGB,valor_RED);
}

while(!(digitalRead(GREEN_botao)))
{
valor_GREEN = map(analogRead(pot),0,1023,0,255);
analogWrite(GREEN_RGB,valor_GREEN);
}

while(!(digitalRead(BLUE_botao)))
{
valor_BLUE = map(analogRead(pot),0,1023,0,255);;
analogWrite(BLUE_RGB,valor_BLUE);
}

}
