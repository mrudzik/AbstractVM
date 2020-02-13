

#include "ParserSystem.hpp"

void LaunchProgramAutomated(char* path)
{
    ParserSystem parser;
    // Decrypt file into vector of commands
	parser.ParseInputFile(std::string(path));
}

void LaunchProgramManual()
{
	ParserSystem parser;
    parser.ParseInputManual();
    // Inf Loop
    //  // Scan user input
    //  // Parse input
    //  // Apply command to Core
    //  // if (command != "exit")
    //  //	repeat;
}

int main(int argc, char** argv)
{

    if (argc > 1)
        LaunchProgramAutomated(argv[1]);
    else
        LaunchProgramManual();

    system("leaks avm");
}