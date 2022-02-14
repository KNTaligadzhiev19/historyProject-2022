#include <iostream>
#include <SFML/Graphics.hpp>
#include "Front-End/header Files/startProgram.h"
#include "Back-End/Header Files/timelineMode.h"

int main()
{
	NODE* head = new NODE;
	head->next = NULL;

	startProgram(head);
}