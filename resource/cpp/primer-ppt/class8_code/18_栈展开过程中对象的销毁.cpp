#include <iostream>
using namespace std;

struct A {
	A() { cout << "A ����\n"; }
	~A() { cout << "A ����\n"; }
};
struct B {
	B() { cout << "B---����\n"; }
	~B() { cout << "B---����\n"; }
};
void f2() {
	A a1;
	A a2;
	B* pb1 = new B;
	cout << "f2(): before throw..\n";
	throw 1;
	delete pb1; //����ִ�е�
}
void f1() {
	A a3;
	B* pb2 = new B;
	cout << "--------------\n";
	try {
		f2();
	}
	catch (double e) {
		cout << "f1(): err_double\n";
	}
	catch (const char* e) {
		cout << "f1(): err_char*\n";
	}
	cout << "f1():2\n";
	delete pb2; //������û�б�ִ�е���
}

int main() {
	try {
		f1();
	}
	catch(int e){
		cout << "main(): err_int\n";
	}
	return 0;
}