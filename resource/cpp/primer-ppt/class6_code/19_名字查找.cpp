#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	void f() { cout << "Base f()" << endl; }
	void f(double d) { cout << "Base f(double)" << endl; }
};
class D1:public Base  {
public:
	void f(int i) { cout << "D1 f(int)" << endl; }
	void f(const string &s) { cout << "D1 f(string)" << endl; }
private:
	void f(short i) { cout << "D1 f(short)" << endl; }
};
int main() {
	Base b1;
	b1.f();  // Base f()
	b1.f(1.2); // Base f(double)
	D1 d1;
	d1.f(10);// D1 f(int)
	
	//d1.f(static_cast<short>(10)); //��,private�����޷�����
	//d1.f(); //��,Base�̳�������f()������(shadow)
	d1.Base::f(); //Ҫ����Base��f(),Ҫ��Base::
	d1.Base::f(1);//Base f(int)

	//��̬�����붯̬���Ͳ�ͬʱ��
	Base &rb = d1;
	rb.f();  // Base f()
	rb.f(10);// Base f(double) ��ʽת��10->10.0
	//rb.f(string("abc")); //��,Base��û��
	Base *pb = &d1;
	pb->f();	 // Base f()
	pb->f(10.0); // Base f(double)
	//pb->f(string("abc")); //��,Base��û��
	return 0;
}