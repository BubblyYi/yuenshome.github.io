#include <iostream>
using namespace std;
struct A { int ai=1;};
struct B { int bi=2;};
class Base1 {
public:
	int i=3;
};
class Base2 {
public:
	int j=4;
};
class D1 :public Base1 {
public:
	A a;
};
class Ok :public D1, public Base2 {
public:
	B b;
};
int main() {
	Ok ok1;
	cout << ok1.b.bi << endl;
	cout << "ok1�ĵ�ַ: " << &ok1 << endl;
	Base1 *pb1 = &ok1;
	cout << "pb1ָ��ĵ�ַ: " << pb1 << endl;
	D1 *pd1 = &ok1;
	cout << "pd1ָ��ĵ�ַ: " << pd1 << endl;
	Base2 *pb2 = &ok1;
	cout << "pb2ָ��ĵ�ַ: " << pb2 << endl;
	cout << "-------------\n";
	Ok * pok1 = static_cast<Ok*>(pb1);
	cout << pok1->b.bi << endl;
	//Ok * pok2 = dynamic_cast<Ok*>(pb1);
	//���У�dynamic_cast�������麯��
	Ok * pok3 = static_cast<Ok*>(pb2);
	cout << "pok3ָ��ĵ�ַ: " << pok3 << endl;
	cout << pok3->b.bi << endl;
	Base2 base2;
	Ok * pok4 = static_cast<Ok*>(&base2);
	cout << "base2��ַ:     " <<&base2 << endl;
	cout << "pok4ָ��ĵ�ַ:" << pok4 << endl;
	cout << pok4->b.bi << endl; //δ����,������δ֪�ڴ�
	return 0;
}

