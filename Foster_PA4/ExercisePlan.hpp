#pragma once
#include "FitnessApplication.hpp"

#pragma region Using Statements
using std::string;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ostream;
using std::string;
using std::ofstream;
#pragma endregion

class ExercisePlan
{
private:
	int goal;
	string planName;
	string date;
public:
	ExercisePlan();
	ExercisePlan(int _goalSteps, string _planName, string _date);
	ExercisePlan(const ExercisePlan& copy);
	~ExercisePlan();
	void setGoal(int _goalSteps);
	void setPlanName(string _planName);
	void setDate(string _date);
	int getGoal() const; //const at end means it is a read only function
	string getPlanName() const;
	string getDate() const;
	void editGoal();
	void editName();
	void editDate();
	void printPlan()const ;
};

ExercisePlan::ExercisePlan()
{
	goal = 0;
	planName = "";
	date = "";
}
ExercisePlan::ExercisePlan(int _goalSteps, string _planName, string _date)
{
	goal = _goalSteps;
	planName = _planName;
	date = _date;
}
ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	goal = copy.goal;
	planName = copy.planName;
	date = copy.date;
}
ExercisePlan::~ExercisePlan()
{
	
}

void ExercisePlan::setGoal(int _goalSteps)
{
	goal = _goalSteps;
}
void ExercisePlan::setPlanName(string _planName)
{
	planName = _planName;
}
void ExercisePlan::setDate(string _date)
{
	date = _date;
}

int ExercisePlan::getGoal() const
{
	return goal;
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
		cin >> goal;
	} while (goal < 0);
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

void ExercisePlan::printPlan() const
{
	cout << "Plan Name: " << planName << endl;
	cout << "Goal Steps: " << goal << endl;
	cout << "Date: " << date << endl;
}

//Nonmember functions
void operator<<(ostream& lhs, ExercisePlan& rhs);
void operator<<(ofstream& lhs, ExercisePlan& rhs);
ExercisePlan& operator>>(ifstream& lhs, ExercisePlan& rhs);

void operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Goal Steps: " << rhs.getGoal() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
}

void operator<<(ofstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate();
}

ExercisePlan& operator>>(ifstream& lhs, ExercisePlan& rhs)
{
	int steps = 0;
	string name = "", name1, name2, date = "", blank = "";

	lhs >> name1;
	lhs >> name2;
	name = name1 + " " + name2;
	rhs.setPlanName(name);

	lhs >> steps;
	rhs.setGoal(steps);

	lhs >> date;
	rhs.setDate(date);

	return rhs;
}