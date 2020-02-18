

#include "ParserSystem.hpp"


int main(int argc, char** argv)
{

    if (argc > 1)
        ParserSystem::ParseInputFile(argv[1]);
    else
        ParserSystem::ParseInputManual();

    std::cout << "\n===DEBUG===" << std::endl;
    system("leaks avm");
}