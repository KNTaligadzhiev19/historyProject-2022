#include <iostream>
#include "../header Files/timelineMode.h"

void newElement(NODE& head)
{
	NODE* newElement = new NODE;

	newElement->next = NULL;

	head.next = newElement;
}