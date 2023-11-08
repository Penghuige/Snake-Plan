#include "map.h"
#include "virables.h"
#include <iostream>
#include "controller.h"

void Map::PrintInitmap()
{
	for (auto& p : initmap)
	{
		Controller::gotoxy(p.getX(), p.getY());
		std::cout << "■";
	}
}
