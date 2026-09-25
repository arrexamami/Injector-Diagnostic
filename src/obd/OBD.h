#pragma once
#include "communication/ICommunication.h"
#include "dtc/DTC.h"
#include <memory>
#include <string>
#include <vector>
namespace injector_diagnostic {enum class ObdPid:unsigned char{EngineRpm=0x0C,CoolantTemperature=0x05,ThrottlePosition=0x11,Map=0x0B,Maf=0x10,O2Sensor=0x14,ControlModuleVoltage=0x42};class OBD{public:explicit OBD(std::shared_ptr<ICommunication>);bool connect();void disconnect()noexcept;bool isConnected()const noexcept;std::vector<std::string> readDtcCodes();bool clearDtc();std::string pidName(ObdPid)const;private:std::shared_ptr<ICommunication> communication_;std::vector<std::string> simulatedDtcs_;};}
