/// 11_main.cpp
#include <iostream>
#include "11_template.h"
using namespace std;

//ʵ��������
extern template int compare(const int&, const int&);
extern template class my_vector<int>;

struct A{ A(int i){} };
//template class my_vector<A>; 
//����,Aû��Ĭ�Ϲ���,�޷�ʵ����my_vector<A>��Ĭ�Ϲ���

int main() {
	int a = 10, b = 20;
	cout << compare(a, b) << endl; //ʵ�����������ط�
	my_vector<int> v1;  //ʵ�����������ط�
	//my_vector<double> �� ���ι��캯�� �ڱ��ļ�ʵ����
	my_vector<double> v2(1); 
	//my_vector<A> �� ���ι��캯�� �ڱ��ļ�ʵ����
	my_vector<A> v3(A(1),3); 
	return 0;
}