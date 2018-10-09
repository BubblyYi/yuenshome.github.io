///shared_ptr�÷�
#include <iostream>
#include <memory>
using namespace std;
class T {
public:
	T(int i = 0) :data(i) { cout << "T����\n"; }
	~T() { cout << "T����\n"; }
	void show()const { cout << data << endl; }
private:
	int data;
};
//ֵ���ݣ����������ü���+1
void print1(shared_ptr<T> p) {  
	cout <<"ֵ: "<< p.use_count() << endl;
	p->show();
}
//���ô���: ���ü�������+1
void print2(const shared_ptr<T> &p) { 
	cout << "����: "<<p.use_count() << endl;
	p->show();
}
void print(const T& obj) {
	cout << "���������\n";
	obj.show();
}
void del_T_arr(T* parr) { //ɾ����
	delete[] parr;
}
//shared_ptr �÷�(�ӿ�)��
int main() {
	shared_ptr<T> p1; //��ָ��
	//use_count() ���ü���(ͬʱ�м���ָ��ָ�����)
	cout << p1.use_count() << endl; //0
	//unique(),use_count()==1����true,����false
	cout << p1.unique() << endl; //0

	//shared_ptr<T> p2= new T(1);//����,explicit����
	shared_ptr<T> p2(new T(10));
	cout << p2.use_count() << endl; //1
	cout << p2.unique() << endl; //1
	(*p2).show(); //10 ��Ϊ��ָ�� *
	p2->show();   //10 ��Ϊ��ָ�� ->
	if (p2) cout << "p2 not null!\n";

	shared_ptr<T> p3 = p2; //��������
	shared_ptr<T> p4(p2);  //��������
	cout << p2.use_count() << endl; //3
	cout << p4.use_count() << endl; //3
	cout << p3.unique() << endl; //0

	//�Ƽ��������ķ�ʽ��ʼ��
	shared_ptr<T> p5 = make_shared<T>(20);
	//��������ָ���б������ָ�룬����ʹ�ã�
	T* p = p5.get();
	p->show(); //20

	shared_ptr<T> p6;
	p6 = p5; //��ֵ

	//reset() �޲���ʱ,���ٹ�����Դ,��ζ��count--,���ܻ��ͷ���Դ
	p3.reset(); 
	cout << p2.use_count() << endl; //2
	//reset(T* p),���ٹ���ԭ��Դ,�ӹ��µ���Դ(��ָ��)
	cout << p4.use_count() << endl; //2
	p4.reset(new T(30));
	cout << p4.use_count() << endl; //1

	//swap() ������Դ
	p4->show(); //30
	p4.swap(p5); 
	p4->show(); //20
	std::swap(p4, p5); //Ч���� p4.swap(p5)һ��

	//����ָ����Ϊ��������
	print1(p4); //ֵ����
	print2(p4); //���ô���
	print(*p4);
	cout << "--------------------\n";
	//ɾ������
	shared_ptr<T> p11(new T[3], del_T_arr);
	shared_ptr<T> p12(new T[3]{7,8,9}, [](T* p) {delete[] p; });
	T* pa = p12.get();
	pa = pa + 2;
	pa->show();
	cout << "--------------------\n";
	return 0;
}