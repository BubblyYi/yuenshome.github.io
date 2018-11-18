///�۲� ���������������㷨���º���֮��Ĺ�ϵ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterN {
public:
	GreaterN(int i=0):val(i){}
	bool operator()(const int& v)const {
		if (v > val) return true;
		return false;
	}
private:
	int val;
};

int main() {
	//vector�Ķ����������£�_Alloc�ǿռ�������,Ĭ��ֵ��allocator<_Ty>
	//template<class _Ty,class _Alloc = allocator<_Ty> > 
	//class vector...
	std::vector<int> v1;
	std::vector<int, std::allocator<int>> v2;

	//�۲죺���������������㷨���º���֮��Ĺ�ϵ
	//����Ҳ�ɿ�����һ������
	int arr[5] = { 1,2,3,4,5 };
	int* it1_beg = std::begin(arr); //�൱�� &arr[0]
	int* it1_end = std::end(arr);	//�൱�� &arr[5]
	//int* ָ��,Ҳ�ɿ�����һ�ֵ�����
	int total = std::count_if(it1_beg, it1_end, GreaterN(3));
	//GreaterN�Ǻ�������(�º���),Э���㷨�ƶ�����
	//count_if���㷨,ͳ��������������֮������Ԫ�����������ĸ���
	cout << total << endl;

	//vector��һ������
	std::vector<int> vec = { 1,2,3,4,5 };
	//std::vector<int>::iterator ��һ�ֵ�����
	std::vector<int>::iterator it2_beg = vec.begin();
	std::vector<int>::iterator it2_end = vec.end();
	int total2 = std::count_if(it2_beg, it2_end, GreaterN(2));
	//����������Լ�дΪ��
	total2 = std::count_if(vec.begin(), vec.end(), GreaterN(2));
	cout << total2 << endl;

	return 0;
}