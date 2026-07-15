#include <iostream>
#include <vector>
#include <stdio.h> 
#include <locale>
#include <climits>

// ========== 两种类成员函数定义 ==========
class box
{
    public:
    double L = 10;
    double W = 20;
    double H = 35;

    double V(void){
        return L * W * H;
    }
    double are(double L, double W);
    double ae(void);
};

double box::are(double L, double W){
    return L * W;
}

double box::ae(void){
    return L;
}


class parent
{
  
    protected:
    int b = 20;
    private:
    int c = 30;

    public:
    int a = 10;
    parent(){
        a=1;
        b=2;
        c=3;
        std::cout << a << b << c << std::endl;
    }//与类同名函数调用就会执行 
};

class son : public parent
{
public:
void test(void){
    std::cout << a <<  std::endl;
    std::cout <<  b <<  std::endl;
    //std::cout << c << std::endl;
}
};

class gson: protected parent
{
public:
void test(void){
    std::cout << a <<  std::endl;
    std::cout <<  b <<  std::endl;
    //std::cout << c << std::endl;
}
};

class ggson : private parent
{
public:
void test(void){
    std::cout << a <<  std::endl;
    std::cout <<  b <<  std::endl;
    //std::cout << c << std::endl;
}
};

// 父类（基类）
class BaseC
{
public:
    // 虚函数，子类必须重写
    virtual bool initDevice() = 0;
    virtual bool start() = 0;
    virtual ~BaseC() = default;

};





// 核心：纯继承写法，没有任何导出宏
class PCBControl : public BaseC
{
public:
    PCBControl(int num) : val(num) {
        std::cout << "num为" << num << std::endl;
    }

    // override 重写父类虚接口
    bool initDevice() override
    {
        std::cout << "PCB设备初始化成功" << std::endl;
        return true;
    }

    bool start() override
    {
        std::cout << "PCB设备启动，内置参数：" << val << std::endl;
        return true;
    }
private:
    int val;
};





// =================================================================

int add(int x, int y);
using namespace std;

//类作用域
class My{
public:
    static int cha ;
};
int My::cha =25;

int main() {
    

    // 创建子类对象，调用继承并重写的方法
    PCBControl pcbObj(100);
    pcbObj.initDevice();
    pcbObj.start();

    box bc;
    double v = 0;
    v = bc.V();

    box ar;
    double a;
    a = ar.are(3,5);
    // a = ar.ae();

    std::cout <<  v << endl;
    std::cout <<  a << endl;

    parent li;
    std::cout <<  li.a  << endl;

    son lii;
    // lii.a;
    gson liii;

    //li.bark();
  
    ggson liiii;

   

    return 0;
}

int add(int x, int y)
{
    return x + y;
}
