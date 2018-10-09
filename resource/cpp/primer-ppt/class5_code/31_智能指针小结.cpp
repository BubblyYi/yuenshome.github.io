#include <iostream>
#include <memory>
using namespace std;
void fun(shared_ptr<int> ptr) { /*...*/ }
int main() {
	//1.һ����ָ�벻Ҫ������shared_ptr��unique_ptr������
	int *pi = new int(1); //��д�����Ĵ���
	shared_ptr<int> pi1(pi);
	//shared_ptr<int> pi2(pi); //��
	shared_ptr<int> pi2 = pi1; //ֻ��������

	//2.��Ҫ������ָͨ�������ָ��
	shared_ptr<int> px1 = make_shared<int>(2);
	fun(px1); //ok,���ü���+1
	cout << *px1 << endl; //ok

	int *px = new int(2);
	//fun(px); //��,shared_ptr<int> ptr = px;����
	fun(shared_ptr<int>(px)); //��Ȼ�������У����ǣ�
	cout << *px << endl; //��ʱ px�Ѿ����ͷ��ˣ���

	//3.��Ҫʹ��get��ʼ�����߸�ֵ����һ������ָ��
	shared_ptr<int> p(new int(3));
	int *p1 = p.get(); //��ȡp�������ָ��,ok
	{
		//shared_ptr<int> p2(p1); //�����Ƶ�1��
	}

	//4.��Ҫdelete get()���ص���ָ��
	int *p2 = p.get();
	//delete p2; //�������ͷ�
	return 0;
}