/*
MECH 307 HW #4
Created by Jacob Beauchamp, Andrew Hanze, Caden Cope, and Caleb Costigan

This code is for an arduino setup which takes the readings from a thermometer component and after converting 
the voltage to a readable temperature, will display it on an attached LCD screen. Secondly, pressing a button will
switch the temperature units from metric to US Customary.

REQUIREMENTS: Needs the liquid display package to be installed

For more information about this project and others like it for the 307 HW, please see the github page 

*/

//Setup loop for assignment of variables on launch of script/deployment on arduino
void setup() {
//BS E D4D5 D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//STILL NEED TO PUT IN UNDEFINED VARIABLES

}

//Code that gets looped by the arduino
void loop() {
//Defines and reads the voltage coming from the defined temperature sensor
int tempReading = analogRead(tempPin);
//Converts voltage into a readable kelvin measurement
double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK ))
* tempK );
//Converts the kelvin measurement to degrees centigrade
float tempC = tempK - 273.15;
//Converts the centigrade measurement into fahrenheit
float tempF = (tempC * 9.0)/ 5.0 + 32.0; 

//From guide. Still needs to be tested. Likely has to do something with reseting the LCD screen
lcd.setCursor(0, 0); 
lcd.print("Temp C "); 
lcd.setCursor(6, 0); 
lcd.print(tempF);


}
