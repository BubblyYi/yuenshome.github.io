#include <iostream>
#include <string>
using namespace std;
class Book {
public:
	string getContent()const {
		return "�ܾúܾ���ǰ����һ��...";
	}
};
class Newspaper {
public:
	string getContent()const {
		return "�����賿��̨��...";
	}
};
class Mother {
public:
	void tellStory(const Book& b) {
		cout << "���迪ʼ������: " 
			<< b.getContent() << endl;
	}
	void tellStory(const Newspaper& b) {
		cout << "���迪ʼ������: "
			<< b.getContent() << endl;
	}
};
int main() {
	Book book;
	Mother m;
	m.tellStory(book);
	Newspaper paper;
	m.tellStory(paper);
	return 0;
}