#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main() {
	//����һ��allocator����Ϊ������string�Ķ�������ڴ�
	allocator<string> alloc;
	//����һ��ԭʼ�ġ�δ������ڴ棬���Ա���10��string����
	string * const  p = alloc.allocate(10);
	string* q = p;
	alloc.construct(q++); //��q��λ�ù������(Ĭ�Ϲ���)
	alloc.construct(q++, 5, 'A'); // "AAAAA"
	alloc.construct(q++, "ABC");  // "ABC"
	//ִ�ж������������
	while (q != p)
		alloc.destroy(--q);
	//�ͷ�һ���ڴ棬p��ǰ��allocte()���ص�ָ��,�ڴ���еĶ���
	//�����Ѿ��������Ѿ����ù�destroy()��
	alloc.deallocate(p, 10);

	vector<string> vec = {"abc","xyz","c++","python"};
	string * const p1 = alloc.allocate(vec.size()+3);
	//ͨ������vec�е�Ԫ��������� p1 ��ʼ��Ԫ��
	string * q1 = uninitialized_copy(vec.begin(), vec.end(), p1);
	//ʣ��Ԫ�س�ʼ��Ϊ "hello"
	q1 = uninitialized_fill_n(q1, 3, "hello");
	string *q2 = p1;
	while (q2 != q1)
		cout << *q2++<<"\t";
	cout << endl;
	return 0;
}