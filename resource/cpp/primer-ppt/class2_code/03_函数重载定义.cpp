#include <iostream>
using namespace std;

int max_val(int a, int b) { return a > b ? a : b; }
double max_val(double a, double b) { return a > b ? a : b; }
float max_val(float a, float b) { return a > b ? a : b; }

void f1(int a) { }
void f1(int a, int b) { }

void f2(int a, char b) { }
void f2(char b, int a) { }

int main() {
	max_val(10, 20);    //��ȫƥ���1��
	max_val(1.2, 1.3);  //��ȫƥ���2��
	max_val(1.2f, 1.3f);//��ȫƥ���3��
	max_val('a', 'b');  //char����Ϊint,ƥ���1��
	return 0;
}