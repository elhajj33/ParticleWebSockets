#include <WebSocketsServer.h>

WebSocketsServer webSocket = WebSocketsServer(81);

#define USE_SERIAL Serial1

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                //IPAddress ip = webSocket.remoteIP(num);
                //USE_SERIAL.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

				// send message to client
				webSocket.sendTXT(num, "Connected");
            }
            break;
        case WStype_TEXT:
            USE_SERIAL.printf("[%u] get Text: %s\n", num, payload);

            char m[50];
            sprintf(m, "[%u] Particle Got your message of: %s\n", num, payload);
            webSocket.sendTXT(num, m);
            // send message to client
            // webSocket.sendTXT(num, "message here");

            // send data to all connected clients
            // webSocket.broadcastTXT("message here");
            break;
        case WStype_BIN:
            USE_SERIAL.printf("[%u] get binary length: %u\n", num, length);
            //hexdump(payload, length);

            // send message to client
            // webSocket.sendBIN(num, payload, length);
            break;
    }
}

/*Purpose: This is a debug function to publish your LocalIP to the Particle
    console.
3xBotsB*/
char * publishIPAddress (IPAddress address)
{
  char s[16];
  byte oct1 = address[0];
  byte oct2 = address[1];
  byte oct3 = address[2];
  byte oct4 = address[3];

  sprintf(s, "%d.%d.%d.%d", oct1, oct2, oct3, oct4);

  Particle.publish("LocalIP", s);
}

void setup() {
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(9600);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(3000);
    }

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    publishIPAddress (WiFi.localIP());
}

void loop() {
    webSocket.loop();
}
