#include <iostream>
using namespace std;
int main() {
	const int i = 10;
	//int &ri = i; ����,�ǳ�������ָ����
	int ii = 20;
	const int &rii = ii; //OK
	//rii = 30; ���󣬳��������޷��޸�ֵ

	double fd = 1.23;
	//int &r = fd; ����
	const int &r = fd; //OK
   	 //�۲� fd �� r ��ֵ
	cout << fd << " " << r << endl;
	//�۲� fd �� r �ĵ�ַ
	cout << &fd << endl;
	cout << &r << endl;

	return 0;
}