#include <iostream>
using namespace std;
void f1(const int a){}
//void f1(int a){} ����,����const
void f2(int * const p) {}
//void f2(int *p){} ����,����const
void f3(const int *p){}
void f3(int *p){} //OK,�ײ�const
void f4(const int &r){}
void f4(int &r){} //OK,�ײ�const

int main() {
	int i = 10;
	int *p1 = &i;
	f3(p1); //���� ��const
	const int *p2 = &i;
	f3(p2);	//���� const
	int &r1 = i;
	f4(r1); //���� ��const
	const int &r2 = i;
	f4(r2);	//���� const
	return 0;
}