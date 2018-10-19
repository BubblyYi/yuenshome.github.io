#include <iostream>
using namespace std;
class Base {
public:
	void f_pub(){}
	int i_pub;
protected:
	void f_pro(){}
	int i_pro;
private:
	void f_pri() {}
	int i_pri;
};

class D1 :public Base { //public�̳�
public:
	void test() {
		//�������ڷ���
		f_pub();   //���ʻ���public��Ա����,ok
		i_pub = 10;//���ʻ���public���ݳ�Ա,ok
		f_pro();   //���ʻ���protected��Ա����,ok
		i_pro = 20;//���ʻ���protected���ݳ�Ա,ok
		//f_pri();   ���ʻ���private��Ա����,error
		//i_pri = 30;���ʼ�¼private���ݳ�Ա,error
	}
};

class D2 :protected Base {  //protected�̳�
public:
	void test() {
		//�������ڷ���
		f_pub();   //���ʻ���public��Ա����,ok
		i_pub = 10;//���ʻ���public���ݳ�Ա,ok
		f_pro();   //���ʻ���protected��Ա����,ok
		i_pro = 20;//���ʻ���protected���ݳ�Ա,ok
		//f_pri();   ���ʻ���private��Ա����,error
		//i_pri = 30;���ʼ�¼private���ݳ�Ա,error
	}
};

class D3 :private Base {  //private�̳�
public:
	void test() {
		//�������ڷ���
		f_pub();   //���ʻ���public��Ա����,ok
		i_pub = 10;//���ʻ���public���ݳ�Ա,ok
		f_pro();   //���ʻ���protected��Ա����,ok
		i_pro = 20;//���ʻ���protected���ݳ�Ա,ok
		//f_pri();   ���ʻ���private��Ա����,error
		//i_pri = 30;���ʼ�¼private���ݳ�Ա,error
	}
};
int main() {
	//�����������
	D1 d1; //D1 public �̳�
	d1.f_pub();    //���ʻ���public��Ա����,ok
	d1.i_pub = 10; //���ʻ���public���ݳ�Ա,ok
	//d1.f_pro();    ���ʻ���protected��Ա����,error
	//d1.i_pro = 20; ���ʻ���protected���ݳ�Ա,error
	//d1.f_pri();    ���ʻ���private��Ա����,error
	//d1.i_pri = 30; ���ʼ�¼private���ݳ�Ա,error

	D2 d2; //D2 protected �̳�
	//d2.f_pub();    ���ʻ���public��Ա����,error
	//d2.i_pub = 10; ���ʻ���public���ݳ�Ա,error
	//d2.f_pro();    ���ʻ���protected��Ա����,error
	//d2.i_pro = 20; ���ʻ���protected���ݳ�Ա,error
	//d2.f_pri();    ���ʻ���private��Ա����,error
	//d2.i_pri = 30; ���ʼ�¼private���ݳ�Ա,error

	D3 d3; //D3 private �̳�
	//d3.f_pub();    ���ʻ���public��Ա����,error
	//d3.i_pub = 10; ���ʻ���public���ݳ�Ա,error
	//d3.f_pro();    ���ʻ���protected��Ա����,error
	//d3.i_pro = 20; ���ʻ���protected���ݳ�Ա,error
	//d3.f_pri();    ���ʻ���private��Ա����,error
	//d3.i_pri = 30; ���ʼ�¼private���ݳ�Ա,error
	return 0;
}