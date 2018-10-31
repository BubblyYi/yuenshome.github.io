/// .c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_fun1(int i) {
	if (i >= 0) {
		//do something...
		return 1;
	}
	//do something...
	return 0;
}

char* my_malloc1(int size) {
	char* p = (char*)malloc(size);
	return p;
}

int error_no = 1;
double triangle_area1(double a, double b, double c) {
	if (!(a + b > c && a + c > b && b + c > a)) {
		error_no = 0;
		return 0.0;
	}
	double p = (a + b + c) / 2;
	double area = sqrt(p*(p - a)*(p - b)*(p - c));
	error_no = 1;
	return area;
}

int main() {
	//1.���÷���ֵ��ȷ���Ƿ���ȷִ��
	int ret = my_fun1(10);
	if (0 == ret) {
		//ʧ���ˣ��������...
	}
	else {
		//�ɹ��ˣ��������...
	}
	//2.����ֵ�����ж��Ƿ�ɹ���Ҳ���䱾������
	char* pc1 = my_malloc1(100);
	if (!pc1) {
		//û�ɹ����������...
	}
	//�ɹ��ˣ�����ִ��...
	//3.��ȫ�ֱ��� error_no���жϴ���
	double s1 = triangle_area1(3, 4, 5);
	if (0 == error_no)
		printf("���������߳��ȹ�ϵ����ȷ��\n");
	else
		printf("���=%f\n", s1);
	s1 = triangle_area1(2, 2, 4);
	if (0 == error_no)
		printf("���������߳��ȹ�ϵ����ȷ��\n");
	else
		printf("���=%f\n", s1);
	return 0;
}