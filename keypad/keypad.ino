
/*
  Project: Arduino and MM74C922N interface demo
  Visit  http://embedded-lab.com/blog/?p=8640 for more details.
  
*/

#define PINA 7
#define PINB 6
#define PINC 5
#define PIND 4


int output, key_code, press_status = 0;
char str[16] = {'1', 'A', '3', '2', '4', 'B', '6', '5', '7', 'C', '9', 
                '8', '*', 'D', '#', '0'};
void setup()
{
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  Serial.println("MM74C22N Demo!");
  attachInterrupt(digitalPinToInterrupt(3), Read_Data, FALLING);
}

void loop()
{
  if(press_status){
    Serial.println("Key press detected.");
    Serial.print("Pressed Key (code) = ");
    Serial.print(str[output]);
    Serial.print(" (");
    Serial.print(output, HEX);
    Serial.println(')');
    press_status = 0;
    
  }
}

void Read_Data()
{ 
  output = 0;
  output = output | digitalRead(4);
  output = output << 1;
  output = output | digitalRead(5);
  output = output << 1;
  output = output | digitalRead(6);
  output = output << 1;
  output = output | digitalRead(7);
  press_status = 1;
  
}

