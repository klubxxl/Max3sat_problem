#include "CGAIndividual.h"
#include <ctime>
#include <random>
#include <sstream>
#include <iostream>
using namespace std;

CGAIndividual::CGAIndividual() {
	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype.push_back(false);

	crossingChance = CROSSINGCHANCE;
}


CGAIndividual::CGAIndividual(std::vector<bool> newGeneration) {
	genotype = newGeneration;
}

CGAIndividual::CGAIndividual(const CGAIndividual& other) {
	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype.push_back(other.genotype[i]);
}

CGAIndividual::~CGAIndividual() {
	genotype.clear();
}

void CGAIndividual::crossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2, CGAIndividual* pcOther) {
	int chooseParent;
	for (int i = 0; i < problemSize; i++) {
		chooseParent = rand() % 2;
		if (chooseParent == 0) {
			pcChild1->genotype.at(i) = genotype.at(i);
			pcChild2->genotype.at(i) = pcOther->genotype.at(i);
		}
		else {
			pcChild1->genotype.at(i) = pcOther->genotype.at(i);
			pcChild2->genotype.at(i) = genotype.at(i);
		}
	}
}


void CGAIndividual::mutation(int propab) {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		if (rand() % 100 < propab) genotype.at(i) = !genotype.at(i);
	}
}

std::vector<bool> CGAIndividual::getGenotype() {
	return genotype;
}

void CGAIndividual::showGenotype() {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		int a = genotype[i] == true ? 1 : 0;
		std::cout << a;
	}
	std::cout << std::endl;
}

int CGAIndividual::getFitness(CMax3SatProblem problem) {
	return problem.compute(genotype);
}