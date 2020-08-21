// Open Source

#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int ledPin = 2; //Led no pino 
int ldrPin = A0; //LDR no pino
int ldrValor = 0; //Valor lido do LDR
 
void setup() {
 pinMode(ledPin,OUTPUT); //define a porta 7 como saída
 Serial.begin(9600); //Inicia a comunicação serial
 lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
 lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
}
 
void loop() {
 ///ler o valor do LDR
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("STATUS LAMPADA");
  Serial.println("LAMPADA");
 
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 100){ 
    digitalWrite(ledPin,HIGH);
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("LUZ LIGADA   ");
    }
 // senão, apaga o led
 else {
    digitalWrite(ledPin,LOW);
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("LUZ DESLIGADA     ");
    }
 
 //imprime o valor lido do LDR no monitor serial
 Serial.println(ldrValor);
 delay(100);
}
