#include <iostream>
#include <string>
#include "worker.h"
#include "employee.h"


Employee::Employee(int id, std::string name, int did) {
	this->id = id;
	this->name = name;
	this->depid = did;
}

void Employee::showinfo() {
	std::cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << std::endl;
}

std::string Employee::getDeptName() {
	return std::string("员工");
}
