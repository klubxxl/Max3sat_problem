#pragma once
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
class CGAOptimizer
{
public:
	CGAOptimizer(CMax3SatProblem problem);
	~CGAOptimizer();
	bool* initialize(std::string fileName);
	CGAIndividual* tournament(std::vector<CGAIndividual*> population);
	void runIteration();
	void showPopulation();
	//void showBestInPopulation();
private:
	int populationSize;
	int crossingChance;
	int mutationChance;
	std::vector<CGAIndividual*> population;
	std::vector <int> values;

	CMax3SatProblem problem;
};

