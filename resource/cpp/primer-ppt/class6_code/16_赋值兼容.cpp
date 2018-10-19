#include <iostream>
using namespace std;
class Base {
public:
	Base() = default;
	Base(const Base& other) :b(other.b) 
			{ cout << "Base copy" << endl; }
	void f() { cout << "Base f()" << endl; }
private:
	int b;
};
class D1:public Base  {
public:
	D1() = default;
	D1(const D1& other) :Base(other), d(other.d) 
			{ cout << "D1 copy" << endl; }
	void f() { cout << "D1 f()" << endl; }
private:
	int d;
};
int main() {
	//1.������� �� ��������� ֮�� �Ŀ����븳ֵ
	//ֻ�ܽ���������󿽱���ֵ���������,��֮����
	D1 d1;
	Base b1(d1);  //ok,��ʽ��ʼ��,ִֻ�� Base��������
	Base b2 = d1; //ok,������ʼ��,ִֻ�� Base��������
	b2 = d1;   //ok,���Խ����������ֵ���������
	//d1 = b1; //error,���ܽ��������ֵ�����������
	//[����������������Ȼ���ԣ�����һ�㲻������]
	b1.f(); //Base f()
	d1.f(); //D1 f()

	//2.��������ã����������������ʼ��
	Base &rb1 = d1; //ok,�������� ������������ʼ��
	cout << &rb1 << &d1 << endl; //��ַһ����˵��û����ʱ��
	//D1 &rd1 = b1; //error,���������ò����û�������ʼ��
	rb1.f(); //Base f(),rb1��Base�����ã����Ե���Base��f

	//3.�����ָ�룺ָ�����������
	Base *pb1 = &d1;//ok,����ָ�� ָ�����������
	//D1 *pd1 = &b1;//error,������ָ�벻��ָ��������
	pb1->f(); //Base f(),pb1��Base��ָ�룬���Ե���Base��f
	return 0;
}