#include <iostream>
using namespace std;
int main() {
	int i = 100;
	int &ref_i = i;	//ok
	//int &ref_i2;	//����(���ñ��뱻��ʼ��)

	//ע����д��ʽ��
	int *a1 = nullptr, a2 = 0;
	//����һ�У�a1��ָ��,a2��int����
	int &r1 = a2, r2 = a2;
	//����һ�У�r1��a2�����ã�r2��int����
	return 0;
}

