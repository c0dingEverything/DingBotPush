#pragma once
#include <string>
#include <Windows.h>
#include "curl.h"
#include <direct.h>
#include <stdio.h>
#include <io.h>
#include <iostream>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

string escapeURL(const string& URL);

string deescapeURL(const string& URL);

string UTF8_To_String(const std::string& s);

string string_To_UTF8(string* str);

void postJson(const char *url,string* body);

void redirectLog();

struct json::basic_json readConfig();
