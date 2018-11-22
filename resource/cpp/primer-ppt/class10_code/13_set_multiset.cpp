///set,multiset
///
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

struct A {
	A(const string& ss1 = "", int i1 = 0) :s1(ss1), d1(i1) {}
	bool operator<(const A& rhs)const { //ʵ���� < û��ʵ�� ==
		if (s1 < rhs.s1) return true;
		if (!(rhs.s1 < s1) && d1 < rhs.d1) return true;
		return false;
	}
	string s1;
	int d1;
};

struct B {
	B(const string& ss1 = "", int i1 = 0) :s1(ss1), d1(i1) {}
	string s1;
	int d1;
};

class compB { //�º���,> ����true,����set�Ӵ�С
public:
	bool operator()(const B& lhs, const B& rhs)const {
		if (lhs.s1 > rhs.s1) return true;
		if (!(rhs.s1 > lhs.s1) && lhs.d1 > rhs.d1) return true;
		return false;
	}
};

int main() {
	//����������Ԫ���ǰ��ؼ���������ͷ��ʵġ�
	//set(�ؼ��ֲ����ظ�), multiset(�ؼ��ֿ����ظ�) ͷ�ļ� #include <set> �����
	//template<class K,class Cmp=less<K>,class _Alloc=allocator<K>> class set...
	//template<class K,class Cmp=less<K>,class _Alloc=allocator<K>> class multiset..

	//1.Ԫ���Զ�����
	//2.�����ɾ��ʱ�临�Ӷ�: O(logN)  [����Ƶ�����롢ɾ�������ң�����Ҫ������]
	//3.Ԫ�ر���֧�֡��ϸ�����
	//  ��1�� (a < b)Ϊ�� ==> (b < a)Ϊ��, (a < a)�϶�Ϊ��
	//  ��2�� (a < b) ���� (b < c) ==> (a < c)
	//  ��3�� (a < b)Ϊ�� ���� (b < a)Ϊ�� ==> (a == b)
	//  ��4�� (a == b) ���� (b == c) ==> (a == c)
	//4.��set�е�Ԫ�أ����ܸı���ֵ
	//5.��Node(���)�ķ�ʽ���,
	//�ڴ����Ľϴ�(������ָ��,������ָ��,�����ָ��,ǰ��ָ��,����ָ��)

	//pair�Ľṹ: 
	//template<typename T1, typename T2> struct pair {
	//	T1 first;
	//	T2 second;
	//	//...
	//};
	pair<int, double> p1(1, 2.0);
	pair<int, char> p2 = { 10, 'c' };
	pair<int, double> p3 = make_pair(1, 3.0);

	//1.��ʼ��
	set<int,less<int>> g1;  //Ĭ�Ͼ��� less<int>
	multiset<int,greater<int>> g2;
	set<double> g3{ 1.0, 3.0, 2.0, 2.0 }; //2.0ֻ���1��
	set<double> g4{ 1.0, 3.0 }; //��ʼֵ�б�
	set<double> g5(g3);  
	set<double> g6 = g3; //��������
	vector<int> vec = { 1,2,3,2,4,4,6 };
	set<int> g7(vec.cbegin(), vec.cend());		 //1 2 3 4 6
	multiset<int> g8(vec.crbegin(), vec.crend());//1 2 2 3 4 4 6
	for (auto& item : g7) cout << item << " "; cout << endl;
	for (auto& item : g8) cout << item << " "; cout << endl;
	cout << "------------------\n";

	//2.��ֵ (û��assign), swap
	g5 = g6; 
	g7 = { 1,2,3,4,6 }; //��ʼֵ�б�ֵ
	initializer_list<int> il = { 1,2,3,2,4,4,6 };
	g8 = il;
	g5.swap(g6);  std::swap(g5, g6); //������ЧO(1)

	//3.�������
	g7.size(); //Ԫ�ظ���
	g7.empty(); //Ԫ�ظ���==0�򷵻�true
	g7.max_size(); //�ܴ洢�����Ԫ�ظ���
	//�Խ����:û��capacity(),reserve(100),resize(25)

	//4.Ԫ�ط���: ��֧���±����,at����, û��front,back�����Ĳ���
	//��ͨ������������������find����Ԫ��

	//5.���������
	set<int>::iterator it1 = g7.begin(); //*it1���ܸ�ֵ
	set<int>::const_iterator it2 = g7.cbegin();
	set<int>::reverse_iterator it3 = g7.rbegin();//*it3���ܸ�ֵ
	set<int>::const_reverse_iterator it4 = g7.crbegin();
	//end()Ҳ��һ��  ʵ����begin()���صĵ�����Ҳ��const��

	//6.�����㷨: count,find,lower_bound,upper_bound,equal_range
	//count: ��׼�㷨��count�Ǳ�����O(N)��,��set����O(logN)
	cout<<g7.count(1)<<" "<<g7.count(10)<<endl;//setֻ����1��0
	cout<<g8.count(2)<<endl; //multiset ����>=0(�п����ж��)
	//find: ��׼�㷨��find�Ǳ���
	auto it5 = g7.find(1); //���ص��ǵ�����
	if (it5 != g7.end()) //��Ҫ��end()�Ƚϲ���֪���Ƿ��и�Ԫ��
		cout << "g7: 1�ҵ���\n";
	else
		cout << "g7: 1û���ҵ�\n";
	//lower_bound,upper_bound,equal_range,��׼�㷨�����������ʵ�����
	auto it6 = g7.lower_bound(5); //���ص�1��>=��Ԫ��λ��
	if (it6 != g7.end()) //g7: 1 2 3 4 6
		cout << "lower_bound 5: " << *it6 << endl; //6��λ��
	it6 = g7.upper_bound(5); //���ص�1��>Ԫ�ص�λ��
	if (it6 != g7.end())
		cout << "upper_bound 5: " << *it6 << endl;//6��λ��
	//��multiset����equal_range
	pair<set<int>::iterator,set<int>::iterator> range_1=g8.equal_range(2); 
	auto range_2 = g8.equal_range(2); //��auto���ӷ���
	//��������2��λ����ɵ�pair 
	//return make_pair(g8.lower_bound(2),g8.upper_bound(2));
	//ʵ���ϣ����緵��pair��first��secondһ�£�˵��û���ҵ���Ԫ��
	//g8: 1 2 2 3 4 4 6
	if (range_1.first!=g8.end()) cout<<"first: "<<*range_1.first<<" -- ";
	else cout << "first: end() -- ";
	if (range_1.second!=g8.end()) cout<<"second: "<<*range_1.second<<endl;
	else cout << "second: end()\n";
	cout << "------------------\n";

	//7.����Ԫ��,û��push_back,emplace_back,push_front,emplace_front�����Ĳ���
	//ֻ��insert �� emplace ����,�ɲ��뵥��Ԫ��,Ҳ�ɲ��������һ����Χ��Ԫ��
	g7.insert(10); //���뵥��Ԫ��(����ֵ������)
	g7.emplace(11); //�������Ԫ�����͵Ĺ������(����ֵͬ��)
	g7.insert(vec.begin(), vec.end()); //����һ����������Χ������void
	g7.insert({ 1,3,9 }); //����һ����ʼֵ�б�, ����void
	//����ֵ: ���� set: ����һ��pair,first:����Ԫ�ص�λ��,second:true����false
	//��Ӧ����set���Ѿ����ڵ�Ԫ��,����pair�� secondΪfalse,������������κ�����
	for (auto& item : g7) cout << item << " "; cout << endl;
	auto r_pair = g7.insert(9); //9�Ѿ�����
	cout << "����Ԫ��:"<<*r_pair.first <<" �Ƿ�ɹ�:"<<r_pair.second << endl;
	r_pair = g7.insert(8); //8�����ڣ������
	cout << "����Ԫ��:" << *r_pair.first <<" �Ƿ�ɹ�:"<<r_pair.second<<endl;
	for (auto& item : g7) cout << item << " "; cout << endl;
	//����ֵ: ����multiset,�����ڲ���ʧ�ܵĸ�����Է��ز���Ԫ�صĵ�����λ��
	auto it9 = g8.insert(2);
	cout << "multiset���벻��ʧ��: "<<*it9 << endl;
	cout << "------------------\n";

	//8.ɾ��Ԫ�� û��pop_back,pop_front�����Ĳ���
	cout <<g7.erase(1)<<endl; // ��Ԫ�ص�ֵ��ɾ��,����ɾ��Ԫ�صĸ���
	for (auto& item : g8) cout << item << " "; cout << endl;
	cout <<g8.erase(2)<<endl; //multiset ���Ԫ��ֵ�� 2 �Ķ�ɾ����
	for (auto& item : g8) cout << item << " "; cout << endl;
	//erase(������λ��),����ɾ��λ�ú����Ԫ��λ��
	auto it11 = g8.find(3);
	if (it11 != g8.end())
		g8.erase(it11); //���ҵ�3��λ��,��ɾ����
	//erase(b,e) ɾ����������Χ,����e
	g8.erase(g8.begin(), g8.end());
	g7.clear(); //���
	//9.�Ƚ����� == != < <= > >= ����

	cout << "------------------\n";
	//�۲�: set��find ��ͨ�� < ����������ҵ�, ��׼�㷨find��ͨ��==
	set<A> a1 = { { "abc",1 },{ "eee",6 },{ "eee",3 },{ "kkk",10 } };
	for (auto& item : a1) cout << item.s1 << ":" << item.d1 << "  ";
	cout << endl;
	auto it = a1.find(A("eee", 3));
	if (it != a1.end()) {
		cout << "A(\"eee\", 3) find! "<<(*it).s1<<":"<<(*it).d1<<endl;
	}
	//std::find(a1.begin(), a1.end(), A("eee", 3)); 
	//������ʾA����û��operator==


	set<B, compB> b1= { { "abc",1 },{ "eee",6 },{ "eee",3 },{ "kkk",10 } };
	for (auto& item : b1) cout << item.s1 << ":" << item.d1 << "  ";
	cout << endl;
	auto it0 = b1.find(B("eee", 3));
	if (it0 != b1.end()) {
		cout << "A(\"eee\", 3) find! " << (*it0).s1 << ":" << (*it0).d1 << endl;
	}

	return 0;
}