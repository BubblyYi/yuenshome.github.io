#include <iostream>
using namespace std;
int f1() { return 33; }  //ok
//��������һ����,����ʱ int i = f2(); ok
const int f2() { int i = 10; return i; }
int *f3() {
	int *p = new int[3]{ 1,2,3 };
	return p;
}
const int *f4() {
	int *p = new int[3]{ 1,2,3 };
	return p;
}
int &f5() {
	int *p = new int(100);
	return *p;
}
const int &f6() {
	int *p = new int(100);
	cout <<"f6():"<< p << endl;
	return *p;
}
//int &f7() { return 10; } //����
int &f7() { int i = 101; return i; }//����ok,���ǲ���������
const int &f8() { return 102; } //����ok,���ǲ���������

int main() {
	//int *p = f4(); //����
	const int *p = f4(); //������const����
	//int &i = f6(); //����
	const int &i = f6(); //������const����
	const double &pd = f6(); //pd��ջ�ռ���
	cout << &pd << endl; //�����ת����,��ַ��ͬ��
	cout << &p << endl;
	cout << "--------" << endl;
	cout << f7() << endl; //���101 ò��ok 
	int &rf7 = f7();
	cout << rf7 << endl;  //���101 ò��Ҳok
	f1(); //��������һ������
	cout << rf7 << endl;  //���-858.... ����
	//���Բ��ܷ��ؾֲ�����������
	return 0;
}

