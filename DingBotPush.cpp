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
		if (!configJson.contains("accessToken")) {
			fprintf(stderr, "accessToken不存在");
			return -1;
		}
		auto token = (string)configJson.at("accessToken");
		int len = strlen( token.c_str()) + 1;
		char* accessToken = (char *)malloc(len);
		memset(accessToken, 0, len);
		strcpy_s(accessToken, len, token.c_str());

		char url[1024];
		sprintf_s(url, "https://oapi.dingtalk.com/robot/send?access_token=%s", accessToken);
		//   strcpy(url, "http://127.0.0.1:8080");
		free(accessToken);
		if (!configJson.contains("messages")) {
			fprintf(stderr, "messages不存在");
			return -1;
		}
		auto messages = configJson.at("messages");
		size_t size = messages.size();
		for (int i = 0; i < size; i++) {
			string body = messages.at(i).dump();
			postJson(url, &body);
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
