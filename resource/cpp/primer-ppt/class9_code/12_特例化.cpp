#include <iostream>
using namespace std;

template<typename T>
void f1(const T&) { cout << "const T&\n"; }
//f1����ģ���һ��������, T Ϊ int,ʵ�ֿ��Բ�ͬ
template<> void f1(const int&) { cout << "const int &\n"; }
//�������ı�����ʵ����һ��ģ��,���������ء�

//��ģ��A
template<typename T1,typename T2>
class A {
public:
	A(const T1& _t1,const T2& _t2):t1(_t1),t2(_t2){}
	inline void show()const;
private:
	T1 t1;
	T2 t2;
};
template<typename T1, typename T2>
inline void A<T1,T2>::show()const {
	cout << t1 << " " << t2 << endl;
}

//1.��ģ��A ��һ��������,T1=int,T2=double,��ȫ�Լ�ʵ��
template<>
class A<int, double> {
public:
	A(const int& _t1,const double& _t2):t1(_t1), t2(_t2) {}
	inline void show()const;
private:
	int t1;
	double t2;
};
//ע�������Ա������д��(template)
inline void A<int, double>::show()const {
	cout << "��:" << t1 << " " << t2 << endl;
}
//2.��ģ��A ֻ������һ����Ա����
template<>
inline void A<char, char>::show()const {
	cout << "��show:" << t1 << " " << t2 << endl;
}

//3.����������
template <typename T1,typename T2> class B {};//��ģ��B
//��ģ��B������������
template<typename T> class B<T, T> {};
template<typename T> class B<T, int> {};
template<typename T1,typename T2> class B<T1*, T2*> {}; 

int main() {
	f1(1.2); //���ݺ���ģ��ʵ���� f1(const double&)
	f1(1);	 //ʹ���������� f1(const int&)
	
	A<double, char> a1(2.2, 'c'); //ʵ����
	a1.show(); // 2.2 c
	A<int, double> a2(1,1.2);     //ʹ��������
	a2.show(); //��: 1 1.2
	A<char, char> a3('a', 'b');   //ʵ����,����show��������������
	a3.show(); //��show: a b

	B<double, char> b1;    //ʹ�� B<T1,T2>
	B<double, double> b2;  //ʹ�� B<T,T>
	B<double, int> b3;     //ʹ�� B<T,int>
	B<int*, double*> b4;   //ʹ�� B<T1*,T2*>
	//B<int, int> b5; �����Դ� B<T,T>��B<T,int>ͬ�ȳ̶�ƥ��
	//B<int*, int*> b6; �����Դ� B<T,T>��B<T1*,T2*>ͬ�ȳ̶�ƥ��
	//int*,int* ���ṩ����һ�������� 	template<typename T> class B<T*,T*>{};
	return 0;
}