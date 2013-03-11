#include "globals.h"
#include "functions.h"
#include "game.h"
#include "army.h"
#include "soldier.h"
#include "map.h"
#include "battle.h"

int main(int argc, char *argv[])
{
	string path;
	int rnd=1,mode;

	//an den dosei parametro o xristis ksekiname me to default arxeio init.txt
	if (argc<2)
	{
		path="init.txt";
		cout << "Den exete dosei orisma!\nTo prokathorismeno orisma einai: "<< path <<endl;
	}

	else
	{
		path=argv[1];
		cout << path <<endl;
	}

	/*H srand() arxikopoiei enan arithmo seed, pou xrisimopoieitai apo tin rand() gia na paragei tyxaious arithmous-> Epeidi
	vazoume tin srand na xrisimopoei tin sinartisi time() to seed tha einai i wra se defterolepta kai tha einai diaforetiki
	kathefora pou ekteleitai to programma-> Synepws kanoume tin rand() na doulevei san gennitria tyxaiwn arithmwn->*/	
	srand ( (unsigned)time(NULL) );

	effect();

	//arxikopoioume mia ontotita tis klasis game
	Game *ngame = new Game(path);
	// ektipwnoume tis rithmiseis tou paixnidiou pou ksekiname
	ngame->printGameSettings();
	//apothikevoume stin mode ton arithmo twn stratopedwn
	mode=ngame->get_armies();

	//dilwsi ontotitas army

	Army *army[4];
	for(int i=0; i<4; i++) 
	{
		army[i]=new Army(i+1, *ngame, mode);
	}

	//dilosi ontotitas xarti
	Map *boxMap[ngame->get_dim()+1][ngame->get_dim()+1];

	//midenismos xarti kai arxikopoihsh tou
	for(int i = 1 ;i<ngame->get_dim()+1 ;i++)
	{
		for(int j = 1 ;j<ngame->get_dim()+1 ;j++)
		{
			
				
			boxMap[i][j]= new Map(ngame->get_dim(),i,j,mode);
			
			boxMap[i][j]->resetAll();

		}
	}

	//apothikefsi sintetagmenwn kastrwn

	for(int i =0; i<mode; i++)
	{
		boxMap[army[i]->getCastleX()][army[i]->getCastleY()]->setCastle(i+1);
	}


	//dilosi tis ontotitas maxis
	Battle *fight = new Battle();
	
	//atermon loop mexri na teleiwsei to paixnidi
	for(;;)
	{
		
		//an einai prwtos gyros ektypwnetai to start game
		if(rnd==1)
		{		
			show_start();
		}
		//alliws to next round
		else
		{
			show_next();
		}
		
		//anamoni patimatos enter apo ton xristi
		if(getchar()=='\0');
			show_round(rnd);
		
		/*PAGIDES kai KASTRA (meta ton prwto gyro)*/
		if(rnd>1)
		{	
			//ginontai kai ektypwnontai ta kills pou eginan apo kastra kai pagides		
			cout<<"\nKILLS:\n";

			//entopizoume tous stratiwtes pou epesan se kastro i pagida
			for(int i=0;i<mode;i++)
			{
				for(int j=0;j<mode;j++)
				{
			
					for(int m=1;m<army[i]->getSoldiers()+1;m++)
					{
						if(army[i]->c_Soldier[m]->getPositionX()==army[j]->getCastleX() && army[i]->c_Soldier[m]->getPositionY()==army[j]->getCastleY() 
							&& army[i]->c_Soldier[m]->getStatus() && (i!=j))
						{
							show_kill(army[i]->c_Soldier[m]->getPositionX(),army[i]->c_Soldier[m]->getPositionY(),
									 army[i]->c_Soldier[m]->getSoldierName(),army[j]->getArmyName(), CASTLE);
							
							//afairoume tous skotomenous stratiwtes
							boxMap[army[i]->c_Soldier[m]->getPositionX()][army[i]->c_Soldier[m]->getPositionY()]->removeSoldier(i+1);
							army[i]->c_Soldier[m]->setStatus(DEAD);	
						}

						else if(boxMap[army[i]->c_Soldier[m]->getPositionX()][army[i]->c_Soldier[m]->getPositionY()]->isTrap()==j+1  
							&& army[i]->c_Soldier[m]->getStatus() && (i!=j))
						{
							show_kill(army[i]->c_Soldier[m]->getPositionX(),army[i]->c_Soldier[m]->getPositionY(),
									 army[i]->c_Soldier[m]->getSoldierName(),army[j]->getArmyName(), TRAP);
	 						
							//afairoume skotomenous stratiwtes kai pagides
							boxMap[army[i]->c_Soldier[m]->getPositionX()][army[i]->c_Soldier[m]->getPositionY()]->removeTrap();
							boxMap[army[i]->c_Soldier[m]->getPositionX()][army[i]->c_Soldier[m]->getPositionY()]->removeSoldier(i+1);
				
							army[i]->c_Soldier[m]->setStatus(DEAD);	
						}
					}
				}
			}
		
	
			/*MONOMAXIES*/
			for(int i=1;i<ngame->get_dim()+1;i++)
			{
				for (int j=1;j<ngame->get_dim()+1;j++)
				{	//Ekteleitai mono se 4-players paixnidia
	
					/*Monomaxia an exoume se ena tetragwno 2 toulaxiston diaforetika stratopeda*/
					while(boxMap[i][j]->getSoldsA()>0 && boxMap[i][j]->getSoldsB()>0
					|| boxMap[i][j]->getSoldsA()>0 && boxMap[i][j]->getSoldsC()>0
					|| boxMap[i][j]->getSoldsA()>0 && boxMap[i][j]->getSoldsD()>0
					|| boxMap[i][j]->getSoldsB()>0 && boxMap[i][j]->getSoldsC()>0
					|| boxMap[i][j]->getSoldsB()>0 && boxMap[i][j]->getSoldsD()>0
					|| boxMap[i][j]->getSoldsC()>0 && boxMap[i][j]->getSoldsD()>0)
					{	
						int soldiers_id[4]={0,0,0,0};
						int fighters[2]={0,0};
						int loser=0, random=0, ok_flag=0;
						bool battle_flag[4]={false,false,false,false};
						
						for(int m=0; m<mode; m++)
						{
							/*entopizetai poioi stratiwtes vriskontai sto idio tetragwno*/
							for(int k=1;k<army[m]->getSoldiers()+1;k++)
							{
								if (army[m]->c_Soldier[k]->getPositionX()==i && army[m]->c_Soldier[k]->getPositionY()==j
									 && army[m]->c_Soldier[k]->getStatus())
									{
										soldiers_id[m]=k;
										battle_flag[m]=true;
									}
							}
						}
						//tyxaia epilegoume 2 stratiwtes gia ti monomaxia
						do{
							random=randomness(4);
							if (battle_flag[random-1])
							{	
								battle_flag[random-1]=false; 
								fighters[ok_flag]=random-1;
								ok_flag++;
							}
					
						}while(ok_flag!=2);
					
						//ginetai i maxi anamesa se aftous pou emeinan

						loser=fight->doFight(*army[fighters[0]]->c_Soldier[soldiers_id[fighters[0]]],
												*army[fighters[1]]->c_Soldier[soldiers_id[fighters[1]]]);
					
					
						//osoi xanoun mpainoun se dead status kai den symetexoun pleon sto paixnidi
						boxMap[i][j]->removeSoldier(loser);
						army[loser-1]->c_Soldier[soldiers_id[loser-1]]->setStatus(DEAD);							

					}					
				}	
			}


			/*KINHSEIS*/
			cout <<"\nMOVEMENTS:\n";
			//kathe statiwtis se kathe gyrw kineitai pros kapoia katefthinsi i vazei pagida				
			//to ti tha ginei kathorizetai apo ti methodo doRandomMove tis ontotitas stratiwtis
			
			for(int i=0; i<mode; i++)
			{
				for(int j=1;j< army[i]->getSoldiers()+1;j++)
				{
					army[i]->c_Soldier[j]->doRandomMove();
				}
			}
	
		}	

		/*midenismos twn stratiwtwn pou ypirxan apo proygoumeno gyro wste na ginei nea katametrisi se afton*/
		for (int i=1; i<ngame->get_dim()+1; i++)
		{
			for (int j=1; j<ngame->get_dim()+1; j++)
			{
				boxMap[i][j]->resetRound();
			}
		}	

		/*Katametisi stratiwtwn ston xarti kai topothetisi twn pagidwn*/
		int trapFlag=0;

		int alive[4]={0,0,0,0};
		
		int x=0;
		int y=0;

		/*gia kathe zontano stratiwti elegxetai se poia thesi einai ston xarti kai to an
		exei afisei pagida, an exei afisei prostithetai kai i pagida ston xarti.*/
		for(int i=0; i<mode; i++)
		{
			for (int k=1; k<army[i]->getSoldiers()+1; k++)	
			{
				if ( army[i]->c_Soldier[k]->getStatus()==ALIVE )
				{
					x = army[i]->c_Soldier[k]->getPositionX();		
					y = army[i]->c_Soldier[k]->getPositionY();
					trapFlag = army[i]->c_Soldier[k]->getTrapFlag();
					boxMap[x][y]->addSoldier(i+1);
					alive[i]++;
				
					if ( trapFlag == 1)
					{
						if(!(x==army[i]->getCastleX() && y==army[i]->getCastleY()))
						{
							boxMap[x][y]->setTrap(i+1);
						}

						army[i]->c_Soldier[k]->clearTrapFlag();
						trapFlag = 0;
					}
				}
			}
		}
		

		/*elegxos gia to an ta stratopeda exoun zontanous stratiwntes. AN oxi pame se nikiti kai game over*/
		if(isGameover(alive[0], alive[1], alive[2], alive[3]))
			break;

		/*sxediazoume ton xarti diaforetiko analoga me ton arithmo twn stratopedwn*/
		for (int i=1; i<ngame->get_dim()+1; i++)
		{
			printLine(ngame->get_dim(),mode);			
			
			for (int j=1; j<ngame->get_dim()+1; j++)
			{
				cout<<boxMap[i][j]->drawBox();
			}

			if(i==ngame->get_dim())
			{
				printLine(ngame->get_dim(),mode);
			}
		}


		/*afksanoume ton metriti gyrwn*/
		rnd++;

	}			
	
}


