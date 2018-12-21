#include "Battle.h"
#include "GUI\GUI.h"
#include<cstdlib>
#include<ctime>

int main()
{
	srand(time(NULL));
	Battle* pGameBattle = new Battle;
	pGameBattle->RunSimulation();
	
	delete pGameBattle;
	
	return 0;
}
