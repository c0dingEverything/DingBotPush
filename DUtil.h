#pragma once
#include <string>
#include <Windows.h>
#include "curl.h"
#include <direct.h>
#include <stdio.h>

using namespace std;

string string_To_UTF8(string* str);

void postJson(const char *url,string* body);

void redirectLog();
