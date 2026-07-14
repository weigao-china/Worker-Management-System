#pragma once
#include "worker.h"
#define COMPANY "company.txt"
#define FILENAME "worker.txt"

class WorkerManager {   //类声明
public:

	//构造函数
	WorkerManager();

	//保存文件
	void savefile(); 

	//统计文件人数
	int getNum();

	//初始化职工
	void init();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();
	
	//增加职工
	void Add();

	//显示职工
	void ShowEmp();

	//判断职工是否存在并返回位置
	int find(int id);

	//删除职工
	void Del();

	//修改职工
	void Mod();

	//查找职工
	void Find();

	//排序职工
	void Sort();

	//清空文件
	void Clean();

	//析构函数
	~WorkerManager();

	bool isEmpty; //文件是否为空
	int empnum; //记录职工人数
	Worker** empArray; //职工数组指针
};