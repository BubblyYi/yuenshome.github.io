#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int a = 12345;
	double f = 123.4567;
	//Ĭ���������
	cout << "a=" << a << "===" << endl;
	//ռ8���Ҷ���
	cout << "a=" << setw(8) << a << "===" << endl;
	//ռ8�������
	cout << "a=" << setw(8) << setiosflags(ios::left)
		<< a << "===" << endl;
	//Ĭ���������������Чλ����ʾ6λ
	cout << "f=" << f << "===" << endl;
	//ռ10��С����ʾ2λ���Ҷ���
	cout << "f=" << setw(10) << setprecision(2)
		<< setiosflags(ios::fixed) << setiosflags(ios::right)
		<< f << "===" << endl;
	
	return 0;
}

