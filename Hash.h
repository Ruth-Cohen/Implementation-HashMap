#include<sstream>
#include <iostream>
#include <string>
using namespace std;

bool isPrime(int num)
{
	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
			count++;
	}
	return (count == 2);
}



enum state { empty, full, deleted };

template<class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item(){}
	Item(T d, K k, state f){ data = d; key = k; flag = f; }
};



template<typename K, typename T>
class Hash
{
public:
	Item<K, T> * val;
	int size;
	//constructors
	Hash(int size)
{
	while (!isPrime(size))
		size++;
	this->size = size;
	val = new Item<K, T>[size];
	for (int i = 0; i < size; i++)
		val[i].flag = empty;
}
	Hash(){};
	virtual ~Hash(){ delete[]val; }

	int h1(K keyWord)//hash function
	{
		string str = keyWord;
		int number;
		if(!(istringstream(str)>>number))
			number = -1;
		return (number % size);
	}
	int h2(K kw)//skip function
	{
		string str = kw;
		int number;
		if(!(istringstream(str)>>number))
			number = -1;
		return number % (size-2) +1;
	}

	int h(K keyWord, int index)
	{
		return (h1(keyWord) + index*h2(keyWord)) % size;
	}

	void insert(K k, T d)
	{
		int temp;
		for (int i = 0; i < size; i++)
		{
			temp = h(k, i);
			if (val[temp].flag == empty || val[temp].flag == deleted)
			{
				val[temp].data = d;
				val[temp].key = k;
				val[temp].flag = full;
				i=size;
			}
		}
	}

	int search(K k)//return the place of the item
	{
		{
			int temp;
			for (int i = 0; i < size; i++)
			{
				temp = h(k,i);
				if (val[temp].key == k && val[temp].flag == full)
					return temp;
			}
			return -1;
		}
	}
	void deleteI(K k)
	{
		int d =search(k);
		if(d != -1)
		{
			val[d].flag = deleted;
			
		}
	}
	T* value(int index)
	{
		if (index < size && val[index].flag == full) return &val[index].data;
		else return NULL;
	}

	Hash& getOneVal(int index){ if (index != -1)return val[index]; else return NULL; }
	friend ostream& operator<< (ostream & out, Hash & h)
	{
		int i=0;
		while(i< size)
		{ 
			if(val[i].flag == full)
				out<<val[i].key<<"  "<<val[i].data<<endl;
			i++;
		}
	}
};

//template <typename K, typename T>  //ctor
//Hash<K, T>::Hash(int size)
//{
//
//	while (!isPrime(size))
//		size++;
//	this->size = size;
//	val = new Item<K, T>[size];
//	for (int i = 0; i < size; i++)
//		val[i].flag = empty;
//}
//
//
////hash function
//template<typename K, typename T>
//int Hash <K,T>:: h1(K keyWord)
//{
//	string str = keyWord;
//	int number;
//	if(!(istringstream(str)>>number))
//		number = -1;
//	return (number % size);
//}
//
////skip function
//template<typename K, typename T>
//int Hash <K,T>:: h2(K kw)  
//{
//	string str = kw;
//	int number;
//	if(!(istringstream(str)>>number))
//		number = -1;
//	return number % (size-2) +1;
//}
//
//template<typename K, typename T>
//int Hash <K,T>:: h(K keyWord, int index=0) //the double -hshing function
//{
//	return (h1(keyWord) + index*h2(keyWord)) % size;
//}
//
//template<typename K, typename T>
//void Hash <K,T>:: insert(K k, T d)//insert into the hash table
//{
//	int temp;
//	for (int i = 0; i < size; i++)
//	{
//			temp = h(k, i);
//			if (val[temp].flag == empty || val[temp].flag == deleted)
//			{
//				val[temp].data = d;
//				val[temp].key = k;
//				val[temp].flag = full;
//				i=size;
//			}
//	}
//}
//
////return the place of the item
//template<typename K, typename T>
//int Hash <K,T>:: search(K k)
//{
//	{
//		int temp;
//		for (int i = 0; i < size; i++)
//		{
//			temp = h(k,i);
//			if (val[temp].key == k && val[temp].flag == full)
//				return temp;
//		}
//		return -1;
//	}
//}
//
//template<typename K, typename T>
//void Hash <K,T>::deleteI(K k)
//{
//	int d =search(k);
//	if(d != -1)
//	{
//		val[d].flag = deleted;
//		val[d].data = NULL;
//	}
//}
//


//int hashFunction(string keyWord);