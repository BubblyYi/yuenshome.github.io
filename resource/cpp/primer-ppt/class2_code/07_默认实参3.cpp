#include <iostream>
using namespace std;
void f1(int a, int b = 0); //��һ������
//void f1(int a, int b = 0); //����
void f1(int a, int b); //OK
void f1(int a = 0, int b); //OK

//void f1(int a, int b = 0) {} //����
void f1(int a, int b) {} //OK