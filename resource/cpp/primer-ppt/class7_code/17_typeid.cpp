#include <iostream>
#include <typeinfo>
using namespace std;
class Base {
public:
	virtual ~Base() = default;
private:
	int b = 1;
};
class Derived :public Base {
private:
	int d1 = 2;
};
int main() {
	cout << typeid(int).name() << endl;			//int
	cout << typeid(double).name() << endl;		//double
	cout << typeid(char *).name() << endl;		//char *
	//����const��ʶ��
	cout << typeid(char * const).name() << endl;//char *
	//�ײ�constʶ��
	cout << typeid(const char *).name() << endl;//char const *
	cout << typeid(Base).name() << endl;	//class Base
	cout << typeid(Derived).name() << endl;	//class Derived

	Derived d;
	Base *pb = &d;
	cout << typeid(pb).name() << endl; //class Base * ָ�뿴������ʵ����
	cout << typeid(*pb).name() << endl; //class Derived
	cout << typeid(d).name() << endl; //class Derived
	Base &rb = d;
	cout << typeid(rb).name() << endl; //class Derived

	Base *pb1 = &d;
	Derived *pd1 = &d;
	//1.�ж������������ʵ�����Ƿ�һ��
	if (typeid(*pb1) == typeid(*pd1)) //ע�� ��*
		cout << "����һ��" << endl;
	else
		cout << "���Ͳ�һ��" << endl;
	//2.�ж�ĳ�������ʵ�����Ƿ�ĳ��������
	if(typeid(*pb1)==typeid(Derived))
		cout << "��Derived�����" << endl;
	else
		cout << "����Derived�����" << endl;
	return 0;
}