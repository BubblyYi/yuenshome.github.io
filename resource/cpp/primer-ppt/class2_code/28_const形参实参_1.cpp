#include <iostream>
#include <string>
using namespace std;

void fun(int &a) {}
void func(const int &a) {}
bool find(string &s, char c) {
	return true; //s���������޸�
}
bool findc(const string &s, char c) {
	return true; //��֤s�����ﲻ���޸�
}
int main() {
	//fun(42); ����
	func(42); //ok
	const string s1 = "abc";
	//find(s1, 'c'); //����
	findc(s1, 'c'); //ok
	return 0;
}