//����find,find_if,count,count_if
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using namespace std;
struct cmp1 {
	cmp1(int th=0):thresh(th){}
	bool operator()(const int& t) {
		if (t > thresh) return true;
		return false;
	}
	int thresh;
};
struct cmp2 {
	cmp2(double th = 0) :thresh(th) {}
	bool operator()(const double& t) {
		if (t == thresh) return true;
		return false;
	}
	double thresh;
};

int main() {
	vector<int> v1 = { 2,1,2,4,7, };
	//find(beg,end,val) beg:��������ʼλ��,end:����������λ��,val:Ҫ�ҵ�ֵ
	//�ڵ�������Χ��,�ҵ���Ԫ��,��: ���ص�һ����Ԫ�صĵ�����λ��
	vector<int>::const_iterator res1 = find(v1.cbegin(), v1.cend(), 1);
	if (res1 != v1.end()) 
		cout << "Ԫ��1:�ҵ�," << *res1 << endl;
	//��û���ҵ���Ԫ��,��: ����endλ�õĵ�����
	vector<int>::iterator res2 = find(v1.begin() + 3, v1.end() - 1, 10);
	if (res2 == v1.end() - 1) //vector�����������������,����+ -
		cout << "Ԫ��10:û���ҵ�\n";

	//find_if(beg,end,unaryPred) beg:��������ʼλ��,end:����λ��,unaryPred:����
	//�ڵ�������Χ��,�ҷ�������unaryPred��Ԫ��, �ҵ���δ�ҵ�����ͬfind()
	//unaryPred: һԪν��,����һ������(���ǵ�������ָ���Ԫ��),���ؿ���Ϊ����������
	auto res3 = find_if(v1.cbegin(), v1.cend(), cmp1(4)); //��>4��Ԫ��
	if (res3 != v1.cend()) 
		cout << ">4��Ԫ���ҵ�," << *res3 << endl;
	auto res4 = find_if(v1.begin(), v1.end(), cmp1(10)); //��>10��Ԫ��
	if (res3 == v1.end())
		cout << ">10��Ԫ��û���ҵ�\n";

	//count(beg,end,val) 
	//�ڵ�������Χ��,�ҳ�Ԫ��ֵ==val ��Ԫ�ظ���,����ֵ����val��Ԫ�ظ���
	list<double> l1 = { 1.0,2.0,1.0,3.0 };
	cout << count(l1.begin(), l1.end(), 1.0) << endl; // 2
	cout << count(l1.begin(), l1.end(), 4.0) << endl; // 0

	//count_if(beg,end,unaryPred) 
	//�ڵ�������Χ��,ͳ�Ʒ�������unaryPred��Ԫ�ظ���
	cout << count_if(l1.cbegin(), l1.cend(), cmp2(1.0)) << endl; //==1.0�ĸ��� 2

	return 0;
}