#include <stdio.h>

namespace A {
	int x = 10;
	void print() { printf("A::x=%d\n", x); }
}
namespace B {
	int x = 20;
	void print() { printf("B::x=%d\n", x); }
}

int main() {
	{
		//��A::x --> x �� A::print --> print
		using A::x; using A::print;
		printf("x=%d\n", x); //��ʱ��x �� A::x
		print();			 //��ʱ��print�� A::print
	}
	{
		//ȫ����B
		using namespace B;
		printf("x=%d\n", x); //��ʱ��x �� B::x
		print();			 //��ʱ��print�� B::print
	}
	
	using A::x; using A::print; //using��������ǿ��
	using namespace B;   
	printf("x=%d\n", x); //��ʱ��x �� A::x
	print();			 //��ʱ��print�� A::print
	return 0;
}

