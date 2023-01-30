#define alcohol      A0
#define buzzer       13
#define ON_LED       12
#define OFF_LED      11
#define start        2
#define right_press  A1
#define left_press   A2

int     value;                               //  x -> <100    , o -> >100
int     right_value;                         //  x -> 10 ~ 800, o > 1000 
int     left_value;
volatile byte state = LOW;                   //  init -> 0, 
int     cnt = 100;                             

void blow() {
  state = !state;
  digitalWrite(OFF_LED, HIGH);
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(start), blow, RISING);
  pinMode(alcohol, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(right_press, INPUT);
  pinMode(left_press, INPUT);
  pinMode(ON_LED, OUTPUT);
  pinMode(OFF_LED, OUTPUT);
  pinMode(start, INPUT);
  digitalWrite(ON_LED, LOW);
  digitalWrite(OFF_LED, LOW);
}

void loop() {
  while(1) {
    if(state == LOW) {                          // 버튼 안눌렀을 때 대기모드
      break;
    }
    else {
      for(int n = 0 ; n < 20 ; n++) {
        digitalWrite(OFF_LED, HIGH);
        delay(100);
        digitalWrite(OFF_LED, LOW);
        delay(100);
      }
      value = analogRead(alcohol);
      if(value > 600) {                        // 음주를 했을 때
        state = LOW;
        digitalWrite(buzzer, HIGH);
        delay(2000);
        digitalWrite(buzzer, LOW);
        digitalWrite(OFF_LED, LOW);
        break;
      }
      else {                                   // 음주를 안했을 때
        digitalWrite(ON_LED, HIGH);
        digitalWrite(OFF_LED, LOW);
        
        while(1) {
          if(state == LOW) {
            digitalWrite(ON_LED, LOW);
            digitalWrite(OFF_LED, LOW);
            digitalWrite(buzzer, LOW);
            break;
          }
          if(cnt > 100) {
            cnt = 100;
          }

          right_value = analogRead(right_press);
          left_value = analogRead(left_press);
          
          if(right_value > 100 && left_value > 100) {
            cnt = 100;
            delay(100);
          }
          else {
            cnt--;
            delay(100);
          }
          
          if(cnt > 65) {
            digitalWrite(buzzer, LOW);
          }
          else if(cnt < 65) {
            digitalWrite(buzzer, HIGH);
          }
        }
      }
    }
  
  }
}
