#include <iostream>
using namespace std;
//ͨ���������ط�ʽ��swap:
//��Ȼ����ʵ�ַ�ʽ��ͬ��
//���ǣ���һ�����;�Ҫдһ������
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void swap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}
//�ú���ģ�壬ֻдһ�״���������
template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int a = 10, b = 20;
	swap(a, b);
	double a1 = 1.0, b1 = 2.0;
	swap(a1, b1);
	const char * c1 = "abc", *c2 = "123";
	::swap(c1, c2);
	::swap<const char*>(c1, c2);
	char cc1 = '1', cc2 = '2';
	::swap(cc1, cc2);
	::swap<char>(cc1, cc2);
	return 0;
}