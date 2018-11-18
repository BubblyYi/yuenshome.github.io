#include <iostream>
using namespace std;

template<typename T>
class Base {
public:
	Base(const T& d):data(d){}
	void set_data(const T& d) { data = d; }
	virtual void show()const { cout << "Base show: data="<<data<<" "; }
	virtual ~Base(){}
private:
	T data;
};
template<> class Base<double> { //double������ȡ���� set_data����
public:
	Base(const double& d) :data(d) {}
	//void set_data(const double& d) { data = d; }
	virtual void show()const { cout << "Base show: data=" << data << " "; }
	virtual ~Base() {}
private:
	double data;
};

template<typename T>
class D1 :public Base<T> {
public:
	D1(const T& d1,const T& d2):Base<T>(d1),data2(d2){}
	void set_d1_data(const T& d1, const T& d2) {
		this->set_data(d1); //����this
		data2 = d2;
	}
	virtual void show()const override{ 
		Base<T>::show(); //��ʽ���û����Ա����
		cout << "D1 show: data2="<<data2<<endl; 
	}
private:
	T data2;
};

int main() {
	D1<int> d1(1,2);
	d1.show();
	d1.set_d1_data(10, 20);
	d1.show();

	Base<int> *pb = &d1; 
	pb->show(); //�麯����������

	D1<double> d2(111, 222);
	d2.show();
	//d2.set_d1_data(11, 22); 
	//����,double����û��ʵ��set_data()
	//ֻҪ������ set_d1_data,ʵ��������
	return 0;
}