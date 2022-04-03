#pragma once
#include <unordered_map>
#include <vector>

class CMax3SatProblem
{
public:
	CMax3SatProblem();
	~CMax3SatProblem();
	bool load(std::string filename);
	std::vector<int> load(bool* done ,std::string filename);
	int compute(std::vector<bool> answ);
	int computeR(int max);
	void printValues();
private:
	std::vector <int> values;
	int size;
	bool checkValue(int valueAt, std::vector<bool> answ);
};

