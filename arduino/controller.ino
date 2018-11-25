// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char *ssid = "";
const char *password = "";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Assign output variables to GPIO pins
const int LED_PINS[] = {13, 14, 26, 23, 5, 2, 4, 16};

// SETTINGS
int delayTime = 500;
int charBreak = 1300;
int wordBreak = 5 * delayTime;

int displayWidth = 16;

// characters
const int a[] = {0b00111111,
                 0b01000100,
                 0b01000100,
                 0b01000100,
                 0b00111111};
const int b[] = {0b01111111,
                 0b01001001,
                 0b01001001,
                 0b01001001,
                 0b00110110};
const int c[] = {0b00111110,
                 0b01000001,
                 0b01000001,
                 0b01000001,
                 0b00100010};
const int d[] = {0b01111111,
                 0b01000001,
                 0b01000001,
                 0b00100010,
                 0b00011100};
const int e[] = {0b01111111,
                 0b01001001,
                 0b01001001,
                 0b01001001,
                 0b01000001};
const int f[] = {0b01111111,
                 0b01001000,
                 0b01001000,
                 0b01001000,
                 0b01000000};
const int g[] = {0b00111110,
                 0b01000001,
                 0b01001001,
                 0b01001001,
                 0b001};
const int h[] = {0b01111111,
                 0b00001000,
                 0b00001000,
                 0b00001000,
                 0b01111111};
const int i[] = {0b00000000,
                 0b01000001,
                 0b01111111,
                 0b01000001,
                 0b00000000};
const int j[] = {0b00000010,
                 0b00000001,
                 0b01000001,
                 0b01111110,
                 0b01000000};
const int k[] = {0b01111111,
                 0b00001000,
                 0b00010100,
                 0b00100010,
                 0b01000001};
const int l[] = {0b01111111,
                 0b00000001,
                 0b00000001,
                 0b00000001,
                 0b00000001};
const int m[] = {0b01111111,
                 0b00100000,
                 0b00011000,
                 0b00100000,
                 0b01111111};
const int n[] = {0b01111111,
                 0b00010000,
                 0b00001000,
                 0b00000100,
                 0b01111111};
const int o[] = {0b00111110,
                 0b01000001,
                 0b01000001,
                 0b01000001,
                 0b00111110};
const int p[] = {0b01111111,
                 0b01001000,
                 0b01001000,
                 0b01001000,
                 0b00110000};
const int q[] = {0b00111110,
                 0b01000001,
                 0b01000101,
                 0b01000010,
                 0b00111101};
const int r[] = {0b01111111,
                 0b01001000,
                 0b01001100,
                 0b01001010,
                 0b00110001};
const int s[] = {0b00110001,
                 0b01001001,
                 0b01001001,
                 0b01001001,
                 0b01000110};
const int t[] = {0b01000000,
                 0b01000000,
                 0b01111111,
                 0b01000000,
                 0b01000000};
const int u[] = {0b01111110,
                 0b00000001,
                 0b00000001,
                 0b00000001,
                 0b01111110};
const int v[] = {0b01111100,
                 0b00000010,
                 0b00000001,
                 0b00000010,
                 0b01111100};
const int w[] = {0b01111110,
                 0b00000001,
                 0b00001110,
                 0b00000001,
                 0b01111110};
const int x[] = {0b01100011,
                 0b00010100,
                 0b00001000,
                 0b00010100,
                 0b01100011};
const int y[] = {0b01110000,
                 0b00001000,
                 0b00000111,
                 0b00001000,
                 0b01110000};
const int z[] = {0b01000011,
                 0b01000101,
                 0b01001001,
                 0b01010001,
                 0b01100001};

const int eos[] = {0b00000000,
                   0b00000011,
                   0b00000011,
                   0,
                   0};
const int excl[] = {0, 0, 0b01111001, 0, 0};
const int ques[] = {0b00100000,
                    0b01000000,
                    0b01000101,
                    0b01001000,
                    0b00110000};

const int one[] = {0b00000000,
                 0b00100001,
                 0b01111111,
                 0b00000001,
                 0};

const int two[] = {0b01000001,
                 0b01000011,
                 0b01000101,
                 0b01001001,
                 0b00110001};

const int three[] = {0b01000010,
                 0b01000001,
                 0b01010001,
                 0b01101001,
                 0b01000110};

const int four[] = {0b00001100,
                 0b00010100,
                 0b00100100,
                 0b01111111,
                 0b00000100};

const int five[] = {0b01110010,
                 0b01010001,
                 0b01010001,
                 0b01010001,
                 0b01001110};

const int six[] = {0b00011110,
                 0b00101001,
                 0b01001001,
                 0b01001001,
                 0b00000110};

const int seven[] = {0b01000000,
                 0b01000111,
                 0b01001000,
                 0b01010000,
                 0b01100000};

const int eight[] = {0b00110110,
                 0b01001001,
                 0b01001001,
                 0b01001001,
                 0b00110110};

const int nine[] = {0b00110000,
                 0b01001001,
                 0b01001001,
                 0b01001010,
                 0b00111100};

const int zero[] = {0b00111110,
                 0b01000101,
                 0b01001001,
                 0b01010001,
                 0b00111110};


const String webpage = "<html><head>    <title>Spinnig 
display</title></head><body>    <h1>Super fancy spinning display</h1>    
<h2>made by Andi and Patrik during Athens November 2018</h2>    <input 
type=\"text\" id=\"T\">    <h3 style=\"color: red;\"></h3>    <script>      
document.getElementById('T').oninput = (e) => {        
fetch(window.location.href, {          method: 'POST',          body: 
e.target.value.toUpperCase()     }).catch(() => 
document.getElementsByTagName('h3')[0].innerText = 'There was an 
error.')      }    </script></body></html>";

String currentString = "Hello World";
String ip = "";

void setup()
{
    Serial.begin(115200);
    // Initialize the output variables as outputs
    // and set outputs to HIGH
    for (int led_pin : LED_PINS)
    {
        pinMode(led_pin, OUTPUT);
        digitalWrite(led_pin, HIGH);
    }

    // Connect to Wi-Fi network with SSID and password
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    currentString = ip = WiFi.localIP().toString();
    server.begin();
}

void loop()
{
    WiFiClient client = server.available(); // Listen for incoming 
clients

    displayString(currentString);


    if (client)
    {                                  // If a new client connects,
        Serial.println("New Client."); // print a message out in the 
serial port
        String currentLine = "";       // make a String to hold incoming 
data from the client
        while (client.connected())
        { // loop while the client's connected
            if (client.available())
            {                           // if there's bytes to read from 
the client,
                char c = client.read(); // read a byte, then
                Serial.write(c);        // print it out the serial 
monitor
                header += c;
                if (c == '\n')
                { // if the byte is a newline character
                    // if the current line is blank, you got two newline 
characters in a row.
                    // that's the end of the client HTTP request, so 
send a response:
                    if (currentLine.length() == 0)
                    {
                        if (header.indexOf("POST") >= 0) {
                            int cont_len_index = 
header.indexOf("Content-Length: "); // 16 chars
                            int newline_index = header.indexOf('\n', 
cont_len_index);
                            String content_len_str = 
header.substring(cont_len_index + 16, newline_index);
                            int content_len = content_len_str.toInt();
                            if (content_len == 0){
                                currentString = ip;
                            } else {
                                currentString = "";
                                for (int i = 0; i < content_len; i++) {
                                    c = client.read();
                                    currentString += c;
                                }
                            }
                        }
                        // HTTP headers always start with a response 
code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's 
coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();

                        // Display the HTML web page
                        client.println(webpage);

                        // The HTTP response ends with another blank 
line
                        client.println();
                        // Break out of the while loop
                        break;
                    }
                    else
                    { // if you got a newline, then clear currentLine
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {                     // if you got anything else but a 
carriage return character,
                    currentLine += c; // add it to the end of the 
currentLine
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

void displayString(String str){
    str.toLowerCase();
    while (str.length() < displayWidth) {
        str += " " + str;
    }
    str = str.substring(0, displayWidth - 1) + " ";

    for (int i = 0; i < str.length(); i++){
        displayChar(str.charAt(i));
    }
}

void displayChar(char character){
    if (character == 'a'){for (int i = 0; i <5; 
i++){displayLine(a[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'b'){for (int i = 0; i <5; 
i++){displayLine(b[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'c'){for (int i = 0; i <5; 
i++){displayLine(c[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'd'){for (int i = 0; i <5; 
i++){displayLine(d[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'e'){for (int i = 0; i <5; 
i++){displayLine(e[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'f'){for (int i = 0; i <5; 
i++){displayLine(f[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'g'){for (int i = 0; i <5; 
i++){displayLine(g[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'h'){for (int i = 0; i <5; 
i++){displayLine(h[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'i'){for (int it = 0; it <5; 
it++){displayLine(i[it]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'j'){for (int i = 0; i <5; 
i++){displayLine(j[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'k'){for (int i = 0; i <5; 
i++){displayLine(k[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'l'){for (int i = 0; i <5; 
i++){displayLine(l[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'm'){for (int i = 0; i <5; 
i++){displayLine(m[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'n'){for (int i = 0; i <5; 
i++){displayLine(n[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'o'){for (int i = 0; i <5; 
i++){displayLine(o[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'p'){for (int i = 0; i <5; 
i++){displayLine(p[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'q'){for (int i = 0; i <5; 
i++){displayLine(q[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'r'){for (int i = 0; i <5; 
i++){displayLine(r[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 's'){for (int i = 0; i <5; 
i++){displayLine(s[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 't'){for (int i = 0; i <5; 
i++){displayLine(t[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'u'){for (int i = 0; i <5; 
i++){displayLine(u[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'v'){for (int i = 0; i <5; 
i++){displayLine(v[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'w'){for (int i = 0; i <5; 
i++){displayLine(w[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'x'){for (int i = 0; i <5; 
i++){displayLine(x[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'y'){for (int i = 0; i <5; 
i++){displayLine(y[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == 'z'){for (int i = 0; i <5; 
i++){displayLine(z[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '!'){for (int i = 0; i <5; 
i++){displayLine(excl[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '?'){for (int i = 0; i <5; 
i++){displayLine(ques[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '.'){for (int i = 0; i <5; 
i++){displayLine(eos[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '0'){for (int i = 0; i <5; 
i++){displayLine(zero[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '1'){for (int i = 0; i <5; 
i++){displayLine(one[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '2'){for (int i = 0; i <5; 
i++){displayLine(two[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '3'){for (int i = 0; i <5; 
i++){displayLine(three[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '4'){for (int i = 0; i <5; 
i++){displayLine(four[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '5'){for (int i = 0; i <5; 
i++){displayLine(five[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '6'){for (int i = 0; i <5; 
i++){displayLine(six[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '7'){for (int i = 0; i <5; 
i++){displayLine(seven[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '8'){for (int i = 0; i <5; 
i++){displayLine(eight[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == '9'){for (int i = 0; i <5; 
i++){displayLine(nine[i]);delayMicroseconds(delayTime);}displayLine(0);}
    if (character == ' ') {delayMicroseconds(wordBreak);}
    delayMicroseconds(charBreak);
}

void displayLine(int line){
    for(int i = 0; i < 8; i++){
        digitalWrite(LED_PINS[i], bitRead(line, i) ? LOW : HIGH);
    }
}
