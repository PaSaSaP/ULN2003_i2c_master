// arduino pro mini 8MHz 3v3
#include <Wire.h>

void sendWireCmd(int cmd, int8_t value) {
    Wire.beginTransmission(0x12);
    Wire.write(cmd);
    Wire.write(value);
    Wire.endTransmission();
}

void setup() {
    Wire.begin();
    Serial.begin(57600);
}

String str;

void loop() {
    if (Serial.available()) {
        str = Serial.readStringUntil('\n');
        Serial.print("GOT CMD: "); Serial.println(str);
        if (str == "j") {
            Serial.println("L rotate");
            sendWireCmd(2, -1);
            Serial.println("L end");
        } else if (str == "k") {
            Serial.println("M rotate");
            sendWireCmd(2, 0);
            Serial.println("M end");
        } else if (str == "l") {
            Serial.println("R rotate");
            sendWireCmd(2, 1);
            Serial.println("R end");
        } else if (str == "q") {
            Serial.println("Q Zero");
            sendWireCmd(1, -1);
            Serial.println("Q end");
        } else if (str == "e") {
            Serial.println("E Zero");
            sendWireCmd(1, 1);
            Serial.println("E end");
        } else {
            Serial.println("invalid cmd");
        }
    }
}
