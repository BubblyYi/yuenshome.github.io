#include <iostream>
using namespace std;
class Base {
public:
	Base() { cout << "Base:Ĭ�Ϲ���" << endl; }
	~Base() { cout << "Base:����" << endl; }
};
class D1 :public Base {
public:
	D1() { cout << "D1:Ĭ�Ϲ���" << endl; }
	~D1() { cout << "D1:����" << endl; }
};
class D2 :public D1 {
public:
	D2() { cout << "D2:Ĭ�Ϲ���" << endl; }
	~D2() { cout << "D2:����" << endl; }
};

int main() {
	D2 d2;
	cout << "---------" << endl;
	return 0;
}