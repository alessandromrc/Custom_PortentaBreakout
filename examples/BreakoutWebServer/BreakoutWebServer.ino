/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using the Portenta Breakout.

 Circuit:
 * Portenta Breakout

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi

 */

#include <Custom_PortentaBreakout.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

// PortentaBreakout analogPin table
breakoutPin analogPin[] = {ANALOG_A0, ANALOG_A1, ANALOG_A2, ANALOG_A3,
                           ANALOG_A4, ANALOG_A5, ANALOG_A6, ANALOG_A7};

void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Breakout.Ethernet.begin(mac);

  // Check for Ethernet hardware present
  if (Breakout.Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Breakout.Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Breakout.Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          // output the value of each analog input pin
          client.print("analog input 0 is " + String(Breakout.analogRead(analog.A0)) + "<br />");
          client.print("analog input 1 is " + String(Breakout.analogRead(analog.A1)) + "<br />");
          client.print("analog input 2 is " + String(Breakout.analogRead(analog.A2)) + "<br />");
          client.print("analog input 3 is " + String(Breakout.analogRead(analog.A3)) + "<br />");
          client.print("analog input 4 is " + String(Breakout.analogRead(analog.A4)) + "<br />");
          client.print("analog input 5 is " + String(Breakout.analogRead(analog.A5)) + "<br />");
          client.print("analog input 6 is " + String(Breakout.analogRead(analog.A6)) + "<br />");
          client.print("analog input 7 is " + String(Breakout.analogRead(analog.A7)) + "<br />");

          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
