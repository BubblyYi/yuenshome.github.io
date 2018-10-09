#include <iostream>
#include <memory>
#include <functional>
using namespace std;
class T {
public:
	T(int i = 0) :data(i) { cout << "T����\n"; }
	~T() { cout << "T����\n"; }
	void show()const { cout << data << endl; }
private:
	int data;
};
//ֵ���ݣ�����
void print1(unique_ptr<T> p) {
	p->show();
}
//���ô���: 
void print2(const unique_ptr<T> &p) {
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
	unique_ptr<T> p1; //��ָ��
	//explicit����,ֻ��ֱ�ӳ�ʼ��
	//unique_ptr<T> p2 = new T(100); //����
	unique_ptr<T> p2(new T(100));
	//û��use_count(),unique(),��Ϊû�����ü���
	(*p2).show(); //100 ��Ϊ��ָ�� *
	p2->show();   //100 ��Ϊ��ָ�� ->
	if (p2) cout << "p2 not null!\n";

	//û����ͨ�������캯��
	//unique_ptr<T> p3(p2); //����
	//unique_ptr<T> p3 = p2;//����
	//û����ͨ��ֵ
	//p1 = p2; //����

	//�����ƶ�����
	unique_ptr<T> p3 = std::move(p2);
	if (!p2) cout << "p2 empty\n";
	//�����ƶ���ֵ
	p1 = std::move(p3);

	T* p = p1.get(); //��ȡ��ָ��
	p->show(); //100
	
	//release(),��������Ȩ,����ָ��
	//p1.release(); //��,release�����ͷ���Դ
	p = p1.release();
	p->show(); //ע�⣬p����ָ��,Ҫdelete����

	unique_ptr<T> p4(p); //���½ӹ�

	p4.reset(); //�ͷ�p4�������Դ
	cout << "----------\n";

	unique_ptr<T> p5(new T(200));
	//���ͷŹ������Դ���ٽӹ�����Դ
	p5.reset(new T(300));
	cout << "==========\n";

	//����ָ����Ϊ��������
	print1(std::move(p5)); //ֵ����
	unique_ptr<T> p6(new T(400));
	print2(p6); //���ô���
	print(*p6);
	cout << "----------------\n";

	//ɾ������
	unique_ptr<T, function<void(T*)>> p11(new T[3], del_T_arr);
	unique_ptr<T, function<void(T*)>> p12(new T[3]{ 7,8,9 }, [](T* p)->void {delete[] p; });
	cout << "===============\n";
	return 0;
}