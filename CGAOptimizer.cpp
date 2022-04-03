#include "CGAOptimizer.h"
#include <iostream>

CGAOptimizer::CGAOptimizer(CMax3SatProblem problem)
{
	this->populationSize = POPULATIONSIZE;
	this->crossingChance = CROSSINGCHANCE;
	this->mutationChance = MUTATIONCHANCE;
	this->problem = problem;
}

CGAOptimizer::~CGAOptimizer()
{
	for (int i = 0; i < populationSize; i++)
		delete population.at(i);

	population.clear();
	values.clear();
}

bool* CGAOptimizer::initialize(std::string fileName)
{
	srand(time(NULL));
	bool* done = new bool;
	values = problem.load(done, fileName);

	for (int i = 0; i < populationSize; i++) {
		std::vector<bool> gens;

		for (int j = 0; j < PROBLEMSIZE; j++) {
			int random = rand() % 2;
			gens.push_back(random);
		}

		population.push_back(new CGAIndividual(gens));
	}

	return done;
}

CGAIndividual* CGAOptimizer::tournament(std::vector<CGAIndividual*> population)
{
	if(BIGGERRANDOM) srand(time(NULL));

	bool* took = new bool[populationSize];
	for (int i = 0; i < populationSize; i++)
		took[i] = false;

	std::vector<CGAIndividual*> inTournament;
	for (int i = 0; i < TOURNAMENTSIZE; i++) {
		int randIndex = (rand() % populationSize);
		if (took[randIndex]) {
			i--;
		}
		else {
			inTournament.push_back(population.at(randIndex));
			took[randIndex] = true;
		}
	}
	int record = 0, recordIndex = 0;
	for (int i = 0; i < TOURNAMENTSIZE; i++) {
		int actual = inTournament.at(i)->getFitness(problem);
		if (actual > record) {
			record = actual;
			recordIndex = i;
		}
	}

	CGAIndividual* winner = inTournament.at(recordIndex);
	inTournament.clear();
	delete[] took;

	return winner;
}

void CGAOptimizer::runIteration()
{
	if (BIGGERRANDOM) srand(time(NULL));

	std::vector<CGAIndividual*> newPopulation;

	CGAIndividual* child1,* child2;
	CGAIndividual* parrent1,* parrent2;


	while (newPopulation.size() < populationSize) {
		parrent1 = tournament(population);
		parrent2 = tournament(population);

		while (parrent1 == parrent2)
			parrent1 = tournament(population);

		if (std::rand() % 100 < crossingChance) {
			child1 = new CGAIndividual;
			child2 = new CGAIndividual;
			parrent1->crossover(child1, child2, parrent2);
		}
		else {
			child1 = new CGAIndividual(*parrent1);
			child2 = new CGAIndividual(*parrent2);
		}

		child1->mutation(mutationChance);
		child2->mutation(mutationChance);

		newPopulation.push_back(child1);
		newPopulation.push_back(child2);
	}

	for (int i = 0; i < populationSize; i++)
		delete population.at(i);

	population.clear();

	population = newPopulation;
}

void CGAOptimizer::showPopulation()
{
	for (int i = 0; i < populationSize; i++) {
		std::cout << population.at(i)->getFitness(problem) << " ";
		population.at(i)->showGenotype();
	}
}
