#include <iostream>
using namespace std;
int main() {
	int i = 10, j = 30;
	int *p1 = &i; //��const�޶�
	*p1 = 20; //���Ըı�ָ�������ֵ(i-->20)
	p1 = &j;  //���Ըı�ָ��ı���(p1ָ����j)

	//ָ������ָ��
	const int *p2; //const��*ǰ��(Ҳ��дint const *p2)
	p2 = &i;	//p2 ��ָ�� ���Ըı� (��ζ��p2���ǳ���)
	p2 = &j;
	//*p2 = 100; ����,*p2�Ĳ���ֵ(��ζ��*p2�ǳ���)

	//����ָ��(ָ�뱾���ǳ���)
	int * const p3 = &i; //const��*����
	//p3 = &j; ����,p3��ָ���ܸı�(p3�ǳ���)
	*p3 = 100; //OK, *p3�����޸�

	//ָ�����ĳ���ָ��
	const int * const p4 = &i; //����const
	//p4 = &j; ����
	//*p4 = 100; ����
	return 0;
}