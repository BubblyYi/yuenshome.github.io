///queue
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct A {
	A(const string& s,int d):s1(s),d1(d){}
	string s1; int d1;
};
int main() {
	//queue ����(�Ƚ��ȳ�), Ĭ���� dequeʵ�� ��������������#include <queue>
	//template<class _Ty,class _Container=deque<_Ty>>class stack;
	queue<int> q1; //Ĭ�Ϲ���(��dequeʵ��)
	//queue<int, vector<int>> q2; ����vector,û��pop_front()
	//queue<int> q = { 1,2,3 }; ����
	queue<int> q3(q1);
	queue<int> q4 = q1; //��������
	
	q4 = q1; //��ֵ,û��assign
	q4.swap(q1);
	std::swap(q4, q1); //���Ը�Чswap
	cout << q4.size() << endl;  //��ǰԪ�ظ���
	cout << q4.empty() << endl; //�Ƿ�Ϊ��,�շ���true;
	
	//��֧�ֵ�����,Ҳû�� begin,end �Ȳ���
	
	//����Ԫ�أ�
	queue<A> q5;
	q5.push(A("abc", 1)); //ͬ����const T& ��T&&
	A a1("aaa", 2);
	q5.push(a1);
	q5.emplace("ccc", 4); //��ͬpush,����������A�Ĺ������

	//����Ԫ�أ�ֻ�ܷ��ʶ���ͷ����β��Ԫ��
	q5.back() = { "bbb",3 }; //back()���ص�����ֵ����
	q5.front(); //����ͷ��Ԫ��

	//ɾ��Ԫ�أ�ֻ��ɾ��ջ��Ԫ��
	if (!q5.empty()) q5.pop(); //pop()����void

	return 0;
}