#include <iostream>
using namespace std;
int main() {
	int a = 1, b = 2, c = 3;

	//OK,ָ������
	int *p_arr[] = { &a,&b,&c };

	//�����������д�������ǲ��е�
	//int &r_arr[] = { a,b,c }; 

	int arr[3] = { a,b,c };
	int(*p1)[3] = &arr; //ok������ָ��
	int(&r1)[3] = arr;  //ok�����������
	return 0;
}