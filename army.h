#ifndef ARMY_H
#define ARMY_H

#include "game.h"
#include "soldier.h"

/* dhlosh ths klashs Army */
class Army{

private:
	int m_soldiers, m_castlePosX, m_castlePosY, m_army_id, m_max_dim;
	char m_army_name;
	

public:
	Soldier *c_Soldier[21];
	/* dhlosh tou constructor xoris orismata */
	Army(){}

	Army(int id);

	/* dhlosh tou constructor me orisma to id tou kathe stratou */
	Army(int id, Game n_Game);

	Army(int id, Game n_Game, int test);


	/* dhlosh ton methodon pou xrhsimopoiei h klash */

	void setSoldiers(int soldiers);

	void setCastleX(int castlex);

	void setCastleY(int castley);
	
	void setArmyID(int id);

	void setArmyName(int id);

	char getArmyName(void){return m_army_name;}

	int getSoldiers(void){return m_soldiers;}

	int getCastleX(void){return m_castlePosX;}

	int getCastleY(void){return m_castlePosY;}

	int getArmyID(void){return m_army_id;}

	void printArmyStats(void);

	void createSoldier(void);

};

#endif
