#pragma once
#include "fitnessApplication.hpp"

class ExercisePlan
{
private:
	int goalSteps;
	string planName;
	string date;
public:
	ExercisePlan();
	ExercisePlan(int _goalSteps, string _planName, string _date);
	ExercisePlan(const ExercisePlan& copy);
	~ExercisePlan();
	void setGoalSteps(int _goalSteps);
	void setPlanName(string _planName);
	void setDate(string _date);
	int getGoalSteps() const; //const at end means it is a read only function
	string getPlanName() const;
	string getDate() const;
	void editGoal();
	void editName();
	void editDate();
	void printPlan();
};

ExercisePlan::ExercisePlan()
{
	goalSteps = 0;
	planName = "";
	date = "";
}
ExercisePlan::ExercisePlan(int _goalSteps, string _planName, string _date)
{
	goalSteps = _goalSteps;
	planName = _planName;
	date = _date;
}
ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	goalSteps = copy.goalSteps;
	planName = copy.planName;
	date = copy.date;
}
ExercisePlan::~ExercisePlan()
{
}
void ExercisePlan::setGoalSteps(int _goalSteps)
{
	goalSteps = _goalSteps;
}
void ExercisePlan::setPlanName(string _planName)
{
	planName = _planName;
}
void ExercisePlan::setDate(string _date)
{
	date = _date;
}
int ExercisePlan::getGoalSteps() const
{
	return goalSteps;
}
string ExercisePlan::getPlanName() const
{
	return planName;
}
string ExercisePlan::getDate() const
{
	return date;
}
void ExercisePlan::editGoal()
{
	do
	{
		cout << "Enter your new goal step count: ";
		cin >> goalSteps;
	} while (goalSteps < 0);
}
void ExercisePlan::editName()
{
	cout << "Enter your new plan name: ";
	cin >> planName;
}
void ExercisePlan::editDate()
{
	cout << "Enter your new date: ";
	cin >> date;
}
void ExercisePlan::printPlan()
{
	cout << "Plan Name: " << planName << endl;
	cout << "Goal Steps: " << goalSteps << endl;
	cout << "Date: " << date << endl;
}

//Nonmember functions
ostream& operator<<(ostream& lhs, ExercisePlan& rhs);
ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs);


ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Goal Steps: " << rhs.getGoalSteps() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	return lhs;
}
ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs)
{
	int steps = 0;
	string name = "", date = "";

	lhs >> name;
	rhs.setPlanName(name);

	lhs >> steps;
	rhs.setGoalSteps(steps);

	lhs >> date;
	rhs.setDate(date);

	return lhs;
}