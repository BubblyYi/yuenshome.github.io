#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

void f1(int a, int b, int c) {
	cout << "a=" << a;
	cout << " b=" << b;
	cout << " c=" << c << endl;;
}

class A {
public:
	int add(int a, int b) { return a + b; }
};

ostream& print(ostream &out, const string &s, char sep) {
	return out << s << sep;
}

int main() {
	auto fun = bind(f1, std::placeholders::_2, 100,std::placeholders::_1);
	//��1�������� ���ܵĿɵ��ö���
	//std::placeholders::_1 _2 _3���¿ɵ��ö���Ĳ���λ��
	fun(10, 20);

	function<void(int)> f = bind(f1, 100, std::placeholders::_1,300);
	f(200);

	//��ĳ�Ա����Ҳ��ʹ��bind��������һ���µĿɵ��ö���
	A a;
	a.add(10, 20);
	function<int(int, int)> fc = bind(&A::add, a, std::placeholders::_1, std::placeholders::_2);
	cout << fc(10, 20) << endl;

	//���ɿ����Ĳ����� ����ref()
	vector<string> ss = { "ABC","12345","China" };
	for_each(ss.begin(), ss.end(), bind(print, ref(cout), std::placeholders::_1, ','));
	return 0;
}