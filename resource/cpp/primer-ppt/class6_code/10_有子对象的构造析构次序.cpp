#include <iostream>
using namespace std;
class A { //��Ĭ�Ϲ���
public:
	A() { cout << "A����" << endl; }
	~A() { cout << "A����" << endl; }
};
class B { //û��Ĭ�Ϲ���
public:
	B(int i) { cout << "B����" << endl; }
	~B() { cout << "B����" << endl; }
};
class Base {
public:
	Base(int i) :b(set_b(i)), bb(A()) //����bb(A())����ʡ��
					  {	cout << "Base:����" << endl;	}
	~Base() { cout << "Base:����" << endl; }
	int set_b(int i) { cout << "b1��ʼ��" << endl; return i; }
private:
	int b;
	A bb;
};
class D1 :public Base {
public:
	D1(int i) :d(set_d(i)), Base(i), dd(B(i))
						{ cout << "D1:����" << endl; }
	~D1() { cout << "D1:����" << endl; }
	int set_d(int i) { cout << "d��ʼ��" << endl; return i; }
private:
	int d;
	B dd;
};
int main() {
	D1 d1(1);
	cout << "---------" << endl;
	return 0;
}