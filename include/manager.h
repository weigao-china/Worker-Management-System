#pragma once
#include <string>
#include "worker.h"

class Manager : public Worker {
public:
	//构造函数
	Manager(int id, std::string name, int did);

	virtual void showinfo();

	virtual std::string getDeptName();

};
