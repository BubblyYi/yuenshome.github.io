#include <iostream>
using namespace std;

int main() {
	//���ȼ��ͽ����
	int n = -10 * 2 + 20 / 2 * 3 - 10; //0
	((((-10) * 2) + ((20 / 2) * 3)) - 10); //0
	int arr[] = { 1,4,5,8 };
	int i1 = *arr + 2;   //3
	int i2 = *(arr + 2); //5

	//����д��:
	int *p = arr;
	*p++; // *(p++), *p Ȼ�� p = p + 1
	*++p; // *(++p) �� p = p + 1, Ȼ�� *p
	
	//��������������д��
	i1 = 0;
	cout << (i1++ + ++i1 - 1) << endl;

	return 0;
}