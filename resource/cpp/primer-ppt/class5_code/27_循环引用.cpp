///ѭ������
#include <iostream>
#include <memory>
using namespace std;
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
class Child;
typedef std::shared_ptr<Child> ChildPtr;
class Parent {
public:
	Parent() { cout << "Parent����\n"; }
	~Parent() { cout << "Parent����\n"; }
	ChildPtr child;
};
class Child {
public:
	Child() { cout << "Child����\n"; }
	~Child() { cout << "Child����\n"; }
	ParentPtr parent;
};
int main() {
	ParentPtr p = make_shared<Parent>();
	ChildPtr c = make_shared<Child>();
	p->child = c;
	c->parent = p;
	//�۲����н����������Դû�б��ͷ�
	cout<<"parent: "<<p.use_count()<<endl;//2
	cout<<"child: "<<c.use_count()<<endl; //2
	return 0;
}