#pragma once
#include "FitnessApplication.hpp"

#pragma region Node
template <typename T>
class Node
{
private: 
	T Plan;
	Node<T>* pNext;
public:
	Node(T newPlan);
	T& getPlan();
	Node* getNext();
	void setNext(Node* newNext);
};

template <typename T>
Node<T>::Node(T newPlan)
{
	Plan = newPlan;
	pNext = nullptr;
}

template<typename T>
T& Node<T>::getPlan()
{
	return Plan;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return pNext;
}

template <typename T>
void Node<T>::setNext(Node* newNext)
{

	pNext = newNext;
}
#pragma endregion

#pragma region List
template <typename T>
class List
{
private:
	Node<T>* pHead;
	void setHead(Node<T>* newHead);
public:
	List();
	~List();
	void insertAtFront(T newData);
	bool isEmpty();
	Node<T>* getHead();
	void clearList();
};

template <typename T>
List<T>::List()
{
	pHead = nullptr;
}

template <typename T>
List<T>::~List()
{
	clearList();
}

template <typename T>
bool List<T>::isEmpty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
Node<T>* List<T>::getHead()
{
	return pHead;
}

template <typename T>
void List<T>::setHead(Node<T>* newHead)
{
	pHead = newHead;
}

template <typename T>
void List<T>::insertAtFront(T newData)
{
	//empty list
	if (isEmpty())
	{
		Node<T>* newNode = new Node<T>(newData);
		setHead(newNode);
	}
	else
	{
		Node<T>* newNode = new Node<T>(newData);
		newNode->setNext(pHead);
		setHead(newNode);
	}
}

template <typename T>
void List<T>::clearList()
{
	Node<T>* pCur = pHead;
	Node<T>* pNext = nullptr;
	while (pCur != nullptr)
	{
		pNext = pCur->getNext();
		delete pCur;
		pCur = pNext;
	}
	pHead = nullptr;
}

#pragma endregion