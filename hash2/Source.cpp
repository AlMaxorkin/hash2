/*
 Приведите содержимое хеш-таблицы, образованной вставками элементов с ключами E
A S Y Q U T I O N в указанном порядке в первоначально пустую таблицу размером M= 16,
использующую линейное опробование. Для преобразования k-ой буквы алфавита в индекс
таблицы используйте хеш-функцию 11k mod М*/

#include <iostream>

using namespace std;
 
template<typename K, typename V>
class HashNode
{
public:
	V value;
	K key;
	
	HashNode(K key, V value)
	{
		this->value = value;
		this->key = key;
	}
};

template<typename K, typename V> 
class HashMap
{ 
	HashNode<K, V>** arr;
	int M; 
	HashNode<K, V>* element;

public:
	HashMap()
	{
		M = 16;
		arr = new HashNode<K, V> * [M];

		for (int i = 0; i < M; i++)
			arr[i] = NULL;

		element = new HashNode<K, V>(-1, -1);
	}

	int hashCode(K key)
	{
		return (11*(int)key - 64) % M;
	}

	void insertNode(K key, V value)
	{
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);

		int hashIndex = hashCode(key);

		while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
			&& arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= M;
		}

		arr[hashIndex] = temp;
	}

	
	V deleteNode(int key)
	{
		
		int hashIndex = hashCode(key);

		
		while (arr[hashIndex] != NULL)
		{
			
			if (arr[hashIndex]->key == key)
			{
				HashNode<K, V>* temp = arr[hashIndex];
			
				arr[hashIndex] = element;

				return temp->value;
			}
			hashIndex++;
			hashIndex %= M;

		}
		return NULL;
	}

 
	void display()
	{
		for (int i = 0; i < M; i++)
		{
			cout << i << ". ";
			if (arr[i] == NULL || arr[i]->key == -1)
				cout << "Empty" << endl;
			else
				cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;
		}
	}
};

//Driver method to test map class 
int main()
{
	HashMap<char, int>* h = new HashMap<char, int>;
	h->insertNode('E', 1);
	h->insertNode('A', 2);
	h->insertNode('S', 3);
	h->insertNode('Y', 4);
	h->insertNode('Q', 5);
	h->insertNode('U', 6);
	h->insertNode('T', 7);
	h->insertNode('I', 8);
	h->insertNode('O', 9);
	h->insertNode('N', 10);

	h->display();

	return 0;
}
