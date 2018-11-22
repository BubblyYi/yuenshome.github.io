//for_each, fill,fill_n (���������)
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <deque>
#include <array>
#include <algorithm>
using namespace std;

class Stu {
public:
	friend ostream& operator<<(ostream&, const Stu&);
	Stu(const string& _name,int _age)
		:name(_name),age(_age){}
private:
	string name;
	int age;
};
ostream& operator<<(ostream &out,const Stu& s) {
	out << s.name << ":" << s.age;
	return out;
}


int main() {
	//for_each(beg,end,unaryOp) unaryOp:һԪ����
	//�Ե�����beg��end֮���ÿ��Ԫ��ִ�� unaryOp����
	forward_list<int> f1 = { 1,2,3 };
	for_each(f1.cbegin(), f1.cend(), //��ӡ���
		[](const int& item) {cout << item << " -> "; });
	cout <<"NULL"<< endl;
	//�������������ͨ�������øı�Ԫ��ֵ,unaryOpҲ���޸�Ԫ��ֵ
	for_each(f1.begin(), f1.end(), [](int &item) {if (item > 1)item+=10; });
	for (const auto& item : f1)
		cout << item << " -> ";
	cout << "NULL" << endl;

	//fill(beg,end,val)
	//����������Χbeg��end�е�Ԫ��ֵ ����Ϊval
	deque<Stu> d1 = { {"����",21},{"����",22},{"����",20} };
	for (const auto& item : d1) cout << item << " "; cout << endl;
	fill(d1.begin(), d1.end(), Stu("NULL", 0)); 
	for (const auto& item : d1) cout << item << " "; cout << endl;

	//fill_n(beg,cnt,val) cnt����
	//�ӵ�����begλ�ÿ�ʼ,����cnt��Ԫ�ص�ֵΪval,�������һ������Ԫ�غ���λ�õĵ�����
	vector<int> v1 = { 1,2,3,4,5,6,7 };
	auto res1 = fill_n(v1.begin(), 3, 0); //�ӿ�ʼλ��,����3��0
	cout << *res1 << endl; //4
	for (const auto& item : v1) cout << item << " "; cout <<endl;
	//fill_n(v1.begin(), 10, 1); ����,v1û��10��Ԫ��,����Ա�Լ���֤

	//back_inserter: ���������(������������)	ʹ��push_back�ĵ�����
	back_insert_iterator<vector<int>> it_back = back_inserter(v1);
	fill_n(it_back, 3, 11); //v1��������3��11(����push_back)
	for (const auto& item : v1) cout << item << " "; cout << endl;

	//front_inserter: ���������(������������) ʹ��push_front�ĵ�����
	//fill_n(front_inserter(v1), 2, 33); ��,vectorû��push_front
	fill_n(front_inserter(d1), 2, Stu("����", 20)); //����push_front
	for (const auto& item : d1) cout << item << " "; cout << endl;

	//inserter: ���������(������������) �ڸ����ĵ�����λ��ǰ����
	insert_iterator<vector<int>> it_insert = inserter(v1, v1.end());
	fill_n(it_insert, 3, 22);
	for (const auto& item : v1) cout << item << " "; cout << endl;
	fill_n(inserter(v1, v1.begin()), 3, -1); 
	for (const auto& item : v1) cout << item << " "; cout << endl;

	return 0;
}