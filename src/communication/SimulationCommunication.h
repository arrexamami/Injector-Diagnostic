#pragma once
#include "ICommunication.h"
namespace injector_diagnostic {class SimulationCommunication final:public ICommunication{public:bool open()override;void close()noexcept override;bool isOpen()const noexcept override;std::vector<std::uint8_t> request(const std::vector<std::uint8_t>&)override;std::string name()const override;private:bool open_{false};};}
