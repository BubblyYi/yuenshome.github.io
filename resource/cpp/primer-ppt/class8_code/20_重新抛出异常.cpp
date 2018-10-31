#include <iostream>
using namespace std;
struct Base { int b_data = 10; };
struct Derived:Base { int d_data = 20; };
void f1() {
	try {
		Derived d;
		throw d;
	}
	catch (Derived e) {
		e.b_data = 100; throw;
	}
}
void f2() {
	try {
		Derived d;
		throw d;
	}
	catch (Derived &e) {
		e.b_data = 100; throw;
	}
}
void f3() {
	try {
		Derived d;
		throw d;
	}
	catch (Base &e) {//�Ჶ�����������͵��쳣����
		cout << "f3(Base):---\n";
		e.b_data = 100; 
		//e.d_data = 200; //��,�����������ת��,�ض�
	}
	catch (Derived &e) { cout << "f1(Base):---\n"; }
	catch (...) { cout << "f1(...):---\n"; }
}

int main() {
	try { f1(); }
	catch (Derived e) {
		cout << e.b_data << endl; //����10,û�иı�
	}
	try { f2(); }
	catch (Derived &e) {
		cout << e.b_data << endl; //100,�ı���
	}
	f3();
	return 0;
}
