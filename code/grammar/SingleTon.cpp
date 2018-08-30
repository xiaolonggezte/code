#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

/**
 * 双重判断加锁
 */
class A {
    public:
    string s;
}
class SingleTon {
    public:
    static A *a;

    A* getInstance() {
        if(a == NULL) {
            // Lock();
            if(a == NULL) {
                a = new A("Hello World");
            }
            // UnLock();
        }
        return a;
    } 
    
}

int main() {
    SingleTon* singleTon = new SingleTon();
    cout << (singleTon -> getInstance() -> s) << endl;
    return 0;
}