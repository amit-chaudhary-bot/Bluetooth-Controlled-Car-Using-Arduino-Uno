const int EnableL = 5;
const int HighL = 6;       // CREATING VARIABLES OF LEFT SIDE MOTOR
const int LowL =7;

const int EnableR = 10;
const int HighR = 8;       //CREATING VARIABLES OF RIGHT SIDE MOTOR
const int LowR =9;
char val;

void setup() {
  // put your setup code here, to run once:
pinMode(EnableL, OUTPUT);
pinMode(HighL, OUTPUT);       //SETTING PINS TO OUTPUT MODE OF LEFT SIDE MOTOR
pinMode(LowL, OUTPUT);


pinMode(EnableR, OUTPUT);
pinMode(HighR, OUTPUT);       //SETTING PINS TO OUTPUT MODE OF RIGHT SIDE MOTOR
pinMode(LowR, OUTPUT);

Serial.begin(9600);         //CREATING SERIAL CONNECTION 
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)    //CHECK INPUT IN BUFFER
  {
  val = Serial.read();      //READ INPUTS
  Serial.println(val);
  }
  if( val == 'F') // Forward
    {
      digitalWrite(HighL, LOW);
      digitalWrite(LowL, HIGH);
      analogWrite(EnableL,180);
                                      //MOVE FORWARD
      digitalWrite(HighR, LOW);
      digitalWrite(LowR, HIGH);
      analogWrite(EnableR,180); 
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(HighL, HIGH);
      digitalWrite(LowL, LOW);
      analogWrite(EnableL,180);
                                      //MOVE BACKWARD
      digitalWrite(HighR, HIGH);
      digitalWrite(LowR, LOW);
      analogWrite(EnableR,180); 
    }
  else if(val == 'L') //Left
    {
    digitalWrite(HighL, LOW);
    digitalWrite(LowL, HIGH);
    analogWrite(EnableL,80);
                                    //MOVE FORWARD LEFT BY SLOW TURN
    digitalWrite(HighR, LOW);
    digitalWrite(LowR, HIGH);
    analogWrite(EnableR,180);
    }
  else if(val == 'R') //Right
    {
    digitalWrite(HighL, LOW);
    digitalWrite(LowL, HIGH);
    analogWrite(EnableL,180);
                                  ////MOVE FORWARD RIGHT BY SLOW TURN
    digitalWrite(HighR, LOW);
    digitalWrite(LowR, HIGH);
    analogWrite(EnableR,80);
    }
   else if(val == 'S') //Stop
    {
    digitalWrite(HighL, LOW);
    digitalWrite(LowL, LOW);
    analogWrite(EnableL,180);

    digitalWrite(HighR, LOW);
    digitalWrite(LowR, LOW);
    analogWrite(EnableR,180); 
    }
   else if(val == 'I') //Forward Right
    {
    digitalWrite(HighL, LOW);
    digitalWrite(LowL, HIGH);
    analogWrite(EnableL,180);
                                      //MOVE FORWARD RIGHT BY SHARP TURN
    digitalWrite(HighR, LOW);
    digitalWrite(LowR, HIGH);
    analogWrite(EnableR,40);
    }
  else if(val == 'J') //Backward Right
    {
    digitalWrite(HighL, HIGH);
    digitalWrite(LowL, LOW);
    analogWrite(EnableL,180);
                                  //MOVE BACKWARD RIGHT BY SHARP TURN
    digitalWrite(HighR, HIGH);
    digitalWrite(LowR, LOW);
    analogWrite(EnableR,40); 
    }
   else if(val == 'G') //Forward Left
    {
    digitalWrite(HighL, LOW);
    digitalWrite(LowL, HIGH);
    analogWrite(EnableL,40);
                                          //MOVE FORWARD LEFT BY SHARP TURN
    digitalWrite(HighR, LOW);
    digitalWrite(LowR, HIGH);
    analogWrite(EnableR,180);
    }
  else if(val == 'H') //Backward Left
    {
    digitalWrite(HighL, HIGH);
    digitalWrite(LowL, LOW);
    analogWrite(EnableL,40);
                                      //MOVE BACKWARD LEFT BY SHARP TURN
    digitalWrite(HighR, HIGH);
    digitalWrite(LowR, LOW);
    analogWrite(EnableR,180);  
    }
}
