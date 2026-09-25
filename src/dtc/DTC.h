#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
namespace injector_diagnostic { struct DtcInfo{std::string code,description,system;std::vector<std::string> possibleCauses,recommendedChecks;}; class DtcDatabase{public:DtcDatabase();std::optional<DtcInfo> find(const std::string&)const;std::vector<DtcInfo> all()const;private:std::unordered_map<std::string,DtcInfo> entries_;}; }
