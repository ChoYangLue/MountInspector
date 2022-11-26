
void setup() {
  Serial.begin(9600);
  Serial.println("command: push");
}
 
void loop() {

  if ( Serial.available() ) { 
    ///char keyc = Serial.read();
    //Serial.write( keyc );
    //if (keyc == 'a') pushButton(22);
    
    String key = Serial.readString();
    if (key == "push") pushButton(22);
    Serial.println(key);
  }
}

void pushButton(int pin)
{
  digitalWrite(pin, HIGH);
  delay(150);
  digitalWrite(pin, LOW);
}

/*
#include <SPI.h>
#include <EthernetENC.h>

boolean skip = false;
boolean catchGET = false;

int oPin = 9;

byte ip [] = {192, 168, 1, 50};
byte mac[] = {0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54};

EthernetServer server = EthernetServer(80);

void setup() {
  pinMode(oPin, OUTPUT);
  digitalWrite(oPin, LOW);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  Serial.println(Ethernet.localIP());
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  
  if (client) {
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        
        if (!skip && catchGET) {
          switch (c) {
            case '1' : digitalWrite(oPin, HIGH); break;
            case '0' : digitalWrite(oPin, LOW);  break;
            default  : continue;
          }
          skip = true;
        }
        
        if (c == '?') catchGET = true;
        
      }else{
        
        returnHTML(client);
        break;
        
      }
    }
  }
  
  skip = false;
  catchGET = false;
  client.stop();
}

void returnHTML(EthernetClient client) {

  //---HTTP HEADER---
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  
  //---HTML DOC------
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name=viewport content=\"width=80px, initial-scale=4, maximum-scale=4, user-scalable=no\" />");
  client.println("<title>A Remote</title>");
  client.println("</head>");
  client.println("<body style=\"color:rgb(205,205,205);background-color:rgb(96,96,96);text-align:center;\">");
  client.println("Remote<br />");
  client.println("<form method=GET>");
  client.println("<input type=submit name=1 value=ON /><br />");
  client.println("<input type=submit name=0 value=OFF />");
  client.println("</form>");
  client.println("</body>");
  client.println("</html>");
  
}
*/
