#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class MyException :public logic_error {
public:
	explicit MyException(int i,const char* s):logic_error(s),index(i){}
	int index;
};
class A {
public:
	A(int n) {
		//assert(n >= 0); ֱ�Ӷ���
		if (n < 0) throw invalid_argument("����ʼ��n>=0");
		vec_data.resize(n, 100);
	}
	int & operator[](int i) {
		//assert(i >= 0 && i < vec_data.size()); Ч������
		if (i < 0 || i >= vec_data.size())
			throw MyException(i, "Խ�������");
		return vec_data[i];
	}
private:
	vector<int> vec_data;
};

int main() {
	try {
		A a(-1);
	}
	catch (invalid_argument &e) {
		cout << e.what() << endl;
	}
	catch (MyException &e) {
		cout << e.what() << " index=" << e.index << endl;
	}

	try {
		A a(10);
		cout << a[11];
	}
	catch (invalid_argument &e) {
		cout << e.what() << endl;
	}
	catch (MyException &e) {
		cout << e.what() << " index=" << e.index << endl;
	}

	return 0;
}