#include <user_config.h>
#include <SmingCore/SmingCore.h>

// If you want, you can define WiFi settings globally in Eclipse Environment Variables
#ifndef WIFI_SSID
	#define WIFI_SSID "aconex-internet" // Put you SSID and Password here
	#define WIFI_PWD "acx2017weputourclientsfirst"
#endif

Timer procTimer;
int sensorValue = 0;
HttpClient thingSpeak;

void onDataReceived(HttpClient& client, bool successful)
{
	if (successful)
		Serial.println("Success Received");
	else
		Serial.println("Failed");

	String response = client.getResponseString();
	Serial.println("Server response: '" + response + "'");
}

void sendData()
{
	if (thingSpeak.isProcessing()) return; // We need to wait while request processing was completed

	// Read our sensor value :)
	sensorValue++;

	thingSpeak.downloadString("http://google.com.au", onDataReceived);
}

// Will be called when WiFi station was connected to AP
void connectOk()
{
	Serial.println("I'm CONNECTED");

	// Start send data loop
	procTimer.initializeMs(25 * 1000, sendData).start(); // every 25 seconds
}

// Will be called when WiFi station timeout was reached
void connectFail()
{
	Serial.println("I'm NOT CONNECTED. Need help :(");

	// Start soft access point
	WifiAccessPoint.enable(true);
	WifiAccessPoint.config("CONFIG ME PLEEEEASE...", "", AUTH_OPEN);

	// .. some you code for configuration ..
}

void init()
{
	spiffs_mount(); // Mount file system, in order to work with files

	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(false); // Disable debug output to serial

	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.enable(true);
	WifiAccessPoint.enable(false);

	// Run our method when station was connected to AP (or not connected)
	WifiStation.waitConnection(connectOk, 20, connectFail); // We recommend 20+ seconds for connection timeout at start
}
