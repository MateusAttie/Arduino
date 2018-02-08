#include <Thermistor.h>


#define TEMP_MAX = 42
#define TEMP_MIN = 24

#define sirene 3

Thermistor temp(0);

void setup()
{
Serial.begin(9600);
Serial.println("Alarme de Temperatura");
}

void loop()
{
int temperatura = temp.getTemp();
delay(2000);
if(temperatura > TEMP_MIN && temperatura < TEMP_MAX)
{
noTone(sirene);
}
else
{
tone(sirene,440,1000);
Serial.println("PERIGO!!!TEMPERATURA FORA DO ESPERADO");
Serial.println("Temperatura deve estar entre");
Serial.println(TEMP_MIN);
Serial.println("e");
Serial.println(TEMP_MAX);
}
Serial.println("Temperatura: ");
Serial.println(temperatura);
Serial.println("*C\n");
}
