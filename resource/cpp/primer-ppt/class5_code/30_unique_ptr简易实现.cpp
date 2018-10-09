#include <iostream>
#include <memory>
#include <cassert>
using namespace std;
class T {
public:
	T(int i = 0) :data(i) { cout << "T����\n"; }
	~T() { cout << "T����\n"; }
	void show()const { cout << data << endl; }
private:
	int data;
};
class Unique_ptr {
public:
	Unique_ptr():ptr(nullptr) {	}
	explicit Unique_ptr(T* p):ptr(p){ }
	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr& operator=(const Unique_ptr&) = delete;
	Unique_ptr(Unique_ptr&& other) noexcept//�ƶ�����
		:ptr(other.ptr) { 
		other.ptr = nullptr;
	}
	Unique_ptr& operator=(Unique_ptr&& other) noexcept {
		if (this == &other) return *this; //�ƶ���ֵ
		del();
		std::swap(ptr, other.ptr);
		return *this;
	}
	~Unique_ptr() { //����
		del();
	}
public:
	T& operator*() {
		assert(ptr);
		return *ptr;
	}
	T* operator->() {
		assert(ptr);
		return ptr;
	}
	operator bool()const {
		return nullptr != ptr;
	}
	T* release() { //��������Ȩ
		T* p = ptr;
		ptr = nullptr;
		return p;
	}
	void reset(T* new_p=nullptr) {//����
		del();
		ptr = new_p;
	}
	T* get() { return ptr; } //������ָ��
private:
	void del() { delete ptr; ptr = nullptr; }
private:
	T* ptr; //�������Դ
};

int main() {
	Unique_ptr p1; //��ָ��
	//Unique_ptr p2 = new T(100); //����
	Unique_ptr p2(new T(100));
	(*p2).show(); //100 ��Ϊ��ָ�� *
	p2->show();   //100 ��Ϊ��ָ�� ->
	if (p2) cout << "p2 not null!\n";

	//�����ƶ�����
	Unique_ptr p3 = std::move(p2);
	if (!p2) cout << "p2 empty\n";
	//�����ƶ���ֵ
	p1 = std::move(p3);

	T* p = p1.get(); //��ȡ��ָ��
	p->show(); //100
	p = p1.release();
	p->show(); //100 ע�⣬p����ָ��,Ҫdelete����

	Unique_ptr p4(p); //���½ӹ�
	p4.reset(); //�ͷ�p4�������Դ
	cout << "----------\n";

	Unique_ptr p5(new T(200));
	//���ͷŹ������Դ���ٽӹ�����Դ
	p5.reset(new T(300));
	cout << "==========\n";
	return 0;
}