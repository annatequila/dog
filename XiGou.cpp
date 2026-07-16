#include <iostream>
 
using namespace std;
// 构造函数与析构函数   实现
// 友元函数  实现
// 调用拷贝构造函数
class Line
{
    private:
    double length;

    int *ptr;

public:
    Line(double length);                        // 构造函数声明
    void   setLength(double len);
    double getLength() ;
    Line( const Line &obj);  

    friend void priF(Line len);
    ~Line(void); // 析构函数是程序结束时 自动执行的
    

};
 

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

// 构造函数定义
Line::Line(double length)
{
    cout << "初始化值 Object is being created of " << length << endl;
    this->length = length; // 
    ptr = new int;        // 给指针分配内存
    *ptr = 0;              // 初始化值
}

 
void Line::setLength(double len)
{
    length = len;
}
 
double Line::getLength() 
{
    return length;
}
 
 Line::~Line(void){
    delete ptr;
    std::cout<< "end" << endl;
 };

 void display(Line obj)
{
   cout << "line 大小 : " << obj.getLength() <<endl;
}

void priF(Line len){
    std::cout << len.length << endl;
}

Line* pr = nullptr;
int* prz = new int;
// 程序的主函数
int main()
{
    Line line(10);
    line.setLength(6);

    cout << "\n===== 演示全局类指针 Line* pr 操作 =====" << endl;
    // ① 先判断空指针，不能直接使用nullptr
    if (pr == nullptr)
    {
        cout << "pr当前是空指针nullptr，不能直接解引用！" << endl;
    }

    pr = &line;

    cout << "Length of pr.line : " << pr->getLength() << endl;

    pr->setLength(32);
    cout << "Length of line : " << line.getLength() << endl;

    priF( line);
    display(line);

    Line* pr1 = new Line(111);


// pr 是外部指针，指向堆上这个Line对象
    Line pr2(112);

    Line* pr3 = pr1;
    //pr3 = pr1;
    
    // pr3->setLength(113);

    cout << "pr1 : " << pr1->getLength() << endl;
    cout << "pr2 : " << pr2.getLength() << endl;


    cout << "pr3 : " << pr3->getLength()  << endl;

    delete pr1;
    return 0;
}