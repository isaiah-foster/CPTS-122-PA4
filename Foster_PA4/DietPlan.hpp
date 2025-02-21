#pragma once
#include "fitnessApplication.hpp"

class DietPlan
{
private:
	int goalCalories;
	string planName;
	string date;
public:
	DietPlan();
	DietPlan(int _goalCalories, string _planName, string _date);
	DietPlan(const DietPlan& copy);
	~DietPlan();
	void setGoalCalories(int _goalCalories);
	void setPlanName(string _planName);
	void setDate(string _date);
	int getGoalCalories() const; //const at end means it is a read only function
	string getPlanName() const;
	string getDate() const;
	void editGoal();
	void editName();
	void editDate();
	void printPlan() const;
};

DietPlan::DietPlan()
{
	goalCalories = 0;
	planName = "";
	date = "";
}
DietPlan::DietPlan(int _goalCalories, string _planName, string _date)
{
	goalCalories = _goalCalories;
	planName = _planName;
	date = _date;
}
DietPlan::DietPlan(const DietPlan& copy)
{
	goalCalories = copy.goalCalories;
	planName = copy.planName;
	date = copy.date;
}
DietPlan::~DietPlan()
{

}
void DietPlan::setGoalCalories(int _goalCalories)
{
	goalCalories = _goalCalories;
}

void DietPlan::setPlanName(string _planName)
{
	planName = _planName;
}
void DietPlan::setDate(string _date)
{
	date = _date;
}
int DietPlan::getGoalCalories() const
{
	return goalCalories;
}
string DietPlan::getPlanName() const
{
	return planName;
}
string DietPlan::getDate() const
{
	return date;
}
void DietPlan::editGoal()
{
	do
	{
		cout << "Enter your new goal calorie count: ";
		cin >> goalCalories;
	} while (goalCalories < 0);
}

void DietPlan::editName()
{
	cout << "Enter your new plan name: ";
	cin >> planName;
}
void DietPlan::editDate()
{
	cout << "Enter your new date: ";
	cin >> date;
}
void DietPlan::printPlan() const
{
	cout << "Plan Name: " << planName << endl;
	cout << "Goal Steps: " << goalCalories << endl;
	cout << "Date: " << date << endl;
}

//Nonmember functions
ostream& operator<<(ostream& lhs, DietPlan& rhs);
ifstream& operator>>(ifstream& lhs, DietPlan& rhs);

//Nonmember function definitions
ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Goal Steps: " << rhs.getGoalCalories() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	return lhs;
}
ifstream& operator>>(ifstream& lhs, DietPlan& rhs)
{
	int cals = 0;
	string name = "", date = "";

	lhs >> name;
	rhs.setPlanName(name);

	lhs >> cals;
	rhs.setGoalCalories(cals);

	lhs >> date;
	rhs.setDate(date);

	return lhs;
}