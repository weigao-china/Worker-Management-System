#include <iostream>
#include <string>
#include "worker.h"
#include "manager.h"


Manager::Manager(int id, std::string name, int did) {
    this->id = id;
    this->name = name;
    this->depid = did;
}

void Manager::showinfo() {
    std::cout << "职工编号：" << this->id
        << "\t职工姓名：" << this->name
        << "\t岗位：" << this->getDeptName()
        << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << std::endl;
}

std::string Manager::getDeptName() {
    return std::string("经理");
}
