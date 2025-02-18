#include "fitnessApplication.hpp"


template <typename T> class Node
{
public:
	T data;
	Node<T>* pNext;

	Node() {};
	Node(T _d) { data = _d; }
};


class FitnessAppWrapper
{

private:
	DietPlan weeklyDietPlan[7];
	ExercisePlan weeklyExercisePlan[7];
	DietPlan dailyDietPlan;
	ExercisePlan dailyExercisePlan;
	fstream dietFile;
	fstream exerciseFile;

public:



};


int main(void)
{
	Node<int>* pHead = new Node<int>(1);
	pHead->pNext = new Node<int>(2);

	std::cout << pHead->data << std::endl;






	return 0;
}