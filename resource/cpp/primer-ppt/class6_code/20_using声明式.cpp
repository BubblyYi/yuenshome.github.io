#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	void f() { cout << "Base f()" << endl; }
	void f(double d) { cout << "Base f(double)" << endl; }
	void f(int i, int j) { cout << "Base f(int,int)" << endl; }
};
class D1:public Base  {
public:
	using Base::f;
	int f() { cout << "D1 f()" << endl; return 0; }
	void f(const string &s) { cout << "D1 f(string)" << endl; }
};
int main() {
	Base b1;
	b1.f();    // Base f()
	b1.f(1.2); // Base f(double)
	D1 d1;
	d1.f();    // D1 f() ��D1�е�f()
	d1.f(1.2); // Base f(double) 
	d1.f(1, 2);// Base f(int,int) 
	cout << "----------------" << endl;
	//��̬�����붯̬���Ͳ�ͬʱ��
	Base &rb = d1;
	rb.f();  // Base f()
	rb.f(10.1);// Base f(double)
	//rb.f(string("abc")); //��,Base��û��
	Base *pb = &d1;
	pb->f();	 // Base f()
	pb->f(10.0); // Base f(double)
	//pb->f(string("abc")); //��,Base��û��
	return 0;
}
