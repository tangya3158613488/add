#include<iostream>
#include<unordered_map>
using namespace std;

struct DLinkedNode
{
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;
	DLinkedNode()
		: key(0)
		, value(0)
		, prev(nullptr)
		, next(nullptr)
	{}
	DLinkedNode(int _key, int _value)
		:key(_key)
		, value(_value)
		, prev(nullptr)
		, next(nullptr)
	{}
};

class LRUCache
{
private:
	unordered_map<int, DLinkedNode*> cache;
	DLinkedNode* head;
	DLinkedNode* tail;
	int size;
	int capacity;

public:
	LRUCache(int _capacity)
		: capacity(_capacity)
		, size(0)
	{
		//ʹ��αͷ����αβ���ڵ�
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key)
	{
		if (!cache.count(key))
		{
			return -1;
		}
		//���key���ڣ���ͨ����ϣ��λ�����ƶ���ͷ��
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}
	void put(int key,int value)
	{
		if (!cache.count(key))
		{
			//���key�����ڣ�����һ���µĽڵ�
			DLinkedNode* node = new DLinkedNode(key, value);
			//��ӽ���ϣ��
			cache[key] = node;
			addToHead(node);
			++size;
			if (size > capacity)
			{
				//�������������ɾ��˫�������β���
				DLinkedNode* removed = removeTail();
				//ɾ����ϣ���ж�Ӧ����
				cache.erase(removed->key);
				//��ֹ�ڴ�й©
				delete removed;
				--size;
			}
		}
		else
		{
			//���key���ڣ���ͨ����ϣ��λ�����޸�value�����Ƶ�ͷ��
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}
private:
	DLinkedNode* removeTail()
	{
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
	void moveToHead(DLinkedNode* node)
	{
		removeNode(node);
		addToHead(node);
	}
	void removeNode(DLinkedNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void addToHead(DLinkedNode* node)
	{
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
};

int main()
{
	LRUCache LRU(10);
	LRU.put(2, 7);
	LRU.put(3, 5);
	LRU.put(5, 6);
	LRU.put(1, 4);
	LRU.put(8, 9);
	LRU.put(1, 7);
	
	LRU.get(2);
}