#ifndef __CONTACT_H__
#define __CONTACT_H__
#include<stdio.h>
#include<string.h>
#include<assert.h>
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT,
};
#define MAX 1000
#define MAX_NAME 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[SEX_MAX];
	short int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;
typedef struct Contact
{
	PeoInfo data[MAX];//�������
	int sz;//ͨѶ¼����Ч��Ϣ����
}Contact;

void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
#endif //__CONTACT_H__