#include <iostream>
using namespace std;
int main() {
	//int �� bool ת�� (bool: 1,0)
	int i = 3;
	bool b = true;
	i = b; //boolתint
	cout << "i= " << i << endl; //i=1
	cout << "b= " << b << endl; //b=1
	i = 3;
	b = i;
	cout << "b= " << b << endl; //b=1
	b = 0; //intתbool
	cout << "b= " << b << endl; //b=0

	i = 3; b = true;
	cout << i + b << endl; //4 (bool��תint������)

	i = 3; b = 1;
	cout << (b == i) << (i == b) << endl; //0 0 bool��תint�ٱȽ�
	i = 1; b = 1;
	cout << (i == b) << endl; //1 bool��תint�ٱȽ�

	long long_i = 123L;
	long long llong_i = 1234LL;
	int hex1 = 0xAA;
	int oct1 = 017;
	int dec = 18;
	return 0;
}

