#include "globals.h"
#include "functions.h"
#include "army.h"


Army::Army(int id)
{
	setArmyID(id);
	setArmyName(id);
	m_soldiers=20, m_castlePosX=0, m_castlePosY=0;
}

Army::Army(int id, Game n_Game)
{
	setArmyID(id);
	setArmyName(id);
	m_soldiers= n_Game.m_soldiers[id-1]; 
	m_castlePosX=n_Game.m_castle_positions[id-1][0];
	m_castlePosY=n_Game.m_castle_positions[id-1][1];
	m_max_dim=n_Game.m_dim;
}

Army::Army(int id, Game n_Game,int mode)
{
	setArmyID(id);
	setArmyName(id);
	if(!(id>mode))
	{
		m_soldiers= n_Game.m_soldiers[id-1]; 
		m_castlePosX=n_Game.m_castle_positions[id-1][0];
		m_castlePosY=n_Game.m_castle_positions[id-1][1];
		m_max_dim=n_Game.m_dim;

		for(int i = 1 ;i< m_soldiers+1;i++)
		{
			c_Soldier[i]= new Soldier(i,id,m_castlePosX, m_castlePosY,m_max_dim);
		}

		printArmyStats();
	}
}


/* ulopoioume th methodo setSoldiers() h poia pairnei san orisma to plhthos ton stratioton kai to antistoixizei sth metavlith m_soldiers */
void Army::setSoldiers(int soldiers)
{
	m_soldiers=soldiers;
}

/* ulopoioume th methodo setCastleX() h poia pairnei san orisma th thesh tou kastrou ston aksona ton x kai to antistoixizei sth metavlith m_CastleX */
void Army::setCastleX(int castlex)
{
	m_castlePosX=castlex;
}

/* ulopoioume th methodo setCastleY() h poia pairnei san orisma th thesh tou kastrou ston aksona ton y kai to antistoixizei sth metavlith m_CastleY */
void Army::setCastleY(int castley)
{
	m_castlePosY=castley;
}

/* ulopoioume th methodo setArmyID() h poia pairnei san orisma to id tou kastrou kai to antistoixizei sth metavlith m_CastleID */
void Army::setArmyID(int id)
{
	m_army_id=id;
}

/* ulopoioume th methodo setArmyName() h opoia dexete san orisma to id kathe kastrou kai gia kathena apo auta ta ids antistoixei sth metavlith m_army_name tis times A, B, C, D */
void Army::setArmyName(int id)
{
	if(id==1)
		m_army_name='A';
	else if(id==2)
		m_army_name='B';
	else if(id==3)
		m_army_name='C';
	else if(id==4)
		m_army_name='D';

}

/* ulopoioume th methodo printArmyStats() h poia ektuponei ta stoixeia kathe kastrou, opos to id tou, to onoma, tis suntetagmenes tou kai telos ton arithmo ton stratioton pou exei kathe kastro */
void Army::printArmyStats(void)
{
	cout<<"ArmyID: "<<m_army_id<<endl;
	cout<<"Army Name: "<<m_army_name<<endl;
	cout<<"Castle Position: ("<<m_castlePosX<<","<<m_castlePosY<<")"<<endl;
	cout<<"Army Soldiers: "<<m_soldiers<<endl;
}

/*void Army::createSoldiers(int num_of_Soldiers, Soldier *solds[])
{
	
	//arxikopoioume to array me tous stratiotes tou A stratopedou
	for(int i = 1 ;i< num_of_Soldiers+1;i++)
	{
		solds[i]= new Soldier(i,getArmyID(), getCastleX(), getCastleY(), m_max_dim);
	}

}*/

void Army::createSoldier(void)
{
Soldier *mits = new Soldier(10,2,3,4,5);

}




