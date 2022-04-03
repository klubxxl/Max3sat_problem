#include <iostream>
#include "GlobalValues.h"
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"

int main()
{
    int iterationCount = 5;

    CMax3SatProblem problem = CMax3SatProblem();
    CGAOptimizer opt = CGAOptimizer(problem);

    if (!opt.initialize("m3s_50_3.txt")) return 0;

    for (int i = 0; i < iterationCount; i++) {
        i == 0 ? std::cout << "Population before 1 iteration: " << std::endl : std::cout << "Population after " << i << " iteration: " << std::endl;
        opt.showPopulation();
        std::cout << std::endl;
        opt.runIteration();
    }

    return 0;
}



/*    TESTY MAX3SAT POCZ¥TKOWE
 
* DLA FUNKCJI

void loadAndTest(std::string filename, std::vector<bool> vectorAnsw, CMax3SatProblem* test)
{
    if (test->load(filename)) {
        std::cout << "Wczytano plik " << filename << std::endl;
        std::cout << "Poprawne: " << test->compute(vectorAnsw) << std::endl << std::endl;
    }
}
void loadAndTestWithRandomValues(std::string filename, int max, CMax3SatProblem* test)
{
    if (test->load(filename)) {
        std::cout << "Wczytano plik " << filename << " z losowymi wartosciami" << std::endl;
        std::cout << "Poprawne: " << test->computeR(max) << std::endl << std::endl;
    }
}
void max3SetProblemTest() {
    CMax3SatProblem* test = new CMax3SatProblem();

    bool answers[] = { true, false, true, true, false, false, true, true, false, true, true, false, true, true, false, false, true, true, false, true, false, false, false, true, false,true, false, true, true, false, false, true, true, false, true, true, false, true, true, false, false, true, true, false, true, false, false, false, true, false, };
    std::vector<bool> vectorAnsw(std::begin(answers), std::end(answers));

    loadAndTest("m3s_50_0.txt", vectorAnsw, test);
    loadAndTest("m3s_50_1.txt", vectorAnsw, test);
    loadAndTest("m3s_50_2.txt", vectorAnsw, test);
    loadAndTest("m3s_50_3.txt", vectorAnsw, test);
    loadAndTest("m3s_50_49.txt", vectorAnsw, test);
    loadAndTest("m3s_50_50.txt", vectorAnsw, test);
    std::cout << "------------------------------\n";
    loadAndTestWithRandomValues("m3s_50_0.txt", 50, test);
    loadAndTestWithRandomValues("m3s_50_50.txt", 50, test);
    loadAndTestWithRandomValues("m3s_350_2.txt", 350, test);
    std::cout << "------------------------------\n";
    if (test->load("prostyTest.txt")) std::cout << "        PROSTY TEST\n";
    std::cout << "------------------------------\n";

    test->printValues();
    std::cout << std::endl;
    std::vector<bool> vectorAnswEs;
    vectorAnswEs.push_back(false);
    vectorAnswEs.push_back(false);
    vectorAnswEs.push_back(false);
    std::cout << "Poprawne (1=false, 2=false, 3=false): " << test->compute(vectorAnswEs) << std::endl << std::endl;
    vectorAnswEs.clear();
    vectorAnswEs.push_back(false);
    vectorAnswEs.push_back(false);
    vectorAnswEs.push_back(true);
    std::cout << "Poprawne (1=false, 2=false, 3=true): " << test->compute(vectorAnswEs) << std::endl << std::endl;
}
int main()
{
    max3SetProblemTest();
    std::cout << std::endl << std::endl << "________________________________________________" << std::endl << std::endl;
}

* OTRZYMALIŒMY WYNIK W KONSOLI:

Wczytano plik m3s_50_0.txt
Size: 213
84.9765 %
Poprawne: 181

Wczytano plik m3s_50_1.txt
Size: 213
88.7324 %
Poprawne: 189

Wczytano plik m3s_50_2.txt
Size: 213
85.446 %
Poprawne: 182

Wczytano plik m3s_50_3.txt
Size: 213
90.1408 %
Poprawne: 192

Wczytano plik m3s_50_49.txt
Size: 213
86.8545 %
Poprawne: 185

Wczytano plik m3s_50_50.txt
Size: 213
88.7324 %
Poprawne: 189

------------------------------
Wczytano plik m3s_50_0.txt z losowymi wartosciami
91.0798 %
Poprawne: 194

Wczytano plik m3s_50_50.txt z losowymi wartosciami
87.3239 %
Poprawne: 186

Wczytano plik m3s_350_2.txt z losowymi wartosciami
87.5502 %
Poprawne: 1308

------------------------------
        PROSTY TEST
------------------------------
1. ( 1 2 3 )
2. ( -1 -2 3 )
3. ( -1 -2 -3 )

Size: 3
66.6667 %
Poprawne (1=false, 2=false, 3=false): 2

Size: 3
100 %
Poprawne (1=false, 2=false, 3=true): 3



________________________________________________

*/