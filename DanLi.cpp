#include <iostream>
#include <mutex>


using namespace std;
 
// 单例实现

class Line
{
    private:
    Line();  // 构造函数私有， 无法 Line ad; 无法 Line* = new Line();
    Line(const Line&) = delete; // 
    Line& operator=(const Line&) = delete; 
    /*
    拷贝构造删除，无法复制对象 auto p = DatabaseInterface::getInstance();
    DatabaseInterface db = \*p;

    编译失败，赋值运算符被删除
    DatabaseInterface db2;
    db2 = \*p; // 
    */

    static std::mutex mytex; // C++ 标准互斥锁，作用是 .同一时间只允许一个线程执行被锁住的代码，防止多线程争抢资源引发错乱；
    
    static Line* instance;

    double length =10;

    int *ptr;

public:
    // Line(double length);                        // 构造函数声明
    // void   setLength(double len);
    double getLength() ;

    static Line* getinst();
    
    bool initTable();

    void setLength(int le);

};

void Line::setLength(int le){
    length = le;
};


double Line::getLength() {
    std::cout << "调用get长度"  << std::endl;
    return length;
}

bool Line::initTable(){
    std::cout << "初始化" << std::endl;
    return true;
}

Line* Line::getinst(){   //Line::getinst();Line成员函数定义，返回  Line型指针 instance
    if(instance == nullptr){
        // 加锁，所有线程走到这里要排队
        std::lock_guard < std::mutex > lock(mytex);// 
        // 二次判空，防止阻塞的线程重复创建
        if(instance == nullptr){
            instance = new Line();
        }
    }
    return instance;
}

Line::Line(){
    std::cout << "构造函数" << std::endl;
}

// 类外初始化静态变量
Line* Line::instance = nullptr;
std::mutex Line::mytex;

// 程序的主函数
int main()
{
    
    cout << "pr3 : "  << endl;
    Line* cc = Line::getinst();
    if(!Line::getinst()->initTable()){
        std::cout << "失败" << cc->getLength() << std::endl;
    }

    Line::getinst()->getLength();

    //
    std::cout << Line::getinst()->getLength()  << std::endl;

    Line::getinst()->setLength(80);

    std::cout << Line::getinst()->getLength()  << std::endl;
    return 0;

}