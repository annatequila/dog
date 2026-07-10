#include <iostream>
#include <vector>
#include <stdio.h> 
#include <locale>
#include <climits>
//  ****************************
#include "cir.h"
#include "cir.cpp"
int add(int x, int y);

using namespace std;

    //类作用域
class My{
    public:
    static int cha ;
};
int My::cha =25;

int main() {

    cout << "hollow" << endl;

    double radius = 5;


    printf("半径为%.2f的圆，周长为%.2f,面积为%.2f\n",radius,Cir::lenthOfCircle(radius), 
    Cir::areaOfCircle(radius));

    cout << "半径为" << radius << "的圆," "周长为"<< Cir::lenthOfCircle(radius)<< ",面积为" << Cir::areaOfCircle(radius) << endl;
    std::clog << "Logging: user entered a number." << std::endl; 

    vector<int> nums = {1, 2, 3};
    for (int num : nums) {
        cout << "Number: " << num << endl;  // 断点位置
    }

    std::cout << "The range of int is from " << INT_MIN << " to " << INT_MAX <<

    std::endl;

    std::cout << "The maximum value of unsigned int is " << UINT_MAX <<

    std::endl;

    std::cout << "The range of long long is from " << LLONG_MIN << " to " << LLONG_MAX << std::endl; 

   // int x=0;
   // std::cin >> x;
   // std::cout << x << endl;
    std::cout << add(3,5) <<endl;

    // 匿名函数
   auto add = [](double a, double b) {

    return a + b;

    };

    // 使用 Lambda 表达式计算两个数的和

    double sum = add(10.2, 20.3);

    std::cout << "Sum is: " << sum << std::endl; 
    //内部作用域与外部作用域的区别
     int a = 10;
    {
        int a = 20;  // 块作用域变量
        std::cout << "块变量: " << a << std::endl;
    }
    std::cout << "外部变量: " << a << std::endl;

   
  std::cout << "外部变量: " << My::cha << std::endl;
    return 0;
}