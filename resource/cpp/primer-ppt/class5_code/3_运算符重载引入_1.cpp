#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	Point(int _x = 0, int _y = 0)
		:x(_x), y(_y) {}
private:
	int x, y;
};
int main() {
	int i1 = 10, i2 = 20;
	int i3 = i1 + i2; //�ӷ�����
	string s1 = "abc", s2 = "123";
	string s3 = s1 + s2; //string��ʵ�ֵ� ���������

	Point p1(10, 20), p2(20, 30);
	//Point p3 = p1 + p2; //���У��������
	//Point p3 = point_add(p1, p2);//���������ֱ��
	//Point p3 = p1.point_add(p2); //���������ֱ��
	return 0;
}