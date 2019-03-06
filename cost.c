#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
 // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
Keypad Keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

#include <Servo.h>
Servo servo[4];
int i;
int time[4]= {0,0,0,0};
int cost[4]= {0,0,0,0};
int pos[4];

// sensor ir 
const int place[]={13,12,11,10};
byte val[4];

int millis;





void setup() { 
	for(int r=0;r<5;r++)
     {pinMode(place[r], INPUT);}
 // imp tip : i do not know how to get pins for servo so this is fake pins and need edit before burn ...
  servo[0].attach(5); 
  servo[1].attach(6); 
  servo[2].attach(7); 
  servo[3].attach(8);   

  Serial.begin(9600);
  lcd.begin(16,2); 
  lcd.print("Calculate Budget Of Parking ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
}


void loop() { 
 
 for (int c=0; c<4; c++) {
 	val[c]=digitalRead(place[c]);
 }

for (int x=0; x<4; x++) { 
	if(val[x]==LOW){
		closeServo(x);
		 millis = millis() ;
		time[x] = millis /30000 //time by min and min equal 30 s to be more faster 
		cost[x] = time[x] / 2 //cost of min by egp as hour equal 30 egp

	       }
}
//first row print

lcd.setCursor(0, 0);
lcd.print("1-"); 
lcd.print(time[0]); //prints time since program started
   delay(1000);
lcd.print("min-"); 
lcd.print(cost[0]);
lcd.print("EGP//")
lcd.print("2-"); 
lcd.print(time[1]); //prints time since program started
   delay(1000);
lcd.print("min-"); 
lcd.print(cost[1]);
lcd.print("EGP")

//second row print

lcd.setCursor(0, 1);
lcd.print("3-"); 
lcd.print(time[2]); //prints time since program started
   delay(1000);
lcd.print("min-"); 
lcd.print(cost[2]);
lcd.print("EGP//")
lcd.print("4-"); 
lcd.print(time[3]); //prints time since program started
   delay(1000);
lcd.print("min-"); 
lcd.print(cost[3]);
lcd.print("EGP")

  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }
// delay at the end of the full loop:

delay(1000);




// for keypad click to open one parking place .. and print number in serial com

  char key = keypad.getKey();

if (Key == 1){
  openServo(0);
  }
if (Key == 2){
  openServo(1);
  }
if (Key == 3){
  openServo(2);
  }
if (Key == 4){
  openServo(3);
  }




}

void openServo(i)
{
    Serial.println(Key);
	for (pos[i] = 0; pos[i]  <= 40; pos[i]  += 1) { servo[i].write(pos[i]);delay(30);} 
    delay(2000);   
    time[x] = 0; 
	cost[x] = 0;    
}

void closeServo(x)
{
	for (pos[x] = 40; pos[x] >= 0; pos[x] -= 1) { myservo[x].write(pos[x]);delay(30);}
    delay(1000);       
}



