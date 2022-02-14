#include "../Header Files/registerForm.h"

void registerUser(std::string username, std::string password)
{
	std::fstream userInfo;

	userInfo.open("userInfo.txt", std::ios::app);
	if (!userInfo.is_open())
	{
		std::cout << "Can not open userInfo.txt";
	}

	userInfo << username << "#&#";
	userInfo << password << '\n';

	userInfo.close();
}