//(5)nullptr
void f(int a, char* p = NULL) { cout << 1; }
void f(int a, int b = 0) { cout << 2; }
int main() {
	f('a'); //��ȷ��
	f('a', 0); //������٣�
	f(10.2, NULL); //������٣�
	f(1, nullptr); //������٣�
	return 0; 
}