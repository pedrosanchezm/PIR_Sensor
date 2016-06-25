int pir =2;
int pirState;
int red1=3;
int red2=4;
int green=5;
int pushbutton2=7;
int pushbutton3=8;
int buttonState2 = 0;
int buttonState3 = 0;
int count1=0;
int x=0;
int speaker=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pushbutton1, INPUT);
  pinMode(pushbutton2, INPUT);
  pinMode(pushbutton3, INPUT);
  pinMode(speaker, OUTPUT);
  pirState=LOW;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pirState = digitalRead(pir);
  x=0;
  if(pirState==HIGH){
        
      while(x!=1){
        alarm(300,160);
           
           buttonState1 = digitalRead(pushbutton2);
           buttonState2 = digitalRead(pushbutton3);
           if(buttonState1==HIGH&&buttonState2==HIGH){
              count1+=1;
            }
           
            if(count1==3){
                  x=1;
              stopalarm();
              count1=0;
              count2=0;
              delay(1000);
              
              }
     
        }

     
  }
  else{
    stopalarm();
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
