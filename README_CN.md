# 职工管理系统（Worker Management System）

> 📦 **cfstream 官方示例项目**
>
> 本仓库演示了如何使用 **cfstream** 库构建一个简单的面向对象控制台应用程序。

---

## ✨ 项目简介

[English README](README.md)

本项目是 **cfstream** 的官方示例项目，基于现代 C++ 实现了一个简单的职工管理系统。

项目通过一个完整的控制台程序，演示了 **cfstream** 在实际项目中的使用方式，同时展示了面向对象程序设计、多态、文件持久化以及现代 CMake 工程组织等内容。

---

## ✨ 功能特性

- 演示 **cfstream** 的基本使用方法
- 面向对象程序设计
- 继承与运行时多态
- 文件数据持久化
- 跨平台支持
  - Windows
  - macOS
  - Linux
- 使用 CMake 构建

---

## 📚 关于 cfstream

本项目使用 **cfstream**，一个轻量级 C++ 文件流库，用于简化常见的文件输入输出操作。

更多信息请访问 **cfstream** 仓库：

https://github.com/weigao-china/cfstream

---

## 📁 项目结构

```text
Worker-Management-System
├── include/
├── src/
├── CMakeLists.txt
├── LICENSE
├── README_CN.md
└── README.md
```

---

## 🔧 环境要求

- C++17 或更高版本
- CMake 3.20 或更高版本

支持的编译器：

- MSVC
- GCC
- Clang
- Apple Clang

---

## 🚀 构建项目

克隆仓库：

```bash
git clone https://github.com/weigao-china/Worker-Management-System.git
cd Worker-Management-System
```

生成构建文件：

```bash
cmake -S . -B build
```

编译：

```bash
cmake --build build
```

---

## ▶️ 运行

### macOS / Linux

```bash
./build/WorkerManagementSystem
```

### Windows

```powershell
.\build\Debug\WorkerManagementSystem.exe
```

---

## 🎯 学习内容

本项目演示了以下内容：

- C++ 面向对象程序设计
- 类的继承
- 虚函数与运行时多态
- 使用 **cfstream** 进行文件读写
- 现代 CMake 工程组织
- 跨平台 C++ 开发

---

## 🤝 贡献

欢迎提出 Bug 报告或功能建议。

如果你希望改进本项目，可以：

- 提交 Issue
- 提交 Pull Request

---

## 📄 开源协议

本项目基于 **MIT License** 开源。

详细内容请参阅 **LICENSE** 文件。
