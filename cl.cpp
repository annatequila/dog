/***********************************************************
  > File Name: cl.cpp
  > Author: https://www.baidu.com/
  > Mail: 1xxxxxx@qq.com
  > Created Time: 2026-07-10 11:24:08
 *******************************************************/

#include <iostream>

// 常量定义为大写字母
#define Max  78
#include "cir.h"


class MyClass {
public:
    static int class_var;  // 类作用域变量
};


int op = 1;


int MyClass::class_var = 30;

int main() {
    std::cout << "类变量: " << MyClass::class_var << std::endl;
    std::cout << "类变量: " << Max << std::endl;
    
    std::cout << MXa << std::endl;

    op = 3503; //新建了局部变量

    std::cout << op << std::endl;
    return 0;
}
