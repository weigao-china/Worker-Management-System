# Worker Management System

> 📦 **Official example project for cfstream**
>
> This repository demonstrates how to build a simple object-oriented application using the **cfstream** library.

**Current version of cfstream in use: V1.4.0**

---

## 📒 Overview

[中文README](README_CN.md)

This project is the official example project for **cfstream**, implemented in modern C++.

It demonstrates how to use **cfstream** in a practical console application while showcasing object-oriented programming, runtime polymorphism, file persistence, and modern CMake project organization.

---

## ✨ Features

- Demonstrates the usage of **cfstream**
- Object-oriented design
- Inheritance and runtime polymorphism
- File persistence
- Cross-platform support
  - Windows
  - macOS
  - Linux
- Built with CMake

---

## 📚 About cfstream

This project uses **cfstream**, a lightweight C++ file stream library designed to simplify common file input and output operations.

For more information, please visit the **cfstream** repository:

https://github.com/weigao-china/cfstream

---

## 📁 Project Structure

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

## 🔧 Requirements

- C++17 or later
- CMake 3.20 or later

Supported compilers:

- MSVC
- GCC
- Clang
- Apple Clang

---

## 🚀 Build

Clone the repository:

```bash
git clone https://github.com/weigao-china/Worker-Management-System.git
cd Worker-Management-System
```

Configure the project:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build
```

---

## ▶️ Run

### macOS / Linux

```bash
./build/WorkerManagementSystem
```

### Windows

```powershell
.\build\Debug\WorkerManagementSystem.exe
```

---

## 🎯 Learning Objectives

This project demonstrates:

- Object-oriented programming
- Class inheritance
- Virtual functions
- Runtime polymorphism
- File persistence using **cfstream**
- Modern CMake project organization
- Cross-platform C++ development

---

## 🤝 Contributing

Contributions are welcome.

If you find a bug or have a suggestion, feel free to:

- Open an Issue
- Submit a Pull Request

---
## 🙏 Acknowledgements

This project was developed with reference to some publicly available courses and learning materials provided by [itheima](http://www.itheima.com/).

It is intended solely for learning, communication, and open-source demonstration purposes. If you believe that any content in this repository infringes upon your legitimate rights or interests, please feel free to contact me. I will promptly review the issue and make appropriate modifications or remove the relevant content if necessary.

---
## 📄 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for more information.
