#include <iostream>
using namespace std;

template <typename T=int>
class A {
public:
	A(const T& t) :data(t) { count++; }
	~A() { count--; }
	static int get_count() { return count; }
private:
	T data;
	static int count;
};

template<typename T>
int A<T>::count = 0;

int main() {
	A<char> a1(' '),a2('c');
	//ʵ���� A<char>,��������� A<char>::count
	cout << A<char>::get_count() << endl; //2

	A<> b1(0), b2(0), b3(0);
	//ʵ���� A<int>,Ĭ��ֵ��int,��дΪ A<>
	//���������A<int>::count
	cout << A<>::get_count() << endl; //3
	cout << A<int>::get_count() << endl; //3
	cout << b1.get_count() << endl; //3
	return 0;
}