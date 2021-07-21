#include "../WebServer/Metrics.h"

#include "../WebServer/WebServer.h"
#include "../WebServer/HTML_wrappers.h"
#include "../WebServer/Markup.h"
#include "../WebServer/Markup_Buttons.h"


#include "../../ESPEasy-Globals.h"

#include "../Commands/Diagnostic.h"

#include "../DataStructs/RTCStruct.h"

#include "../ESPEasyCore/ESPEasyNetwork.h"
#include "../ESPEasyCore/ESPEasyWifi.h"

#include "../Globals/CRCValues.h"
#include "../Globals/ESPEasy_time.h"
#include "../Globals/ESPEasyWiFiEvent.h"
#include "../Globals/NetworkState.h"
#include "../Globals/RTC.h"

#include "../Helpers/CompiletimeDefines.h"
#include "../Helpers/ESPEasyStatistics.h"
#include "../Helpers/ESPEasy_Storage.h"
#include "../Helpers/Hardware.h"
#include "../Helpers/Memory.h"
#include "../Helpers/Misc.h"
#include "../Helpers/OTA.h"
#include "../Helpers/StringConverter.h"
#include "../Helpers/StringGenerator_GPIO.h"
#include "../Helpers/StringGenerator_System.h"

#include "../Static/WebStaticData.h"

#ifdef USES_MQTT
# include "../Globals/MQTT.h"
# include "../Helpers/PeriodicalActions.h" // For finding enabled MQTT controller
#endif

#ifdef ESP32
# include <esp_partition.h>
#endif // ifdef ESP32


void handle_metrics() {
    int result;
    String resultString;
    resultString.reserve(1000);


    //uptime
    resultString = F("# HELP espeasy_uptime current device uptime in minutes\n");
    resultString += F("# TYPE espeasy_uptime counter\n");        
    resultString += "espeasy_uptime ";
    resultString += getValue(LabelType::UPTIME);       
    resultString += "\n";
  

    //load
    resultString += F("# HELP espeasy_load device percentage load\n");
    resultString += F("# TYPE espeasy_load gauge\n");         
    resultString += "espeasy_load ";
    resultString += getValue(LabelType::LOAD_PCT);     
    resultString += "\n";

    //Free RAM
    resultString += F("# HELP espeasy_free_ram device amount of RAM free in Bytes\n");
    resultString += F("# TYPE espeasy_free_ram gauge\n");    
    resultString += "espeasy_free_ram ";
    resultString += getValue(LabelType::FREE_MEM);   
    resultString += "\n";

    //Free RAM
    resultString += F("# HELP espeasy_free_stack device amount of Stack free in Bytes\n");
    resultString += F("# TYPE espeasy_free_stack gauge\n");     
    resultString += "espeasy_free_stack ";
    resultString += getValue(LabelType::FREE_STACK);  
    resultString += "\n";

    //Wifi strength
    resultString += F("# HELP espeasy_wifi_rssi Wifi connection Strength\n");
    resultString += F("# TYPE espeasy_wifi_rssi gauge\n");   
    resultString += "espeasy_wifi_rssi ";
    resultString += getValue(LabelType::WIFI_RSSI); 
    resultString += "\n";

    //Wifi uptime
    resultString += F("# HELP espeasy_wifi_connected Time wifi has been connected in milliseconds\n");
    resultString += F("# TYPE espeasy_wifi_connected counter\n");    
    resultString += "espeasy_wifi_connected ";
    resultString += getValue(LabelType::CONNECTED_MSEC);
    resultString += "\n";

    //Wifi reconnects
    resultString += F("# HELP espeasy_wifi_reconnects Number of times Wifi has reconnected since boot\n");
    resultString += F("# TYPE espeasy_wifi_reconnects counter\n");   
    resultString += "espeasy_wifi_reconnects ";
    resultString += getValue(LabelType::NUMBER_RECONNECTS); 
    resultString += "\n";



    web_server.send(200, F("text/plain;"), resultString);

}

