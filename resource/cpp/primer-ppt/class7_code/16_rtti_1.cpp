#include <iostream>
using namespace std;
class Base {
public:   //����������һ���麯��
	virtual ~Base() = default; 
private:
	int b;
};
class Derived :public Base {
private:
	int d;
};

int main() {
	Derived d1;
	Base *pd1 = &d1;
	//������ָ��ָ��Ķ���תΪ������ָ��ָ��Ķ���
	Derived *p1 = dynamic_cast<Derived*>(pd1); //�ɹ�
	if (p1 != nullptr)
		cout << "ת���ɹ�" << endl;
	else
		cout << "ת��ʧ��" << endl;

	Base b1;
	Base *pb1 = &b1;
	Derived *p2 = dynamic_cast<Derived*>(pb1); //ʧ��
	if (p2 != nullptr)
		cout << "ת���ɹ�" << endl;
	else
		cout << "ת��ʧ��" << endl;

	return 0;
}