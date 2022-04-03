#pragma once
#include "GlobalValues.h"
#include "CMax3SatProblem.h"

class CGAIndividual
{
public:
	CGAIndividual();
	CGAIndividual(const CGAIndividual& other);
	CGAIndividual(std::vector<bool> newGeneration);
	//CGAIndividual(bool value);
	~CGAIndividual();

	void crossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2, CGAIndividual* other);
	void mutation(int probab);
	int getFitness(CMax3SatProblem problem);
	std::vector<bool> getGenotype();
	void showGenotype();
private:
	std::vector<bool> genotype;
	int fitness = 0;
	int crossingChance = CROSSINGCHANCE;
	int problemSize = PROBLEMSIZE;
};

