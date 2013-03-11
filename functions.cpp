#include "globals.h"
#include "functions.h"

/*H synartisi afti dexetai ena string kai to metatrepei se akeraio*/
int strtoint(string str)
{
	int integer;
	/*Me ti methodo c_str() metatrepoume to string se mia diataksi char kai me tin atoi() metatrepoume afto to char se int*/
	integer = atoi(str.c_str());
	return integer;
}

/*H sinartisi afti pairnei san orisma enan akeraio pou einai ena evros timwn kai epistrefei mia tyxaia timi apo afto
to evros me tin xrisi tis rand() PROSOXH!: gia na einai kathe fora tyxaioi oi arithmoi pou paragontai tha prepei kapou
stin arxi tou programmatos mas na klithei i srand pou dinei ena diaforetiko kathe fora seed stin rand me vasi to opoio 
tha paragontai oi arithmoi.*/
int randomness(int range)
{
	int rand_num;
	/*H rand me vasi kapoion arithmo seed paragei tyxaious arithmous. To akeraio ypoloipo tis diairesis aftou tou arithmou
	me tin range mas dinei enan aritmo sto evros range. To +1 einai gia na ksekinaei to evros apo to 1 kai na teleiwnei sto
	range. Ekxwroume tin tyxaia timi sti meravliti rand_num*/
	rand_num = rand()%range +1;
	/*epistrefoume tin tyxaia timi pou ftiaksame */
	return rand_num;
}

void effect(void)
{
	//xrisi tis entolis clear tou unix gia effe antistrofis metrisis
	system("clear");
	cout << "Game is starting in: 3" <<endl;
	sleep(1);
	system("clear");
	cout << "Game is starting in: 2" <<endl;
	sleep(1);
	system("clear");
	cout << "Game is starting in: 1" <<endl;
	sleep(1);
	system("clear");
	cout << "New Game Started!" <<endl;
}

void show_start(void)
{
	cout << "===================================\n";
	cout << "     PRESS ENTER TO START GAME    \n";
	cout << "===================================\n";
}

void show_next(void)
{
	cout << "===================================\n";
	cout << "     PRESS ENTER TO NEXT ROUND    \n";
	cout << "===================================\n";
}

void show_round(int round)
{
	system("clear");
	cout << "===================================\n";
	cout << "              ROUND "<<round<<"      \n";
	cout << "===================================\n";

}

void show_kill(int row, int col, string soldiers1_name, string soldiers2_name)
{
	cout << "ROW:"<<row<<" COL:"<<col<<" "<<soldiers1_name<<" killed by "<<soldiers2_name<<endl; 
}

void show_kill(int row, int col, string soldiers1_name, char army_name, int weapon)
{
	string weapon_name;
	if (weapon==CASTLE)weapon_name=" Castle!";
	else if(weapon==TRAP)weapon_name=" TRAP!";
	
	cout << "ROW:"<<row<<" COL:"<<col<<" "<<soldiers1_name<<" killed by "<<army_name<<weapon_name<<endl; 
}

bool isGameover(int alive_A, int alive_B, int alive_C, int alive_D)
{
	string winner; 
	bool win_flag=false;

	/*elegxos gia to an ta stratopeda exoun zontanous stratiwntes. AN oxi pame se nikiti kai game over*/
	if(alive_A==0&&alive_C==0&&alive_D==0&&alive_B!=0) 
		winner="ARMY B WINS", win_flag=true;

	else if(alive_B==0&&alive_C==0&&alive_D==0&&alive_A!=0)
		winner="ARMY A WINS", win_flag=true;

	else if(alive_B==0&&alive_A==0&&alive_D==0&&alive_C!=0)
		winner="ARMY C WINS", win_flag=true;

	else if(alive_B==0&&alive_C==0&&alive_A==0&&alive_D!=0)
		winner="ARMY D WINS", win_flag=true;

	//an oloi skothikana stin telftaia kinisi exoume isopalia
	else if(alive_B==0&&alive_C==0&&alive_A==0&&alive_D==0)
		winner="DRAW NOBODY WINS", win_flag=true;
	
	if (win_flag)
	{
		cout <<"=============GAME OVER=============\n";
		cout << "           "<<winner<<"!!!\n";
		cout << "============GAME OVER=============\n";		
		return win_flag;
	}
	else return win_flag;

}

void printLine(int mapSize, int game_mode)
{
	/*Sxediazoume tis orizonties grammes tou xarti diaforetika analoga me ta stratopeda*/
	for(int k=1; k<mapSize+1; k++)
	{
		if(game_mode==2)
		{	
			if(k!=mapSize)				
				cout << "-------------------------";
			else
				cout << "-------------------------\n";
		}

		else if(game_mode==3)
		{	
			if(k!=mapSize)				
				cout << "------------------------------";
			else
				cout << "------------------------------\n";
		}
		if(game_mode==4)
		{	
			if(k!=mapSize)				
				cout << "-----------------------------------";
			else
				cout << "-----------------------------------\n";
		}
	}


}




