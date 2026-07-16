
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};



int main() {

    Node* a = new Node{10, nullptr};  //创建对象，并返回这块内存的地址（指针）
    
    // 让a的next存储b的地址
    //a->next = &b;

    // 1. 打印a->next里面存的值：就是b的地址
    cout << "a->next中存放的地址：" << &a << endl;
    cout << "a->next中存放的地址a：" << a->next << endl;

 // 栈上创建节点b
    Node b{11, a->next};

    cout << "节点b的内存地址：" << &b << endl;
    cout << "a->next中存放的地址b：" << b.next << endl;
    
    // 堆上创建节点a
    
    // 2. 通过地址找到b的数据，证明next确实指向b
    // cout << "a->next指向的节点data：" << a->next->data << endl;

    delete a;
  
    return 0;
}

