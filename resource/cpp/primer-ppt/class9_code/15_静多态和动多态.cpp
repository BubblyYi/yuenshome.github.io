#include <iostream>
using namespace std;

class Shape {
public:
	virtual void show()const = 0;
	virtual ~Shape() = default;
};
class Rectangle :public Shape { //�̳��Գ������
public:
	virtual void show()const override { cout << "Rect show\n"; }
};
class Circle :public Shape {
public:
	virtual void show()const override{ cout << "Circle show\n"; }
};
void my_show(const Shape& obj) { //��ͨ����
	obj.show(); //��������,�麯������ʵ�ֶ�̬
}

class Rectangle_1 { //û�м̳й�ϵ
public:
	void show()const { cout << "Rect_1 show\n"; }
};
class Circle_1 {
public:
	void show()const { cout << "Circle_1 show\n"; }
};
template<typename T> //����ģ��
void my_show_1(const T& obj) {
	obj.show();
}
int main() {
	//����̬��
	Rectangle r1;
	Circle c1;
	my_show(r1);
	my_show(c1);
	//����̬
	Rectangle_1 r2;
	Circle_1 c2;
	//my_show_1<Rectangle_1>(const Rectangle_1 &) 
	my_show_1(r2); 
	//my_show_1<Circle_1>(const Circle_1 &)
	my_show_1(c2); 
	return 0;
}