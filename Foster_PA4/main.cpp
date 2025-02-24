#include "fitnessApplication.hpp"



int main(void)
{
	FitnessAppWrapper application("dietPlans.txt", "exercisePlans.txt");

	application.runApp;

	return 0;
}