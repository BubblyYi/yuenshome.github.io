#include <iostream>
using namespace std;
int main() {
	//int �� char ת��
	int i = 67;
	char c = 'A'; // 'A'��ascii���� 65
	c = i;
	cout << "c= " << c << endl; //c= C
	c = 'A'; i = c;
	cout << "i= " << i << endl; //i= 65
	c = 'A'; i = 66;
	cout << c + i << endl;//131 (����ʱ��char��תint)
	cout << (i > c) << endl;//1

	return 0;
}

