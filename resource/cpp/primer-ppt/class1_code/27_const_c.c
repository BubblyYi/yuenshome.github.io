#include <stdio.h>
int main() {
	const int i = 10;
	//const int i;	//����const���������ڶ���ʱ��ʼ��
	//i=100;		//����const���Ͳ����޸�
	int *p = &i;	//��i�ĵ�ַ��ֵ��ָ��p( ��C��ok)
	*p = 20;		//ͨ��ָ���޸�const int i��ֵ
	printf("i=%d,*p=%d\n", i, *p); // 20 20
	return 0;
}