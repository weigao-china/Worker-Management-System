#pragma once
#include <string>
#include "worker.h"

class Employee : public Worker{
public:
	//构造函数
	Employee(int id, std::string name, int did);

	virtual void showinfo();

	virtual std::string getDeptName();

};
