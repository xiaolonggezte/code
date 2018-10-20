#include<iostream>
#include<cstdio>
using namespace std;


class Node {
//	virtual void func();
	public:
 	int a;
	//char b;
	static int c;
};

class SingleTon {
	private:
	SingleTon(){}
	static SingleTon* instance;
	public:
	static SingleTon* getInstance() {
		if(instance == null) {
			instance = new SingleTon(); 
		}
		return instance;
	}
	static SingleTon* get();
}

SingleTon* SingleTon::get() {

}
int main() {
	Node a = Node();
	cout << sizeof(a) << endl;
    return 0;
}
