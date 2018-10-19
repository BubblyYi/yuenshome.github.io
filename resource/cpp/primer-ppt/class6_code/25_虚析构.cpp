#include <iostream>
using namespace std;
class Base {
public:
	~Base() { cout << "Base����\n"; }
};
class D1 :public Base {
public:
	D1():pi(new int(0)){ }
	~D1() { delete pi; cout << "delete\n"; }
	int * pi;
};

class Base2 {
public:
	virtual ~Base2() { cout << "Base����\n"; }
};
class D2 :public Base2 {
public:
	D2() :pi(new int(0)) { }
	~D2() { delete pi; cout << "delete\n"; }
	int * pi;
};

int main() {
	Base *pb = new D1;
	delete pb;
	//pb�ľ�̬������ Base,���Ի���� Base������
	//D1������û�����е����ڴ�й©
	cout << "------------\n";

	Base2 *pb2 = new D2;
	delete pb2;
	//��ΪBase2�������������麯��
	//�����ڵ���pb2������ʱ,�������ʵ�����͵�����
	//pb2��ʵ��������D2��ָ��,��ȷ�ͷ��ڴ�
	return 0;
}