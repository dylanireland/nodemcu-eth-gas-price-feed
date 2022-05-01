# NodeMCU Ethereum Gas Price Feed Display

Arduino C sketch to display the live Ethereum gas price on a TM1637 7-segment display. Connects to wifi, and uses Etherscan's API for querying gas price.

## Supplies

[NodeMCU](https://www.amazon.com/s?k=nodemcu&crid=2UKH19UVPAX12&sprefix=nodemcu%2Caps%2C71&ref=nb_sb_noss_1)

[Display](https://www.amazon.com/s?k=tm1637&sprefix=tm1637%2Caps%2C64&ref=nb_sb_ss_ts-doa-p_1_6)

[Dupont Jumpers](https://www.amazon.com/s?k=dupont+jumper+wires&sprefix=dupont%2Caps%2C72&ref=nb_sb_ss_ts-doa-p_1_6)

## Required Libraries

[TM1637Display](https://github.com/avishorp/TM1637)

[ESP8266Wifi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)

[ESP8266HTTPClient](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)

[ArduinoJson](https://arduinojson.org/)

