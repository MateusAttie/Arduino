#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int i;

byte heart[8]={
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};

byte M[8]={
B10001,
B11011,
B10101,
B10001,
B10001,
B10001,
B10001,
};

byte G[8]={
B11111,
B10001,
B10000,
B10111,
B10001,
B10001,
B11111,
};

void setup()
{
lcd.createChar(0,M);
lcd.createChar(1,heart);
lcd.createChar(2,G);

lcd.begin(16,2);

}

void loop()
{
lcd.setCursor(16,0);
lcd.print("Ola Mateus!");
lcd.setCursor(16,1);
lcd.print("O que deseja ?");
delay(1000);

for(i=0;i<16;i++){
lcd.scrollDisplayLeft();
delay(20);
}

delay(1000);

delay(400);
lcd.noDisplay();
delay(400);
lcd.display();
delay(400);
lcd.noDisplay();
delay(400);
lcd.display();
delay(400);
lcd.display();

for(i = 0;i<16;i++){
lcd.scrollDisplayLeft();
delay(20);
}

lcd.clear();

lcd.setCursor(16,0);

lcd.write(byte(0));
lcd.write(byte(1));
lcd.write(byte(2));
delay(1000);

for(i = 0;i<10;i++){
lcd.scrollDisplayLeft();
delay(20);
}
delay(1000);

delay(400);
lcd.noDisplay();
delay(400);
lcd.display();
delay(400);
lcd.noDisplay();
delay(400);
lcd.display();
delay(400);
lcd.display();

for(i = 0;i<10;i++){
lcd.scrollDisplayRight();
delay(20);
}
delay(1000);

lcd.clear();

}
