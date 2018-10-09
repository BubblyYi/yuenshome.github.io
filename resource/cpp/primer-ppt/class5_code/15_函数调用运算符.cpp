#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Func {
public:
	Func(int len = 3) :length(len) {}
	bool operator()(const string& s) {
		if (s.size() < length) return true;
		return false;
	}
private:
	int length;
};

bool less3(const string& s) {
	if (s.size() < 3) return true;
	return false;
}
int main() {
	vector<string> vs = { "abc","as","a","aff" };
	int res = count_if(vs.begin(), vs.end(), less3);
	cout << res << endl; //��� 2

	//���⣺����Ҫ���������С��4��Ԫ�ظ�����ô�죿
	//����1���޸�less3����������� 3�޸�Ϊ4�������㣬̫�鷳��
	//����2��less3��������һ������������count_if�����еĵ�3�������Ǻ���ָ�룬
	//		ֻ������һ�������������У�
	//����3����һ��ȫ�ֱ�����less3������ �� 3��ȫ�ֱ��������������,���׳���

	//�º�����ͨ������ operator() �������������
	res = count_if(vs.begin(), vs.end(), Func()); //Ĭ�Ϲ�����3,ע�������()
	cout << res << endl; //���2
	res = count_if(vs.begin(), vs.end(), Func(4));
	cout << res << endl; //���4
	return 0;
}
