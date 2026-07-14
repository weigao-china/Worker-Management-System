#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "cfs.hpp"
#include "workerManager.h"

#if defined(_WIN32)
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

void startup() {
	system(CLEAR_CMD);
    //打开文件输入流
    cfs::cppfs(COMPANY, nullptr);

    //检查文件是否存在
    if (!cfs::cin.is_open()) {
        std::cout << "初次使用，请输入公司/团队名称：";
        std::string name;
        std::getline(std::cin, name);  //使用 getline 支持包含空格的名称

        cfs::closecppfs();
        cfs::cppfs(nullptr, COMPANY);  //打开文件输出流

		cfs::cout << name << std::endl; //将公司名称写入文件
        std::cout << "初始化成功！请重启程序！" << std::endl;

		std::cout << "按回车键继续...";
		std::cin.get();
		std::exit(0); //退出
    }
    else {
        std::string name;
        std::getline(cfs::cin, name);  //从文件读取整行作为公司名称

		std::cout << "欢迎使用 " << name << " 职工管理系统！" << std::endl;

		std::cout << "按回车键继续...";
		std::cin.get();
		std::system(CLEAR_CMD); //清屏
    }
}

int main()
{
    startup(); //初始化
    cfs::closecppfs(); //关闭文件流

	WorkerManager wm; //创建管理者对象

    int choice = -1;

    while (true) {
        wm.ShowMenu(); //调用展示菜单
        std::cout << "请输入您的选择：";
        std::cin >> choice; //接受选择

        switch (choice) {
            case 0: { //退出系统
                wm.ExitSystem();
                break;
            }
            case 1: { //增加职工
                wm.Add();
                break;
            }
            case 2: { //显示职工
				wm.ShowEmp();
                break;
            }
			case 3: { //删除职工
                wm.Del();
                break;
            }
			case 4: { //修改职工
                wm.Mod();
                break;
            }
			case 5: { //查找职工
                wm.Find();
                break;
            }
			case 6: { //排序职工
                wm.Sort();
                break;
            }
			case 7: { //清空文档
                wm.Clean();
                break;
            }
            default: {
				std::cout << "输入有误，请重新输入！" << std::endl;
				break;
            }
        }
		std::cout << "按回车键继续...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		std::system(CLEAR_CMD);
    }
    
	return 0;
}
