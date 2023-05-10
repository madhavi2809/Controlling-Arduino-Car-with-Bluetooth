int speed;
int LED = 13;
char input;

void setup()
{
  Serial.begin(9600);  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(LED, OUTPUT);
  }

void loop()
{
  int potentiometer = analogRead(A0);
  int potent = potentiometer/4;

  analogWrite(10, potent);
  analogWrite(11, potent);

  digitalWrite(LED, LOW);
  speed = 350;
  while(Serial.available())
  {
    digitalWrite(LED, HIGH);
    input = Serial.read();
    if(input == 'F')
    {
      forward();
    }
    else if (input== 'R')
    {
      right();
    }
    else if (input== 'L')
    {
      left();
    }
    else if (input== 'G')
    {
      backward();
    }  
    else if (input== 'S')
    {
      stop();
    }
  }
}
void stop(){
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
void backward()
{
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
void forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}
void left()
{
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
void right()
{
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
