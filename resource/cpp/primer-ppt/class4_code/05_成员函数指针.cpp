#include <iostream>
using namespace std;

struct A {
	int add(int a, int b) { cout << "add()" << endl; return a + b; }
	static void show() { cout << "show()" << endl; }
};
void f1(int a, int b) { cout << "f1()" << endl; }
void f2(int a, int b) { cout << "f2()" << endl; }
typedef void(*P_FUN)(int, int);  //typedef ���庯��ָ��
using P_FUN1 = void(*)(int, int);//using ���庯��ָ��

typedef int(A::*P_ADD)(int, int);
using P_ADD1 = int(A::*)(int, int);
int main(){
	void(*p_fun)(int, int) = &f1; //��ͨ����ָ��,��ʡ��&
	p_fun(2, 2); // f1()
	p_fun = &f2;
	p_fun(1, 2); // f2()

	P_FUN p1 = &f1;
	p1(1, 1);  // f1()
	p1 = &f2;
	p1(2, 2);  // f2()

	P_FUN1 p2 = &f1;
	p2(1, 1);  // f1()
	p2 = &f2;
	p2(2, 2);  // f2()

	//�Ǿ�̬��Ա����ָ�룬��������ͨ��������Ҫ������������thisָ��
	int(A::*p_add)(int, int) = &A::add; //�Ǿ�̬��Ա����ָ��
	A a;
	cout << (a.*p_add)(0,2) << endl;     //.* �����ж���,ע������ ���н��add() 2
	A* pa = new A;
	cout << (pa->*p_add)(1, 2) << endl;  //->* //���н��add() 3

	auto p_add1 = &A::add; 
	cout << (a.*p_add1)(2, 2) << endl;	//���н��add() 4

	P_ADD p11 = &A::add;
	cout << (a.*p11)(3, 2) << endl; //���н��add() 5
	P_ADD1 p22 = &A::add;
	cout << (pa->*p22)(2, 4) << endl; //���н��add() 6

	delete pa;

	void(*p_show)() = &A::show; //��̬��Ա����ָ�� ����ͨ����ָ������
	p_show();
	return 0;
}