#include <iostream>
using namespace std;

int main() {
	//1.auto ���������ڶ���ʱ��ʼ����������const
	auto i1 = 0; auto i2 = i1;
	//auto i3; //���󣬱����ʼ��
	//2.�����ʼ�����ʽ�����ã���ȥ����������
	int a1 = 10;
	int &a2 = a1; // a2������
	auto a3 = a2; // a3��int���ͣ�����������
	auto &a4 = a1; // a4�� ����
	//3.ȥ������const
	const int b1 = 100;
	auto b2 = b1; // b2 �� int
	const auto b3 = b1; // b3�� const int
	//4.���ϵײ�const
	auto &b4 = b1; // b4 �� const int ������
	//5.��ʼ�����ʽΪ����ʱ���Ƶ�����Ϊָ��
	int arr[3] = { 1,2,3 };
	auto parr = arr; //parr �� int * ����
	cout << typeid(parr).name() << endl;
	//6.���ʽΪ������auto����&���Ƶ�����Ϊ����
	auto &rarr = arr; //rarr �� int [3]
	cout << typeid(rarr).name() << endl;
	//7.�����������Ͳ����� auto
	//func(auto arg); //����
	//8.auto������һ������������,����ʱȷ��
	//sizeof(auto); ����
	return 0;
}