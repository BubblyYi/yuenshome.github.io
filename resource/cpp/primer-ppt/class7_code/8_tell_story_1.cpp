#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	string getContent()const {
		return "�ܾúܾ���ǰ����һ��...";
	}
};

class Mother {
public:
	void tellStory(const Book& b) {
		cout << "���迪ʼ������: " 
			<< b.getContent() << endl;
	}
};

int main() {
	Book book;
	Mother m;
	m.tellStory(book);
	return 0;
}