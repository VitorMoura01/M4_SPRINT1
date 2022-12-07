
 /*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "S22Vitor";
const char* password = "vvzv9972";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String outputGreenState = "off";
String outputRedState = "off";

// Assign output variables to GPIO pins
#define green 42
#define red 40

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  // Set outputs to LOW
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /win") >= 0) {
              Serial.println("GPIO 26 on");
              outputGreenState = "on";
              digitalWrite(green, HIGH);
              digitalWrite(red, LOW);

            } else if (header.indexOf("GET /lost") >= 0) {
              Serial.println("GPIO 27 on");
              outputRedState = "on";
              digitalWrite(red, HIGH);
              digitalWrite(green, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>");
            client.println("<link rel=\"icon\" href=\"data:,\"/>");
            client.println("<title>Pedra Papel e Tesoura</title>");

            client.println("<style>body{background-color:#ccc}}");
            client.println(".selections{display:flex;justify-content:center}");
            client.println(".selection{background:0 0;border:none;outline:0;cursor:pointer;font-size:2rem;transition:.1s}");
            client.println(".selection:hover{transform:scale(1.2)}");
            client.println(".results{margin-top:1rem;display:grid;justify-content:center;grid-template-columns:repeat(2,1fr);justify-items:center;align-items:center}");
            client.println(".result-score{margin-left:.1rem;font-size:.5rem;color:#333}</style></head>");


            client.println("<body><div class=\"selections\">");
            client.println("<button class=\"selection\" data-selection=\"rock\">Pedra</button>");
            client.println("<button class=\"selection\" data-selection=\"paper\">Papel</button>");
            client.println("<button class=\"selection\" data-selection=\"scissors\">Tesoura</button></div>");
            client.println("<div class=\"results\">");
            client.println("<div>You<span class=\"result-score\" data-your-score>0</span></div>");
            client.println("<div data-final-column>Computer<span class=\"result-score\" data-computer-score>0</span></div>");
                   

            client.println("<script type=\"text/javascript\">");
            client.println("const selectionButtons=document.querySelectorAll(\"[data-selection]\"),finalColumn=document.querySelector(\"[data-final-column]\"),computerScoreSpan=document.querySelector(\"[data-computer-score]\"),yourScoreSpan=document.querySelector(\"[data-your-score]\")");
            client.println("SELECTIONS=[{name:\"rock\",emoji:\"PEDRA\",beats:\"scissors\"},{name:\"paper\",emoji:\"PAPEL\",beats:\"rock\"},{name:\"scissors\",emoji:\"TESOURA\",beats:\"paper\"}];");
            client.println("selectionButtons.forEach(a=>{a.addEventListener(\"click\",e=>{var t=a.dataset.selection,n=SELECTIONS.find(e=>e.name===t);makeSelection(n)})});");
            client.println("function makeSelection(e){var n=randomSelection(),o=isWinner(e,n),i=isWinner(n,e);addSelectionResult(n,i),addSelectionResult(e,o),o&&(incrementScore(yourScoreSpan),window.location.href=\"/win\"),i&&(incrementScore(computerScoreSpan),window.location.href=\"/lost\")}");
            client.println("function incrementScore(scoreSpan) {scoreSpan.innerText = parseInt(scoreSpan.innerText) + 1;}");
            client.println("function addSelectionResult(selection, winner) {const div = document.createElement('div');div.innerText = selection.emoji;div.classList.add('result-selection');if (winner) div.classList.add('winner');finalColumn.after(div);}");
            client.println("function isWinner(selection, opponentSelection) {return selection.beats === opponentSelection.name;}");
            client.println("function randomSelection() {const randomIndex = Math.floor(Math.random() * SELECTIONS.length);return SELECTIONS[randomIndex];}");
            client.println("</script>");
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}