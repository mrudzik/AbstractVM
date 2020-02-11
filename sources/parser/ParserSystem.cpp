

#include "ParserSystem.hpp"
#include "CustomExceptions.hpp"
#include <fstream>

#include "CommandFactory.hpp"
#include "OperandFactory.hpp"
#include "Core.hpp"

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
	int i = static_cast<int>(_resultCommands.size()) - 1;
	while (i > -1)
	{// Releasing memory behind pointers
		delete _resultCommands.at(i);
		i--;
	}
	// Releasing now pointers
	_resultCommands.clear();
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

void 	ParserSystem::ParseLinesToCommands()
{
	// Loop
	size_t size = lexerMod->GetLexedSize();
	size_t i = 0;
	size_t foundErrors = 0;
	bool foundExit = false;

	while (i < size)
	{
		try
		{// Line Tokens to Parser
			Command *tempCommand = parserMod->ParseLine(lexerMod->GetLexedLine(i));
			// Recieve Command to result
			// If there is no exceptions than instance will be added to result
			_resultCommands.push_back(tempCommand);
			if (tempCommand->GetInstruction() == e_InstructionType::Exit)
				foundExit = true;
		}
		catch (const std::exception& err)
		{
			std::cout << "Line " << i + 1 << ": "
				<< "\033[21;36m" << lexerMod->GetLexedLine(i).line << "\033[0m\n"
				<< err.what() << std::endl;
			foundErrors++;
		}
		i++;
	}
	
	if (!foundExit)
		throw NoExitException();

	if (foundErrors != 0)
	{// Throw Custom exception that found alot of Errors
		throw FoundErrorsException();
	}
}



void 	ParserSystem::ParseInputFile(std::string path)
{	// TODO Return Vector of ICommands

	std::cout << path << std::endl;
	// Extract string contents from file
	// Lexer Content on Lines Split
	// Lexer Lines on Tokens Split
	lexerMod->SetupNewLines(ReadFileLines(path));
	try
	{
		ParseLinesToCommands();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'
		<< "Closing Program" << '\n';
		return;
	}

	// Return Result
	size_t i = 0;
	while (i < _resultCommands.size())
	{
		std::cout << "\n";
		_resultCommands.at(i)->ShowCommand();
		i++;
	}

	std::cout << "\n\n--------\nTesting Core" << std::endl;
	Core testCore(_resultCommands);

	std::cout << "\nEnd of Parser System" << std::endl;
}

