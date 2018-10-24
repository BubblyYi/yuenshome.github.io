#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = default;
	void f1(int i=0) { 
		cout << "Base f1():" << i << endl;
	}
	virtual void vf2(int i = 0) { 
		cout << "Base vf2():" << i << endl; 
	}
};
class D1 :public Base {
public:
	void f1(int i=1) {
		cout << "D1 f1():"<<i << endl; 
	}
	virtual void vf2(int i = 1)override{ 
		cout << "D1 vf2():" << i << endl; 
	}
};

int main() {
	Base b;
	b.f1(); //0
	b.vf2();//0
	D1 d;
	d.f1(); //1
	d.vf2();//1
	Base *pb = &d;
	pb->f1(); //0
	pb->vf2();//0 ������Ԥ��: Ĭ�ϲ����� Base::vf2�е�
	D1 *pd = &d;
	pd->f1(); //1
	pd->vf2();//1 ����ʱȷ���ĸ�����,�ĸ�Ĭ�ϲ���
	return 0;
}