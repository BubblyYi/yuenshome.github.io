#include <iostream>
using namespace std;
int main() {
	int *p1 = new int[336870912];
	int *p2 = new int[336870912]; 
	//����ʧ�ܣ��׳��쳣�����������ֹ����
	int *p3 = new (std::nothrow)int[336870912];
	//����ʧ�ܣ�p3==NULL������C�Ĵ���ʽ
	return 0;
}