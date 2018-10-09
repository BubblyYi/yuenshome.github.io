#include <iostream>
#include <memory>
using namespace std;
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
class Child;
typedef std::shared_ptr<Child> ChildPtr;
typedef std::weak_ptr<Parent> WeakParentPtr;
typedef std::weak_ptr<Child> WeakChildPtr;
class Parent {
public:
	Parent() { cout << "Parent����\n"; }
	~Parent() { cout << "Parent����\n"; }
	WeakChildPtr child;
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
	cout << "parent: " << p.use_count() << endl;//2
	cout << "child: " << c.use_count() << endl; //1
	return 0;
}