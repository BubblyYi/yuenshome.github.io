#include <stdio.h>
void fun() {
	static int k = 10; //��ʼ���ľ�̬�ֲ�����(data����rw��)
	static int kk;	   //δ��ʼ����̬�ֲ�����(data����bss��) Ĭ�ϳ�ʼ��Ϊ0
	printf("data: static= %p(rw),%p(bss)\n", &k, &kk);
}
int g_int1, g_int2;	   //δ��ʼ��ȫ�ֱ���(data��bss��)
int g_int3 = 10;	   //��ʼ����ȫ�ֱ���(data��rw��)
char *g_pstr1 = "abc"; //g_pstr1 ��ʼ����ȫ�ֱ���(data��rw��)
					   //"abc" �ַ�������(data��������)
int main() {
	printf("data: global= %p(bss),%p(bss)\n", &g_int1, &g_int2);
	printf("data: global= %p(rw)\n", &g_int3);
	printf("data: global= %p(rw)\n", &g_pstr1);
	printf("data:p_str1ָ��ĵ�ַ��%p(������)\n", g_pstr1);
	printf("data: abc��            %p(������)\n", &"abc");
	printf("code: fun= %p(code)\n", fun);
	fun();
	int i = 10, j = 20;	//ջ��
	printf("ջ��: %p(ջ��),%p(ջ��)\n", &i, &j);
	int *pi = new int(10); //pi��ջ����piָ�������(*pi)�ڶ���
	printf("����: pi %p(����)\n", pi);
	delete pi;
	return 0;
}