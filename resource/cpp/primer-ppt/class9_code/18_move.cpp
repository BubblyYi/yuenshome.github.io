#include <iostream>
#include <string>

template<typename T>
struct remove_reference {
	typedef T type; 
};

template<typename T>
struct remove_reference<T&> {
	typedef T type;
};

template<class T>
struct remove_reference<T&&> {
	typedef T type;
};

template<typename T>
inline typename remove_reference<T>::type&& move(T&& t) {
	return (static_cast<typename remove_reference<_Ty>::type&&>(t));
}

// move(string("abc")); //��ֵ
//1.�ƶϳ� T �������� string
//2.remove_reference<string> ʵ����(��1��)
//3.remove_reference<string>��type��Ա�� string
//4.move�ķ��������� string&&
//5.move�����Ĳ��� t �������� string&&
//�˵���ʵ���� move<string>: ���� string&& move(string&& t);

// string s1="abc"; move(s1); //��ֵ
//1.�ƶϳ� T �������� string&
//2.remove_reference<string&> ʵ����(��2��)
//3.remove_reference<string&>��type��Ա�� string
//4.move�ķ��������� string&&
//5.move�����Ĳ��� t �������� string& &&,�۵�Ϊ string&
//�˵���ʵ���� move<string&>: ���� string&& move(string& t);

int main() {
	remove_reference<int>::type i1;
	remove_reference<int&>::type i2;
	remove_reference<int&&>::type i3;
	//�����������Ͷ��� int (�൱��ȥ��������)
	return 0;
}