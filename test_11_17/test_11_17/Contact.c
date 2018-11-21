#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
void InitContact(Contact* pcon)
{
	assert(pcon != NULL);
	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));
}
void destroyContact(Contact* pcon)
{

	assert(pcon != NULL);
	//�������ݵ��ļ�
	SaveContact(pcon);
	free(pcon->data);
	pcon->data = NULL;
	pcon->sz = 0;
	pcon->capacity = 0;
} 
void LoaContact(Contact* pcon)
{
	FILE* pf = fopen("contact.dat", "rb");
	PeoInfo tmp = { 0 };
	int i = 0;
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//������
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pcon);
		pcon->data[pcon->sz++] = tmp;
	}
	fclose(pf);
	pf = NULL;

}
void SaveContact(Contact* pcon)
{
	FILE* pf = fopen("contact.dat", "wb");
	int i = 0;
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//д����
	for (i = 0; i < pcon->sz; i++)
	{
		fwrite(pcon->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

int CheckCapacity(Contact* pcon)
{

	assert(pcon != NULL);
	if (pcon->capacity == pcon->sz)
	{
		//����
		PeoInfo *ptr = realloc(pcon->data, (pcon->capacity + INC_SZ)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pcon->data = ptr;
			pcon->capacity += INC_SZ;
			printf("���ݳɹ�\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void AddContact(Contact* pcon)
{
	assert(pcon != NULL);
	//���������ĺ���
	if (CheckCapacity(pcon) == 0)
	{
		printf("ͨѶ¼�������������ݣ�ʧ�ܣ��޷����\n");
		return;
	}
		printf("����������:>");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("����������:>");
		scanf("%d", &(pcon->data[pcon->sz].age));
		printf("�������Ա�:>");
		scanf("%s", &(pcon->data[pcon->sz].sex));
		printf("������绰:>");
		scanf("%s", &(pcon->data[pcon->sz].tele));
		printf("�������ַ:>");
		scanf("%s", &(pcon->data[pcon->sz].addr));
		pcon->sz++;
		printf("��ӳɹ�\n");
}
void ShowContact(const Contact* pcon)
{
	assert(pcon != NULL);
	int i = 0;
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�","�绰","��ַ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n", pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}
static int FindEntry(Contact* pcon, char name[])
{
	int i = 0;
	assert(pcon != NULL);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name)==0)
		{
			return i;//�ҵ���
		}
	}
	return -1;//û�ҵ�
}
void DelContact(Contact* pcon)
{
	int pos = 0;
	assert(pcon != NULL); 
	char name[MAX_NAME] = { 0 };
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
	}
	else
	{
		printf("������Ҫɾ���˵�����:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
		}
		else
		{
			//ɾ��
			int i = 0;
			for (i = pos; i <pcon->sz-1; i++)
			{
				pcon->data[i] = pcon->data[i + 1];
			}
			pcon->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}