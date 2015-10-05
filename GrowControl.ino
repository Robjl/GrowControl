#include <LiquidCrystal.h> // include LCD library
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Set LCD pins

int menuPos = 0; // Value determines what is displayed and adjusted
int menuPosLast = -1; // Value is compared to menuPos in order to prevent constant LCD clear and print

int EC = 0; // EC value - variable will be used to set EC range 
float PH = 0.0; // PH value - variable will be used to set PH range
 
void setup() {
lcd.begin(16, 2); // Initialize LCD
delay(20); // settle time
lcd.clear(); // clear anything previously on LCD
lcd.print("hello world!"); // lcd is alive and working  
delay(2000); // keep displaying "hello world"
}

void loop() {
const int Select = 721; // analog read value of select button
const int Left = 479; // analog read value of left button
const int Right = 0; // analog read value of right button
const int Up = 131; // analog read value of up button
const int Down = 307; //analog read value of down button
int Buttons = analogRead(0); // used to compare with button value
int moist = analogRead(8);

if (Buttons == Right){        // Increments up menuPos to change display
  if (menuPos >= 5){          // Takes menuPos back to 0 after 5
    menuPos = 0;              //
  }
    else{                     
    menuPosLast = menuPos;    // Sets menuPosLast to menuPos
    menuPos++ +1;             // Increments up menuPos
    }
    delay(170);               // delay to stop over pushing of button 
  }
if (Buttons == Left){         // Increments down menuPos to change display  
if (menuPos <= 0){            // Takes menuPos up to 5 if 0
  menuPos = 5;                // 
}
  else {
  menuPosLast = menuPos;      // Sets menuPosLast to menuPos
  menuPos-- -1;               // Increments down menuPos
  }
  delay(170);                 // delay to stop over pushing of button 
}
if (menuPos == 0) {           // If menuPos == 0
  if (menuPos != menuPosLast) {       // Compares menuPos and MenuPosLast   
  lcd.clear();                        //
  lcd.print("Set EC Value");          // 
  lcd.setCursor(6,1);                 // Set cursor to second line
  lcd.print(EC);                    // Prints the current set value of EC
  menuPosLast = menuPos;              // Sets menuPosLast to menuPos to prevent constant lcd clear / print
  }  
  if (Buttons == Up){                 // Increase desired EC value and display its value
    EC++ +1;                           
    delay(170);                       
    lcd.clear();
    lcd.print("Set EC Value"); 
    lcd.setCursor(6,1);
    lcd.print(EC);                    //
    }
    if (Buttons == Down){             // Decrease desired EC value and display its value
    EC-- -1;
    delay(170);
    lcd.clear();
    lcd.print("Set EC Value");
    lcd.setCursor(6,1);
    lcd.print(EC);                    //
    }
}
if (menuPos == 1) {                  
  if (menuPos != menuPosLast){
  lcd.clear();
  lcd.print("Set PH Value");
  lcd.setCursor(6,1);
  lcd.print(PH);
  menuPosLast = menuPos;
  }
  if (Buttons == Up){
   if (PH >= 14){
      PH = 1;
    }
    PH = PH + 0.1;
    delay(150); 
    lcd.clear();
    lcd.print("Set PH Value");
    lcd.setCursor(6,1);
    lcd.print(PH);
    }
    if (Buttons == Down){
      if (PH <=1){
        PH = 14;
      }
    PH = PH - 0.1;
    delay(150);
    lcd.clear();
    lcd.print("Set PH Value");
    lcd.setCursor(6,1);
    lcd.print(PH);
    }         
}
if (menuPos == 2) {
  if (menuPos != menuPosLast){
  lcd.clear();
  lcd.print("Fill Mixing Res");
  lcd.setCursor(0,1);
  lcd.print("Press Select = Yes");
  menuPosLast = menuPos;
  }                                                                                                                                      
}
if (menuPos == 3) {
  if (menuPos != menuPosLast){
  lcd.clear();
  lcd.print("Start Solution Management");
  lcd.setCursor(0,1);
  lcd.print("Select = YES");
  menuPosLast = menuPos;
  }                                                                                                                                      
}
if (menuPos == 4) {
  if (menuPos != menuPosLast){
  lcd.clear();
  lcd.print("Menu 5");
  lcd.setCursor(0,1);
  lcd.print("Test");
  menuPosLast = menuPos;
  }                                                                                                                                      
}
if (menuPos == 5) {
  if (menuPos != menuPosLast){
  lcd.clear();
  lcd.print("Menu 6");
  lcd.setCursor(0,1);
  lcd.print("Test");
  menuPosLast = menuPos;
  }
  lcd.clear(); 
  lcd.print(moist);
  delay(50);                                                                                                                                      
}
}
                                                                                  
