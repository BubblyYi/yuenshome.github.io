#include <iostream>
#include <cstring>
using namespace std;

//������̬����,����ΪT,����ΪN, �������׵�ַ
template<typename T,int N>
T* f1(const T& t) {
	static T tmp[N];
	for (auto &tt : tmp) tt = t;
	return tmp;
}
//�Ƚ�2���ַ�������  ע�⣺��������inline��λ��
template<unsigned M,unsigned N>
inline int compare(const char(&p1)[M], const char(&p2)[N]) {
	cout << "M=" << M << ",N=" << N << endl;
	return strcmp(p1, p2);
}
int main() {
	int *p = f1<int,10>(33);
	for (int i = 0; i < 10; i++)
		cout << *p++ << " ";
	cout << endl;
	int flag = compare("abc","abcd");
	return 0;
}