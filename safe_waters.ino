int celsius = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT); //Red Led
  pinMode(3, OUTPUT); //Green Led
  pinMode(4, OUTPUT); //Yellow Led
}

void loop()
{
 celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
 Serial.print(celsius);
 Serial.print(" C, ");
  
  //If the temperature is too low for the fish living there (<=28)
  if (celsius<28){
   digitalWrite(4, HIGH); //Turns on the yellow led
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
  }
  //If the temperature is ok for the fish living there (28<temp<32)
  if (celsius>=28 && celsius<=32){
   digitalWrite(4, LOW);
   digitalWrite(3, HIGH); //Turns on the green led
   digitalWrite(2, LOW);
  }
  //If the temperature is too high for the fish living there (>=32)
  if (celsius>32){
   digitalWrite(4, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH); //Turns on the red led
  }
    delay(10000); 
}