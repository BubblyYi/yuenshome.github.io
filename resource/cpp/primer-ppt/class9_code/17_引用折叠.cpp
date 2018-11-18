#include <iostream>
using namespace std;

//ģ�壺����һ�� ��ֵ���� �󶨵� һ����ֵ
//һ: ��һ����ֵ���ݸ���������ֵ���ò���ʱ,���Ҵ���ֵ����ָ��ģ�����Ͳ�������T&&��ʱ���ƶ�ģ�����Ͳ�����ʵ�ε���ֵ�������͡�
//��: �����۵�,����T& &��T& &&��T&& & �۵������� T&, ���� T&& && �۵������� T&&

//ʵ�α�������ֵ
template <typename T> void f1(T&) {}
//ʵ�ο�������ֵ
template <typename T> void f2(const T&) {}
//ģ�壺ʵ�ο�������ֵ
template <typename T> void f3(T&&) {}

template <typename T> void f4(T&& val) {
	T t = val;
	//1.���紫��һ��int��ֵ: T ���� int&, ��ô�����൱�� int& t = val;
	//2.���紫��һ��int��ֵ: T ���� int, ��ô�����൱�� int t = val;

	t = 100; //���1: val������Ϊ100, ���2: val����ı�
	cout << "f4(): val = " << val << endl;
}

int main() {
	int i = 10; 
	const int ci = 20;
	f1(i);  // T: int
	f1(ci); // T: const int
	//f1(2);// ��,��������ֵ
	f2(i);  // T: int
	f2(ci); // T: int
	f2(2);  // T: int
	f3(i);  // T: int &
	f3(ci); // T: const int &
	f3(2);  // T: int

	f4(i);
	cout << "��ֵi= "<<i << endl;
	i = 10;
	f4(std::move(i));
	cout << "��ֵi="<<i << endl;
	return 0;
}