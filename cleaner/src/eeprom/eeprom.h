/**
 *  0  ~  24 -> SSID
 *  25 ~  49 -> Password
 *  50 ~  74 -> AP SSID
 *  75 ~  99 -> AP Password
 * 100 ~ 124 -> ESP32 MDNS Name
 * 125 ~ 149 -> GitHub Token
 * 150 ~ 174
 * 175 ~ 199
 * 200 ~ 224
 * 225 ~ 249
 * 250 ~ 254
 */

#include <Arduino.h>
#include <EEPROM.h>

#include "conf/authentication.h"
#include "conf/conf.h"

#define EEPROM_SSID_START        0
#define EEPROM_SSID_END         24

#define EEPROM_PASSWD_START     25
#define EEPROM_PASSWD_END       49

#define EEPROM_AP_SSID_START    50
#define EEPROM_AP_SSID_END      74

#define EEPROM_AP_PASSWD_START  75
#define EEPROM_AP_PASSWD_END    99

#define EEPROM_MDNS_START      100
#define EEPROM_MDNS_END        124

#define EEPROM_TOKEN_START     125
#define EEPROM_TOKEN_END       149

/**
 * eeprom.cpp
 * 
 */
bool eeprom_setup    (char** ssid, char** passwd, char** esp_mdns);

bool set_esp_mdns    (const char*  mdns);
bool set_github_token(const char*  token);
bool get_esp_mdns    (char** mdns);
bool get_github_token(char** token);

/**
 * eeprom_sta.cpp
 * 
 */
bool set_ssid  (const char*  ssid);
bool set_passwd(const char*  passwd);
bool get_ssid  (char** ssid);
bool get_passwd(char** passwd);

/**
 * eeprom_ap.cpp
 * 
 */
bool set_ap_ssid  (const char*  ssid);
bool set_ap_passwd(const char*  passwd);
bool get_ap_ssid  (char** ssid);
bool get_ap_passwd(char** passwd);

/**
 * eeprom_data.cpp
 * 
 */
bool set_eeprom_data(int start, int end, uint8_t*  data);
bool get_eeprom_data(int start,          uint8_t** data);

bool is_eeprom_data(int start);

void show_eeprom_data(bool toChar);
void clean_eeprom_data();
