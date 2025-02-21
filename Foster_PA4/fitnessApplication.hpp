#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ExercisePlan.hpp"
#include "DietPlan.hpp"

using std::string;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ostream;

class FitnessAppWrapper
{
private:
	DietPlan* dietPlansHead;
	ExercisePlan* exercisePlansHead;

	template <typename T>
	void loadDailyPlan(ifstream& filesStream, T* plan);

	template <typename T>
	void loadWeeklyPlan(ifstream& filesStream, T* plan);

	template <typename T>
	void displayDailyPlan(T* plan);

	template <typename T>
	void displayWeeklyPlan(T* plan);


	
