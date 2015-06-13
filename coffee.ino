#include "coffee.h"
#include "HttpClient.h"

HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    //  { "Content-Type", "application/json" },
    //  { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

int sent = 0;
int buttonPressed = 0;

void setup() {
    Serial.begin(9600);
    pinMode(D0, INPUT);
    pinMode(D7, OUTPUT);
}

void loop() {
    delay(500);

    buttonPressed = digitalRead(D0);
    digitalWrite(D7, buttonPressed);

    if (!sent && buttonPressed) {
        sent = 1;

        Serial.println("sending request...");

        request.hostname = "example.com";
        request.port = 80;
        request.path = "/";

        http.get(request, response, headers);

        Serial.print("Application>\tResponse status: ");
        Serial.println(response.status);

        Serial.print("Application>\tHTTP Response Body: ");
        Serial.println(response.body);
    }
}
