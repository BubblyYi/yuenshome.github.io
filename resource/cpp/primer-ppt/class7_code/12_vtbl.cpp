#include <iostream>
using namespace std;
class Base { 
public:
	void func() { cout << "Base::func()\n"; }
	virtual void f1() { cout << "Base::f1()\n"; }
	virtual void f2() { cout << "Base::f2()\n"; }
};
class D1 :public Base {
public:
	void func1() { cout << "D1::func1()\n"; }
	virtual void f2()override { cout << "D1::f2()\n"; }
};
int main() {
	//class���ɶ����size�����仯,32bit����4
	//(û�����ݳ�Աʱ����ǰ��1,˵�����麯��ʱ����һЩ����)
	cout << sizeof(Base) << "--" << sizeof(D1) << endl;
	Base b;
	int *p_vtbl = reinterpret_cast<int*>(&b); //�ؽ���
	int *vtbl = reinterpret_cast<int*>(*p_vtbl);
	typedef void(*PFUN)();
	PFUN pf1 = reinterpret_cast<PFUN>(vtbl[0]);
	pf1();
	PFUN pf2 = reinterpret_cast<PFUN>(vtbl[1]);
	pf2();
	cout << "-----------------" << endl;
	D1 d;
	p_vtbl = reinterpret_cast<int*>(&d); //�ؽ���
	vtbl = reinterpret_cast<int*>(*p_vtbl);
	pf1 = reinterpret_cast<PFUN>(vtbl[0]);
	pf1();
	pf2 = reinterpret_cast<PFUN>(vtbl[1]);
	pf2();
	return 0;
}