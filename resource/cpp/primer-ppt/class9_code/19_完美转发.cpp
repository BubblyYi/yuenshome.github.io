#include <iostream>
#include <utility>
using namespace std;

template<class TT> 
TT&& my_forward(typename remove_reference<TT>::type& tt) {
	cout << "my_forward: 1\n";
	return (static_cast<TT&&>(tt));
}

template<class TT>
TT&& my_forward(typename remove_reference<TT>::type&& tt){
	cout << "my_forward: 2\n";
	return (static_cast<TT&&>(tt));
}

void inner(const int& i){ cout << "left: " << i << std::endl;}
void inner(int&& i){ cout << "right: " << i << std::endl; }

template <typename T> void outer_1(T&& i) { inner(i); }
template <typename T> void outer_2(T&& i) { inner(my_forward<T>(i)); }
template <typename T> void outer_3(T&& i) { inner(std::forward<T>(i)); }

int main() {
	int i = 10;
	outer_1(i); //T: int&, i������int&
	outer_1(42);//T: int, ��Ȼ������ֵ,��������ֵ���ý����Ժ�תΪ��ֵ
	cout << "--------\n";
	outer_2(i); //T: int&, TT: int&, typename remove_reference<TT>::type --> int, tt: int&, TT&&: int& &&-->int&(��ֵ)
	outer_2(42);//T: int,  TT: int,  typename remove_reference<TT>::type --> int, tt: int&, TT&&: int&&-->int&&(��ֵ)
	cout << "--------\n";
	outer_3(i);
	outer_3(42);
	return 0;
}
