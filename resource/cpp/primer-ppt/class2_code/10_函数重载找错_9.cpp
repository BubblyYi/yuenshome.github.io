#include <iostream>
using namespace std;
void f1(int a, int b) {}
void f1(int a) {}
int main() {
	void f1(int a); //�ڸ�����������������
	//A�е�f1��B�е�f1����������?
	f1(10);
	//f1(10, 20); //����
	return 0;
}

