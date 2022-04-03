#include "CMax3SatProblem.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "GlobalValues.h"

CMax3SatProblem::CMax3SatProblem() {
    size = 0;
}

CMax3SatProblem::~CMax3SatProblem() {
    values.clear();
}

bool CMax3SatProblem::load(std::string filename) {
    size = 0;
    values.clear();

    std::ifstream plik;
    plik.open(filename.c_str());

    if (!plik.good()) return false;

    while (!plik.eof())
    {
        std::string empty;
        int num1, num2, num3;
        plik >> empty;

        if (empty[0] == 40) {
            plik >> num1 >> num2 >> num3 >> empty;

            values.push_back(num1);
            values.push_back(num2);
            values.push_back(num3);

            size++;
        }
    }

    plik.close();
    return true;
}

std::vector<int> CMax3SatProblem::load(bool* done, std::string filename)
{
    size = 0;
    values.clear();

    std::ifstream plik;
    plik.open(filename.c_str());

    if (!plik.good()) *done = false;

    while (!plik.eof())
    {
        std::string empty;
        int num1, num2, num3;
        plik >> empty;

        if (empty[0] == 40) {
            plik >> num1 >> num2 >> num3 >> empty;

            values.push_back(num1);
            values.push_back(num2);
            values.push_back(num3);

            size++;
        }
    }

    plik.close();
    *done = true;

    return values;
}

int CMax3SatProblem::compute(std::vector<bool> answ) {
    int answer = 0;
    // std::cout << "Size: " << size << std::endl;;

    for (int i = 0; i < size * 3; i += 3) {
        if (checkValue(values.at(i), answ)) answer++;
        else if (checkValue(values.at(i + 1), answ)) answer++;
        else if (checkValue(values.at(i + 2), answ)) answer++;
    }

    // std::cout << ((float)(answer) / (float)(size)) * 100 << " %\n";

    return answer;
}

int CMax3SatProblem::computeR(int max) {
    int answer = 0;
    std::vector<bool> answ;

    for (int i = 0; i < max; i++) {
        srand((int)time(0));
        answ.push_back((rand() % 2));
    }

    for (int i = 0; i < size * 3; i += 3) {
        if (checkValue(values.at(i), answ)) answer++;
        else if (checkValue(values.at(i + 1), answ)) answer++;
        else if (checkValue(values.at(i + 2), answ)) answer++;
    }

    //if (((float)(answer) / (float)(size)) =< 0.85) computeR(max);
                         // ABY LOSOWANIE BY£O EFEKTYNE MUSIMY OSI¥GN¥Æ WYNIK >85%
                         // MO¯NA USUN¥Æ KOMENTARZ POWY¯EJ, ABY POWTRARZAÆ LOSOWANIA TAK D£UGO, A¯ OSI¥GNIEMY WYNIK >= 85%
                         // POWTÓRZEÑ NIE BÊDZIE DU¯O, PONIEWA¯ PRAWDOPODOPIEÑSTWO WYLOSOWANIA TAKIE ROZWI¥ZANIA WYNOSI 7/8

    std::cout << ((float)(answer) / (float)(size)) * 100 << " %\n";

    return answer;
}

bool CMax3SatProblem::checkValue(int valueAt, std::vector<bool> answ) {
    if ((valueAt >= 0 && valueAt < answ.size()) || (valueAt < 0 && -valueAt < answ.size())) {
        if (valueAt >= 0 && answ.at(valueAt)) return true;
        else if (valueAt < 0 && !answ.at(-valueAt)) return true;
    }
    return false;
}

void CMax3SatProblem::printValues() {
    for (int i = 0; i < size * 3; i += 3) {
        if (i == 0) std::cout << 1 << ". ";
        else std::cout << (i / 3) + 1 << ". ";

        std::cout << "( " << values.at(i) << " " << values.at(i + 1) << " " << values.at(i + 2) << " )\n";
    }
}
