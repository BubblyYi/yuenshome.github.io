#include <iostream>
using namespace std;
class Base {
public:
	virtual ~Base() {
		f2();   //���� this->f2();
		func(); //���� this->func();
		//��������麯����ֻ����ñ���ģ����������������
		cout << "typeid: " << typeid(*this).name() << endl; //Base
	}
	virtual void func() { cout << "Base func()" << endl; }
	void f2() { cout << "Base f2()" << endl; }
private:
	int i;
};
class Derived :public Base {
public:
	virtual ~Derived() {
		f2();
		func();
		cout << "typeid: " << typeid(*this).name() << endl; //Derived
	}
	virtual void func()override { cout << "Derived func()" << endl; }
	void f2() { cout << "Derived f2()" << endl; }
private:
	int j;
};
int main() {
	Derived d1;
	return 0;
}