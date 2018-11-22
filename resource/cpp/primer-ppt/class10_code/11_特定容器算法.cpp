//list,forward_list�ض��㷨(��Ա����)
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

//list,forward_list�ض��㷨(��Ա����)
int main() {
	//1. reverse() ��ת����
	forward_list<int> f1 = { 1,2,3,4,5 };
	//reverse(f1.begin(), f1.end()); ����,��Ҫ˫�������,list���Ե�Ч�ʲ���
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	f1.reverse(); //��ת
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	cout << "----------------\n";

	//2.remove(val),remove_if(pred) ɾ��  Ԫ��==val, pred����Ϊ��
	//remove(l1.begin(), l1.end(), 2);
	f1.remove(2); //����ɾ����Ԫ��2
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	f1 = { 1,2,3,4,5 };
	remove(f1.begin(), f1.end(), 2); //��Ȼ����,����������ɾ��,Ч�ʵ�
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	cout << "----------------\n";

	//3.unique(),unique(pred) ȥ�ظ�, == , pred����Ϊ�� ������ȥ��,Ҫ������
	f1 = { 1,2,2,3,3,3,4,5,5 };
	f1.unique(); //�ظ���ɾ����
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	cout << "----------------\n";

	//4.sort(),sort(comp)
	//sort(l1.begin(), l1.end()); ����,sort�㷨Ҫ������ʵ�����
	f1 = { 3,2,1,2,3,4,9 };
	f1.sort();
	for (const auto& item : f1) { cout << item << " "; } cout << endl;
	f1.sort([](const int& t1, const int& t2) {if (t1 > t2) return 1; return 0; });
	for (const auto& item : f1) { cout << item << " "; } cout << endl; //�Ӵ�С
	cout << "----------------\n";

	//5.merge(lst2), merge(lst2,comp) ���������, <����, comp����Ϊ��
	//�ϲ�2����������
	list<int> l1 = { 1,3,5,7,9 }, l2 = { 2,4,6,8,10 }, l3;  //���㷨merge: l2����
	merge(l1.begin(), l1.end(), l2.begin(), l2.end(), back_inserter(l3));
	for (const auto& item : l3) { cout << item << " "; } cout << endl;

	l1 = { 1,3,5,7,9 };	l2 = { 2,4,6,8,10 };
	l1.merge(l2); //l2 ���ݱ����
	for (const auto& item : l1) { cout << item << " "; } cout << endl;
	for (const auto& item : l2) { cout << item << " "; } cout << endl;
	cout << "----------------\n";

	//6.splice(p,lst2)  splice_after(p,lst2) 
	//��lst2���뵽p��λ�� (����forward_list����p���λ��)
	l1 = { 1,3,5,7,9 };	l2 = { 2,4,6,8,10 };
	l1.splice(++l1.begin(), l2); //��l2�嵽3��λ��,l2�������
	for (const auto& item : l1) { cout << item << " "; } cout << endl;
	for (const auto& item : l2) { cout << item << " "; } cout << endl;
	
	forward_list<int> f0 = { 1,3,9,4,5 }, f2 = {13,11,12};
	auto it1 = next(f0.before_begin(), 3); //it1��9��λ��
	f0.splice_after(it1, f2);
	for (const auto& item : f0) { cout << item << " "; } cout << endl;
	
	//splice(p,lst2,p2) ��lst2��p2��ʼ��Ԫ���ƶ��� ��ǰ�б��pλ��
	//splice(p,lst2,b,e) b,e����lst2�е�һ��ϵ�з�Χ
	//splice_after(p,lst2,p2)
	//splice_after(p,lst2,b,e)


	return 0;
}