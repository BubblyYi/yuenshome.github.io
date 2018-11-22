///map,multimap
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	//map/multimap: һ�� key-value �����ݽṹ
	//map(�ؼ��ֲ����ظ�), multimap(�ؼ��ֿ����ظ�) ͷ�ļ� #include <map> �����
	//template<class K,class V,class cmp=less<K>,class _Alloc=allocator<pair<const K,V>>>
	//class map/multimap...  ��4��ģ�����  ע�⣺ʵ�ʴ�ŵ��� pair<const K,V>
	//map��set����ͬһ����ϵ����������ӿڷ�װ������

	//1.��ʼ��
	map<string, int, less<string>> m1; //Ĭ����less<string>
	map<double, string, greater<double>> m2;
	map<string, int> m3{ {"C++",80},{"Python",90 },{"C",85} };
	map<string, int> m4 = m3; //��������
	map<string, int> m7(m3.begin(), m3.end()); //��������Χ
	multimap<string, int> m8 = 
			{ {"C++",80},{"Python",90},{"C",85},{"C",83} };
	for (const auto& item : m8)
		cout << item.first << ":" << item.second << "  ";
	cout << endl;
	cout << "------------------\n";
	//2.��ֵ (û��assign), swap ����set��ͬ
	m3 = m4; m4 = { { "C++",80 },{ "Python",90 } };
	m3.swap(m4); std::swap(m3, m4);
	//3.�������,��setһ��
	m4.size(); m4.empty(); m4.max_size();
	
	//4.Ԫ�ط��� 
	//map���±��at����,multimapû��(��Ϊkey�����ظ�,��֪���ĸ�key)
	//m7.at("D"); ��Ϊû���ҵ�,at�����쳣�����Բ�����ʹ��
	m7["C"] = 100; 
	cout << m7["C"] << " " << m7.at("C") << endl;
	//�����±��Ӧ��keyû���ҵ�,���Զ�����һ��key,valueĬ�ϳ�ʼ��
	cout << m7["JAVA"] << endl; //"JAVA"û��,�Զ�����,value=0
	cout << "------------------\n";

	//5.���������,��setһ��
	//6.�����㷨,��set����
	cout << m7.count("C++") << endl; //1
	cout << m8.count("C") << endl;   //2
	auto it1 = m7.find("C++");
	if (it1 != m7.end()) { //�ҵ�
		//ע��: �����������õõ����� һ�� pair<const string,int>
		cout << (*it1).first << ":" << (*it1).second << endl;
		pair<const string, int> &pa1 = *it1; //ע��const
	}
	//lower_bound, upper_bound, equal_range��set����

	//7.���� insert emplace
	//map����ͨ���±�ֱ�Ӳ���,multimap����
	//ֱ���±��൱��: auto it=m7.insert(make_pair(string("PHP"),0)).first;
	//               return (*it).second; //��value�����÷��� 
	m7["PHP"] = 99; //û��"PHP"ֱ�Ӳ���,�����޸����Ӧ�� value
	pair<map<string, int>::iterator, bool> res = m7.insert({ "GO",60 });
	cout << (*res.first).first << ":" << (*res.first).second << endl;
	cout << "�Ƿ�ɹ��� "<<res.second << endl;
	m7.insert(pair<string, int>("GO", 60));
	m7.insert(make_pair("GO", 60));
	m8.emplace("CPP", 30);
	m8.insert(m7.begin(), m7.end());

	//8.ɾ�� erase ��setһ��
	m7.erase("C");
	m7.erase(m7.begin(), m7.end());

	return 0;
}