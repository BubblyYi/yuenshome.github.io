#include <iostream>
using namespace std;
class A {
public:
	A(int i = 0) :pi(new int(i)) { cout << "A����\n";}
	~A() {cout << "A������\n"; delete pi; }
	void show()const { cout << *pi << endl; }
private:
	int* pi;
};
char g_buf[200];
int main() {
	void* pbuf = malloc(100);
	//��λnew,�� pbuf��ַ������ʼ��һ������
	//1.�ڴ��� �ѿռ�
	A *pa1 = new(pbuf) A(1);
	pa1->show();  //������ȷ���� 1
	cout << pbuf << endl;
	cout << pa1 << endl;
	pa1->~A(); //��ʽ��������
	free(pbuf);
	cout << "-------------------\n";
	char buf[200];
	//2.�ڴ��� ջ�ռ�
	A* pa2 = new(buf) A(2);
	pa2->show(); //������ȷ���� 2
	cout << (void*)buf << endl;
	cout << pa2 << endl;
	// delete pa2; //���󣬶�λnew�����Ķ�����delete
	pa2->~A(); //��ʽ��������
	cout << "-------------------\n";
	//3.�ڴ���data��
	A* pa3 = new(g_buf) A(3);
	pa3->show(); //������ȷ���� 3
	cout << (void*)g_buf << endl;
	cout << pa3 << endl;
	pa3->~A();
	return 0;
}