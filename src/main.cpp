#include "communication/SimulationCommunication.h"
#include "diagnosis/Diagnosis.h"
#include "dtc/DTC.h"
#include "ecu/ECU.h"
#include "injector/InjectorTester.h"
#include "live_data/LiveData.h"
#include "obd/OBD.h"
#include "settings/Settings.h"
#include <iostream>
#include <limits>
#include <memory>
#include <string>
using namespace injector_diagnostic;
namespace {
int readChoice(int min,int max){int value{};while(true){std::cout<<"> ";if(std::cin>>value&&value>=min&&value<=max){std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');return value;}std::cout<<"Invalid input. Enter a number from "<<min<<" to "<<max<<".\n";std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');}}
void showLiveData(const LiveData& liveData){std::cout<<"\n--- LIVE DATA (SIMULATION) ---\n";for(const auto& value:liveData.readAll())std::cout<<LiveData::parameterName(value.parameter)<<": "<<value.value<<" "<<value.unit<<(value.simulated?" [SIMULATED]":"")<<"\n";}
void ecuScan(ECU& ecu,const DtcDatabase& database){std::cout<<"\n--- ECU SCAN (SIMULATION) ---\n";const auto codes=ecu.scan();if(codes.empty()){std::cout<<"No simulated DTCs stored. This is not a real ECU scan.\n";return;}for(const auto& code:codes){const auto info=database.find(code);if(!info){std::cout<<code<<" - Unknown database entry\n";continue;}std::cout<<"\nFault Code: "<<info->code<<"\nDescription: "<<info->description<<"\nSystem: "<<info->system<<"\nPossible Causes:\n";for(const auto& cause:info->possibleCauses)std::cout<<"  - "<<cause<<"\n";std::cout<<"Recommended Checks:\n";for(const auto& check:info->recommendedChecks)std::cout<<"  - "<<check<<"\n";}}
void injectorTest(const InjectorTester& tester){std::cout<<"\n1. Resistance\n2. Pulse Test\n3. Flow Test\n4. Leak Test\n";const auto type=static_cast<InjectorTestType>(readChoice(1,4)-1);const auto result=tester.run(type);std::cout<<InjectorTester::testName(result.type)<<": "<<(result.passed?"PASS":"FAIL")<<" | "<<result.measuredValue<<" "<<result.unit<<"\n"<<result.message<<"\nIMPORTANT: This result is simulated and is not a real injector measurement.\n";}
void diagnosis(const DtcDatabase& database){const auto all=database.all();if(all.empty())return;const Diagnosis engine;std::cout<<"\n--- DIAGNOSIS WORKFLOW (SIMULATION) ---\n";for(const auto& step:engine.createWorkflow(all.front()))std::cout<<"["<<step.stage<<"] "<<step.result<<"\nNext: "<<step.nextAction<<"\n\n";}
void settingsMenu(SettingsManager& manager){const auto& current=manager.get();std::cout<<"\nVehicle: "<<current.vehicle<<"\nECU: "<<current.ecu<<"\nCommunication: "<<current.communication<<"\n1. Change Vehicle\n2. Change ECU\n3. Back\n";const auto choice=readChoice(1,3);if(choice==3)return;std::string value;std::cout<<"Enter new value: ";std::getline(std::cin,value);if(value.empty()){std::cout<<"Value cannot be empty.\n";return;}if(choice==1)manager.setVehicle(value);else manager.setEcu(value);}
}
int main(){auto communication=std::make_shared<SimulationCommunication>();auto obd=std::make_shared<OBD>(communication);ECU ecu(obd);ecu.connect();LiveData liveData;InjectorTester injectorTester;DtcDatabase dtcDatabase;SettingsManager settings;std::cout<<"========================================\n       INJECTOR DIAGNOSTIC v0.1\n       C++17 / SIMULATION MODE\n========================================\n";bool running=true;while(running){std::cout<<"\n1. Live Data\n2. ECU Scan\n3. Injector Test\n4. Diagnosis\n5. Settings\n6. Exit\n";switch(readChoice(1,6)){case 1:showLiveData(liveData);break;case 2:ecuScan(ecu,dtcDatabase);break;case 3:injectorTest(injectorTester);break;case 4:diagnosis(dtcDatabase);break;case 5:settingsMenu(settings);break;case 6:running=false;break;}}ecu.disconnect();std::cout<<"Goodbye.\n";}
