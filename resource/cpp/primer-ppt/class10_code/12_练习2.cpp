//ʵ�� my_for_each,�������������,������ִ�в���
//for_each(beg,end,unaryOp) ==> my_for_each(����������,unaryOp)
//�Լ�дһ��my_for_each
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�ҳ�������������
template<typename C, typename F>
void my_for_each_1(C &c, F f) {
	for (auto it = c.begin(); it < c.end(); it++)
		f(*it);
}
//����1: ++it (it++������ʱ����,Ч�ʵ�)
//����2: it != c.end() (it < c.end() ��Щ������������֧��)
//����3: for (auto it=c.begin(),it_end=c.end(); it!=it_end;it++) Ч�ʻ��һЩ
//����4: ���紫�������������,����: c.begin��c.end��дΪstd::begin(c)��std::end(c)
//����5: ���д��  for_each(std::begin(c), std::end(c), f);
int main() {
	vector<int> vec = { 1,2,3 };
	for_each(vec.begin(), vec.end(), [](int& v) {v += 1; });
	for_each(vec.begin(), vec.end(), [](int& v) {cout << v << " "; });
	cout << endl;

	vec = { 1,2,3 };
	my_for_each_1(vec, [](int& v) {v += 1; });
	my_for_each_1(vec, [](int& v) {cout << v << " "; });
	cout << endl;

	return 0;
}