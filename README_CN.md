# Worker Management System / 职工管理系统

A simple cross-platform **Worker Management System** written in modern C++.

一个基于现代 C++ 开发的跨平台职工管理系统示例。

> This project is an example application for **cfstream**. It demonstrates how to use **cfstream** in a practical object-oriented project.
>
> 本项目是 **cfstream** 的官方示例项目，演示如何在实际面向对象项目中使用 **cfstream** 进行文件读写。

---

## ✨ Features / 功能

- Add, delete, modify and search workers.
  - 添加、删除、修改、查找职工信息。
- Display and sort worker information.
  - 显示并排序职工信息。
- Save and load data using **cfstream**.
  - 使用 **cfstream** 保存和读取数据。
- Object-oriented design with inheritance and polymorphism.
  - 使用面向对象设计，实现继承与多态。
- Cross-platform support.
  - 支持跨平台运行。

---

## 📦 Project Structure / 项目结构

```text
Worker-Management-System
├── include/
├── src/
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

## 🛠 Requirements / 环境要求

- C++17 or later
- CMake 3.20 or later

Supported compilers / 支持编译器：

- MSVC
- GCC
- Clang
- Apple Clang

---

## 🚀 Build / 构建

Clone the repository / 克隆仓库：

```bash
git clone https://github.com/weigao-china/Worker-Management-System.git
cd Worker-Management-System
```

Configure / 配置：

```bash
cmake -S . -B build
```

Build / 编译：

```bash
cmake --build build
```

Run / 运行：

### Windows

```powershell
.\build\Debug\WorkerManagementSystem.exe
```

### macOS / Linux

```bash
./build/WorkerManagementSystem
```

---

## 📚 About cfstream / 关于 cfstream

This project uses **cfstream** to simplify file input and output operations.

本项目使用 **cfstream** 简化 C++ 文件输入输出操作。

For more information, please visit the **cfstream** repository.

更多信息请访问 **cfstream** 项目主页。

---

## 🎯 Learning Objectives / 学习内容

This project demonstrates:

本项目演示了以下内容：

- Object-oriented programming / 面向对象程序设计
- Inheritance / 继承
- Runtime polymorphism / 运行时多态
- File persistence using **cfstream** / 使用 **cfstream** 进行文件持久化
- Modern CMake project organization / 现代 CMake 项目组织方式
- Cross-platform C++ development / 跨平台 C++ 开发

---

## 📄 License / 开源协议

This project is licensed under the MIT License.

本项目基于 MIT License 开源。

See the LICENSE file for details.

详细内容请参阅 LICENSE 文件。