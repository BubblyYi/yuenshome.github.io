#include <iostream>
using namespace std;
class Base {
public:
	Base(int _b) :b(_b), pb(new int(_b)) { }
	~Base() { cout << pb <<" Base����" << endl; delete pb;  }
	Base(Base&& other)
		:b(other.b), pb(other.pb) {
		other.pb = NULL; //��֤�ƺ�Դ���������
		cout << "Base�ƶ�����" << endl;
	}
	Base& operator=(Base &&other) {
		if (this != &other) {
			b = other.b;
			pb = other.pb;
			other.pb = NULL;//��֤�ƺ�Դ���������
		}
		cout << "Base�ƶ���ֵ���������" << endl;
		return *this;
	}
	int b;
	int *pb;
};
class D1 :public Base {
public:
	D1(int _b, int _d) :Base(_b), d(_d), pd(new int(_d)) { }
	~D1() { cout <<pd<< " D1����" << endl; delete pd;  }
	D1(D1&& other) //����� std::move()
		:Base(std::move(other)), d(other.d), pd(other.pd) {
		other.pd = NULL;//��֤�ƺ�Դ���������
		cout << "D1�ƶ�����" << endl;
	}
	D1 &operator=(D1 &&other) {
		//����� Base::  �� std::move()
		Base::operator=(std::move(other));  
		if (this != &other) {
			d = other.d;
			pd = other.pd;
			other.pd = NULL;//��֤�ƺ�Դ���������
		}
		cout << "D1�ƶ���ֵ���������" << endl;
		return *this;
	}
	int d;
	int *pd;
};
int main() {
	D1 d1(1, 2);
	//D1 d2(d1); //���������ƶ����죬�����Լ����忽������
	D1 d2(std::move(d1)); //�ƶ�����
	cout << d2.b << " " << d2.d << endl;
	cout << d1.pb << " " << d1.pd << endl; // NULL
	cout << d2.pb << " " << d2.pd << endl;
	D1 d3(0, 0);
	//d3 = d2; //���������ƶ����죬�����Լ����忽����ֵ��������
	d3 = std::move(d2);
	cout << d3.b << " " << d3.d << endl;
	cout << d2.pb << " " << d2.pd << endl;
	cout << d3.pb << " " << d3.pd << endl;
	return 0;
}