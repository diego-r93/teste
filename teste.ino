int AC_1 = 32;
unsigned long counter_LOW = 0;
unsigned long counter_HIGH = 0;

unsigned long previousMillis = 0;

const long interval = 1000; // Esse será o intervalo de contagem

void setup() {
  Serial.begin(9600);
  pinMode(AC_1, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();  

  counter_LOW = 0;
  counter_HIGH = 0;

  while (currentMillis - previousMillis <= interval) {
    previousMillis = currentMillis;
    
    byte VAC_1 = digitalRead(AC_1);    
       
    if (!VAC_1){
      counter_LOW++;           
    }
    else{
      counter_HIGH++;      
    }

    Serial.println(String("OPTO:") + VAC_1);
    Serial.println(String("contando LOW:") + counter_LOW);
    Serial.println(String("contando HIGH:") + counter_HIGH);
  }
  
  Serial.println(String("DUTYCYCLE:" + ((counter_HIGH)/(counter_HIGH + counter_LOW))*100));
}
