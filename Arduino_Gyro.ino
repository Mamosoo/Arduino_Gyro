#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  int val1 = analogRead(A0);
  int val3 = analogRead(A2); // get rid of A1(Y)
  int sum = val1 + val3 - 714;

  Serial.println(sum);

  if (sum <= 10 && sum >= -10)
  {
    Serial.println("Stand");
    BTSerial.write("Stand");
  }

  else if (sum <= 80 && sum >= -80)
  {
    Serial.println("Walk");
    BTSerial.write("Walk");
  }

  else if (sum >= 80 || sum <= -80)
  {
    Serial.println("Run");
    BTSerial.write("Run");
  }


  delay(1000);

}
