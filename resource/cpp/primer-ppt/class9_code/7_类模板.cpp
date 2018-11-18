#include <iostream>
#include <cassert>
using namespace std;

template <typename T,int MAXSIZE>
class MyStack{
public:
	MyStack():size(0){}
	MyStack(const MyStack& other):size(other.size){ //����ʵ��
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];
	}
	MyStack& operator=(const MyStack& other);
	bool empty()const { return size == 0; }//����ʵ��,��ʽ����
	bool full()const { return size == MAXSIZE; }
	void push(const T& elem) { 
		assert(!full()); data[size++] = elem;
	}
	void pop() { assert(!empty()); size--; }
	inline T& top();
private:
	T data[MAXSIZE]; //ջ����
	int size;		 //Ԫ�ظ���
};
template<typename T,int MAXSIZE>
MyStack<T, MAXSIZE>& MyStack<T, MAXSIZE>::operator=
			(const MyStack/*<T, MAXSIZE>*/ &other) {
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];
	}
	return *this;
}
template<typename T,int MAXSIZE>
T& MyStack<T,MAXSIZE>::top() {
	assert(!empty());
	return data[size - 1];
}
int main() {
	MyStack<int, 10> st1;
	st1.push(1);
	st1.pop();
	MyStack<int, 20> st2;
	st2.empty();
	//st1��st2��ͬһ���͵Ķ�����
	//MyStack<int, 10> �� 
	//MyStack<int, 20>ʵ�����ĳ�Ա������
	return 0;
}