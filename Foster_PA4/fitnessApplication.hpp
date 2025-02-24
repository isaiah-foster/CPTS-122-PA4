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

public:

	FitnessAppWrapper(string dietFile, string exerciseFile);


	void loadDailyPlan(DietPlan *list);
	void loadDailyPlan(ExercisePlan* list);

	
	void loadWeeklyPlan(DietPlan plan);
	void loadWeeklyPlan(ExercisePlan plan);



	void displayDailyPlan(DietPlan plan);
	void displayDailyPlan(ExercisePlan plan);



	void displayWeeklyPlan(DietPlan plan);
	void displayWeeklyPlan(ExercisePlan plan);

};

FitnessAppWrapper::FitnessAppWrapper(string dietFile, string exerciseFile)
{
	ifstream dietIn(dietFile);
	ifstream exerciseIn(exerciseFile);
}


void FitnessAppWrapper::loadDailyPlan(DietPlan *list)
{
	DietPlan newPlan;
	dietIn >> newPlan;
	dietList.insertAtFront(newPlan);
}

void FitnessAppWrapper::loadDailyPlan(ExercisePlan* list)
{
	ExercisePlan newPlan;
	exerciseIn >> newPlan;
	exerciseList.insertAtFront(newPlan);
	
}


void FitnessAppWrapper::loadWeeklyPlan(DietPlan plan)
{
	DietPlan newPlan;
	while (!exerciseIn.eof())
	{

	}
}
void loadWeeklyPlan(ExercisePlan plan);
