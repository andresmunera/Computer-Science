


#include <WiFiClient.h>;
#include <ThingSpeak.h>; // Include ThingSpeak Library
#include <ESP8266WiFi.h>; // Include ESP8266wifi Library

const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino

char ssid[] = "FamiliaMu5"; // Nombre del WiFi (nombre del router)
char pass[] = "goyito89?"; // WiFi router password
unsigned long myChannelNumber = 870229; // Thingspeak número de canal
const char * myWriteAPIKey = "E63M77BGI375BFO4"; // ThingSpeak write API Key

//Variable a la cual le vamos a pasar lo que midamos
int limit;
int value;
//no tocar
int status = WL_IDLE_STATUS;

WiFiClient client;

void setup() {
//NO TOCAR
WiFi.begin(ssid, pass); // Inicia WiFi
ThingSpeak.begin(client); // Inicia ThingSpeak


Serial.begin(115200); // Velocidad puerto serie

Serial.println();
Serial.print("Conectando a ");
Serial.print(ssid);

while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println();
Serial.println("Conectado a WiFi");
Serial.print("Dirección IP: ");
Serial.println(WiFi.localIP());

}


void loop() {
value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
limit = digitalRead(D0); 
Serial.print("CO value: ");
Serial.println(value);//prints the CO value


// Carga los valores a enviar
ThingSpeak.setField(1, value);

// Escribe todos los campos a la vez.
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);


// Añadimos un retraso para limtitar el número de escrituras en Thingspeak

delay(3000);



}
