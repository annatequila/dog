/***********************************************************
  > File Name: ZhiZhen.cpp
  > Author: https://www.baidu.com/
  > Mail: 1xxxxxx@qq.com
  > Created Time: 2026-07-17 08:24:58
 *******************************************************/

#include <iostream>

using namespace std;

int a = 1, b = 2, c =3;

int *p[3] = {&a, &b, &c};


void PtZhiZhen(){
    cout << &p[0] << endl;
    cout << &p[1] << endl;
    cout << &p[2] << endl;


    cout << "hello..." << endl;

    cout << p[0] << endl;
    cout << p[1] << endl;
  

    cout << "a地址..." << endl;

    cout << &a << endl;
    cout << &b << endl;;
}



//==========回调函数==========
using Callback = void (*)(int);

// 接收函数指针作为参数
void handleData(int data, Callback cb)
{
    cout << "处理数据：" << data << endl;
    // 回调外部传入的函数
    cb(data);
}

void logInfo(int val)
{
    cout << "日志记录：" << val << endl;
}

//==================函数指针======================
void func1() { cout << "功能1" << endl; }
void func2() { cout << "功能2" << endl; }
void func3() { cout << "功能3" << endl; }

void (*funcTable[3])() = {func1, func2, func3};

int main() {
    
    cout << "普通指针" << endl;
    PtZhiZhen();

    cout << "回调函数" << endl;

    handleData(666, logInfo);

    cout << "函数指针" << endl;

    funcTable[1]();

    return 0;
}




