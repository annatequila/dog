#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    for (int num : nums) {
        cout << "Number: " << num << endl;  // 断点位置
    }
    return 0;
}