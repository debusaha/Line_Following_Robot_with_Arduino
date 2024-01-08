// connect motor controller pins to Arduino digital pins
// motor one
int enA = 5;
int in1 = 7;
int in2 = 8;
// motor two
int enB = 3;
int in3 = 2;
int in4 = 4;
// analog input from linesensor
int d1 = A0;
int d3 = A1;
int d4 = A2;
int d5 = A3;
int d6 = A4;
int d8 = A5;
//--------------------------------------------
void setup()
{
  Serial.begin(9600);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void linefollower1()
{
  float threshold = 4.00;
  int p1 = 150;
  int p2 = 120;
  int l3 = analogRead(d3);
  int l6 = analogRead(d6);
  float v3 = l3 * (5.0 / 1024.0);
  float v6 = l6 * (5.0 / 1024.0);
  if(v3<threshold && v6<threshold) // Robot moves forward
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v3>threshold && v6<threshold) // Robot turns right
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v3<threshold && v6>threshold) // Robot turns left
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }  
  if(v3>threshold && v6>threshold) // Robot stops
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }            
}
void linefollower2()
{
  float threshold = 4.00;
  int p1 = 255;
  int p2 = 200;
  int p3 = 150;
  int p4 = 0;  
  int l1 = analogRead(d1);
  int l3 = analogRead(d3);
  int l4 = analogRead(d4);
  int l5 = analogRead(d5);
  int l6 = analogRead(d6);
  int l8 = analogRead(d8);
  float v1 = l1 * (5.0 / 1024.0);
  float v3 = l3 * (5.0 / 1024.0);
  float v4 = l4 * (5.0 / 1024.0);
  float v5 = l5 * (5.0 / 1024.0);
  float v6 = l6 * (5.0 / 1024.0);
  float v8 = l8 * (5.0 / 1024.0);
  if(v4>threshold && v5>threshold) // Robot moves forward (max speed)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if(v5>threshold && v6>threshold) // Robot moves forward (reduced speed)
  {
    analogWrite(enA, p2);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p2);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v3>threshold && v4>threshold) // Robot moves forward (reduced speed)
  {
    analogWrite(enA, p2);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p2);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v3>threshold && v4<threshold) // Robot turns right (slow rotation)
  {
    analogWrite(enA, p3);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p3);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v5<threshold && v6>threshold) // Robot turns left (slow rotation)
  {
    analogWrite(enA, p3);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p3);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }  
  if(v1>threshold)  // Robot turns right (fast rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v8>threshold)  // Robot turns left (fast rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }  
  if(v1>threshold && v3>threshold && v4>threshold && v5>threshold && v6>threshold && v8>threshold) // Robot stops
  {
    analogWrite(enA, p4);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p4);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }            
}
void linefollower3()
{
  float threshold = 4.00;
  int p1 = 255;
  int p2 = 200;
  int p3 = 150;
  int p4 = 0;  
  int l1 = analogRead(d1);
  int l3 = analogRead(d3);
  int l4 = analogRead(d4);
  int l5 = analogRead(d5);
  int l6 = analogRead(d6);
  int l8 = analogRead(d8);
  float v1 = l1 * (5.0 / 1024.0);
  float v3 = l3 * (5.0 / 1024.0);
  float v4 = l4 * (5.0 / 1024.0);
  float v5 = l5 * (5.0 / 1024.0);
  float v6 = l6 * (5.0 / 1024.0);
  float v8 = l8 * (5.0 / 1024.0);
  if(v4>threshold && v5>threshold) // Robot moves forward (max speed)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if(v5>threshold && v6>threshold) // Robot moves forward (max speed)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v3>threshold && v4>threshold) // Robot moves forward (max speed)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v3>threshold && v4<threshold) // Robot turns right (fast rotation)
  {
    analogWrite(enA, p2);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, p2);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v5<threshold && v6>threshold) // Robot turns left (fast rotation)
  {
    analogWrite(enA, p2);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p2);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }  
  if(v1>threshold)  // Robot turns right (max rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v8>threshold)  // Robot turns left (max rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }  
  if(v1>threshold && v3>threshold && v4>threshold && v5>threshold && v6>threshold && v8>threshold) // Robot stops
  {
    analogWrite(enA, p4);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p4);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }            
}
void linefollower4() // Did not work as intended. Robot turns backward when it a face 90 degree turn
{
  float threshold = 4.00;
  int p1 = 255;
  int p2 = 200;
  int p3 = 150;
  int p4 = 0;
  int p5 = 225;  
  int l1 = analogRead(d1);
  int l3 = analogRead(d3);
  int l4 = analogRead(d4);
  int l5 = analogRead(d5);
  int l6 = analogRead(d6);
  int l8 = analogRead(d8);
  float v1 = l1 * (5.0 / 1024.0);
  float v3 = l3 * (5.0 / 1024.0);
  float v4 = l4 * (5.0 / 1024.0);
  float v5 = l5 * (5.0 / 1024.0);
  float v6 = l6 * (5.0 / 1024.0);
  float v8 = l8 * (5.0 / 1024.0);
  if(v4>threshold && v5>threshold) // Robot moves forward (max speed)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  if(v5>threshold && v6>threshold) // Robot moves forward (two different pwm for the two motors)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p5);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v3>threshold && v4>threshold) // Robot moves forward (two different pwm for the two motors)
  {
    analogWrite(enA, p5);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v3>threshold && v4<threshold) // Robot turns right (fast rotation + forward motion)
  {
    analogWrite(enA, p2);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  if(v5<threshold && v6>threshold) // Robot turns left (fast rotation + forward motion)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p2);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v1>threshold)  // Robot turns right (max rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, p1);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }  
  if(v8>threshold)  // Robot turns left (max rotation)
  {
    analogWrite(enA, p1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, p1);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }  
  if(v1>threshold && v3>threshold && v4>threshold && v5>threshold && v6>threshold && v8>threshold) // Robot stops
  {
    analogWrite(enA, p4);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, p4);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }            
}

void loop()
{
//linefollower1();
//linefollower2(); //15.1 sec per loop 
//linefollower3(); //14.3 sec per loop 
  linefollower4(); //13.0 sec per loop 
}
