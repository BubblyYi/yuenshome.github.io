#include <stdio.h>
#include <stdlib.h>
int a = 0, b, c = 10; // a,b ��data��bss�Σ�c��data��rw��
extern int x;		  //������������û�з����ڴ�
static char ch1, ch2 = 'o';//ch1��data��bss�Σ�ch2��data��rw��
struct A {            //�ṹ�����Ͷ��壬�������ڴ�
	int data;
	int *p_data;
};
int main() {
	char d = 'x';	//ջ��
	static int e;	//data��bss��
	char *p = (char *)malloc(20);//p��ջ����pָ����ڴ��ڶ���
	A a1;				  //ջ��
	a1.p_data = &a1.data; //ָ�뱾�� �� ��ָ����ڴ� ���� ջ��
	A* pa2 = (A*)malloc(sizeof(A));//pa2��ջ����*pa2�ڶ���
	pa2->p_data = (int*)malloc(10 * sizeof(int)); //���ڶ���
	free(pa2->p_data);
	free(pa2);
	return 0;
}