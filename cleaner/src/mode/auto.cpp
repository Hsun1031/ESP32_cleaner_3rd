#include "mode/mode.h"

unsigned long auto_time = 0;
int auto_image          = 0;

void auto_mode(Adafruit_SSD1306* _display, int *wifi_mode, const char* esp_ip_address, const char* esp_mdns) {
    if(analogRead(RIGHT_IR) > 3700 || analogRead(LEFT_IR) > 3700) {
        motor_mode1();
        delay(300);
        motor_mode0();
        delay(100);
        motor_mode2();
        delay(500);
        if(analogRead(RIGHT_IR) > analogRead(LEFT_IR)) {
            motor_mode3();
            delay(200);
            while(analogRead(RIGHT_IR) > 3800)
                motor_mode3();
            motor_mode0();
            delay(100);
        } else {
            motor_mode4();
            delay(300);
            while(analogRead(LEFT_IR) > 3800)
                motor_mode4();
            motor_mode0();
            delay(100);
        }
        motor_mode1();
    }

    if((millis() - auto_time) > 2000) {
        switch (auto_image) {
            case 0:
                showLogo(_display, esp_ip_address, esp_mdns);
                auto_image += 1;
                break;
            case 1:
                showAuto(_display, esp_ip_address, esp_mdns);
                auto_image += 1;
                break;
            case 2:
                if(*wifi_mode)
                    showWiFi(_display, esp_ip_address, esp_mdns);
                else
                    showAP(_display, esp_ip_address, esp_mdns);
                auto_image = 0;
                break;
            default:
                auto_image = 0;
                break;
        }
        
        auto_time = millis();
    }
}

void auto_begin() {
    fan_mode(3);
    motor_mode1();
}