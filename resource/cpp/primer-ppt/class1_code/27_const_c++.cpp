#include <iostream>
using namespace std;
int main() {
	const int i = 10;
	//int *pi = &i; �������(C++�в���)
	const int *pi = &i;	//ok
	//*pi = 20; �������(ָ������ָ���޷��޸ĳ���)

	//���波�ԣ�ǿתת�����޸ĳ�����
	int *pi2 = (int*)&i; //������i�ĵ�ַǿתΪint *
	*pi2 = 20;	 //��pi2ָ��ָ��ĵ�ַ�����޸�Ϊ20
	//�۲� *pi2 �� i ��Ӧ���ڴ��ַ�Ƿ�һ����
	cout << "pi2=" << pi2 << " &i=" << &i << endl;
	//�۲� *pi2 �� i ��ֵ
	cout << "*pi2=" << *pi2 << " i=" << i << endl;
	//��� *pi2=20 i=10
	//˼����Ϊʲô����������Ľ������

	//һ��Ҫ��ô������ô����
	volatile const int ii = 10; //ʹ��volatile�ؼ���
	int *pii = (int*)&ii;
	*pii = 20;
	cout << "*pii=" << *pii << " ii=" << ii << endl;
	//��� *pii=20 ii=20

	return 0;
}