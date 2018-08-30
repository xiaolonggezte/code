#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class A {
    int func();
    public:
    int a;
    char b;
    char d;
    char e;
    char f;
    char k;
    static int c;
};
class B {
    char ccc;
    // char d;
    // short b;
    int c;
    // double d;
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    return 0;
}