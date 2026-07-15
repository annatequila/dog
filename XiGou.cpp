#include <iostream>
 
using namespace std;
 
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



// 程序的主函数
int main()
{
    Line line(10);
 
    // 设置长度
    line.setLength(6.0);
    
    cout << "Length of line : " << line.getLength() << endl;
    priF( line);
    display(line);
    return 0;
}