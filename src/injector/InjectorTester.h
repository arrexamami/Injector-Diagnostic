#pragma once
#include <string>
#include <vector>
namespace injector_diagnostic {enum class InjectorTestType{Resistance,Pulse,Flow,Leak};struct InjectorTestResult{InjectorTestType type;bool passed;double measuredValue;std::string unit,message;bool simulated;};class InjectorTester{public:InjectorTestResult run(InjectorTestType)const;static std::string testName(InjectorTestType);};}
