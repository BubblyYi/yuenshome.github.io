#include <iostream>
using namespace std;
int main() {
	//static_cast<ת��������>(��Ҫת��������)
	double fd1 = 1.2;
	int i1 = fd1; //��ʽת��,���ȶ�ʧ,�������ᾯ��
	i1 = static_cast<int>(fd1); //��ȷת��,������
	void *vi1 = &i1;
	int* pi1 = (int*)vi1; //cд�� void* --> int*
	pi1 = static_cast<int*>(vi1); //c++д��
	//ע�⣺int* <--> char* ����static_cast
	char *pc1 = (char*)pi1; //cд�� ǿתint*-->char*
	//pc1 = static_cast<char*>(pi1); ����

	//const_cast:
	const int i2 = 10;
	const int *cpi2 = &i2;
	int *pi2 = (int*)cpi2; //cд��
	pi2 = const_cast<int*>(cpi2); //ȥ���ײ�const
	int &ri2 = const_cast<int&>(i2);

	//reinterpret_cast
	int a = 0x00434241;
	int* p = &a;
	char* pc = (char*)p; //cд��
	pc = reinterpret_cast<char*>(p);
	int *pa = (int*)a; //cд��,int-->int*
	pa = reinterpret_cast<int*>(a);

	return 0;
}