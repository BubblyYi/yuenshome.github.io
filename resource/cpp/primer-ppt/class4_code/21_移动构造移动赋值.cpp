#include <iostream>
#include <cstring>
#include <string>
#include <utility>
using namespace std;

class myString {
public:
	myString(const char *str = nullptr); //����
	myString(const myString &other);     //��������
	myString(myString &&other);			 //�ƶ�����
	myString &operator=(const myString &other);//��ֵ���������
	myString &operator=(myString &&other); //�ƶ���ֵ���������
	~myString() {
		if(ps)
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
myString::myString(myString &&other):ps(other.ps) { //�ƶ�����
	other.ps = nullptr;
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

myString &myString::operator=(myString &&other) {//�ƶ���ֵ���������
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
int main() {
	myString s1("abc");
	myString s2("123");
	myString s3 = s1; //��������
	cout << "1====================" << endl;
	myString s4(myString("ok"));
	cout << "2====================" << endl;
	myString s5 = s1 + s2; 
	// s1 + s2 ����ʱ��(��ֵ),�����ƶ������s4,��������
	cout << "3====================" << endl;
	myString s6 = fun();
	// fun()����ֵ ����ʱ��(��ֵ),�����ƶ������s6,��������
	cout << "4====================" << endl;
	myString s7 = std::move(s6); //std::move������#include <utility>
	cout << (void*)s6.c_str() << endl; //s6�е���Դps=NULL�ˡ�
	cout << "5====================" << endl;
	return 0;
}