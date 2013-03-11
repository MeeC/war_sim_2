#ifndef BATTLE_H
#define BATTLE_H

#include "soldier.h"

#include "globals.h"
#include "functions.h"
//#include "battle.h"

class Battle{

private:
	int m_sold_type;
	Soldier *testS;
	Soldier *testS2;
	
public:
	Battle(){};
	//methodos pou pairnei san orismata dyo antikeimena soldier kai kanei tin maxi
	int doFight(Soldier cSold1,Soldier cSold2)
	{
		int winner, winners_id, loser_army_id;
		//i randomness epistrefei enan tyxaio arithmo apo to 1 ews to 100
		int rate=randomness(100);
		//analoga me ton typo twn stratiwtwn ginetai maxi me ta analoga pososta
		if(cSold1.m_type== cSold2.m_type)
		{
			if(rate<51)winner=1;
			else winner=2;
		}

		else if(cSold1.m_type==ARCHER && cSold2.m_type== SWORDSMAN)
		{
			if(rate<71)winner=1;
			else winner=2;
		}
		else if(cSold1.m_type==SWORDSMAN && cSold2.m_type== ARCHER)
		{
			if(rate<31)winner=1;
			else winner=2;
		}
		//analoga me ton nikiti pername to id tou stratopedou tou se mia metavliti
		if(winner==1)
		{
			winners_id=cSold1.m_armys_id;
			loser_army_id=cSold2.m_armys_id;
			printBattleResult(cSold1.m_posX, cSold1.m_posY, cSold2.m_soldier_name, cSold1.m_soldier_name);
		}

		else if(winner==2)
		{		
			winners_id=cSold2.m_armys_id;
			loser_army_id=cSold1.m_armys_id;
			printBattleResult(cSold1.m_posX, cSold1.m_posY, cSold1.m_soldier_name, cSold2.m_soldier_name);
		}
		

		//epistrefei to id tou xamenou tis maxis
		return loser_army_id;	
	}

	void printBattleResult(int row, int col, string soldiers1_name, string soldiers2_name)
	{
		show_kill(row,col,soldiers1_name,soldiers2_name);		
	}

};

#endif
