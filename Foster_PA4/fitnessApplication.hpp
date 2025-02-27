#pragma once
#include "Includes.hpp"

class FitnessAppWrapper
{
private:
	List<DietPlan> dietList;
	List<ExercisePlan> exerciseList;
	ifstream dietIn;
	ifstream exerciseIn;
	ofstream dietOut;
	ofstream exerciseOut;

public:

	FitnessAppWrapper();
	~FitnessAppWrapper();

	template <typename T>
	void loadDailyPlan(ifstream& fileStream, T& plan);
	
	template <typename T>
	void loadWeeklyPlan(ifstream& fileStream, List<T> *list);

	template <typename T>
	void storeDailyPlan(ofstream& fileStream, T& plan);

	template <typename T>
	void storeWeeklyPlan(ofstream& fileStream, List<T>& list);

	template <typename T>
	void displayDailyPlan(T planCur);

	template <typename T>
	void displayWeeklyPlan(List<T> *exerciseList);

	template <typename T>
	T* getPlan(List<T>* list);

	template <typename T>
	void editDailyPlan(T *plan);

	void displayMenu();
	int getSelection();
	void processSelection(int choice);
	void runApp();

};

#pragma region Constructor/Destructor
FitnessAppWrapper::FitnessAppWrapper(){}

FitnessAppWrapper::~FitnessAppWrapper()
{
	//make sure files arent open when out of scope
	if (dietIn.is_open()) { dietIn.close(); }
	if (exerciseIn.is_open()) exerciseIn.close();
	if (dietOut.is_open()) dietOut.close();
	if (exerciseOut.is_open()) exerciseOut.close();
}
#pragma endregion

#pragma region Load functions
template <typename T>
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, T& plan)
{
	fileStream >> plan;
}

template <typename T>
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, List<T> *list)
{
	list->clearList();
	T tempPlan;
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, tempPlan);
		list->insertAtFront(tempPlan);
		
	}
}
#pragma endregion

#pragma region Store Functions

template <typename T>
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, T& plan)
{
	fileStream << plan;
}
template <typename T>
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, List<T>& list)
{
	Node<T>* pCur = list.getHead();
	T planCur;
	while (pCur != nullptr)
	{
		planCur = pCur->getPlan();
		storeDailyPlan(fileStream, planCur);
		pCur = pCur->getNext();
		if (pCur != nullptr)
		{
			fileStream << "\n\n";
		}
	}
}
#pragma endregion

#pragma region Display Functions
template <typename T>
void FitnessAppWrapper::displayDailyPlan(T planCur)
{
	cout << planCur;
	cout << "\n";
}

template <typename T>
void FitnessAppWrapper::displayWeeklyPlan(List<T> *exerciseList)
{
	Node<T>* pCur = exerciseList->getHead();
	T planCur;
	while (pCur != nullptr)
	{
		planCur = pCur->getPlan();
		displayDailyPlan(planCur);
		pCur = pCur->getNext();
	}
	system("pause");
}

#pragma endregion

#pragma region Edit Functions
template <typename T>
T* FitnessAppWrapper::getPlan(List<T>* list)
{
	displayWeeklyPlan(list);
	cout << "\nEnter the date of the plan you want to edit: ";
	string date;
	cin >> date;
	Node<T>* pCur = list->getHead();
	while (pCur != nullptr)
	{
		if (pCur->getPlan().getDate() == date)
		{
			return &(pCur->getPlan());
		}

		pCur = pCur->getNext();
	}
	cout << "Plan not found." << endl;
}

template <typename T>
void FitnessAppWrapper::editDailyPlan(T *plan)
{
	system("CLS");
	cout << "Which part of the plan would you like to edit?\n";
	cout << "1. Goal\n";
	cout << "2. Plan Name\n";
	cout << "3. Date\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: plan->editGoal();
		break;
	case 2: plan->editName();
		break;
	case 3: plan->editDate();
		break;
	default: cout << "Invalid choice." << endl;
		break;
	}
}
#pragma endregion

#pragma region Menu functions
void FitnessAppWrapper::displayMenu()
{
	cout << "\nMenu Options:\n";
	cout << "1. Load weekly diet plan from file\n";
	cout << "2. Load weekly exercise plan from file\n";
	cout << "3. Store weekly diet plan to file\n";
	cout << "4. Store weekly exercise plan to file\n";
	cout << "5. Display weekly diet plan to screen\n";
	cout << "6. Display weekly exercise plan to screen\n";
	cout << "7. Edit daily diet plan\n";
	cout << "8. Edit daily exercise plan\n";
	cout << "9. Exit\n";
}

int FitnessAppWrapper::getSelection()
{
	int choice = 0;
	do
	{
	cout << "Enter your choice from 1-9: ";
	cin >> choice;
	cin.ignore(); //  newline left in buffer ignored
	} while (choice < 1 || choice>9);
	return choice;
}

void FitnessAppWrapper::processSelection(int choice)
{
	switch (choice)
	{
		case 1: 
			dietIn.open("dietPlans.txt");

			if (!dietIn.is_open())
			{
				cout << "Not opened" << endl;
			}
			loadWeeklyPlan(dietIn, &dietList);
			dietIn.close();
			break;
		case 2: 
			exerciseIn.open("exercisePlans.txt");
			loadWeeklyPlan(exerciseIn, &exerciseList);
			exerciseIn.close();
			break;
		case 3:
			dietOut.open("dietPlans.txt");
			storeWeeklyPlan(dietOut, dietList);
			dietOut.close();
			break;
		case 4: 
			exerciseOut.open("exercisePlans.txt");
			storeWeeklyPlan(exerciseOut, exerciseList);
			exerciseOut.close();
			break;
		case 5: displayWeeklyPlan(&dietList);
			break;
		case 6: displayWeeklyPlan(&exerciseList);
			break;
		case 7: editDailyPlan(getPlan(&dietList));
			break;
		case 8: editDailyPlan(getPlan(&exerciseList));
			break;
		case 9: 
			dietOut.open("dietPlans.txt");
			storeWeeklyPlan(dietOut, dietList);
			dietOut.close();
			exerciseOut.open("exercisePlans.txt");
			storeWeeklyPlan(exerciseOut, exerciseList);
			exerciseOut.close();
			cout << "Exiting program..." << endl;
			exit(0);
			break;
	}
		
}
#pragma endregion

void FitnessAppWrapper::runApp()
{
	while (1)
	{
		displayMenu();
		processSelection(getSelection());
		system("CLS");
	}
}