#include <virtuabotixRTC.h>
// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8);
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup()  {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
//  int seconds_var;
//  int minutes_var;
//  int hours_var;
//  int week_day_var;
//  int day_var;
//  int month_var;
//  int year_var; 
  
// Set the current date, and time in the following format:
//  while(1){
//  if(Serial.available()){
//      String My_S = Serial.readString();
//      String time_string = My_S.substring(0, My_S.indexOf(' '));  
//      if(time_string == "time"){
//        String seconds_value = My_S.substring(My_S.indexOf(' ')+1,My_S.indexOf('!'));
//        String minutes_value = My_S.substring(My_S.indexOf('!')+1,My_S.indexOf('@'));
//        String hours_value = My_S.substring(My_S.indexOf('@')+1,My_S.indexOf('#'));
//        String weekday_value = My_S.substring(My_S.indexOf('#')+1,My_S.indexOf('$'));
//        String day_value = My_S.substring(My_S.indexOf('$')+1,My_S.indexOf('%'));
//        String month_value = My_S.substring(My_S.indexOf('%')+1,My_S.indexOf('^'));
//        String year_value = My_S.substring(My_S.indexOf('^')+1,My_S.indexOf('&'));
//        Serial.println(seconds_value);
//        Serial.println(minutes_value);
//        Serial.println(hours_value);
//        Serial.println(weekday_value);
//        Serial.println(day_value);
//        Serial.println(month_value);
//        Serial.println(year_value);
//        seconds_var = seconds_value.toInt();
//        minutes_var = minutes_value.toInt();
//        hours_var = hours_value.toInt();
//        week_day_var = weekday_value.toInt();
//        day_var = day_value.toInt();
//        month_var = month_value.toInt();
//        year_var = year_value.toInt(); 
//        break;
//      }
//    }    
//  }
//  
//  // seconds, minutes, hours, day of the week, day of the month, month, year
//  
//  myRTC.setDS1302Time(seconds_var, minutes_var, hours_var, week_day_var, day_var, month_var, year_var);
}
void loop()  {
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  // Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);


  if(myRTC.seconds % 2==0){
    setColor(170, 0, 255);  // Purple Color
  }
  else {
    setColor(0, 255, 0);  // Green Color
  }
    
  // Delay so the program doesn't print non-stop
  delay(1000);



// setColor(255, 0, 0);  // Red Color
// setColor(0, 255, 0);  // Green Color
// setColor(0, 0, 255);  // Blue Color
// setColor(255, 255, 255);  // White Color
// setColor(170, 0, 255);  // Purple Color
}

void setColor(int redValue, int greenValue, int blueValue) {
 analogWrite(redPin, redValue);
 analogWrite(greenPin, greenValue);
 analogWrite(bluePin, blueValue);
}
