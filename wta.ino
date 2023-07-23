int r1 = 14; // RELAYOUT
int r2 = 20; // SUMPIN
int r3 = 19; // float

void setup()
{
    pinMode(r1, OUTPUT);
    pinMode(r2, INPUT);
    pinMode(r3, INPUT);
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(r3), overflo, CHANGE);
    attachInterrupt(digitalPinToInterrupt(r2), underflo, CHANGE);
}
void loop()
{
}
void overflo()
{
    if (!digitalRead(r3))
    {
        digitalWrite(r1, LOW);
        Serial.println("overflow");
    }
}
void underflo()
{
    if (digitalRead(r2))
    {
        digitalWrite(r1, HIGH);
        Serial.println("underflo");
    }
}
