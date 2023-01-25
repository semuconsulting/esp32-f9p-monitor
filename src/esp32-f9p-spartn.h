#ifndef _ZED_F9P
#define _ZED_F9P

/*
  Use the NEO-D9S L-Band receiver to provide corrections to a ZED-F9x via UBX-RXM-PMP messages
  By: SparkFun Electronics / Paul Clark
  Based on original code by: u-blox AG / Michael Ammann
  Date: February 7th, 2022
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to obtain SPARTN correction data from a NEO-D9S L-Band receiver and push it over I2C to a ZED-F9x.

  This is a proof of concept to show how the UBX-RXM-PMP corrections control the accuracy.

  If you are using the SparkFun Combo Board (SPX-20167), the correction data is transferred from the NEO to the ZED via UART2.
  You don't need to push it over I2C. Doing so just gives the ZED twice as many correction messages.
  Uncomment the "#define noPush" below to disable the I2C push.

  You will need a Thingstream PointPerfect account to be able to access the SPARTN Credentials (L-Band or L-Band + IP Dynamic Keys).
  Copy and paste the Current Key and Next Key into secrets.h.

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  ZED-F9P RTK2: https://www.sparkfun.com/products/16481
  NEO-D9S:      https://www.sparkfun.com/products/19390
  Combo Board:  https://www.sparkfun.com/products/20167

  Hardware Connections:
  Use Qwiic cables to connect the NEO-D9S and ZED-F9x GNSS to your board
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
*/

//#define noPush // Uncomment this line to disable pushing the correction data over I2C. Useful for the combo board which uses UART2 instead.

#include <Arduino.h>
#include "secrets.h" // <- Copy and paste the Current Key and Next Key into secrets.h
#include <SparkFun_u-blox_GNSS_Arduino_Library.h> //http://librarymanager/All#SparkFun_u-blox_GNSS

SFE_UBLOX_GNSS myGNSS; // ZED-F9x
SFE_UBLOX_GNSS myLBand; // NEO-D9S

//const uint32_t myLBandFreq = 1556290000; // Uncomment this line to use the US SPARTN 1.8 service
const uint32_t myLBandFreq = 1545260000; // Uncomment this line to use the EU SPARTN 1.8 service

#define OK(ok) (ok ? F("  ->  OK") : F("  ->  ERROR!")) // Convert uint8_t into OK/ERROR

void pushRXMPMP(UBX_RXM_PMP_message_data_t *pmpData);

#endif