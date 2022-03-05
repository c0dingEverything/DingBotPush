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
    const char* accessToken = "c290ef58b478e2ad59ac87ec4c347a0dd96c9893669f6653b8e728600032a617";
    char url[1024];
    sprintf_s(url, "https://oapi.dingtalk.com/robot/send?access_token=%s", accessToken);
 //   strcpy(url, "http://127.0.0.1:8080");

    string body1 = "{\"msgtype\":\"actionCard\",\"at\":{\"isAtAll\":\"true\"},\"actionCard\":{\"title\": \"今天您写日报了吗？test\",\"text\":\"![A3F96E70-C0D8-4697-9EFA-ECD509882C5B.png](https://upload-images.jianshu.io/upload_images/1840444-b7f47b1cc82e1073.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)### 日报小助手温馨提示 \n\n 愉快的一天总是过的辣么快，为了不耽误大家准时下班，请及时填写日报！\",\"btnOrientation\":\"1\",\"singleTitle\":\"立即填写\",\"singleURL\":\"dingtalk://dingtalkclient/page/link?url=https%3A%2F%2Flydoa.szlanyou.com%2FLogin.aspx&pc_slide=false\"}}";
    postJson(url,&body1);

    string body2 = "{\"msgtype\":\"text\",\"at\":{\"isAtAll\":\"true\"},\"text\":{\"content\":\"今天您写日报了吗？启辰智联test\"}}";
    postJson(url, &body2);

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
