#include <iostream>
using namespace std;
class Base {
public:
	Base(int i) :b1(set_b1(i)), b2(set_b2(i))
					  {	cout << "Base:Ĭ�Ϲ���" << endl;	}
	~Base() { cout << "Base:����" << endl; }
	int set_b1(int i) { cout << "b1��ʼ��" << endl; return i; }
	int set_b2(int i) { cout << "b2��ʼ��" << endl; return i; }
private:
	int b1;
	int b2;
};
class D1 :public Base {
public:
	D1(int i) :d1_2(set_d1_2(i)), d1_1(set_d1_1(i)), Base(i)
						{ cout << "D1:Ĭ�Ϲ���" << endl; }
	~D1() { cout << "D1:����" << endl; }
	int set_d1_1(int i) { cout << "d1_1��ʼ��" << endl; return i; }
	int set_d1_2(int i) { cout << "d1_2��ʼ��" << endl; return i; }
private:
	int d1_1;
	int d1_2;
};
class D2 :public D1 {
public:
	D2(int i) :D1(i), d2_1(set_d2_1(i)), d2_2(set_d2_2(i)) 
								{ cout << "D2:Ĭ�Ϲ���" << endl; }
	~D2() { cout << "D2:����" << endl; }
	int set_d2_1(int i) { cout << "d2_1��ʼ��" << endl; return i; }
	int set_d2_2(int i) { cout << "d2_2��ʼ��" << endl; return i; }
private:
	int d2_1;
	int d2_2;
};
int main() {
	D2 d2(1);
	cout << "---------" << endl;
	return 0;
}