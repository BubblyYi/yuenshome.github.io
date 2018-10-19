#include <iostream>
using namespace std;
class Base {
public:
	Base() { cout << "BaseĬ�Ϲ���" << endl; }
	Base(int _b) :b(_b), pb(&b) { }
	Base(const Base& other)
		:b(other.b), pb(other.pb){
		cout << "Base��������" << endl;
	}
	Base& operator=(const Base &other) {
		if (this != &other) {
			b = other.b;
			pb = other.pb;
		}
		cout << "Base��ֵ���������" << endl;
		return *this;
	}
	int b;
	int *pb;
};
class D1 :public Base {
public:
	D1(int _b, int _d) :Base(_b), d(_d), pd(&d) { }
	D1(const D1& other)
		:d(other.d),pd(other.pd){
		cout << "D1��������" << endl;
	}
	D1 &operator=(const D1 &other) {
		if (this != &other) {
			d = other.d;
			pd = other.pd;
		}
		cout << "D1��ֵ���������" << endl;
		return *this;
	}
	int d;
	int *pd;
};
int main() {
	D1 d1(1, 2);
	D1 d2(d1); //��������  d1 --> d2
	cout << d2.b << " " << d2.d << endl; // ??? 2
	cout << d1.pb << " " << d1.pd << endl;
	cout << d2.pb << " " << d2.pd << endl;
	D1 d3(0, 0);
	d3 = d2;   //��ֵ����� d2 --> d3
	cout << d3.b << " " << d3.d << endl; // 0 2
	cout << d2.pb << " " << d2.pd << endl;
	cout << d3.pb << " " << d3.pd << endl;
	return 0;
}