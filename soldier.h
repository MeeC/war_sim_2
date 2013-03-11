#ifndef SOLDIER_H
#define SOLDIER_H

/* dhlosh ths klashs Soldier */
class Soldier{

private:
	int m_soldier_id, m_armys_id, m_type, m_posX, m_posY; 
	int m_life_status,m_max_dim,m_trap_flag,m_casx,m_casy;
	string m_soldier_name; 

public:
	/* dhlosh tou constructor xoris orismata */
	Soldier(){};

	/* dhlosh tou constructor me orismata ta ids ton stratioton, ta ids ton kastron, tis suntetagmenes x kai y 
	kai telos th megisth diastash tou kosmou */
	Soldier(int s_id, int a_id, int posX, int posY, int max_dim);

	/* dhlosh ton methodon pou xrhsimopoiei h klash */

	void setSoldierID(int s_id);

	void setArmysID(int a_id);

	void setType(int type);

	void setPosition(int posX, int posY);

	void setStatus(int status);

	void setTrapFlag(void){m_trap_flag=1;}

	void clearTrapFlag(void){m_trap_flag=0;}

	int getTrapFlag(void){return m_trap_flag;}

	int getSoldierID(void);

	int getArmysID(void);

	int getType(void);

	int getPositionX(void);

	int getPositionY(void);

	int getStatus(void);
	
	void setSoldierName(void);

	string getSoldierName(void){return m_soldier_name;}

	int getMaxDim(void){return m_max_dim;}

	void moveSoldier(int moveto);	

	void printSoldierStats(void);
	
	void doRandomMove(void);
	
	friend class Battle;
};

#endif
