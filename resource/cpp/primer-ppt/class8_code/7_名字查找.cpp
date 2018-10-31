#include <iostream>
using namespace std;
struct A { int ai=1;};
struct B { int bi=2;};
class Base1 {
public:
	void fun() { cout << "Base1::fun()\n"; }
	void fun_1(int i) { cout << "Base1::fun_1(int)\n"; }
	void print() { cout << "Base::print()\n"; }
	int i=3;
};
class Base2 {
public:
	void fun() { cout << "Base2::fun()\n"; }
	void fun_1(const char*) { cout << "Base2::fun_1(const char*)\n"; }
	void print(int i) { cout << "Base2::print(int)\n"; }
	int j=4;
};
class D1 :public Base1 {
public:
	void fun_2(int) {}
	void fun_2(const char*) {}
	A a;
};
class Ok :public D1, public Base2 {
public:
	void print(const char*) { cout << "Ok::Print(const char*)\n"; }
	B b;
};
int main() {
	Ok ok;
	//ok.fun(); //�����Դ���
	//Ok�����������У����� fun()����

	//ok.fun_1(1);    �����Դ���
	//ok.fun_1("abc");�����Դ���
	//��Ȼ���������е�fun_1�����б�ͬ,���ǲ���������
	
	ok.fun_2(1);
	ok.fun_2("abc");
	//ֻ����ͬһ������ͬ����ͬ�����б�ĲŹ�������

	//ok.print();
	//ok.print(1); //�����е�print���������shadow�ˡ�
	ok.print("abc");
	ok.Base2::print(1); //��ʽָ��Base2�е�print

	Base2 *pb = &ok; //����ָ��ָ��������
	pb->fun();
	pb->fun_1("abc");
	pb->print(1);
	//pb->print("abc"); //��
	//pbֻ�ܵ����侲̬�������еĳ�Ա��
	return 0;
}
