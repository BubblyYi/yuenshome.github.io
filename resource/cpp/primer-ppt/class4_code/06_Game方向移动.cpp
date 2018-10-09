#include <iostream>
using namespace std;

class Game {
public:
	using Action = void(Game::*)(); //������� ��Ա����ָ��
	enum Direction { LEFT, RIGHT, UP, DOWN }; //ö��
	void move(Direction d) {
		(this->*menu[d])();
	}
private:
	void left() { cout << "left" << endl; }
	void right() { cout << "right" << endl; }
	void up() { cout << "up" << endl; }
	void down() { cout << "down" << endl; }
	static Action menu[]; //����ָ�� ����
};

Game::Action Game::menu[] = {	&Game::left,
								&Game::right,
								&Game::up,
								&Game::down };

int main(){
	Game g;
	g.move(Game::LEFT);
	g.move(Game::RIGHT);
	g.move(Game::UP);
	g.move(Game::DOWN);
	return 0;
}