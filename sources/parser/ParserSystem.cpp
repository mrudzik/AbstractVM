

#include "ParserSystem.hpp"
#include "CustomExceptions.hpp"
#include <fstream>

ParserSystem::ParserSystem(/* args */)
{
	lexerMod = new LexerModule();
	parserMod = new ParserModule();
}

ParserSystem::~ParserSystem()
{
	delete lexerMod;
	delete parserMod;
	ClearResults();
}


void ParserSystem::ClearResults()
{
	size_t i = resultCommands.size();
	while (i > -1)
	{// Releasing memory behind pointers
		delete resultCommands.at(i);
		i--;
	}
	// Releasing now pointers
	resultCommands.clear();
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
	// Lexer Lines on Tokens Split
	lexerMod->SetupNewLines(ReadFileLines(path));
	// Lexer Clear empty lines with no tokens
	lexerMod->ClearEmptyLines();
	lexerMod->ShowScannedData();


	// Loop
	size_t size = lexerMod->GetLexedSize();
	size_t i = 0;
	size_t foundErrors = 0;
	while (i < size)
	{
		bool foundError = false;
		// Line Tokens to Parser
		try
		{
			Command *tempCommand = parserMod->ParseLine(lexerMod->GetLexedLine(i));
			// Recieve Command to result
			// If there is no exceptions than instance will be added to result
			resultCommands.push_back(tempCommand);
		}
		catch (const std::exception& err)
		{
			std::cout << "Found Error at line " << i << ":\n"
				<< err.what() << std::endl;
			foundError = true;
		}
		
		if (foundError)
		{
			foundErrors++;
			i++;
			continue;
		}
		i++;
	}


	if (foundErrors != 0)
	{// Throw Custom exception that found alot of Errors
		std::cout << "Found Errors" << std::endl;
	}

	// Return Result
	 


}

