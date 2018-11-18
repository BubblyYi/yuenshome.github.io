///list
#include <iostream>
#include <utility>
#include <string>
#include <list>
using namespace std;
struct A {
	A(const string& ss1 = "", int i1 = 0) :s1(ss1), d1(i1) {}
	string s1;
	int d1;
};
int main() {
	//list ˫������ #include <list>
	//��֧���������Ԫ�أ�����ͷ����β��Ԫ�غܿ졣�κ�λ�ò���ɾ��Ԫ�ض��ܿ죬O(1)
	//�����ɾ��������ɵ�����ʧЧ���ռ�ɱ��ϸߣ���2��ָ�룩
	//template<class _Ty, class _Alloc = allocator<_Ty>> class list ...
	//1.��ʼ�� ��vectorһ��
	list<int> l1; //Ĭ�Ϲ���
	list<int> l2{ 1,2,3 };
	list<double> l3 = { 1.0,2.0,3.0 }; //��ʼ���б�
	list<int> l4(l2);
	list<int> l5 = l2; //��������
	list<double> l6(l3.cbegin(), l3.cend()); //��������Χ
	list<string> l7(10);
	list<string> l8(10, "abc"); //10��Ԫ�أ�ÿ������"abc"

	//2.��ֵ  ��vectorһ��
	l1 = l2; //����Ҫһ��
	l2 = { 2,3,4 }; //��ʼֵ�б�ֵ
	l2.assign({ 1,2,3 });
	l2.assign(10, 0);
	l2.assign(l1.cbegin(), l1.cend());

	//3.swap ��vectorһ��
	//4.������� ����ҪԤ��׼���ռ�
	l2.size(); //Ԫ�ظ���
	l2.empty(); //Ԫ�ظ���==0�򷵻�true
	l2.max_size(); //�ܴ洢�����Ԫ�ظ���
	//l2.capacity(); listû��capacity(���������������Ĳ���)
	//l2.reserve(100); û��
	l2.resize(25); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����ֵ��ʼ�����Ԫ��
	l2.resize(30, 2); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����2���Ԫ��
	//l2.shrink_to_fit(); ����ҪԤ��׼���ռ�,��1��Ԫ�ؿ���1���ռ�

	//5.Ԫ�ط��� �����������,ͷβ��,�м���
	//l2[1] = 2; list ����
	//12.at(1) = 20; list ����
	if (!l2.empty()) l2.front() = 1; //��1��Ԫ�ص�����
	if (!l2.empty()) l2.back() = 2; //���һ��Ԫ�ص�����
	//��Ҫ���ʵ�5��Ԫ�أ�(list�����м��Ԫ��Ҫ����)
	list<int> l10 = { 1,2,3,4,5,6,7 };
	auto it = l10.begin();
	for (int i = 0; i < 4; ++i) ++it;
	cout << *it << endl;
	it = l10.begin();
	std::advance(it, 4); //it��������ǰ�ƶ�4��
	cout << *it << endl;
	it = l10.begin();
	auto it0=std::next(it,4);//��it��ǰ��4��,��it����,����ֵ���ƺ��λ��
	cout << *it0 << "  " << *it << endl;

    //6.��������� ��vectorһ��,��Ϊ��˫������,���з��������ok
	//7.����Ԫ�� ֧�� push_front(����deque) ������vectorһ��
	//push_back,emplace_back,emplace,insert
	l10.push_front(100);

	//8.ɾ��Ԫ�� ֧��pop_back pop_front
	if(!l10.empty()) l10.pop_back(); //ɾ�����1��Ԫ��
	if (!l10.empty()) l10.pop_front();//ɾ����1��Ԫ��
	//ɾ��������λ�õ�Ԫ��,����ָ��ɾԪ�غ���Ԫ�صĵ�����,����������end(),����Ϊδ����
	l10.erase(l10.begin());
	//ɾ����������Χ,�������1��ɾ��Ԫ��֮��Ԫ�صĵ�����
	l10.erase(l10.begin() /*+1��֧��*/, l10.end());
	l10.clear(); //�������Ԫ��

	//9.��ϵ����, ����vector == != < > <= >=
	return 0;
}
