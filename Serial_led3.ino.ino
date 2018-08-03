int command = 0;
int led = 13;
int n=0;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}



void loop() {
    while(Serial.available() > 0){ //受け取った命令dataがあるとき        
        command = Serial.read(); //命令データは何なのかを読み込む
        Serial.print(command);
        set();
        if(command == 'a'){//python側でbyteでwriteしたのでこっちもbyteで対応
          digitalWrite(led,HIGH);
          delay(1000);
          digitalWrite(led,LOW);
          delay(1000);
          digitalWrite(led,HIGH);
          delay(1000);
      }else if(command == 'b'){
        digitalWrite(led,HIGH);
        delay(3000);
        digitalWrite(led,LOW);
        delay(2000);
        digitalWrite(led,HIGH);
        delay(3000);
      }
    }
}
void set(){
  for(n=0;n<=5;n++){
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  Serial.print(n);
  }
}

