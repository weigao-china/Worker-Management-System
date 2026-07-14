#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
#include <limits>
#include "cfs.hpp"
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


WorkerManager::WorkerManager()
{
	cfs::cppfs(FILENAME, nullptr);

	//判断文件是否存在
	if (!cfs::cin.is_open()) {
		std::cout << "文件不存在" << std::endl;

		//初始化属性
		this->empnum = 0;
		this->empArray = nullptr;
		this->isEmpty = true;
		cfs::closecppfs();
		return;
	}

	//文件存在，判断文件是否为空
	char ch;
	cfs::cin >> ch;
	if (cfs::cin.eof()) {
		std::cout << "文件为空" << std::endl;

		//初始化属性
		this->empnum = 0;
		this->empArray = nullptr;
		this->isEmpty = true;
		cfs::closecppfs();
		return;
	}

	cfs::closecppfs();// 关闭文件流

	int num = this->getNum(); //获取职工人数
	this->empnum = num; //更新职工人数
	this->empArray = new Worker * [this->empnum]; //开辟职工数组
	this->init(); //初始化数据
	this->isEmpty = false; //更新文件不为空
}

void WorkerManager::savefile() {
	cfs::cppfs(nullptr, FILENAME);
	for (int i = 0; i < this->empnum; i++) {
		cfs::cout << this->empArray[i]->id << " "
				  << this->empArray[i]->name << " "
				  << this->empArray[i]->depid << std::endl;
	}
	cfs::closecppfs();
}

int WorkerManager::getNum() {
	cfs::cppfs(FILENAME, nullptr);

	int id;
	std::string name;
	int did;

	int cnt = 0;
	while (cfs::cin >> id >> name >> did) {
		cnt++;
	}

	cfs::closecppfs();
	return cnt;
}

void WorkerManager::init() {
	cfs::cppfs(FILENAME, nullptr);

	int id;
	std::string name;
	int did;

	int idx = 0; //索引位置

	while (cfs::cin >> id >> name >> did) {
		Worker* worker = nullptr;
		switch (did) {  //根据部门编号创建不同类型的职工对象
			case 1: {
				worker = new Employee(id, name, did);
				break;
			}
			case 2: {
				worker = new Manager(id, name, did);
				break;
			}
			case 3: {
				worker = new Boss(id, name, did);
				break;
			}
		}
		this->empArray[idx] = worker; //存放到数组中
		idx++;
	}
	cfs::closecppfs();
}

void WorkerManager::ShowMenu()
{
	std::cout << "**********************************************" << std::endl;
	std::cout << "******* 欢迎使用职工管理系统 开发者:weigao ***" << std::endl;
	std::cout << "**************** 0.退出管理程序 **************" << std::endl;
	std::cout << "**************** 1.增加职工信息 **************" << std::endl;
	std::cout << "**************** 2.显示职工信息 **************" << std::endl;
	std::cout << "**************** 3.删除离职职工 **************" << std::endl;
	std::cout << "**************** 4.修改职工信息 **************" << std::endl;
	std::cout << "**************** 5.查找职工信息 **************" << std::endl;
	std::cout << "**************** 6.按照编号排序 **************" << std::endl;
	std::cout << "**************** 7.清空所有文档 **************" << std::endl;
	std::cout << "**********************************************" << std::endl;
	std::cout << std::endl;
}

void WorkerManager::ExitSystem() {
	std::cout << "确认退出吗？(Y/N)" << std::endl;
	char choice;
	std::cin >> choice;
	if (choice == 'Y') {
		std::cout << "欢迎下次使用！" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3)); //延时3秒
		std::exit(0);
	}
}

void WorkerManager::Add() {
	std::cout << "tips:若输入信息有误，可以稍后修改！" << std::endl;
	std::cout << "请输入增加的职工人数：";
	int n;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "输入有误" << std::endl;
	}
	else {
		int newSize = this->empnum + n; //新空间大小

		Worker** newSpace = new Worker* [newSize]; //创建新空间

		//拷贝旧数据
		if (this->empArray != nullptr) {
			for (int i = 0; i < this->empnum; i++) {
				newSpace[i] = this->empArray[i];
			}
		}

		std::cout << "tips:相同编号的职工会被覆盖！" << std::endl;

		//添加新数据
		for (int i = 0; i < n; i++) {
			int id;
			std::string name;
			int did = 0;

			std::cout << "请输入第 " << i + 1 << " 个新职工编号：";
			std::cin >> id;
			std::cout << "请输入第 " << i + 1 << " 个新职工姓名：";
			std::cin >> name;
			std::cout << "请选择该职工岗位（1.普通员工 2.经理 3.老板）：";
			std::cin >> did;
			while (did != 1 && did != 2 && did != 3) {
				std::cout << "输入有误，请重新选择该职工岗位（1.普通员工 2.经理 3.老板）：";
				std::cin >> did;
			}

			Worker* worker = nullptr;
			switch (did) {
				case 1: {
					worker = new Employee(id, name, did);
					break;
				}
				case 2: {
					worker = new Manager(id, name, did);
					break;
				}
				case 3: {
					worker = new Boss(id, name, did);
					break;
				}
			}

			newSpace[this->empnum + i] = worker;
		}

		//释放原有空间
		delete[] this->empArray;

		//更新新空间指针
		this->empArray = newSpace;

		//更新职工人数
		this->empnum = newSize;

		//保存数据到文件
		this->savefile();

		//更新文件不为空标志
		this->isEmpty = false;

		std::cout << "成功添加 " << n << " 名新职工！" << std::endl;
	}
}

void WorkerManager::ShowEmp() {
	//判断文件是否为空
	if (this->isEmpty) {
		std::cout << "这里空空如也..." << std::endl;
	}
	else {
		for (int i = 0; i < empnum; i++) {
			//调用多态接口显示职工信息
			this->empArray[i]->showinfo();
		}
	}
}

int WorkerManager::find(int id) {
	int idx = -1;
	for (int i = 0; i < this->empnum; i++) {
		if (this->empArray[i]->id == id) {
			idx = i;
			break;
		}
	}
	return idx;
}

void WorkerManager::Del() {
	if (this->isEmpty) {
		std::cout << "何意味？" << std::endl;
	}
	else {
		std::cout << "请输入要删除的职工编号：";
		int id;
		std::cin >> id;

		int idx = this->find(id); //查找职工位置
		if (idx != -1) {
			for (int i = idx; i < this->empnum - 1; i++) {
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empnum--; //更新职工人数

			this->savefile(); //保存文件

			std::cout << "删除成功！" << std::endl;
		}
		else {
			std::cout << "未找到该职工！" << std::endl;
		}
	}
}

void WorkerManager::Mod() {
	if (this->isEmpty) {
		std::cout << "何意味？" << std::endl;
	}
	else {
		std::cout << "请输入要修改的职工编号：";
		int id;
		std::cin >> id;

		int idx = this->find(id); //查找职工位置
		if (idx != -1) {
			delete this->empArray[idx]; //释放原有职工对象

			int id;
			std::string name;
			int did = 0;

			std::cout << "请输入职工新编号：";
			std::cin >> id;
			std::cout << "请输入职工新姓名：";
			std::cin >> name;
			std::cout << "请选择该职工新岗位（1.普通员工 2.经理 3.老板）：";
			std::cin >> did;
			while (did != 1 && did != 2 && did != 3) {
				std::cout << "输入有误，请重新选择该职工新岗位（1.普通员工 2.经理 3.老板）：";
				std::cin >> did;
			}

			Worker* worker = nullptr;
			switch (did) {
				case 1: {
					worker = new Employee(id, name, did);
					break;
				}
				case 2: {
					worker = new Manager(id, name, did);
					break;
				}
				case 3: {
					worker = new Boss(id, name, did);
					break;
				}
			}
			this->empArray[idx] = worker; //更新职工对象

			this->savefile(); //保存文件

			std::cout << "修改成功！" << std::endl;
		}
		else {
			std::cout << "未找到该职工！" << std::endl;
		}
	}
}

void WorkerManager::Find() {
	if (this->isEmpty) {
		std::cout << "何意味？" << std::endl;
	}
	else
	{
		std::cout << "请输入查找方式（1.按职工编号查找 2.按职工姓名查找）：";
		int choice;
		std::cin >> choice;
		while (choice != 1 && choice != 2) {
			std::cout << "请输入重新查找方式（1.按职工编号查找 2.按职工姓名查找）：";
			std::cin >> choice;
		}

		switch (choice) {
			case 1: {
				int id;
				std::cout << "请输入要查找的职工编号：";
				std::cin >> id;

				int idx = this->find(id); //查找职工位置
				if (idx != -1) {
					std::cout << "查找成功！职工信息如下：" << std::endl;
					this->empArray[idx]->showinfo();
				}
				else {
					std::cout << "未找到该职工！" << std::endl;
				}
				break;
			}
			case 2: {
				std::string name;
				std::cout << "请输入要查找的职工姓名：";
				std::cin >> name;

				bool flag = false; //标志是否找到
				for (int i = 0; i < empnum; i++) {
					if (this->empArray[i]->name == name) {
						std::cout << "查找成功！职工信息如下：" << std::endl;
						this->empArray[i]->showinfo();
						flag = true; //不停止查找，继续查找是否有同名职工
					}
				}

				if (flag == false) {
					std::cout << "未找到该职工！" << std::endl;
				}

				break;
			}
		}
	}
}

//排序规则-升序
bool wless(Worker* w1, Worker* w2) {
	return w1->id < w2->id;
}

//排序规则-降序
bool wgreater(Worker* w1, Worker* w2) {
	return w1->id > w2->id;
}

void WorkerManager::Sort() {
	if (this->isEmpty) {
		std::cout << "何意味？" << std::endl;
	}
	else {
		int choice;
		std::cout << "请选择排序方式（1.按职工编号升序 2.按职工编号降序）：";
		std::cin >> choice;
		while (choice != 1 && choice != 2) {
			std::cout << "输入有误，请重新选择排序方式（1.按职工编号升序 2.按职工编号降序）：";
			std::cin >> choice;
		}

		switch (choice) {
		case 1: {
			std::sort(this->empArray, this->empArray + this->empnum, wless);
			break;
		}
		case 2: {
			std::sort(this->empArray, this->empArray + this->empnum, wgreater);
			break;
		}
		}

		this->savefile(); //保存文件

		std::cout << "排序成功！" << std::endl;
		this->ShowEmp(); //显示排序后的职工信息
	}
}

void WorkerManager::Clean() {
	std::cout << "确认清空？此操作不可回退！（Y/N）：";
	char choice;
	std::cin >> choice;

	if (choice == 'Y') {
		//删除数据文件
		remove(FILENAME);
		remove(COMPANY);

		if (this->empArray != nullptr) {
			//删除对象
			for (int i = 0; i < this->empnum; i++) {
				delete[] this->empArray;
				this->empArray = nullptr;
			}

			//删除指针
			delete[] this->empArray;
			this->empArray = nullptr;

			//重置属性
			this->empnum = 0;
			this->isEmpty = true;
		}

		std::cout << "清空成功！请重启！" << std::endl;
		std::cout << "按回车键继续...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		std::exit(0);
	}
}

WorkerManager::~WorkerManager()
{
	if (this->empArray != nullptr) {
		for (int i = 0; i < this->empnum; i++) {
			if (this->empArray[i] != nullptr) {
				delete this->empArray[i];
			}
		}
		delete[] this->empArray;
		this->empArray = nullptr;
	}
}
