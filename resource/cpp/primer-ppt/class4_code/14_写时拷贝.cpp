#include <iostream>
#include <cstring>
using namespace std;
class myString {
public:
	myString(const char * pstr = NULL) {
		if (!pstr) 
			ps = new char[1]{'\0'};
		else {
			ps = new char[strlen(pstr) + 1];
			strcpy(ps, pstr);
		}
		count = new int(1); //����ʱ���ٿռ䲢��Ϊ1
	}
	myString(const myString &other) 
		:ps(other.ps), count(other.count) {
		(*count)++; //��������ʱ count + 1
	}
	myString &operator=(const myString &other) {
		if (this != &other) {
			(*count)--; //������ԭ���ļ����� -1
			if (*count == 0) {
				cout << "delete in = ." << endl;
				delete[] ps;
				delete count;
			}
			ps = other.ps;
			count = other.count;
			(*count)++;
		}
		return *this;
	}
	~myString() { 
		(*count)--; //����ʱ count - 1
		if (*count == 0) { //countΪ 0 �ͷ��ڴ�
			delete[] ps;
			delete count;
		}
	}
	int get_count()const { return *count; }
	myString operator+(const myString &other) {
		int len = strlen(ps) + strlen(other.ps);
		char * ps_tmp = new char[len + 1]{ 0 };
		strcpy(ps_tmp, ps);
		strcat(ps_tmp, other.ps);
		myString tmp(ps_tmp);
		return tmp;
	}
	void reverse() {
		int len = strlen(ps) - 1;
		for (int i = 0; i < len / 2; i++) {
			char c = ps[i];
			ps[i] = ps[len - i];
			ps[len - i] = c;
		}
	}
	const char * c_str()const { return ps; }
private:
	char *ps;
	int *count;
};

myString fun(myString s) {
	cout << "fun: " << s.get_count() << endl;
	return s;
}
int main() {
	myString s1("abc");
	myString s2 = s1;
	cout << "s1=" << s1.c_str() << endl;
	s1.reverse();
	cout << "s1=" << s1.c_str() << endl;
	cout << "s2=" << s2.c_str() << endl;
	return 0;
}