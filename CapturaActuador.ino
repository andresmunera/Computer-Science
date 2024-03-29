const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//sets the baud rate
pinMode (D0,INPUT);//pin digital del sensor
pinMode (D1,OUTPUT);
pinMode (D2,OUTPUT);
pinMode (D3,OUTPUT);

}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
limit = digitalRead(D0);
Serial.print("CO value: ");
Serial.println(value);//prints the CO value

if (value < 95){
  digitalWrite (D1,HIGH);
  digitalWrite (D2,LOW);
  digitalWrite (D3,LOW);  
}
else
{
  if(value < 130){
    digitalWrite (D2,HIGH);
    digitalWrite (D1,LOW);
    digitalWrite (D3,LOW);  
  }
    else{
      digitalWrite (D3,HIGH);
      digitalWrite (D2,LOW);
      digitalWrite (D1,LOW);  
    }
}
delay(500);
}
