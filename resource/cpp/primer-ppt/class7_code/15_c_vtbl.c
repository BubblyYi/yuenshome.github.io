#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��ͬ�Ķ����ͬ�Ľ���,��ͬ���ж���ʽ
typedef void(*SING)();
typedef void(*MOVE)();
struct vtbl { //ģ���麯����
	SING sing; //����ָ��
	MOVE move;
};

//���ࣺAnimal
struct Animal {
	//ָ������ָ��
	const struct vtbl *ptr_vtbl;
	//��������ƣ�(��������)
	char name[16];
};

//�����ࣺDog
struct Dog {
	struct Animal base;
	int x; //Dog˽�е�����
};
//Dog��sing��move����
void dog_sing() { printf("Dog:������\n"); }
void dog_move() { printf("Dog:�����\n"); }
//Dog����麯����vtbl
const struct vtbl dog_vtbl={dog_sing,dog_move};
//����Dog����
struct Animal *create_dog(const char* name) {
	assert(name);
	struct Dog *p_dog = 
		(struct Dog*)malloc(sizeof(struct Dog));
	assert(p_dog); 
	p_dog->base.ptr_vtbl = &dog_vtbl; 
	strcpy(p_dog->base.name, name);
	p_dog->x = 10;
	//���棺��Dog������麯����󶨵� ���ָ��
	return (struct Animal*)p_dog;
}

//�����ࣺMaque (��ȸ)
struct Maque {
	struct Animal base;
	int y; //Maque��˽������
};
//Maque��sing��move����
void maque_sing() { printf("Maque:������\n"); }
void maque_move() { printf("Maque:�Ϳ����ҷ�\n"); }
//Maque���麯����vtbl
const struct vtbl maque_vtbl={maque_sing,maque_move};
//����Maque����
struct Animal *create_maque(const char* name) {
	assert(name);
	struct Maque *p_maque =
		(struct Maque*)malloc(sizeof(struct Maque));
	assert(p_maque); 
	p_maque->base.ptr_vtbl = &maque_vtbl;
	strcpy(p_maque->base.name, name);
	p_maque->y = 20;
	return (struct Animal*)p_maque;
}

int main() {
	struct Animal *p = NULL;
	//����ָ�� ָ�����������
	p = create_dog("С��");
	p->ptr_vtbl->sing();
	p->ptr_vtbl->move();
	free(p); printf("-------\n");
	p = create_maque("��ȸ");
	p->ptr_vtbl->sing();
	p->ptr_vtbl->move();
	free(p);
	return 0;
}