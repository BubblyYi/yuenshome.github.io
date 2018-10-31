#include <iostream>
using namespace std;
class A {
public:
	A() { cout << "A\n"; }
	~A() { cout << "~A\n"; }
	/*explicit*/ A(const A&) { cout << "��������\n"; }
	A(A&&) { cout << "�ƶ�����\n"; }
	int a = 100;
};
void f1() {
	try {
		A a;
		throw a; // �� explicit �Ŀ�������Ͳ�����
				 //����throw a;�׳��쳣���ʽ,��ִ�п�������(���ƶ�����)
				 //����������쳣����,λ��һ������ռ���(����������)
				 //�쳣������Ϻ󣬸ö������١�
	}
	catch (A e) {
		cout << "f1():----------\n";
	}
}
void f2() {
	try {
		A a;
		throw &a; //�����׳���ָ��ֲ������ָ��
	}
	catch (A* pe) {
		//�˴�pe��ָ��Ķ����Ѿ�����,�����δ�����
		cout << "f2():----------\n";
	}
}
void f3() {
	try {
		throw 1;
	}
	catch (double e) { //����ƥ��(û����ʽת��)
		cout << "f3(double):----\n";
	}
	catch (int e) { //��ȷƥ��
		cout << "f3(int):-------\n";
	}
}
int main() {
	f1();
	f2();
	f3();
	return 0;
}