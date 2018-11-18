#include <iostream>
using namespace std;

class Base{};
class D1:public Base{};

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T* p=nullptr)
		:ptr(p), count(new int(p ? 1 : 0)) { }
	~SmartPtr() {
		if(--(*count)<=0){delete ptr;delete count;}
	}
	void swap(SmartPtr& rhs) {
		std::swap(ptr, rhs.ptr);
		std::swap(count, rhs.count);
	}
	//��������
	SmartPtr(const SmartPtr& rhs) 
		:ptr(rhs.ptr), count(&(++*rhs.count)) {}
	template<typename U> 
	SmartPtr(const SmartPtr<U>& rhs)
		:ptr(rhs.ptr), count(&(++*rhs.count)) {}
	//��ֵ
	SmartPtr& operator=(const SmartPtr& other);
	template<typename U>
	SmartPtr& operator=(const SmartPtr<U>& other);
private:
	T* ptr;
	int* count;
	//���е�SmartPtr<...>����SmartPtr<...>����Ԫ
	template<typename X> friend class SmartPtr;
	//friend class Test<T>; 
	//Test<int> �� Smart<int>����Ԫ,ƥ�����
};

template<typename T>
template<typename U> //�����ܴ�
SmartPtr<T>& SmartPtr<T>::operator=
					(const SmartPtr<U>& other){
	SmartPtr(other).swap(*this);
	return *this;
}
template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=
					(const SmartPtr& other) {
	SmartPtr(other).swap(*this);
	return *this;
}
int main() {
	//����ָ��ָ�����������
	Base *pb = new D1;
	delete pb;

	SmartPtr<Base> s_pb1 = SmartPtr<D1>(new D1);
	SmartPtr<Base> s_pb2;
	s_pb2 = s_pb1;
	s_pb2 = SmartPtr<D1>(new D1);
	return 0;
}