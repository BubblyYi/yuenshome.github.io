#include <iostream>
using namespace std;
int main() {
	int i = 10, j = 20;
	int *pi = &i; //pi��ָ��i��ָ��
	cout << *pi << " " << i << endl; //*pi �൱�� i
	*pi = 100;
	cout << *pi << " " << i << endl; //ͨ��ָ��ı�ֵ
	pi = &j; //piָ��ָ������������
	cout << *pi << " " << j << endl;

	//��ָ�룺
	//NULL ��c�еĶ����� ((void*)0)
	//NULL ��c++�ж����� 0
	//nullptr ��c++��������ʾ��ָ��
	int *p = nullptr;
	if (p)
		cout << "p is true" << endl;
	else
		cout << "p is false" << endl;
	return 0;
}

