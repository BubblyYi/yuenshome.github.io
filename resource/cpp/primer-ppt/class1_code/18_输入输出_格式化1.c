#include <stdio.h>

int main() {
	int a = 12345;
	double f = 123.4567;
	//Ĭ���������
	printf("a=%d===\n", a);
	//ռ8���Ҷ���
	printf("a=%8d===\n", a);
	//ռ8�������
	printf("a=%-8d===\n", a);
	//Ĭ�������������С����ʾ6λ
	printf("f=%f===\n", f);
	//ռ10��С����ʾ2λ���Ҷ���
	printf("f=%10.2f===\n", f);
	//ռ10��С����ʾ2λ�������
	printf("f=%-10.2f===\n", f);

	return 0;
}

