#pragma once
#include "obd/OBD.h"
#include <memory>
#include <string>
#include <vector>
namespace injector_diagnostic {class ECU{public:explicit ECU(std::shared_ptr<OBD>);bool connect();void disconnect()noexcept;std::vector<std::string> scan();bool clearFaults();bool isConnected()const noexcept;private:std::shared_ptr<OBD> obd_;};}
