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
		//使用伪头部和伪尾部节点
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
		//如果key存在，先通过哈希表定位，再移动到头部
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}
	void put(int key,int value)
	{
		if (!cache.count(key))
		{
			//如果key不存在，创建一个新的节点
			DLinkedNode* node = new DLinkedNode(key, value);
			//添加进哈希表
			cache[key] = node;
			addToHead(node);
			++size;
			if (size > capacity)
			{
				//如果超出容量，删除双向链表的尾结点
				DLinkedNode* removed = removeTail();
				//删除哈希表中对应的项
				cache.erase(removed->key);
				//防止内存泄漏
				delete removed;
				--size;
			}
		}
		else
		{
			//如果key存在，先通过哈希表定位，再修改value，并移到头部
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