#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <iostream>
#include <Windows.h>
#include <string>
#include "curl.h"
#include "DUtil.h"

using namespace std;


int main()
{
	redirectLog();
	auto configJson = readConfig();

	if (configJson != NULL)
	{
		if (configJson.empty()) {
			fprintf(stderr, "配置文件为空");
			return -1;
		}
		if (!configJson.contains("url")) {
			fprintf(stderr, "url不存在");
			return -1;
		}

		string url = (string)configJson.at("url");
		
		if (url.find("?") == url.npos && url[strlen(url.c_str()) - 1] != '?') {
			url.append("?");
		}

		string param;
		auto jsonParam = configJson.at("param");
		for (json::iterator it = jsonParam.begin(); it != jsonParam.end(); ++it) {
			param.append(it.key().c_str()).append("=");
			if (it.value().is_string()) {
				param.append(escapeURL(it.value()));
			}else{
				param.append(::to_string((int)it.value()));
			}
			param.append("&");
		}

		vector<string> toIds = configJson.at("to_id");
		for (int i = 0; i < toIds.size(); i++) {
			string toId = toIds[i];
			string tempParam = param;
			string tempUrl = url;
			tempParam.append("to_id=").append(toId);
			string empty = "";
			postJson(tempUrl.append(tempParam).c_str(), &empty);
		}
	}
	else
	{
		fprintf(stderr, "配置文件config.json不存在");
		return -1;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
