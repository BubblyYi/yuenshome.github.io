///deque
#include <iostream>
#include <utility>
#include <string>
#include <deque>
using namespace std;
struct A {
	A(const string& ss1 = "", int i1 = 0) :s1(ss1), d1(i1) {}
	string s1;
	int d1;
};
int main() {
	//deque ˫�˶��� #include <deque>
	//�������Ԫ�أ�ͷ����β�����ɾ��Ԫ��Ч�ʺܸߣ��м�ɾ�������Ч�ʵ͡�
	//Ԫ�صķ��ʺ͵�����vectorҪ������������������ͨ��ָ�롣
	//template<class _Ty, class _Alloc = allocator<_Ty>> class deque ...	
	//1.��ʼ��,��vectorһ��
	deque<int> d1; //Ĭ�Ϲ���
	deque<int> d2{ 1,2,3 };
	deque<double> d3 = { 1.0,2.0,3.0 }; //��ʼ���б�
	deque<int> d4(d2);
	deque<int> d5 = d2; //��������
	deque<double> d6(d2.cbegin(), d2.cend()); //��������Χ,Ԫ�ؿ�ת������
	deque<string> d7(10); //10��Ԫ�أ�ÿ�����ǿմ�
	deque<string> d8(8, "abc"); //8��Ԫ�أ�ÿ������"abc"

	//2.��ֵ,��vectorһ��
	d8 = d7;
	d8 = { "aaa","bbb","ccc" }; //�ó�ʼ���б�ֵ
	d8.assign(d7.cbegin(), d7.cend()); //��������Χ��ֵ
	d8.assign({ "aa","bb","cc" }); //��ʼֵ�б�ֵ
	initializer_list<string> il = { "a","b","c" };
	d8.assign(il);
	d8.assign(10, "abc");  //��10��"abc"��ֵ

	//3.swap ��vectorһ��,O(1)
	deque<int> d10, d11{ 1,2,3 };
	d10.swap(d11);	std::swap(d10, d11);

	//4.������� û��capacity��reserve,������vectorһ��
	d10.size(); //Ԫ�ظ���
	d10.empty(); //Ԫ�ظ���==0�򷵻�true
	d10.max_size(); //�ܴ洢�����Ԫ�ظ���
	//d10.capacity(); dequeû��
	//d10.reserve(100); dequeû��
	cout << d10.size() << endl;
	d10.resize(25); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����ֵ��ʼ�����Ԫ��
	d10.resize(30, 2); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����2���Ԫ��
	d10.shrink_to_fit(); //��������,���ǲ���ǿ���Ե�,ֻ��֪ͨstl���Խ�������
	
	//5.Ԫ�ط��� ��vectorһ�� [] at front back
	//6.��������� ��vector array һ��
	
	//7.����Ԫ��  ����push_front,emplace_front ������vectorһ��
	//push_back,emplace_back,emplace,insert
	deque<A> d12;
	d12.push_front(A("123", 1)); //ͷ�����Ԫ��
	if (!d12.empty()) d12.pop_front(); //ͷ��ɾ��Ԫ��
	d12.emplace_front("abc", 2);

	//8.ɾ��Ԫ�� ����pop_front ������vectorһ��
	d12.pop_front(); //ɾ����1��Ԫ��
	d12.clear(); //�������Ԫ��,�п����ͷſռ�(һ���ͷſռ�)
	//9.��ϵ���� ��vectorһ��
	return 0;
}
