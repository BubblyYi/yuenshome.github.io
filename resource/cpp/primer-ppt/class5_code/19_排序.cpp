#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
class Person {
	friend bool cmp(const Person& lhs, const Person& rhs);
	friend class cmp1;
public:
	Person(int _age,const string& _name)
		:age(_age),name(_name){}
	bool operator<(const Person& rhs)const {
		if (age < rhs.age) return true;
		if (age == rhs.age && name < rhs.name) 
			return true;
		return false;
	}
	bool operator>(const Person& rhs)const {
		if (age > rhs.age) return true;
		if (age == rhs.age && name > rhs.name)
			return true;
		return false;
	}
	string to_str()const {
		return string("(" + to_string(age) + "," + name + ")");
	}
private:
	int age;
	string name;
};
void print(const vector<Person>& vec) {
	for_each(vec.begin(), vec.end(), [](const Person& pn) {cout << pn.to_str() << "\t"; });
}
bool cmp(const Person& lhs, const Person& rhs) {
	if (lhs.age < rhs.age) return true;
	if (lhs.age == rhs.age && lhs.name < rhs.name)
		return true;
	return false;
}
struct cmp1 {
	bool operator()(const Person& lhs, const Person& rhs) {
		if (lhs.age < rhs.age) return true;
		if (lhs.age == rhs.age && lhs.name < rhs.name)
			return true;
		return false;
	}
};
int main() {
	vector<Person> vec = { {20,"ZhangSan"},{21,"Lisi"},{20,"WangWu"} };
	sort(vec.begin(), vec.end());//Ĭ���ǵ��� less<Person> �ȼ����������
	print(vec); cout << endl;
	sort(vec.begin(), vec.end(), less<Person>()); //��С��������
	print(vec); cout << endl;
	sort(vec.begin(), vec.end(), greater<Person>()); //Ĭ���ǵ��� less<Person>
	print(vec); cout << endl;
	sort(vec.begin(), vec.end(), cmp); //�ȽϺ����� cmp
	print(vec); cout << endl;
	sort(vec.begin(), vec.end(), cmp1()); //�ȽϺ����� ��������cmp1
	print(vec); cout << endl;
	sort(vec.begin(), vec.end(), [](const Person& lhs, const Person& rhs)->bool {
		if (lhs < rhs) return true;
		return false;
	}); //�ȽϺ����� lambda��������
	print(vec); cout << endl;
	return 0;	return 0;
}