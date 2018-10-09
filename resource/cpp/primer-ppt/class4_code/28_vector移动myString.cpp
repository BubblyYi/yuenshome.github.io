#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class myString {
public:
	myString(const char *str = nullptr); //����
	myString(const myString &other);     //��������
	myString(myString &&other) noexcept; //�ƶ�����
	myString &operator=(const myString &other);//��ֵ���������
	myString &operator=(myString &&other) noexcept; //�ƶ���ֵ���������
	~myString() {
		if (ps)
			cout << ps << " --Destructor" << endl;
		else
			cout << "ps is NULL" << " --Destructor" << endl;
		delete[] ps;
	}
	const char * c_str()const { return ps; }
private:
	char *ps;
};

myString::myString(const char *str) {
	if (str == nullptr) {
		ps = new char[1]{ 0 };
		cout << ps << " --Default constructor" << endl;
	}
	else {
		int length = strlen(str);
		ps = new char[length + 1];
		strcpy(ps, str);
		cout << ps << " --Str constructor" << endl;
	}
}

myString::myString(const myString &other) {//��������
	int length = strlen(other.ps);
	ps = new char[length + 1];
	strcpy(ps, other.ps);
	cout << ps << " --Copy constructor" << endl;
}
myString::myString(myString &&other) noexcept:ps(other.ps)  { //�ƶ�����
	other.ps = nullptr; //Ҫ��֤���ƺ�Դ��������������
	cout << ps << " --Move constructor" << endl;
}
myString &myString::operator=(const myString &other) { //��ֵ���������
	if (this != &other) {
		delete[] ps;
		int length = strlen(other.ps);
		ps = new char[length + 1];
		strcpy(ps, other.ps);
	}
	cout << ps << " --Copy assignment" << endl;
	return *this;
}

myString &myString::operator=(myString &&other) noexcept {//�ƶ���ֵ���������
	if (this != &other) {
		delete[] ps;
		ps = other.ps;
		other.ps = nullptr;
	}
	cout << ps << "--Move assignment" << endl;
	return *this;
}

myString operator+(const myString &a, const myString &b) {
	int length = strlen(a.c_str()) + strlen(b.c_str());
	char * p = new char[length + 1];
	strcpy(p, a.c_str());
	strcat(p, b.c_str());
	myString tmp(p);
	delete[] p;
	return tmp;
}

myString fun() {
	myString tmp("allok");
	return tmp;
}
//myString ʵ������ͨ���죬�������죬��ֵ��������أ�����
//         ����ʵ���� �ƶ����죬�ƶ���ֵ���������

int main() {
	vector<myString> vs1;
	vs1.reserve(3);
	cout << "size=" << vs1.size() << " capacity=" << vs1.capacity() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "--------------------------" << endl;
		vs1.push_back(myString("abc"));
		cout << "size=" << vs1.size() << " capacity=" << vs1.capacity() << endl;
		cout << &vs1[0] << endl; //�۲������ڴ����ʼ��ַ
	}
	cout << "==========================" << endl;
	vs1.push_back(myString("12345"));
	cout << "size=" << vs1.size() << " capacity=" << vs1.capacity() << endl;
	cout << &vs1[0] << endl; //�۲������ڴ����ʼ��ַ
	cout << &(*vs1.begin()) << endl;
	cout << "==========================" << endl;
	return 0;
}