#pragma once

#include <windows.h>
#include <iostream>
#include <stdexcept>

#include "pe_sieve_types.h"
#include "scanners/scan_report.h"
#include "postprocessors/report_formatter.h"

static char PESIEVE_VERSION[] = "0.1.6";
static DWORD PESIEVE_VERSION_ID = 0x00010600; // 00 01 06 00
static char PESIEVE_URL[] = "https://github.com/hasherezade/pe-sieve";

std::string info();
ProcessScanReport* scan_process(const t_params args);
