#include "globals.h"
#include "functions.h"
#include "map.h"

//dimiourgos tis klasis me orismata
Map::Map(int max_dim, int array_x,int array_y,int armies)
{
	m_max_dim=max_dim;	
	m_array_posX=array_x; 
	m_array_posY=array_y;
	m_armies=armies;
	setMapPosition();
}

//arxikopoioei osa prpeei na einai 0 stin axri tou paixnidiou
void Map::resetAll(void)
{
	m_soldsA=0; 
	m_soldsB=0; 
	m_soldsC=0; 
	m_soldsD=0;
	m_trap=0;
	m_castle=0;


	memset(&m_soldsA,'\0',sizeof(int));
	memset(&m_soldsB,'\0',sizeof(int));
	memset(&m_soldsA,'\0',sizeof(int));
	memset(&m_soldsB,'\0',sizeof(int));
	memset(&m_trap,'\0',sizeof(int));	
	memset(&m_castle,'\0',sizeof(int));	
			

}

//arxikopoiei osa prpei na einai 0 prin tin sxediasi tou xarti se kathe gyro
void Map::resetRound(void)
{
	m_soldsA=0; 
	m_soldsB=0; 
	m_soldsC=0; 
	m_soldsD=0;

	memset(&m_soldsA,'\0',sizeof(int));
	memset(&m_soldsB,'\0',sizeof(int));
	memset(&m_soldsC,'\0',sizeof(int));	
	memset(&m_soldsD,'\0',sizeof(int));		
}

//methodos pou enimerwnei tin metavliti castle wste na kserei an yparxei kastro kai apo poion
void Map::setCastle(int castle_id)
{
	m_castle=1;
	m_castle_id=castle_id;
}

//methodos pou enimerwnei tin metavliti trap wste na kserei an yparxei pagida kai apo poion
void Map::setTrap(int trap_id)
{
	m_trap=1;
	m_trap_id=trap_id;
}
//den xrisimopoieitai
void Map::setMapPosition(void)
{
	m_pos_x=m_array_posX;
	m_pos_y=m_array_posY;
}
//afairei pagida
void Map::removeTrap(void)
{
	m_trap=0;
	m_trap_id=0;
}
//epistrefei apo poion yparxei pagida, 0 an den yparxei
int Map::isTrap(void)
{
	return m_trap_id;	
}
//sxediazei ena apo ta koutia tou xarti me tis sxetikes plirofories
string Map::drawBox(void)
{
	string castle, trap, box;
	ostringstream output;
	char zeroA,zeroB,zeroC,zeroD;	
	if (m_castle==1)
	{
		if (m_castle_id==1) castle=", A";
		else if (m_castle_id==2) castle=", B";
		else if (m_castle_id==3) castle=", C";
		else if (m_castle_id==4) castle=", D";
	}	
	else castle=" ,e";

	if (m_trap==1)
	{
		if (m_trap_id==1) trap=", A";
		else if (m_trap_id==2) trap=", B";
		else if (m_trap_id==3) trap=", C";
		else if (m_trap_id==4) trap=", D";
	}	
	else trap=" ,e";

	//an enas arithmos einai katw apo to 10 prosthetei ena mideniko wste na einai stin morfi xx
	if(getSoldsA()<10) zeroA='0';
		else zeroA='\0';
	if(getSoldsB()<10) zeroB='0';
		else zeroB='\0';
	if(m_armies>2)
	{
		if(getSoldsC()<10) zeroC='0';
		else zeroC='\0';
		if(m_armies>3)
		{
			if(getSoldsD()<10) zeroD='0';
			else zeroD='\0';
		}
	}

	if(getarrayY()==getMaxDim())
	{
		if(m_armies==2)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()<<trap<<castle<<" |\n";
		else if(m_armies==3)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()
			<<" C:"<<zeroC<<getSoldsC()<<trap<<castle<<" |\n";
		else if(m_armies==4)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()
			<<" C:"<<zeroC<<getSoldsC()<<" D:"<<zeroD<<getSoldsD()<<trap<<castle<<" |\n";
	}
	else
	{
		
		if(m_armies==2)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()<<trap<<castle<<" |";
		else if(m_armies==3)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()
			<<" C:"<<zeroC<<getSoldsC()<<trap<<castle<<" |";
		else if(m_armies==4)
			output <<"| ("<< getposX()<<","<<getposY()<<")" << " A:"<<zeroA<<getSoldsA()<<" B:"<<zeroB<<getSoldsB()
			<<" C:"<<zeroC<<getSoldsC()<<" D:"<<zeroD<<getSoldsD()<<trap<<castle<<" |";
		
	}
	
	box=output.str();
	return box;
	
}



void Map::addSoldier(int army_id)
{
	if(army_id==1){m_soldsA++;}
	else if(army_id==2){m_soldsB++;}
	else if(army_id==3){m_soldsC++;}
	else if(army_id==4){m_soldsD++;}
}

void Map::removeSoldier(int army_id)
{
	if(army_id==1){m_soldsA--;}
	else if(army_id==2){m_soldsB--;}
	else if(army_id==3){m_soldsC--;}
	else if(army_id==4){m_soldsD--;}
}

