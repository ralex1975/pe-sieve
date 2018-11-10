
#pragma once

#include <Windows.h>

#include "module_scanner.h"
#include "../utils/util.h"

class MappingScanReport : public ModuleScanReport
{
public:
	MappingScanReport(HANDLE processHandle, HMODULE _module, size_t _moduleSize)
		: ModuleScanReport(processHandle, _module, _moduleSize)
	{
	}

	const virtual void fieldsToJSON(std::stringstream &outs, size_t level = JSON_LEVEL)
	{
		ModuleScanReport::toJSON(outs, level);
		outs << ",\n";
		OUT_PADDED(outs, level, "\"mapped_file\" : \"" << escape_path_separators(this->mappedFile) << "\"");
		outs << ",\n";
		OUT_PADDED(outs, level, "\"module_file\" : \"" << escape_path_separators(this->moduleFile) << "\"");
	}

	const virtual bool toJSON(std::stringstream& outs, size_t level = JSON_LEVEL)
	{
		OUT_PADDED(outs, level, "\"mapping_scan\" : ");
		outs << "{\n";
		fieldsToJSON(outs, level + 1);
		outs << "\n";
		OUT_PADDED(outs, level, "}");
		return true;
	}
	std::string mappedFile;
	std::string moduleFile;
};

//is the mapped file name different than the module file name?
class MappingScanner {
public:
	MappingScanner(HANDLE hProc, ModuleData &moduleData)
		: processHandle(hProc), moduleData(moduleData)
	{
	}

	virtual MappingScanReport* scanRemote();

	HANDLE processHandle;
	ModuleData &moduleData;
};
