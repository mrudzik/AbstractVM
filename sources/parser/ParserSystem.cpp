

#include "ParserSystem.hpp"
#include <fstream>

ParserSystem::ParserSystem(/* args */)
{
	lexerMod = new LexerModule();
	//std::make_unique<LexerModule>(new LexerModule);
	parserMod = new ParserModule();
	//std::make_unique<ParserModule>(new ParserModule);
}

ParserSystem::~ParserSystem()
{
	// lexerMod.reset();
	delete lexerMod;
	// parserMod.reset();
	delete parserMod;
}






std::vector<std::string> 	ParserSystem::ReadFileLines(std::string path)
{
	std::vector<std::string> result;
	std::string content;
	std::ifstream in(path.c_str());
	// Extracting process
	if (in.is_open())
	{
		while (getline(in, content))
		{
			result.push_back(std::string(content));
		}
	}
	else
	{
		std::cout << "File cannot be Opened" << std::endl;
		throw; // TODO Add custom Exception 
	}
	return result;
}

void 	ParserSystem::ParseInputFile(std::string path)
{	// TODO Return Vector of ICommands

	std::cout << path << std::endl;
	// Extract string contents from file
	// Lexer Content on Lines Split
	lexerMod->SetupNewLines(ReadFileLines(path));
	lexerMod->ShowScannedData();

	// Lexer Lines on Tokens Split

	// Loop
		// Line Tokens to Parser
		// Recieve Command to result
	
	// Return Result
	 


}

