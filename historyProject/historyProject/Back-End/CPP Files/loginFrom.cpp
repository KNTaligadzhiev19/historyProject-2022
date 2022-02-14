#include "../Header Files/loginForm.h"

bool extractInfo(std::string line, std::string enteredUsername, std::string enteredPassword)
{
	std::string username, password;
	int i = 0;

	for (; i < line.size(); i++)
	{
		if (line[i] != '#')
		{
			username += line[i];
		}
		else
		{
			break;
		}
	}

	i++;

	for (; i < line.size(); i++)
	{
		if (line[i] != '#')
		{
			password += line[i];
		}
		else
		{
			break;
		}
	}

	if (enteredUsername == username && enteredPassword == password)
	{
		return true;
	}

	return false;
}

bool findUser(std::string enteredUsername, std::string enteredPassword, std::fstream& userInfo)
{
	userInfo.open("userInfo.txt", std::ios::in);

	if (userInfo.is_open())
	{
		std::string line, info;
		while (std::getline(userInfo, line))
		{
			if (extractInfo(line, enteredUsername, enteredPassword))
			{
				return true;
			}
		}
		userInfo.close();
	}

	return false;
}