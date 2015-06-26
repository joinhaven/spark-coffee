#include "coffee.h"
#include "HttpClient.h"
#include "env_vars.h"

HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    { "Content-Type", "application/json" },
    { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers with NULL
};

http_request_t request;
http_response_t response;

int postedBrewingMessage = 0;
int buttonPressed = 0;
int loopDelayInMilliseconds = 100; // in milliseconds
int iterationsSinceBrewingSent = 0;

void setup() {
    Serial.begin(9600);
    pinMode(D0, INPUT);
    pinMode(D7, OUTPUT);
}

void loop() {
    if (!postedBrewingMessage) {
        // light up the LED when we have pressed it
        // but only if we haven't pressed the button recently
        buttonPressed = digitalRead(D0);
        digitalWrite(D7, buttonPressed);

        if (buttonPressed) {
            postedBrewingMessage = 1;
            iterationsSinceBrewingSent = 0;

            Serial.println("posting 'brewing'...");

            request.hostname = SERVER_HOSTNAME;
            request.path = BREWING_PATH;

            http.post(request, response, headers);

            Serial.print("Application>\tResponse status: ");
            Serial.println(response.status);

            Serial.print("Application>\tHTTP Response Body: ");
            Serial.println(response.body);
        }
    }

    if (postedBrewingMessage) {
        iterationsSinceBrewingSent++;

        // flash to say that we got your message
        digitalWrite(D7, iterationsSinceBrewingSent % 4 == 0);

        // takes ten minutes to brew coffee, send ready message then
        if (iterationsSinceBrewingSent >= 1000 * 60 * 10 / loopDelayInMilliseconds) {
            Serial.println("posting 'ready'...");

            request.hostname = SERVER_HOSTNAME;
            request.path = READY_PATH;

            http.post(request, response, headers);

            Serial.print("Application>\tResponse status: ");
            Serial.println(response.status);

            Serial.print("Application>\tHTTP Response Body: ");
            Serial.println(response.body);

            // reset the loop so we can send again
            postedBrewingMessage = 0;

            // clear the LED status
            digitalWrite(D7, 0);
        }
    }

    delay(loopDelayInMilliseconds);
}
