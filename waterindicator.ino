#include <LiquidCrystal.h> 
#define trigPin 6 
#define echoPin 7 
#define buzzPin 8 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
float const c = 124.62; 
float v; 
float const q = 24; 

void setup() 
{ 
	lcd.begin(16,2); 
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT); 
	pinMode(buzzPin, OUTPUT); 
} 
 
void loop() 
{ 
	float duration, distance; 
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2); 
  
	digitalWrite(trigPin, HIGH); 
	delayMicroseconds(10); 
	digitalWrite(trigPin, LOW); 
   
duration = pulseIn(echoPin, HIGH); 
distance = (duration / 2) * 0.0344; 
   
if (distance >= 9 && distance <= 12)
{ 
	lcd.setCursor(0, 0); 
	lcd.print("Tank Full"); 
	v=c*(q-distance); 
	lcd.setCursor(0, 1); 
	lcd.println("Vol:"); 
	lcd.print(v); 
	lcd.println("cc"); 
	delay(500); 
	digitalWrite(buzzPin,HIGH); 
}

else if (distance >= 22 && distance <= 24)
{ 
	lcd.setCursor(0, 0); 
	lcd.print("Tank Empty"); 
	v=c*(q-distance); 
	lcd.setCursor(0, 1); 
	lcd.println("Vol:"); 
	lcd.print(v); 
	lcd.println("cc"); 
	delay(500); 
	digitalWrite(buzzPin,HIGH); 
} 

else if (distance > 12 && distance < 24)
{ 
	lcd.setCursor(0,0); 
	lcd.print("Water Volume is :"); 
	v=c*(q-distance); 
	lcd.setCursor(0,1); 
	lcd.print(v); 
	lcd.println("cc"); 
	delay(500); 
	digitalWrite(buzzPin,LOW); 
} 

delay(500); 
lcd.clear(); 

} 