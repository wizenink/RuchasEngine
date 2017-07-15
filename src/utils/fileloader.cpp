#include "fileloader.h"
namespace utils 
{
	std::string loadfile(std::string filepath)
	{
		std::ifstream filehandler;
		filehandler.open(filepath);
		std::string errormsg = "Could not open file:" + filepath;
		std::stringstream stringbuffer;
		if (filehandler.is_open())
		{
			stringbuffer << filehandler.rdbuf();
		}
		return stringbuffer.str();

	}
}