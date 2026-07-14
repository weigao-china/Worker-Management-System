#include <iostream>
#include <string>
#include "worker.h"
#include "boss.h"


Boss::Boss(int id, std::string name, int did) {
    this->id = id;
    this->name = name;
    this->depid = did;
}

void Boss::showinfo() {
    std::cout << "职工编号：" << this->id
        << "\t职工姓名：" << this->name
        << "\t岗位：" << this->getDeptName()
        << "\t岗位职责：管理公司所有事物" << std::endl;
}

std::string Boss::getDeptName() {
    return std::string("老板");
}
