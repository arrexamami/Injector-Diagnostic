#pragma once
#include <optional>
#include <string>
#include <vector>
namespace injector_diagnostic {enum class LiveDataParameter{RPM,CoolantTemperature,TPS,MAP,MAF,O2Sensor,BatteryVoltage};struct LiveDataValue{LiveDataParameter parameter;double value;std::string unit;bool simulated;};class LiveData{public:std::vector<LiveDataValue> readAll()const;std::optional<LiveDataValue> read(LiveDataParameter)const;static std::string parameterName(LiveDataParameter);};}
