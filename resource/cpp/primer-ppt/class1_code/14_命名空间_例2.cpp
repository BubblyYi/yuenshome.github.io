#include <stdio.h>

namespace A {
	int x = 10, y = 20;
}
namespace B {
	int x = 30;
}
int main() {
	{
		using namespace A;
		using namespace B;
		y++; // ok
	}

	{
		using namespace A;
		using namespace B;
		//x++; //A B �ж���x, ������ (����)
	}
	{
		using namespace A;
		int x; //����ֲ����� (ok)
	}

	{
		using A::x;
		//int x; //����
	}

	return 0;
}

