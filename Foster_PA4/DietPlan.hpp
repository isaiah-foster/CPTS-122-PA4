#pragma once
#include "Includes.hpp"

class DietPlan
{
private:
	int goal;
	string planName;
	string date;
public:
	DietPlan();
	DietPlan(int _goalCalories, string _planName, string _date);
	DietPlan(const DietPlan& copy);
	~DietPlan();
	void setGoal(int _goalCalories);
	void setPlanName(string _planName);
	void setDate(string _date);
	int getGoal() const; //const at end means it is a read only function
	string getPlanName() const;
	string getDate() const;
	void editGoal();
	void editName();
	void editDate();
	void printPlan() const;
};

DietPlan::DietPlan()
{
	goal = 0;
	planName = "";
	date = "";
}
DietPlan::DietPlan(int _goalCalories, string _planName, string _date)
{
	goal = _goalCalories;
	planName = _planName;
	date = _date;
}
DietPlan::DietPlan(const DietPlan& copy)
{
	goal = copy.goal;
	planName = copy.planName;
	date = copy.date;
}
DietPlan::~DietPlan()
{
	
}

void DietPlan::setGoal(int _goalCalories)
{
	goal = _goalCalories;
}
void DietPlan::setPlanName(string _planName)
{
	planName = _planName;
}
void DietPlan::setDate(string _date)
{
	date = _date;
}

int DietPlan::getGoal() const
{
	return goal;
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
		cin >> goal;
	} while (goal < 0);
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
	cout << "Goal Calories: " << goal << endl;
	cout << "Date: " << date << endl;
}

//Nonmember functions
void operator<<(ostream& lhs, DietPlan& rhs);
void operator<<(ofstream& lhs, DietPlan& rhs);
DietPlan& operator>>(ifstream& lhs, DietPlan& rhs);


void operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Goal Calories: " << rhs.getGoal() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	
}
void operator<<(ofstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl;
}

DietPlan& operator>>(ifstream& lhs, DietPlan& rhs)
{
	int cals = 0;
	string name = "", name1, name2, date = "", blank = "";

	lhs >> name1;
	lhs >> name2;
	name = name1 + " " + name2;
	rhs.setPlanName(name);

	lhs >> cals;
	rhs.setGoal(cals);

	lhs >> date;
	rhs.setDate(date);

	return rhs;
}

