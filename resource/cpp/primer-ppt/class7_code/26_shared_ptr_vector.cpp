#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Base {
public:
	virtual void show()const = 0;
protected:
	virtual ~Base() =default;
//������private������,����D1�޷�����
};
class D1 : public Base {
public:
	D1(int i) :data(i) { }
	virtual void show()const override{
		cout << data << " ";
	}
private:
	int data;
};
shared_ptr<Base> createBase(int data) {
	shared_ptr<Base> p = make_shared<D1>(data);
	return p;
}

int main() {
	vector<shared_ptr<Base>> vec;
	for (int i = 0; i<10; ++i) 
		vec.push_back(createBase(i));
	
	vector<shared_ptr<Base>>::iterator end = vec.end();
	for (auto it = vec.begin(); it != end; ++it) 
		(*it)->show();
	cout << endl;

	Base* p = vec[0].get();
	//delete p; //����,��ֹdelete ��ָ��
	//ͨ��get��õ���ָ�벻��delete,��ΪBase��������protected
	//ֻ��shared_ptr���ԣ�unique_ptr���С�
}