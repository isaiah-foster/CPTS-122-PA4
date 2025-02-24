#pragma once
#include "Includes.hpp"
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "LinkedLists.hpp"
#include <string>
#include <fstream>
using std::string;
using std::ifstream;

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

	void loadDailyPlan(ifstream& fileStream, DietPlan& plan);
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);
	
	void loadWeeklyPlan(ifstream& fileStream, List<DietPlan> *list);
	void loadWeeklyPlan(ifstream& fileStream, List<ExercisePlan> *list);

	void storeDailyPlan(ofstream& fileStream, DietPlan& plan);
	void storeDailyPlan(ofstream& fileStream, ExercisePlan& plan);

	void storeWeeklyPlan(ofstream& fileStream, List<DietPlan> list);
	void storeWeeklyPlan(ofstream& fileStream, List<ExercisePlan> list);

	void displayDailyPlan(DietPlan planCur);
	void displayDailyPlan(ExercisePlan planCur);

	void displayWeeklyPlan(List<DietPlan> *dietList);
	void displayWeeklyPlan(List<ExercisePlan> *exerciseList);

	DietPlan* getPlan(List<DietPlan>* list);
	ExercisePlan* getPlan(List<ExercisePlan>* list);
	void editDailyPlan(DietPlan *plan);
	void editDailyPlan(ExercisePlan *plan);

	void displayMenu();
	int getSelection();
	void processSelection(int choice);
	void runApp();

};

#pragma region Constructor/Destructor
//constructs appwrapper to open filestreams
FitnessAppWrapper::FitnessAppWrapper()
{

}
#pragma endregion

#pragma region Load functions
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}


void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}


void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, List<DietPlan> *list)
{
	list->clearList();
	DietPlan tempPlan;
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, tempPlan);
		list->insertAtFront(tempPlan);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, List<ExercisePlan> *list)
{
	list->clearList();
	ExercisePlan tempPlan;
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, tempPlan);
		list->insertAtFront(tempPlan);
	}
}
#pragma endregion

#pragma region Store Functions
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan& plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan& plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, List<DietPlan> list)
{
	Node<DietPlan>* pCur = list.getHead();
	DietPlan planCur;
	while (pCur != nullptr)
	{
		planCur = pCur->getPlan();
		storeDailyPlan(fileStream, planCur);
		if (pCur->getNext() != nullptr)
		{
			fileStream << "\n";
		}
		pCur = pCur->getNext();
	}
}
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, List<ExercisePlan> list)
{
	Node<ExercisePlan>* pCur = list.getHead();
	ExercisePlan planCur;
	while (pCur != nullptr)
	{
		planCur = pCur->getPlan();
		storeDailyPlan(fileStream, planCur);
		if (pCur->getNext() != nullptr)
		{
			fileStream << "\n";
		}
		pCur = pCur->getNext();
	}
}
#pragma endregion

#pragma region Display Functions
void FitnessAppWrapper::displayDailyPlan(DietPlan planCur)
{
	cout << planCur;
	cout << "\n";
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan planCur)
{
	cout << planCur;
	cout << "\n";
}

void FitnessAppWrapper::displayWeeklyPlan(List<DietPlan> *dietList)
{
	Node<DietPlan>* pCur = dietList->getHead();
	DietPlan planCur;
	while (pCur != nullptr)
	{
		planCur = pCur->getPlan();
		displayDailyPlan(planCur);
		pCur = pCur->getNext();
	}
	system("pause");
}

void FitnessAppWrapper::displayWeeklyPlan(List<ExercisePlan> *exerciseList)
{
	Node<ExercisePlan>* pCur = exerciseList->getHead();
	ExercisePlan planCur;
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
DietPlan* FitnessAppWrapper::getPlan(List<DietPlan>* list)
{
	displayWeeklyPlan(list);
	cout << "\nEnter the date of the plan you want to edit: ";
	string date;
	cin >> date;
	Node<DietPlan>* pCur = list->getHead();
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

ExercisePlan* FitnessAppWrapper::getPlan(List<ExercisePlan>* list)
{
	displayWeeklyPlan(list);
	cout << "\nEnter the date of the plan you want to edit: ";
	string date;
	cin >> date;
	Node<ExercisePlan>* pCur = list->getHead();
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

void FitnessAppWrapper::editDailyPlan(DietPlan *plan)
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

void FitnessAppWrapper::editDailyPlan(ExercisePlan *plan)
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
			// add store plan to file
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
	dietIn.close();
	dietOut.close();
	exerciseIn.close();
	exerciseOut.close();
}