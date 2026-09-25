#pragma once
#include "dtc/DTC.h"
#include "injector/InjectorTester.h"
#include <string>
#include <vector>
namespace injector_diagnostic {struct DiagnosisStep{std::string stage,result,nextAction;};class Diagnosis{public:std::vector<DiagnosisStep> createWorkflow(const DtcInfo&)const;};}
