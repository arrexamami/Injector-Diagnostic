#pragma once
#include <string>
namespace injector_diagnostic {struct Settings{std::string vehicle="Simulation Vehicle",ecu="Simulation ECU",communication="Simulation";};class SettingsManager{public:const Settings& get()const noexcept;void setVehicle(const std::string&);void setEcu(const std::string&);void setCommunication(const std::string&);private:Settings settings_;};}
