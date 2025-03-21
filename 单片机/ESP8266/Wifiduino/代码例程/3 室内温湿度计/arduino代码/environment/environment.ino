#define BLINKER_WIFI

#include <Blinker.h>
#include <DHT.h>

char auth[] = "d8bdba0f8f8d";
char ssid[] = "mostfun";
char pswd[] = "1803808xxxx";

BlinkerNumber HUMI("humi");
BlinkerNumber TEMP("temp");

#define DHTPIN D8

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

float humi_read = 0, temp_read = 0;

void heartbeat()
{
    HUMI.print(humi_read);
    TEMP.print(temp_read);
}

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    BLINKER_DEBUG.debugAll();
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin(auth, ssid, pswd);
    Blinker.attachHeartbeat(heartbeat);
    dht.begin();
}

void loop()
{
    Blinker.run();

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
        BLINKER_LOG("Failed to read from DHT sensor!");
    }
    else
    {
        BLINKER_LOG("Humidity: ", h, " %");
        BLINKER_LOG("Temperature: ", t, " *C");
        humi_read = h;
        temp_read = t;
    }

    Blinker.delay(2000);
}
