#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	// int ,float, double��ת��
	int i = 1234567890;
	float f = 1.234f;
	double fd = 3.1415926;
	f = i; //(��ʧ����)
	cout << "f= " << setw(10) << setprecision(2)
		<< setiosflags(ios::fixed) << f << endl;
	i = fd; //i = 3 (С������涪ʧ)
	cout << "i= " << i << endl;
	f = fd; //doubleתfloat,(���ȶ�ʧ)
	cout << "f= " << setw(10) << setprecision(7)
		<< setiosflags(ios::fixed) << f << endl;

	return 0;
}

