///forward_list
#include <iostream>
#include <utility>
#include <string>
#include <forward_list>
using namespace std;

int main() {
	//forward_list �������� #include <forward_list>
	//��֧���������Ԫ�أ�����ͷ��Ԫ�غܿ졣�κ�λ�ò���ɾ��Ԫ�ض��ܿ죬O(1)
	//�����ɾ��������ɵ�����ʧЧ���ռ�ɱ��ϸߣ���1��ָ�룩,��list��ʡ
	//����д��C���ĵ��������,û���κ�ʱ��Ϳռ��ϵĶ��⿪��(����û��size)
	//template<class _Ty,class _Alloc = allocator<_Ty>> class forward_list
	
	//1.��ʼ��,��vector listһ��
	forward_list<int> l1; //Ĭ�Ϲ���
	forward_list<int> l2{ 1,2,3 };
	forward_list<double> l3 = { 1.0,2.0,3.0 }; //�б��ʼ��
	forward_list<int> l4(l2);
	forward_list<int> l5 = l2; //��������
	//��������Χ��ʼ��,��������������,ֻҪԪ��������ת��(��������һ��)
	forward_list<double> l6(l2.cbegin(), l2.cend());
	forward_list<string> l7(9);
	forward_list<string> l8(9, "aaa"); //9��Ԫ��,"aaa"

	//2.��ֵ  ��vector listһ��
	l1 = l2; //����Ҫһ��
	l2 = { 2,3,4 }; //��ʼֵ�б�ֵ
	l2.assign({ 1,2,3 });
	l2.assign(10, 0);
	l2.assign(l1.cbegin(), l1.cend());

	//3.swap ��vectorһ��
	//4.������� ����ҪԤ��׼���ռ�
	//l2.size(); forward_list û��Ԫ�ظ���size()����
	l2.empty(); //Ԫ�ظ���==0�򷵻�true
	l2.max_size(); //�ܴ洢�����Ԫ�ظ���
	//l2.capacity(); ͬlist û��
	//l2.reserve(100); ͬlist û��
	l2.resize(25); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����ֵ��ʼ�����Ԫ��
	l2.resize(30, 2); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����2���Ԫ��
	//l2.shrink_to_fit(); ����ҪԤ��׼���ռ�,��1��Ԫ�ؿ���1���ռ�

	//5.Ԫ�ط��� �����������,ͷ��,β�����м���
	//l2[1] = 2; list ����
	//12.at(1) = 20; list ����
	if (!l2.empty()) l2.front() = 10; //��1��Ԫ�ص�����
	//l2.back(); forward_listû��
	
    //6.��������� ��vectorһ��,��Ϊ��˫������,���з��������ok
	forward_list<int>::iterator it1 = l2.begin();
	forward_list<int>::const_iterator it2 = l2.cbegin();
	//forward_list<int>::reverse_iterator û�� rbegin() û��
	//forward_list<int>::const_reverse_iteratorû�� crbegin()û��
	forward_list<int>::iterator it3 = l2.before_begin(); //���
	forward_list<int>::const_iterator it4 = l2.cbefore_begin();//���

	//7.����Ԫ�� ��list������
	//l2.push_back(100); ��֧��
	l2.push_front(100); //ͷ������,ok
	l2.emplace_front(101); //ͷ������
	//emplaceû���ˣ�����emplace_after
	l2.emplace_after(l2.before_begin(), 102); //��befor_begin()�����102
	//insertû���ˣ�����insert_after, �ڵ�����λ�ú������
	//����ָ�����1������Ԫ�صĵ����� (���������������ص�1����Ԫ�صĵ�����)
	l2.insert_after(std::next(l2.before_begin(), 2), 103);
	l2.insert_after(l2.before_begin(), l1.cbegin(), l1.cend());

	//8.ɾ��Ԫ�� ��list������
	if(!l2.empty()) l2.pop_front(); //ɾ����1��Ԫ��
	//l2.pop_back(); û��
	//ɾ��������λ�ú����Ԫ��,����void,(��������:ָ��ɾԪ�غ���Ԫ�صĵ�����)
	l2.erase_after(l2.before_begin()); //ɾ��1��Ԫ��
	//ɾ����������Χ,����void,(��������:�������1��ɾ��Ԫ��֮��Ԫ�صĵ�����)
	for (const auto& item : l2) cout << item << " "; cout << endl;
	l2.erase_after(l2.cbegin(), l2.end()); //��1��Ԫ��û��ɾ��
	for (const auto& item : l2) cout << item << " "; cout << endl;
	l2.erase_after(l2.cbefore_begin(), l2.end()); //ȫ��ɾ����
	for (const auto& item : l2) cout << item << " "; cout << endl;
	l2.clear(); //�������Ԫ��

	//9.��ϵ����, ����list == != < > <= >=
	return 0;
}
