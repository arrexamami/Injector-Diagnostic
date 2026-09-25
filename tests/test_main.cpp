#include "dtc/DTC.h"
#include "injector/InjectorTester.h"
#include "live_data/LiveData.h"
#include "communication/SimulationCommunication.h"
#include <cassert>
#include <memory>
using namespace injector_diagnostic;
int main(){DtcDatabase db;assert(db.find("p0100").has_value());assert(db.find("P9999")==std::nullopt);LiveData live;const auto values=live.readAll();assert(values.size()==7);assert(values.front().simulated);InjectorTester tester;const auto result=tester.run(InjectorTestType::Resistance);assert(result.simulated);assert(result.passed);auto communication=std::make_shared<SimulationCommunication>();assert(!communication->isOpen());assert(communication->open());assert(communication->isOpen());assert(communication->request({1,2,3}).size()==3);communication->close();assert(!communication->isOpen());}
