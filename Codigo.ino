int pir =2;
int pirState;
int red1=3;
int red2=4;
int green=5;
int pushbutton=6;
int buttonState = 0;
int count=0;
int x=0;
int speaker=7;
int sensorMQ2 = A0;
int sensorMQ2Valores = 0;
int limiteMQ2 = 1300;


void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pushbutton, INPUT);
  pinMode(speaker, OUTPUT);
  pirState=LOW;
}

void loop() {
  sensorMQ2Valores = analogRead(sensorMQ2);
  pirState = digitalRead(pir);
  Serial.println("Valor actual MQ-2: ");
  Serial.println(sensorMQ2Valores, DEC);
  x=0;
  if(pirState==HIGH){
      while(x!=1){
        alarm(300,160);
           
           buttonState = digitalRead(pushbutton);
           if(buttonState==HIGH){
              count+=1;
            }     
            if(count==1){
		x=1;
              stopalarm();
              count=0;
              delay(1000);            
              }
        }
  }
  else if(pirState==LOW){
    stopalarm();
  }
  else if(sensorMQ2Valores >= limiteMQ2) {
    digitalWrite(speaker, HIGH);
    delay(200);
    digitalWrite(speaker, LOW);
    delay(200);
  }
  else if(sensorMQ2Valores < limiteMQ2){
    digitalWrite(speaker, LOW);
  }      
}

void alarm(long duration,int frequency){
  digitalWrite(green, LOW);
  digitalWrite(red2,LOW);
  digitalWrite(red1, HIGH);
  delay(300);
  digitalWrite(red1, LOW);
  digitalWrite(red2, HIGH);
  delay(300);
  play(duration, frequency);
}

void play(long duration, int frequency){
  duration = duration*1000;
  int period = (1.0/frequency)*1000000;
  long elapsed = 0;
  while(elapsed<duration){
    digitalWrite(speaker, HIGH);
    delayMicroseconds(period/2);
    digitalWrite(speaker, LOW);
    delayMicroseconds(period/2);
    elapsed+= period;
  }
}

void stopalarm(){
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green, HIGH); 
  pirState=LOW;
  delay(700);
}
