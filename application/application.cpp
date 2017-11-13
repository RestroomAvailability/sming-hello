#include <SmingCore/SmingCore.h>

void connectOk(IPAddress ip, IPAddress mask, IPAddress gateway) {
    Serial.println("I'm CONNECTED");
    Serial.println(ip.toString());
}

void init() {
    Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
    Serial.systemDebugOutput(false);

    // Station - WiFi client
    WifiStation.enable(true);  
    WifiStation.config("your-wifi-ssid", "your-ssid-password"); // Put you SSID and Password here

    // Set callback that should be triggered when we have assigned IP
    WifiEvents.onStationGotIP(connectOk);
    Serial.println("I'm awake again!");
}
