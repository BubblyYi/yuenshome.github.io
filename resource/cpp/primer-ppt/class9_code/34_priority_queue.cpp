///priority_queue
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct A {
	A(const string& s, int d) :s1(s), d1(d) {}
	string s1; int d1;
};
struct compare_A {
	bool operator()(const A& lhs, const A& rhs)const {
		//�ȱȽ� s1,�ٱȽ� d1
		if (lhs.s1 < rhs.s1) return true;
		if (!(rhs.s1 < lhs.s1) && lhs.d1 < rhs.d1) return true;
		return false;
	}
};
int main() {
	//priority_queue ���ȼ�����(���������������ȳ�), 
	//Ĭ����vectorʵ�� ��������������#include <queue>
	//template<class _Ty, class _Container = vector<_Ty>,
	//	class _Pr = less<typename _Container::value_type> >
	//	class priority_queue;

	//Ĭ�Ϲ���(��vectorʵ��,���ȼ��ıȽ���<,�󶥶�,�������ȳ���)
	//ʹ��Ĭ�ϵ� less<T> ����Ԫ��Ҫʵ�� < �����
	priority_queue<int> q1; 
	priority_queue<int> q2 = q1; //��������
	q1.swap(q2);
	std::swap(q1, q2); //��Ч����
	cout << q1.size() << endl;
	cout << q1.empty() << endl;
	
	//��֧�ֵ�����,Ҳû�� begin,end �Ȳ���

	//ʹ���Զ���ıȽϺ���,Ҫ������ģ�������д����
	priority_queue<A, vector<A>,compare_A> q3;

	//����
	q3.push(A("123",4));
	q3.push(A("123",2));
	q3.push(A("abc",13));
	q3.push(A("abc", 5)); //��Ԫ�����Ͷ���
	q3.emplace("abb", 2); //���������
	
	//����Ԫ��,ֻ��top(),û��front, back
	cout << q3.top().s1 << "--" << q3.top().d1 << endl;

	//ɾ��Ԫ��:
	if(!q3.empty()) q3.pop();
	
	return 0;
}