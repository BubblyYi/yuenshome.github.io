#include <iostream>
using namespace std;
//C��������
#define max_val_c(a,b) (((a) > (b)) ? (a) : (b))
//C++����,inline��������
inline int max_val(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a1 = 10, a2 = 20;
	int c = max_val_c(a1,a2); //Ԥ����ʱչ��
	int cpp = max_val(a1, a2);	//�������ڱ��������ת��Ϊ int cpp = a1 > a2 ? a1 : a2;
	return 0;
}