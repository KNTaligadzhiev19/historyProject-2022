#include "pch.h"
#include "CppUnitTest.h"
#include "../historyProject/Back-End/Header Files/loginForm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
	TEST_CLASS(UnitTestProject)
	{
	public:
		
		TEST_METHOD(checkLoginFormWithCorrectData)
		{
			std::string enteredUsername = "admin", enteredPassword = "admin";
			std::fstream userInfo;

			bool flag = findUser(enteredUsername, enteredPassword, userInfo);

			Assert::IsTrue(flag);
		}

		TEST_METHOD(checkLoginFormWithIncorrectUserName)
		{
			std::string enteredUsername = "username", enteredPassword = "admin";
			std::fstream userInfo;

			bool flag = findUser(enteredUsername, enteredPassword, userInfo);

			Assert::IsFalse(flag);
		}

		TEST_METHOD(checkLoginFormWithIncorrectPassword)
		{
			std::string enteredUsername = "admin", enteredPassword = "password";
			std::fstream userInfo;

			bool flag = findUser(enteredUsername, enteredPassword, userInfo);

			Assert::IsFalse(flag);
		}


	};
}
