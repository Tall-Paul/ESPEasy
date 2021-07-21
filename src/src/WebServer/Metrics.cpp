#include "../WebServer/SysInfoPage.h"

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
    addHtml(F("Hellow World"));
}

