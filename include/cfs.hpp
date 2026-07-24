/*
 * @repository cfstream
 * @file cfs.hpp
 * @language C++
 * @author weigao (https://github.com/weigao-china)
 * @version 1.4.0
 * @date 2026-7-24
 *
 * @copyright 2026 weigao
 * @license MIT

MIT License

Copyright (c) 2026 weigao

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#pragma once

#ifndef CFS_H_CPP
#define CFS_H_CPP

#include <fstream>
#include <cstdio>
#include <iostream>

#if __cplusplus >= 201103L
#define CFS_NULLPTR nullptr
#else
#define CFS_NULLPTR NULL
#endif

#if defined(_WIN32) || defined(_WIN64)
#define CFS_STDIN_DEVICE "CON"
#define CFS_STDOUT_DEVICE "CON"
#else
#define CFS_STDIN_DEVICE "/dev/tty"
#define CFS_STDOUT_DEVICE "/dev/tty"
#endif

namespace cfs {
    static std::ifstream cin;
    static std::ofstream cout;

#if __cplusplus >= 201103L
    static constexpr const char* versionnumber = "1.4.0";
#else
    static const char* versionnumber = "1.4.0";
#endif

    static inline const char* getversion() {
        return versionnumber;
    }

    static inline void cfs(const char* input, const char* output) {
        if (input != CFS_NULLPTR) {
            std::fflush(stdin);
            if (std::freopen(input, "r", stdin) == CFS_NULLPTR) {
                std::cerr << "Error-from-cfs Failed to open input file: " << input << std::endl;
            }
        }
        if (output != CFS_NULLPTR) {
            std::fflush(stdout);
            if (std::freopen(output, "w", stdout) == CFS_NULLPTR) {
                std::cerr << "Error-from-cfs Failed to open output file: " << output << std::endl;
            }
        }
    }

    static inline void cppfs(const char* input, const char* output) {
        if (cin.is_open() || cout.is_open()) {
            std::cerr << "Error-from-cfs Already open cppfs, please close first!" << std::endl;
            return;
        }

        if (input != CFS_NULLPTR) {
            cin.open(input);
            if (!cin.is_open()) {
                std::cerr << "Error-from-cfs Failed to open input file: " << input << std::endl;
            }
        }

        if (output != CFS_NULLPTR) {
            cout.open(output);
            if (!cout.is_open()) {
                std::cerr << "Error-from-cfs Failed to open output file: " << output << std::endl;
            }
        }
    }

    static inline void closecfs() {
        std::fflush(stdin);
        std::fflush(stdout);

        if (std::freopen(CFS_STDIN_DEVICE, "r", stdin) == CFS_NULLPTR) {
            std::cerr << "Error-from-cfs Failed to restore stdin" << std::endl;
        }
        if (std::freopen(CFS_STDOUT_DEVICE, "w", stdout) == CFS_NULLPTR) {
            std::cerr << "Error-from-cfs Failed to restore stdout" << std::endl;
        }
    }

    static inline void closecppfs(){
        if (cin.is_open()) cin.close();
        if (cout.is_open()) cout.close();
        cin.clear();
        cout.clear();
    }
}

#undef CFS_NULLPTR
#undef CFS_STDIN_DEVICE
#undef CFS_STDOUT_DEVICE

#endif // CFS_H_CPP