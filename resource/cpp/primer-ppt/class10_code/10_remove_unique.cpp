//remove,remove_if,unique,reverse,random_shuffle
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	//remove(beg,end,val) ɾ��ֵ��val��Ԫ��   ==���� 
	//�㷨����ı������Ĵ�С,���õİ취��:�ñ�����Ԫ�ظ���Ҫɾ����Ԫ��
	//����һ��������,ָ�����һ��ɾ��Ԫ�صĺ����λ��
	array<int, 5> a11 = { 1,2,3,1,4 };
	auto it1 = remove(a11.begin(), a11.end(), 1);
	cout << *it1 << endl;
	for (const auto &item : a11) cout << item << " "; cout << endl;

	//remove_if(beg,end,unaryPred) ����unaryPred���������Ƿ�ɾ��
	forward_list<int> f11 = { 1,3,2,4,1 };
	auto it2 = remove_if(f11.begin(), f11.end(), //ż��ɾ��
		[](const int& t) {if (t % 2 == 0) return true; return false; });
	cout << *it2 << endl;
	for (const auto &item : f11) cout << item << " "; cout << endl;
	cout << "--------------\n";

	//unique(beg,end) ������Ԫ��,�����ظ�,��ͨ�������ǡ���ɾ��(����remove)
	//����һ��������,ָ���ظ�Ԫ�ص�β��λ��   ==����
	//unique(beg,end,binaryPred)
	array<int, 7> a1 = { 1,2,3,1,4,4,2 };
	//������ȥ�ظ���ֻ��ȥ�����ڵ�
	for (const auto &item : a1) cout << item << " "; cout << endl;
	auto it3 = unique(a1.begin(), a1.end());
	for_each(a1.begin(), it3, [](const int& t) {cout << t << " "; });
	cout << endl << "--------------\n";

	//�����Ժ���unique:
	a1 = { 1,2,3,1,4,4,2 };
	sort(a1.begin(), a1.end());
	for (const auto &item : a1) cout << item << " "; cout << endl;
	auto it4 = unique(a1.begin(), a1.end());
	for_each(a1.begin(), it4, [](const int& t) {cout << t << " "; });
	cout << endl << "--------------\n";

	//reverse(beg,end) ��ת�����е�Ԫ��,��Ҫ˫�������
	a1 = { 1,2,3,4,5,6,7 };
	for (const auto &item : a1) cout << item << " "; cout << endl;
	reverse(a1.begin(), a1.end());
	for (const auto &item : a1) cout << item << " "; cout << endl;
	cout << endl << "--------------\n";

	//random_shuffle(beg,end) �������� ��Ҫ������ʵ�����
	random_shuffle(a1.begin(), a1.end());
	for (const auto &item : a1) cout << item << " "; cout << endl;
	random_shuffle(a1.begin(), a1.end());
	for (const auto &item : a1) cout << item << " "; cout << endl;

	return 0;
}