///unordered_set,unordered_map��
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
	//0.set��unordered_set�ıȽ�(map��unordered_mapҲ��һ��)��
	set<int> set1 = { 3,2,1,2,4,6 };
	unordered_set<int> uset1 = { 3,2,1,2,4,6 };
	unordered_multiset<int> umset1 = { 3,2,1,2,4,6 };
	for (auto& item : set1) cout << item << " "; cout << endl; //1 2 3 4 6 ����
	for (auto& item : uset1) cout << item << " "; cout << endl;//3 2 1 4 6 ����
	for (auto& item : umset1) cout << item << " "; cout << endl;//3 2 2 1 4 6 ����
	//(unordered_multiset����ȵ�Ԫ�أ������һ��)
	cout << "------------------------\n";

	//1.��ʼ��
	unordered_map<string, int, hash<string>> g1;//Ĭ�Ͼ��� hash<string>
	unordered_multimap<int, double> g2 = { {1,1.1},{2,2.2} };
	unordered_map<string, int> g3{ { "C++",80 },{ "Python",90 },{ "C",85 } };
	unordered_map<string, int> g4(g3); 
	unordered_map<string, int> g5 = g3; //��������
	unordered_map<string, int> g7(g3.begin(), g3.end()); //��������Χ��ʼ��
	
	//2.��ֵ,swap
	g4 = g3;
	unordered_multimap<string, int> g8;
	g8 = { { "C++",80 },{ "Python",90 },{ "C",85 },{ "C",85 } };
	g4.swap(g3); std::swap(g3, g4);

	//3.�������
	g7.size();   g7.empty();   g7.max_size();
	cout << "g7��Ͱ������: "<<g7.bucket_count()<<endl; //��ǰͰ����
	g7.max_bucket_count(); //���������ɵ�����Ͱ����
	for (int i = 0; i < g7.bucket_count(); i++) //�ڼ���Ͱ��Ԫ�صĸ���
		cout << "��" << i << "��Ͱ��Ԫ������: " << g7.bucket_size(i) << endl;
	cout << "\"C++\"��Ͱ: "<<g7.bucket("C++") << endl;//����ĳ���ؼ������ĸ�Ͱ��
	cout << "------------------------\n";
	
	//4.��ϣ����
	cout << "ÿ��Ͱ��ƽ��Ԫ������(double): " << g7.load_factor() << endl;
	cout << g7.max_load_factor() << endl; 
	//c++��ͼά����ƽ��Ͱ��С,��Ҫʱ������µ�Ͱ,ʹ�� load_factor<=max_load_factor
	g7.rehash(10); //����洢,ʹ�� bucket_count(Ͱ��) >= n
	g7.reserve(100); //����洢,ʹ���������Ա���n��Ԫ��

	//5.����,һ��(set,map), unordered_map ���±�,at����, multimapû��
	g7["C++"] = 10; g7["JAVA"] = 100; 
	try { g7.at("C");}catch(...){ }
	
	//6.���������
	unordered_map<string, int>::iterator it01 = g7.begin();
	unordered_map<string, int>::const_iterator it02 = g7.cbegin();
	//û�з��������, ������ Ͱ������local_iterator, const_local_iterator
	//��ʾ��n��Ͱ����Ԫ��(begin(n),cbegin(n))��β�������(end(n),cend(n))
	unordered_map<string, int>::local_iterator it03 = g7.begin(0); 

	//7.����,һ��,insert,emplace, �����±����
	//8.ɾ��(erase) ��һ��
	//9.�����㷨һ��,find,count,lower_bound, upper_bound, equal_range
	
	return 0;
}