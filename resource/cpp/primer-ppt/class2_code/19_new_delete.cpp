#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	int *p1 = (int*)malloc(sizeof(int)); 
	free(p1); //C��malloc��free
	int *p2 = new int; //C++����Ҫ����ת��
	delete p2;         //C++����Ҫsizeof(int)
	//new �� new[]
	//���ٵ������ռ�
	int *p3 = new int; //û��ʼ��,�����
	p3 = new int(10);  //��ʼ��Ϊ 10
	int *p4 = new int{100}; //��ʼ��Ϊ 100
	//��������ռ�
	p4 = new int[10];  //����10��int�ռ�(û��ʼ��)
	p4 = new int[10]{ 1,2 };//��ʼ��,������0��ʼ��
	int **pp = new int*[10]{NULL}; //10�����int*�Ŀռ�
	//delete �� delete []
	delete p3;   // delete ��Ӧ new
	delete[] p4; // delete [] ��Ӧ new []
	delete[] pp;
	return 0;
}