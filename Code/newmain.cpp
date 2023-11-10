#include "controller.h"
#include "virables.h"

int main()
{
	Controller c;
	c.SetSize(2 * COL + 2, 2 * ROW + 2);
	c.gameMenu();

	return 0;
}