int command = 0;
int led = 13;
int i=0;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}



void loop() {
    while(Serial.available() > 0){ //受け取った命令dataがあるとき        
        command = Serial.read(); //命令データは何なのかを読み込む
        Serial.print(command);
        //set(); ここにいれることで、雑音を拾ったときにもset()が作動してしまう
        if(command == 'a'){//python側でbyteでwriteしたのでこっちもbyteで対応
          set();
          digitalWrite(led,HIGH);
          delay(1000);
          digitalWrite(led,LOW);
          delay(1000);
          digitalWrite(led,HIGH);
          delay(1000);
      }else if(command == 'b'){
        set();
        digitalWrite(led,HIGH);
        delay(3000);
        digitalWrite(led,LOW);
        delay(1000);
        digitalWrite(led,HIGH);
        delay(3000);
      }else if(command == 'c'){
        set();
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
        delay(3000);
        digitalWrite(led,HIGH);
        delay(1000);
      }else if(command == 'd'){
        set();
        digitalWrite(led,HIGH);
        delay(3000);
        digitalWrite(led,LOW);
        delay(1000);
        digitalWrite(led,HIGH);
        delay(3000);
      }
    }
}
int set(){
  for(i=0;i<=5;i++){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
}

