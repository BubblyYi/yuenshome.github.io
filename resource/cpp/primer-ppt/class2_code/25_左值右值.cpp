#include <iostream>
using namespace std;
int main() {
	int a; //a �ĺ���
	a = 10;
	int b;
	b = a + 20; //��ʱ��
	b = a + 20.1;
	int *p = &b;

	//�������͵���ʱ����const����
	//(a + 2) = 10; //Ϊɶ���У�
	int &ra = a; 
	//int &ra1 = a + 2; //Ϊɶ���У�
	const int &cra = a + 2; //ok
	int &&rra = a + 2; //��ֵ����

	++++a; //ok
	//++a++; //����

	return 0;
}