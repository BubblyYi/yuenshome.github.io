#include <stdio.h>

namespace A {
	int x = 10, y = 20;
}
int x = 30;
int main() {
	//����A, A�е����ֱ�����ӡ���ȫ��������
	{
		using namespace A;
		y++; //�˴�y�� A::y (ok)
		//x++; //�˴���x������::xҲ������A::x (����)
		::x++; //ָ������ȫ���������x (ok)
		A::x++; //ָ������ A::x (ok)
		int x = 31; //��ǰ�ľֲ�����x (ok)
		x++;  //�˴���x ������ľֲ����� 31 (ok)
	}

	{
		using A::x;
		x++; //�˴���x�� A::x (ok)
	}

	return 0;
}

