///stack
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct A {
	A(const string& s, int d) :s1(s), d1(d) {}
	string s1; int d1;
};
int main() {
	//stack ջ(�Ƚ����), Ĭ���� dequeʵ�� ��������������#include <stack>
	//template<class _Ty,class _Container=deque<_Ty>>class stack;
	stack<int> s1; //Ĭ�Ϲ���(��dequeʵ��)
	stack<int, vector<int>> s2; //Ĭ�Ϲ���(��vectorʵ��)
	//stack<int> s1 = { 1,2,3 }; ����
	stack<int> s3(s1);
	stack<int> s4 = s1; //��������

	s4 = s1; //��ֵ,û��assign
	s4.swap(s1);
	std::swap(s4, s1); //���Ը�Чswap
	cout << s4.size() << endl;  //��ǰԪ�ظ���
	cout << s4.empty() << endl; //�Ƿ�Ϊ��,�շ���true

	//��֧�ֵ�����,Ҳû�� begin,end �Ȳ���

	//����Ԫ�أ�
	stack<A> s5;
	s5.push(A("abc", 1)); //ͬ����const T& ��T&&
	A a1("aaa", 2);
	s5.push(a1);
	s5.emplace("ccc", 4); //��ͬpush,����������A�Ĺ������

	//����Ԫ�أ�ֻ�ܷ���ջ��Ԫ��
	s5.top() = { "bbb",3 }; //top()���ص�����ֵ����
	cout << s5.top().s1 << s5.top().d1 << endl;

	//ɾ��Ԫ�أ�ֻ��ɾ��ջ��Ԫ��
	if (!s5.empty()) s5.pop(); //pop()����void

	return 0;
}
