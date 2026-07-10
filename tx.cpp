#include <iostream>
#include <vector>
#include <stdio.h> 
#include <locale>
#include <climits>
//  ****************************
#include "cir.h"


using namespace std;

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

    return 0;
}