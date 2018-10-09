#include <stdio.h>

namespace A {
	int x = 10;
	void print() { printf("A::x=%d\n", x); }
}
namespace B {
	int x = 20;
	void print() { printf("B::x=%d\n", x); }
}

int x = 30;
void print() { printf("x=%d\n", x); }
int main() {
	int x = 40;
	printf("main:x=%d\n", x); //�ֲ�����x 40
	printf("ȫ��:x=%d\n", ::x); //ȫ�ֵ�x 30
	printf("�����ռ�A::x=%d\n", A::x);//A�е�x 10
	printf("�����ռ�B::x=%d\n", B::x);//B�е�x 20
	A::print(); //10
	B::print(); //20
	print();    //30
	return 0;
}

