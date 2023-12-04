#include "../include/HomeController.h"
#include "../include/Lights.h"
#include "../include/Menu.h"
#include "../include/SecuritySystem.h"
#include "../include/SmartDevice.h"
#include "../include/Television.h"
#include "../include/Thermostat.h"
#include "../include/Vacuum.h"
#include <iostream>

using namespace std;

int main() {

    class HomeController homeController;
    homeController.loadConfig();
    homeController.saveConfig();
    homeController.runAutomation();
    homeController.manualOverride();

    class Lights lights;
    lights.testMessage();

    class Menu menu;
    menu.runMenu();

    class SecuritySystem securitySystem;
    securitySystem.getSensitivity();
    securitySystem.getMotionLightsIsOn();
    securitySystem.getAlarmIsOn();
    securitySystem.setSensitivity();
    securitySystem.setMotionLightIsOn();
    securitySystem.setAlarmIsOn();

    class SmartDevice smartDevice;
    smartDevice.activateDevice();
    smartDevice.deavtivateDevice();
    smartDevice.getId();
    smartDevice.getName();
    smartDevice.getStatus();
    smartDevice.getAmSetPoint();
    smartDevice.getPmSetPoint();
    smartDevice.setId();
    smartDevice.setName();
    smartDevice.setSatus();
    smartDevice.setAmSetPoint();
    smartDevice.setPmSetPoint();

    class Television television;
    television.getChannel();
    television.setChannel();

    class Thermostat thermostat;
    thermostat.getCurrentTemp();
    thermostat.setCurrentTemp();

    class Vacuum vacuum;
    vacuum.getBinIsFull();
    vacuum.setBinIsFull();

    return 0;
}