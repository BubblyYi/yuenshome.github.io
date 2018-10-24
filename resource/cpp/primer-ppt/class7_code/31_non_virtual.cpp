#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = default;
	void f1() { 
		cout << "Base f1()\n";
	}
};
class D1 :public Base {
public:
	void f1() {
		cout << "D1 f1():\n"; 
	}
};

int main() {
	D1 d;
	Base *pb = &d;
	pb->f1(); //Base f1()
	D1 *pd = &d;
	pd->f1(); //D1 f1()
	//���麯������:
	//ͨ����ͬ��ָ�����͵��ý����ͬ��
	//(�﷨û�д���,���Ƕ��û�����˺���)
	//�麯��������ˣ�
	return 0;
}

