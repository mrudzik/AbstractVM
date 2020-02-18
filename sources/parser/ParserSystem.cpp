

#include "ParserSystem.hpp"
#include "CustomExceptions.hpp"
#include <fstream>

#include "CommandFactory.hpp"
#include "OperandFactory.hpp"
#include "Core.hpp"

ParserSystem::ParserSystem(/* args */)
{}

ParserSystem::~ParserSystem()
{}


void ParserSystem::ClearCommands(std::vector<Command*> &commVec)
{
	if (commVec.empty())
		return;

	for (int i = static_cast<int>(commVec.size()) - 1; i > -1; i--)
	{// Releasing memory behind pointers
		delete commVec.at(i);
	}
	// Releasing now pointers
	commVec.clear();
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
		throw CustomException("Cannot Open File"); 
	}
	return result;
}

std::vector<Command*>  	ParserSystem::ParseLinesToCommands(std::vector<s_LexerLine> &parsedData)
{
	std::vector<Command*> resultCommands;
	// Loop
	size_t size = parsedData.size();
	size_t i = 0;
	size_t foundErrors = 0;
	bool foundExit = false;
	while (i < size)
	{
		try
		{// Line Tokens to Parser
			Command *tempCommand = ParserModule::ParseLine(parsedData.at(i));
			// Recieve Command to result
			// If there is no exceptions than instance will be added to result
			resultCommands.push_back(tempCommand);
			if (tempCommand->GetInstruction() == e_InstructionType::Exit)
				foundExit = true;
		}
		catch (const std::exception& err)
		{
			std::cout << "Line " << i + 1 << ": "
				<< "\033[21;36m" << parsedData.at(i).line << "\033[0m\n"
				<< err.what() << std::endl;
			foundErrors++;
		}
		i++;
	}
	
	if (!foundExit)
	{
		ClearCommands(resultCommands);
		throw NoExitException();
	}
	if (foundErrors != 0)
	{
		ClearCommands(resultCommands);
		throw FoundErrorsException();
	}
	return resultCommands;
}



void 	ParserSystem::ParsingProcedure(std::vector<s_LexerLine> &parsedData)
{
	std::vector<Command*> resultCommands;
	try
	{
		resultCommands = ParseLinesToCommands(parsedData);

		for (size_t i = 0; i < resultCommands.size(); i++)
		{
			std::cout << "\n" << (i + 1) << "|\t";
			resultCommands.at(i)->ShowCommand();
		}
		std::cout << "\n\nApplying Commands to Core\n" << std::endl;
		Core realCore(resultCommands);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Closing Program" << '\n';
	ClearCommands(resultCommands);
}





void 	ParserSystem::ParseInputFile(std::string path)
{	// TODO Return Vector of ICommands

	std::cout << path << std::endl;
	// Extract string contents from file
	// Lexer Content on Lines Split
	// Lexer Lines on Tokens Split
	try
	{
		std::vector<s_LexerLine> parsedData = LexerModule::SetupNewLines(ReadFileLines(path));
		ParsingProcedure(parsedData);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ParserSystem::ParseInputManual()
{
	std::vector<std::string> scannedText;

	bool loop = true;
	while (loop)
	{// Inf Loop
		std::string str;
		std::getline(std::cin, str);

		if (str.compare(";;") == 0)
			break; //Checking exit command for manual parsing
	
		scannedText.push_back(str);
	}
	try
	{
		std::vector<s_LexerLine> parsedData = LexerModule::SetupNewLines(scannedText);
		ParsingProcedure(parsedData);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}

