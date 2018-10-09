#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	//unsigned ע��㣺
	unsigned int a = 2, b = 1;
	cout << a - b << endl; // 1
	cout << b - a << endl; // 4294967295
	cout << hex << b - a << dec << endl; //0xFFFFFFFF
	long long long_a = 0xFFFFFFFF;
	cout << long_a << endl;// 4294967295

	//ͬ�ڴ�ͬ���ݣ����Ͳ�ͬ���ѡ�
	//��ͬ�ĵ�ַ����ͬ�����ݣ�ֻ�ǽ��ͷ�ʽ�Ĳ�ͬ
	unsigned int ok = b - a;
	int *p_ok = (int*)&ok;
	cout << *p_ok << "---" << ok << endl;
	cout << &ok << endl;
	cout << p_ok << endl;

	//�ڴ��з��� 0x41424344 ��ɶֵ��
	char str[5] = { 'A','B','C','D','\0' };
	cout << str << endl;
	int *p_str = (int*)str;
	cout << *p_str << endl; //1145258561
	cout << hex << *p_str << dec << endl;
	cout << hex << (int)(str[0]) << str[1] << str[2] << str[3] << dec << endl;
	//hex����������� \x?

	//������Ҳ��һ����
	int test = 1145258561;
	char *p_char = (char*)&test;
	cout << *p_char << *(p_char + 1) << *(p_char + 2) << endl;

	return 0;
}

