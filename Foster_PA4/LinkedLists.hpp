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
	T getPlan();
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
T Node<T>::getPlan()
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
public:
	List();
	~List();
	void insertAtFront(T newData);
	bool isEmpty();
	void printList();
	void deleteAtFront();
	void deleteAtEnd();
};

template <typename T>
List<T>::List()
{
	pHead = nullptr;
	pTail = nullptr;
}

template <typename T>
List<T>::~List()
{
	pHead = nullptr;
	pTail = nullptr;
}

template <typename T>
void List<T>::insertAtFront(T newData)
{
	//should work for empty and not empty
	Node<T> newNode = new Node(newData);
	newNode.setNext(*pHead);
	pHead = &newNode;
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

#pragma endregion