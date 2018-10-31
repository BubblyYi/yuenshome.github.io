#include <iostream>
using namespace std;

class Base {
public:
	int x=1;
};
class D1 :virtual public Base {
public:
	int i=2;
};
class D2 :virtual public Base {
public:
	int j=3;
};
class Ok :public D1, public D2 {
public:
	int k=4;
};
int main() {
	cout << "Base�ߴ�: " << sizeof(Base) << endl; //4
	cout << "  D1�ߴ�: " << sizeof(D1) << endl;   //12
	cout << "  D2�ߴ�: " << sizeof(D2) << endl;   //12
	cout << "  Ok�ߴ�: " << sizeof(Ok) << endl;   //24
	cout << "----------------\n";
	D1 d1;
	cout << "d1��ַ: " << &d1 << endl;
	cout << " i��ַ: " << &d1.i << endl;
	cout << " x��ַ: " << &d1.x << endl;
	//�۲�d1����ǰ��4���ֽ�, ָ���������ָ�� vbptr
	int *p = (int*)(&d1);
	int *p1 = (int*)(*p);
	cout << p1[0] << endl;
	cout << p1[1] << endl; //8 (ƫ����)
	cout << "----------------\n";
	Ok ok;
	cout << "  ok��ַ: " << &ok << endl;
	Base *pb = &ok;
	cout << "Base��ַ: " << pb << endl;
	D1 *pd1 = &ok;
	cout << "  D1��ַ: " << pd1 << endl;
	D2 *pd2 = &ok;
	cout << "  D2��ַ: " << pd2 << endl;
	cout << " x��ַ: " << &ok.x << endl;
	cout << " i��ַ: " << &ok.i << endl;
	cout << " j��ַ: " << &ok.j << endl;
	cout << " k��ַ: " << &ok.k << endl;
	return 0;
}


