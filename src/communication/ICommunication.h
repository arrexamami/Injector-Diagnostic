#pragma once
#include <cstdint>
#include <string>
#include <vector>
namespace injector_diagnostic {class ICommunication{public:virtual~ICommunication()=default;virtual bool open()=0;virtual void close()noexcept=0;virtual bool isOpen()const noexcept=0;virtual std::vector<std::uint8_t> request(const std::vector<std::uint8_t>&)=0;virtual std::string name()const=0;};}
