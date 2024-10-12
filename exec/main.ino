#include <RF24.h>
#include <SPI.h>
#include <RF24Audio.h>
#include "printf.h"

RF24 radio(7, 8);
RF24Audio rfAudio(radio, 0);
int talkButton = 3;

void setup()
{
  Serial.begin(115200);

  printf_begin();
  radio.begin();
  radio.printDetails();
  rfAudio.begin();

  pinMode(talkButton, INPUT);

  attachInterrupt(digitalPinToInterrupt(talkButton), talk, CHANGE);

  rfAudio.receive();
}

void talk()
{
  if (digitalRead(talkButton))
  {
    rfAudio.transmit();
  }
  else
  {
    rfAudio.receive();
  }
}
void loop()
{
}
