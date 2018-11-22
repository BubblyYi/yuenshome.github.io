///��������
//binary_search,lower_bound,upper_bound,equal_range
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
	//binary_search(beg,end,val) �����������������Ƿ���Ԫ��ֵ==val
	//�з���true,û�з���false  �������� < (==) ���㡿
	//binary_search(beg,end,val,comp)
	vector<int> v1{ 20,10,30,40,20,80,90,0 };
	sort(v1.begin(), v1.end());
	bool flag = binary_search(v1.begin(), v1.end(), 31);
	cout << flag << endl;
	flag = binary_search(v1.begin(), v1.end(), 31, //���+-1��Ϊ���
		[](const int&t1, const int&t2){if(t1+1==t2||t1-1==t2)return 1;return 0;});
	cout << flag << endl; //31���ҵ��ˡ�
	cout << "---------------\n";

	//lower_bound(beg,end,val) ����������������Ԫ��==val,û���ѵ�����end
	//�ҵ�������һ��������: ָ�� ��һ�� ���ڵ��� val ��Ԫ��  ��<���㡿
	//lower_bound(beg,end,val,comp)
	v1 = { 1,2,3,4,4,4,5,6 };
	auto it1 = lower_bound(v1.begin(), v1.end(), 3); //��3,����3��λ��
	cout << "��3: " << *it1 << endl;
	it1 = lower_bound(v1.begin(), v1.end(), 4); //��4,���ص�1��4��λ��
	for_each(it1, v1.end(), [](const int& t) {cout << t << " "; });
	cout << endl <<"---------------\n";

	//upper_bound(beg,end,val) ����������������Ԫ��==val,û���ѵ�����end
	//�ҵ�������һ����������ָ�� ��һ�� ���� val ��Ԫ��
	//upper_bound(beg,end,val,comp)
	auto it2 = upper_bound(v1.cbegin(), v1.cend(), 3); //��3�����ص�1��4��λ��
	for_each(it2, v1.cend(), [](const int& t) {cout << t << " "; });
	cout << endl;
	it2 = upper_bound(v1.cbegin(), v1.cend(), 4); //��4�����ص�5��λ��
	for_each(it2, v1.cend(), [](const int& t) {cout << t << " "; });
	cout << endl << "---------------\n";

	//equal_range(beg,end,val) ��������������Ԫ��==val, ����һ��pair, 
	//first��Ա��lower_bound���صĵ�����,second��Ա��upper_bound���صĵ�����
	//equal_range(beg,end,val,comp)
	for (const auto& item : v1) cout << item << " "; cout << endl;
	pair<vector<int>::iterator, vector<int>::iterator> pr1 =
		equal_range(v1.begin(), v1.end(), 4);
	cout << "*first: " << *pr1.first << endl;
	cout << "*second: " << *pr1.second << endl;
	for_each(pr1.first, pr1.second, [](const int &t) {cout << t << " "; });
	cout << endl;

	return 0;
}