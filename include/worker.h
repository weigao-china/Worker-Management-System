#pragma once
#include <string>

//职工抽象类
class Worker {
public:
	Worker() {
		this->id = -1;
		this->name = "";
		this->depid = -1;
	}

	//显示个人信息
	virtual void showinfo() = 0;

	//获取岗位名称
	virtual std::string getDeptName() = 0;

	// 虚析构函数
	virtual ~Worker() {}

	int id; //职工编号
	std::string name; //职工姓名
	int depid; //职工部门编号
};
