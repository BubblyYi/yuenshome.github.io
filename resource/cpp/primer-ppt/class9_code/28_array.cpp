///array
#include <iostream>
#include <utility>
#include <string>
#include <array>
using namespace std;

int main() {
	//array(û�пռ�������) #include <array> (ԭ�������һ����װ)
	//��ȷ֪�����Ҫ���ٸ�Ԫ�أ����Կ���array
    //ֱ�� array<int,10> a; Ԫ������ջ�ϵġ�ע���С��ջ�ռ����ޣ�

	//template<class _Ty, size_t _Size> class array{ _Ty _Elems[_Size]; ...}
	//1����ʼ��
	array<int, 10> a1;  //Ĭ�Ϲ���,ֵû�г�ʼ��
	array<int, 3> a2{}; //ֵ��ʼ��,����0
	array<string, 4> a3 = { "abc" }; //��1�����б��ʼ��,�����Ĭ�ϳ�ʼ��""
	array<int, 3> a4(a2);
	array<int, 3> a5 = a2;//����(��������������,�������鲻����������)
	array<string, 4> a6 = std::move(a3); //�ƶ�,ÿ��Ԫ�ض�ִ���ƶ�(�򿽱�)
	//array<int, 3> a7(a2.begin(), a2.end()); ��֧�ֵ�������Χ��ʼ��
	//array<int, 6> a8(6);
	//array<int, 6> a8(6,0); ָ������Ԫ�صĳ�ʼ������
	
	//2.��ֵ
	a5 = a4; //�������鲻֧�ָò���
	a5 = { 2,3 }; //�ó�ʼ���б�ֵ
	//��֧�� assign����
	a5.fill(9); //����Ԫ�ض���ֵΪ9
	
	//3.swap����,2��array����,O(n)ʱ�临�Ӷ�(ÿ��Ԫ�ؽ���)
	array<int, 10> a10 = { 1,2,3 };
	array<int, 10> a11 = { 5,6,7,8 };
	a10.swap(a11);
	std::swap(a10, a11); //ͬ��
	//4.�������
	a10.size(); //Ԫ�ظ���,ͬ������ģ�����
	a10.empty(); //���� array<int,0> a10;���򲻿���Ϊtrue
	a10.max_size(); //ͬsize()
	//����Ķ���֧��
	//a10.capacity(); //a10.reserve(100); //a10.resize(25);
	
	//5.Ԫ�ط���, ��vectorһ��
	a10[2] = 10; //�±����,Ҫ��֤�±겻Խ��,����δ������
	a10.at(1) = 20;//�±�Խ����out_of_range�쳣
	a10.front(); //��1��Ԫ�ص�����
	a10.back(); //���һ��Ԫ�ص�����

	//6.��������� , �ߴ�Ҫƥ��,��vectorһ��
	array<int, 10>::iterator it1 = a10.begin();
	array<int, 10>::const_iterator it2 = a10.cbegin();
	array<int, 10>::reverse_iterator it3 = a10.rbegin();
	array<int, 10>::const_reverse_iterator it4 = a10.crbegin();
	
	//7.����Ԫ��,������
	//8.ɾ��Ԫ��,������ clear()Ҳû��
	
	//9. == != < > <= >= ����, ��������Ҫһ��
	array<int, 2> a12 = { 1,2 };
	array<int, 3> a13 = { 1,2,3 };
	//cout << (a12 == a13) << endl; ����,���Ͳ�ƥ��
	
	//10.C�ӿ� ͬvector
	array<char, 10> a16 = {'a','b','c','\0'};
	printf("%s\n", a16.data()); //abc
	//printf("%s\n", a16.begin()); //��
	printf("%s\n", &(*a16.begin())); //OK
	return 0;
}
