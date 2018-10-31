#include <iostream>
using namespace std;
struct A { int ai=1;};
struct B { int bi=2;};
class Base1 {
public:
	virtual void f0() { cout << "Base1::f0()\n"; }
	virtual void f1() { cout << "Base1::f1()\n"; }
	virtual void f2() { cout << "Base1::f2()\n"; }
	int i=3;
};
class Base2 {
public:
	virtual void f0() { cout << "Base2::f0()\n"; }
	virtual void f2() { cout << "Base2::f2()\n"; }
	virtual void f3() { cout << "Base2::f3()\n"; }
	int j=4;
};
class D1 :public Base1 {
public:
	virtual void f2()override { cout << "D1::f2()\n"; }
	virtual void f4() { cout << "D1::f4()\n"; }
	A a;
};
class Ok :public D1, public Base2 {
public:
	virtual void f2()override { cout << "Ok::f2()\n"; }
	virtual void f5() { cout << "Ok::f5()\n"; }
	B b;
};
int main() {
	Ok ok;
	Base1 *pb1 = &ok;
	pb1->f0(); //Base1::f0()
	pb1->f1(); //Base1::f1()
	pb1->f2(); //Ok::f2()
	Base2 *pb2 = &ok;
	pb2->f0(); //Base2::f0()
	pb2->f2(); //Ok::f2()
	pb2->f3(); //Base2::f3()
	D1 *pd1 = &ok;
	pd1->f0(); //Base1::f0()
	pd1->f1(); //Base1::f1()
	pd1->f2(); //Ok::f2()
	pd1->f4(); //D1::f4()

	//���麯��,����ʹ��dynamic_cast
	Ok *pok1 = dynamic_cast<Ok*>(pb1);
	Ok *pok2 = dynamic_cast<Ok*>(pb2);
	cout << pok1 << " " << pok2 << endl;
	//dynamic_cast�а�ȫ��֤
	Base2 base2;
	cout << "base2: " << &base2 << endl;
	Ok *pok3 = dynamic_cast<Ok*>(&base2);
	cout << pok3 << endl; // 0 ˵��ת��ʧ��
	Ok *pok4 = static_cast<Ok*>(&base2);
	cout << pok4 << endl; //��0,����ȫ

	cout << sizeof(Ok) << endl; 
	//��ԭ����16��Ϊ24(32λ����)
	//����8�ֽ�,�²���2���麯����ָ��
	cout << "pb1: " << pb1 << endl;
	cout << "pb2: " << pb2 << endl;
	//��ַ���8��Ϊ12(���˸��麯����ָ��)
	return 0;
}

