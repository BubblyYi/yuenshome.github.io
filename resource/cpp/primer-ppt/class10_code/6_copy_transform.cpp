//copy,copy_if,copy_n,transform
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;
class Stu {
public:
	friend ostream& operator<<(ostream&, const Stu&);
	Stu(const string& _name, int _age)
		:name(_name), age(_age) {}
private:
	string name;
	int age;
};
ostream& operator<<(ostream &out, const Stu& s) {
	out << s.name << ":" << s.age;
	return out;
}
int main() {
	//copy(beg,end,dest) dest:��Ŵ����Ԫ�ص�Ŀ��λ��
	//�������е�Ԫ�ؿ�����destָ����Ŀ��������
	//dest��Ҫ�ܷŵ�����ô��Ԫ��
	int arr[] = { 11,22,33 };
	vector<int> v0(5); 
	copy(begin(arr), end(arr), v0.begin()); //arr������v0
	for (const auto &item : v0) cout << item << " "; cout <<endl;
	
	//copy_if(beg,end,dest,unaryPred) unaryPred:һ������������
	//ֻ�з��������Ĳſ���(unaryPred����true��ʾ��������)
	copy_if(begin(arr), end(arr),v0.begin(), //��������
				[](const int& t) {if (t % 2 == 1) return 1; return 0; });
	for (const auto &item : v0) cout << item << " "; cout << endl;

	//copy_n(beg,n,dest)
	//����ǰn��Ԫ��,beg��ʼ��������Ҫ��n��Ԫ��,dest��Ҫ�ܷ���n��Ԫ��
	vector<int> v00; //��back_inserter
	copy_n(begin(arr), sizeof(arr) / sizeof(int), back_inserter(v00));
	for (const auto &item : v00) cout << item << " "; cout << endl;
	cout << "----------------\n";

	//transform(beg,end,dest,unaryOp) 
	//�������е�Ԫ�ص���unaryOp����,�������dest
	list<int> l11 = { 1,2,3,4,5,6 };
	vector<int> v11(10, 0);  //��list�е�Ԫ��+10�����vector
	transform(l11.cbegin(), l11.cend(), v11.begin(), //ÿ��Ԫ��+10
	/*Ҫ��֤dest�����λ���㹻*/      	[](const int& t) {return t + 10; });
	for (const auto &item : v11) cout << item << " "; cout << endl;

	vector<int> v12;  //���� back_inserter ���������ʵ��
	transform(l11.cbegin(), l11.cend(), back_inserter(v12), 
							     	[](const int& t) {return t + 10; });
	for (const auto &item : v12) cout << item << " "; cout << endl;

	//transform(beg,end,beg2,dest,binaryOp)  binaryOp:���������Ĳ���
	//�����������е�Ԫ����Ϊ2���������ݸ�binaryOp,�����������dest
	array<int, 3> a13 = { 21,22,23 };
	forward_list<string> f13 = { "����","����","����" };
	deque<Stu> d13;
	transform(a13.cbegin(), a13.cend(), f13.cbegin(), back_inserter(d13), 
			[](const int& age, const string& name) {return Stu{name,age}; });
	for (const auto &item : d13) cout << item << " "; cout << endl;

	return 0;
}
