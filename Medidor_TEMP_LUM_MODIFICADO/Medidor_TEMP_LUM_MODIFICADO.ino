#include<LiquidCrystal.h>
#include<Thermistor.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Thermistor temp(0);

#define LDR A1
#define led 8
#define rgb 9

float luminosidade;
int amostra, temperatura;
int porcao = 100;

void setup()
{
  lcd.begin(16, 2);

}

void loop()
{
  temperatura = temp.getTemp();
  /*tcc:
    if(temp_alvo < 40 && temp_alimento < 0){
    digitalWrite(led, HIGH);
    }else {
      digitalWrite(led, LOW);
    }

  */
  if (temperatura < 20) {
    lcd.clear();
    lcd.print("Esquentando...");
    digitalWrite(led, HIGH);
    delay(5000);
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:");
    lcd.print(temperatura);
    lcd.print("C");
  }
  else
    digitalWrite(led, LOW);


  amostra = 0;

  for (int i = 0; i < porcao; i++) {
    luminosidade = analogRead(LDR);
    luminosidade = (luminosidade / 1024) * 100;
    amostra = amostra + luminosidade;
  }

  amostra = amostra / porcao;
  if(amostra < 40){
    analogWrite(rgb,254);
    }else
    analogWrite(rgb,0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.print(temperatura);
  lcd.print("C");

  Serial.print("Luminosidade: ");
  Serial.print(amostra);

  lcd.setCursor(0, 1);
  lcd.print("Luminosidade:");
  lcd.print(amostra);
  lcd.print("%");

 delay(1000);

}
