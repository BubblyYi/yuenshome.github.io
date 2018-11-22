//sort,stable_sort,partial_sort,nth_element
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
	//sort(beg,end) ����,Ҫ��������ʵ�����,Ԫ����<����,��С����
	//sort(beg,end,comp) ��comp��ȷ���������
	vector<int> v1{ 2,1,3,4,2,8,9,0 };
	sort(v1.begin(), v1.end());
	for (const auto& item : v1) cout << item << " "; cout << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	for (const auto& item : v1) cout << item << " "; cout << endl;
	sort(v1.begin(), v1.end(), //������ǰ,ż���ں�
	  [](const int& t1, const int& t2){if(t2%2 < t1%2)return 1;return 0;});
	for (const auto& item : v1) cout << item << " "; cout << endl;
	cout << "----------------\n";

	//stable_sort(beg,end) �ȶ�����,������ʵ�����, <����
	//stable_sort(beg,end,comp)
	stable_sort(v1.begin(), v1.end());
	for (const auto& item : v1) cout << item << " "; cout << endl;
	cout << "----------------\n";

	//partial_sort(beg,mid,end) ����mid-beg��Ԫ��,�൱���ҳ�ǰ������СԪ��
	//partial_sort(beg,mid,end,comp)
	deque<int> d1 = { 9,8,1,3,2,1 };
	partial_sort(d1.begin(), d1.begin() + 4, d1.end()); // 1 1 2 3...
	for (const auto& item : d1) cout << item << " "; cout << endl;
	partial_sort(d1.begin(),d1.begin()+4,d1.end(),greater<int>());//9 8 3...
	for (const auto& item : d1) cout << item << " "; cout << endl;
	cout << "----------------\n";

	//nth_element(beg,nth,end) nth�ǵ�����λ��(ָ��һ��Ԫ��),
	//�������,nthָ�����Ǹ�Ԫ��,������֮ǰ�Ķ�С�ڵ�����,������֮��Ķ����ڵ�����
	//nth_element(beg,nth,end,comp)
	array<int, 7> a1 = { 1,3,8,2,5,4,9 };
	auto it1 = a1.begin() + 4; //ָ��Ԫ�� 5
	nth_element(a1.begin(), it1, a1.end());
	cout << "it1: " << *it1 << endl;
	for (const auto& item : a1) cout << item << " "; cout << endl;

	return 0;
}
