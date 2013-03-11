#include "globals.h"
#include "functions.h"
#include "soldier.h"

//orismos tou dimiourgou tis klassis
Soldier::Soldier(int s_id, int a_id, int posX, int posY, int max_dim)
{
	m_soldier_id=s_id;	
	m_armys_id=a_id;
	m_posX=posX; 
	m_posY=posY;
	setStatus(ALIVE);
	m_max_dim=max_dim;
	m_casx=posX;
	m_casy=posY;

	if(getSoldierID()%2==0)
	{
		setType(ARCHER);
	}
	else if(getSoldierID()%2==1)
	{
		setType(SWORDSMAN);
	}
	setSoldierName();
}

/* ulopoioume th methodo setSoldierID() h poia pairnei san orisma to id tou kathe stratioti kai to antistoixizei sth metavlith m_soldier_id */
void Soldier::setSoldierID(int s_id)
{
	m_soldier_id=s_id;
}

/* ulopoioume th methodo setSoldierID() h poia pairnei san orisma to id tou kathe kastrou kai to antistoixizei sth metavlith m_armys_id */
void Soldier::setArmysID(int a_id)
{
	m_armys_id=a_id;
}
/* ulopoioume th methodo setType() h opoia pairnei san orisma ton typou tou stratioti Archer 'h Swordsman kai to apothikeuei sth metavlith m_type */

void Soldier::setType(int type)
{
	m_type=type;
}
/* ulopoioume th methodo setPosition() h poia pairnei san orisma tis suntetagmenes x, y kai tis antistoixizei stis metavlithes m_posX kai m_posY antistoixa  */
void Soldier::setPosition(int posX, int posY)
{
	m_posX=posX; 
	m_posY=posY;
}

/* ulopoioume th methodo setStatus() h opoia pairnei san orisma thn katastash tou kathe stratioth pou mporei na exei ti9s times ALIVE 'h DEAD kai apothikeuei auth th katastash sth metavlith m_life_status */
void Soldier::setStatus(int status)
{
	m_life_status=status;
}

/* ulopoioume th methodo getSoldierID() h opoia epistrefei to id tou stratioti meso ths metavliths m_soldier_id */
int Soldier::getSoldierID(void)
{
	return m_soldier_id;
}

/* ulopoioume th methodo getArmyID() h opoia epistrefei to id tou stratou meso ths metavliths m_armys_id */
int Soldier::getArmysID(void)
{
	return m_armys_id;
}

/* ulopoioume th methodo getType() h opoia epistrefei ton typo tou stratioti: Archer 'h Swordsman sth metavlith m_type */
int Soldier::getType(void)
{
	return m_type;
}

/* ulopoioume th methodo getPositionX() h opoia epistrefei th thesi ston aksona x sth metavlith m_posX */
int Soldier::getPositionX(void)
{
	return m_posX; 
}

/* ulopoioume th methodo getPositionY() h opoia epistrefei th thesi ston aksona y sth metavlith m_posY */
int Soldier::getPositionY(void)
{
	return m_posY;
}

/* ulopoioume th methodo getStatus() h opoia epistrefei th katastash tou kathe stratioti kai thn apothikeuei sth metavlith m_life_status */

int Soldier::getStatus(void)
{
	return m_life_status;
}

/* ulopoioume th methodo setSoldierName() mesa sthn opoia antistoixizetai o tupos tou stratioti se Archer 'h Swordman analoga me thn eisodo kai epishs ta stratopeda antistoixizonte se A, B, C, D analoga me thn eisodo 1, 2, 3, 4 */
void Soldier::setSoldierName(void)
{
	stringstream soldName;
	string s_army;
	string s_type;
	string s_name;
	int type,army;
	army=getArmysID();
	type=getType();

	if (type==ARCHER)s_type="Archer ";
	else if(type==SWORDSMAN)s_type="Swordsman ";

	if (army==1)s_army="A ";
	else if (army==2)s_army="B ";
	else if (army==3)s_army="C ";
	else if (army==4)s_army="D ";
	soldName<<s_army<<s_type<<getSoldierID();

	s_name=soldName.str();

	m_soldier_name=s_name;
}

/* ulopoioume th methodo printSoldiresStats() h opoia gia kathe stratioti ektuponei to id tou, to id tou stratopedou mou anhkei, tis suntetagmenes tou stratioti mesa sto xarti, ton typo tou kai mtelos thn katastash tou DEAD or ALIVE */
void Soldier::printSoldierStats(void)
{
	cout<<"SoldiersID: "<<m_soldier_id<<endl;
	cout<<"Army's ID: "<<m_armys_id<<endl;
	cout<<"Soldiers Position: ("<<m_posX<<","<<m_posY<<")"<<endl;

	if(m_type == ARCHER)
		cout<<"Soldiers Type: ARCHER"<<endl;
	else if(m_type == SWORDSMAN)
		cout<<"Soldiers Type: SWORDSMAN"<<endl;	

	if(m_life_status == ALIVE)
		cout<<"Soldiers Status: ALIVE"<<endl;
	else if(m_life_status == DEAD)
		cout<<"Soldiers Status: DEAD"<<endl;
}

/* ulopoioume th methodo moveSoldier() h opoia ulopoei tis kinhseis ton stratioton, pairnei san parametro thn kinhsh thn opoia thelei na kanei dld Up, DOWN, LEFT, RIGHT, upologizei tis torines suntetagmenes tou stratioti kai me vasi autes pragmatopoiei thn kinhsh. Oles oi kinhseis prepei na einai entos ton diastaseon tou kosmou, opote an enas stratioths prospathisei na metakinhthei ektos, tote metakineitai sthn apenanti kateuthunsh apo auth pou hthele na paei */
void Soldier::moveSoldier(int moveto)
{
	int cur_x, cur_y, max_dim;
	cur_x=getPositionX();
	cur_y=getPositionY();
	max_dim=getMaxDim();

	if(moveto == UP)
	{
		cur_y++;
		if(cur_y>max_dim)cur_y=1;
		setPosition(cur_x,cur_y);
	}

	else if(moveto == DOWN)
	{
		cur_y--;
		if(cur_y<1)cur_y=max_dim;
		setPosition(cur_x,cur_y);
	}

	else if(moveto == LEFT)
	{
		cur_x--;
		if(cur_x<1)cur_x=max_dim;
		setPosition(cur_x,cur_y);
	}

	else if(moveto == RIGHT)
	{
		cur_x++;
		if(cur_x>max_dim)cur_x=1;
		setPosition(cur_x,cur_y);
	}
}

/* ulopoioume thn methodo doRandomMove() sumfona me thn opoia se kathe kinhsh enas stratiotis mporei na proxorhsei pros mia tuxaia kateuthunsh me pithanothta 80% 'h na valei pagida sth thesi pou vriskete me pithanothta 20%  */
void Soldier::doRandomMove(void)
{
	int current_x, current_y, direction, rate1, rate2;
	current_x=getPositionX();
	current_y=getPositionY();

	/* paragoume ton proto tuxaio arithmo rate1 me times apo 1 eos 100 pou antiprosopeuei thn pithanothta o stratioths na kinhthei 'h na valei pagida */
	rate1=randomness(100);

	/* an o arithmos rate1 pou opos eipame antiprosopeuei pithanoththa einai megaluteros tou 20, tote o stratioths tha kinhtei efoson omos elenksoume oti einai zontanos */
	if((rate1>20 && getStatus()==ALIVE) || (getPositionX()==m_casx && getPositionY()==m_casy)) 
	{ 	/* paragoume enan deutero tuxaio arithmo rate2 epishs apo to 1 eos to 100 pou auth th fora antiprosopeuei tis pithanonhtes an to stratioths kinhthei na paei pros mia apo tis 4 katheuthunseis UP DOWN LEFT RIGHT. Kai oi 4 kateuthunseis einai isopithanes kai tous antistoixoun 25% pithanothta */
		rate2=randomness(100);
		if(rate2<31) direction=UP;
		else if(rate2>30 && rate2<51) direction=DOWN;
		else if(rate2>50 && rate2<76) direction=LEFT;
		else if(rate2>75) direction=RIGHT;

		/* kaloume th mehthodo moveSoldier() h opoia tha pragmatopoihsei thn kinhsh */
		moveSoldier(direction);	
		
		cout <<"ROW:"<<current_x<<" COL:"<<current_y<<" ";
		cout <<getSoldierName() << " moved to ";
		cout <<"("<<getPositionX()<<","<<getPositionY()<<")"<<endl;
	}	

	/* erxomaste pali ston elenxo tou protou tuxaiou arithmou rate1. AN einai mikroteros tou 20 tote antiprosopeuei thn pithanothta o startioths na valei padiga sth thesi edoson omos vevea einai zontanos */
	else if(rate1<21 && getStatus()==ALIVE)	
	{	
		cout <<"ROW:"<<current_x<<" COL:"<<current_y<<" ";
		cout << getSoldierName() << " set TRAP on ";
		cout <<"("<<getPositionX()<<","<<getPositionY()<<")"<<endl;

		/* kaloume th methodo setTrapFlag() kai energopoioume to flag pou einai endeiksh gia to an mphke padiga */
		setTrapFlag();
	}
}

