#include "Settings.h"
namespace injector_diagnostic {const Settings& SettingsManager::get()const noexcept{return settings_;}void SettingsManager::setVehicle(const std::string& v){if(!v.empty())settings_.vehicle=v;}void SettingsManager::setEcu(const std::string& v){if(!v.empty())settings_.ecu=v;}void SettingsManager::setCommunication(const std::string& v){if(!v.empty())settings_.communication=v;}}
