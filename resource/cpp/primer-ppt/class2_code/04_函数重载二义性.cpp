#include <iostream>
using namespace std;
void f1(int a){}
void f1(float a){}
void f2(long a) {}
void f2(double a){}
int main() {
	//f1(1.2); 
	//�����ԣ�1.2��double����,��int��float����ת��
	//f2(1); 
	//������: 1������,��long��double����ת��
	return 0;
}