#ifndef MAP_H
#define MAP_H

class Map{

private:
	int m_soldsA, m_soldsB, m_soldsC, m_soldsD, m_armies;
	int m_trap, m_trap_id, m_castle,m_castle_id,m_max_dim, m_pos_x, m_pos_y,m_array_posX,m_array_posY; 
	
public:
	//dimiourgoi xwris kai me orismata antistoixa	
	Map(){};

	Map(int max_dim,int array_x,int array_y,int armies);
	

	void resetAll(void);

	void resetRound(void);

	string drawBox(void);

	void addSoldier(int army_id);

	void removeSoldier(int army_id);
	
	//prosthetoun enan stratiwti apo to antistoixo stratopedo
	void addSoldierA(void){m_soldsA++;}

	void addSoldierB(void){m_soldsB++;}

	void addSoldierC(void){m_soldsC++;}

	void addSoldierD(void){m_soldsD++;}

	//afairoun enan stratiwti apo to antistoixo stratopedo
	void removeSoldierA(void){m_soldsA--;}

	void removeSoldierB(void){m_soldsB--;}

	void removeSoldierC(void){m_soldsC--;}

	void removeSoldierD(void){m_soldsD--;}

	void setTrap(int trap_id);

	void removeTrap(void);
	
	void setCastle(int castle_id);

	void setMapPosition(void);

	int isTrap(void);

	//get methodoi pou epistrefoun kapoia metavliti
	int getCastle(void){return m_castle;};

	int getSoldsA(void){return m_soldsA;}

	int getSoldsB(void){return m_soldsB;}

	int getSoldsC(void){return m_soldsC;}

	int getSoldsD(void){return m_soldsD;}

	int getposX(void){return m_pos_x;}

	int getposY(void){return m_pos_y;}

	int getarrayX(void){return m_array_posX;}

	int getarrayY(void){return m_array_posY;}	

	int getMaxDim(void){return m_max_dim;}
};

#endif

