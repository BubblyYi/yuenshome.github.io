#include <iostream>
using namespace std;

int g_i = 10;
int main() {
	static int s_i = 20;
	int i1 = 10;
	auto f1 = [] {
		cout << g_i << s_i << endl; //ȫ��,static����������
		//cout << i1 << endl; �ò���i1
	};
	f1(); //���10 20
	auto f2 = [i1](int i) {
		cout << i1 << i <<endl; //ֵ����
	};
	i1 = 100;
	f2(0); //��� 10 0, �˴�ע�⣺i1�Ƕ���lambdaʱ��i1,ֵ����
	auto f3 = [&i1] {cout << i1 << endl; }; //���ô���
	i1 = 20;
	f3(); //���20 ���ô���
	int i2 = 30;
	[&] {cout << i1 << i2 << endl; }(); //ֱ��ȫ�����þֲ�����
	//��� 20 30
	return 0;
}

