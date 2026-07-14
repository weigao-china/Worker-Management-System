#pragma once
#include <string>
#include "worker.h"

class Boss : public Worker {
public:
	//构造函数
	Boss(int id, std::string name, int did);

	virtual void showinfo();

	virtual std::string getDeptName();

};
