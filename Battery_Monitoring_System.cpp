#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

#define DIP_SW1	7

int Analog = 0;
int volt=9;
int reading = 0;
float Voltage = 0;

byte BatteryLCD1[8] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F};
byte BatteryLCD2[8] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x1F};
byte BatteryLCD3[8] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x1F};
byte BatteryLCD4[8] = {0x0E, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F};
byte BatteryLCD5[8] = {0x0E, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
byte BatteryLCD6[8] = {0x0E, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
byte BatteryLCD7[8] = {0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};

void setup()
{
  pinMode(A0, INPUT);
  pinMode(DIP_SW1, INPUT_PULLUP);
  
  pinMode(5, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("VOLTS : ");
  lcd.setCursor(13,0);
  lcd.print("V");
  
  lcd.createChar(1,BatteryLCD1);
  lcd.createChar(2,BatteryLCD2);
  lcd.createChar(3,BatteryLCD3);
  lcd.createChar(4,BatteryLCD4);
  lcd.createChar(5,BatteryLCD5);
  lcd.createChar(6,BatteryLCD6);
  lcd.createChar(7,BatteryLCD7);
  lcd.setCursor(0,1);
  lcd.write(1);
}

void loop()
{  
  reading = digitalRead(DIP_SW1);
  Analog = analogRead(A0);
  Voltage = ((Analog / 1023.0) * 5)*3.75;
  
  digitalWrite(5, HIGH);
  lcd.setCursor(8,0);
  lcd.print(Voltage);

  switch((int)Voltage)
  {
    case 0:
      	lcd.setCursor(0,1);
      	lcd.write(1);
    	break;
    
    case 1:
      	lcd.setCursor(0,1);
      	lcd.write(2);
    	break;
    
    case 2:
      	lcd.setCursor(0,1);
      	lcd.write(3);
    	break;
    
    case 3 ... 4:
      	lcd.setCursor(0,1);
      	lcd.write(4);
    	break;
    
    case 5 ... 6:
      	lcd.setCursor(0,1);
      	lcd.write(5);
    	break;
    
    case 7:
      	lcd.setCursor(0,1);
      	lcd.write(6);
    	break;
    
	case 8 ... 9:
    	lcd.setCursor(0,1);
      	lcd.write(7);
    	break;
  }
  if(volt*0.2>=Voltage){
    digitalWrite(5, LOW);//network module is connected to 5
  	lcd.print("Switching off network mode");
  	delay(5000);
  }
  
}

