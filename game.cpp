#include "globals.h"
#include "functions.h"
#include "game.h"

/* ulopoioume thn methodo start() ths klashs Game h opoia pairnei san parametro ena string me thn dieuthunsh arxeiou .txt 
kai diavazei ta periexomena tou.
Diavazontas to init.txt arxeio apothikeuoume sthn s metavliti to megethos pou dhlonei to disdiastato kosmo (NxN), 
sthn metavliti s ton arithmo ton antipalon stratopedon kai telos ston pinaka solds[] apothikeuoume stis theseis tou ton 
arxiko arithmo stratioton se kathe straopedo antistoixa gia kathe mia apo tis 4 theseis tou */
void Game::start(string path)
{
	string str;
	int i=0,j=0,n, s, solds[4];
	
	ifstream file ( "init.txt" );
	if (file == 0) 
	{
		cout << "Error: Input file cannot be opened for reading!" << endl;
		exit(1);
	}

	while(file.eof()==false)
	{
		
		file>> str;
		
		if(file.eof()==false)
		{	
			/* an to i einai iso me 0 shmainei oti eimaste sthn proth grammh tou init.txt arxeiou, kaloume 
			thn sunarthsh strtoint() pou dexetai ena string kai to metatrepei se akeraio me orisma to 
			string pou diavazoume se authn th grammh kai apothikeuoume sthn metavlith s thn proth parametro tou 
			programmatos mas pou einai to megethos tou disdiastatou kosmou */
			if(i==0)s=strtoint(str);
			
			/* an to i einai iso me 1 shmainei oti eimaste sth deuterh grammh tou init.txt arxeiou, kaloume 
			thn sunarthsh strtoint() pou dexetai ena string kai to metatrepei se akeraio me orisma to string 
			pou diavazoume se auth th grammh kai apothikeuoume sthn metavlith n th deuterh parametro tou programmatos 
			mas pou einai to megethos tou disdiastatou kosmou */
			else if(i==1)
			{
				n=strtoint(str);
				if(n<2 || n>4)
				{
					cout << "Number of Armies MUST be between 2 and 4!\n";
					break;
				}

			}

			/* se auth thn periptosh gia oses times exei h trith seira tou init.txt arxeiou kaloume th 
			sunarthsh strtoint() diavazoume kathe timh thn metatrepoume apo string se akeraio kai to apothikeoume ston pinaka solds[]  */
			else if(i>1 && i<n+2)
			{
				solds[j]=strtoint(str);
				j++;
			}			
			else cout << "Something is wrong with your init file!\n";
			i++;

		}
	}
	file.close();

	/* an o arithmos ton stratopedon pou diavasame apo th grammh 2 tou init.txt arxeiou sumfonei me to 
	plhthos ton timon pou diavasame apo thn trith seira tou arxeiou tote: */	
	if(j==n)
	{
		//cout << "Everything is OK!\n";
		set_dim(s);
		set_armies(n);
		set_soldiers(solds,n);
		set_posmax(s,s);
		set_castle_positions(n,s);
		
	}
	else
	{
		cout<<"Something is wrong with your init file!!\n";
		exit(1);
	}
}

/* ulopoioume thn methodo printGameSettings() h opoia ektuponei tis arxikes sunthikes tou provlimatos mas dhladh 
thn diastash tou kosmou, ton arithmo ton straton kai ton arithmo ton stratioton kathe stratopedou */
void Game::printGameSettings(void)
{
	cout << "Everything is OK!\n";
	cout << "World Dimensions: "<<m_dim<<"X"<<m_dim<<endl;
	cout << "Number of Armies: "<<m_armies<<endl;
	for(int k=1;k<m_armies+1;k++)
	{
		cout <<"Number of Soldiers of "<<k<<"st Army: "<<m_soldiers[k-1]<<endl;
	}
}

/* ulopoioume thn methodo set_dim() h opoia pernei san orisma thn diastash tou kosmou kai thn antistoixizei sth metavlith m_dim */
void Game::set_dim(int d)
{
	m_dim=d;
}


void Game::set_armies(int a)
{
	m_armies=a;
}

void Game::set_soldiers(int *array, int arrlen)
{
	for(int i=0;i<arrlen;i++)
	{
		m_soldiers[i]=array[i];
	}
}

/* ulopoioume th methodo set_posmax() h poia pairnei san orismata duo akeraious kai tous antistoixei stis 
metavlites m_posMaxX kai M-posMaxY, oi opoies dhlonoun th megisth thesi ston aksona x kai y antistoixa */
void Game::set_posmax(int x, int y)
{
	m_posMaxX=x;
	m_posMaxY=y;
}

int Game::get_dim(void)
{
	return m_dim;
}

/* ulopoioume th methodo get_armies() h opoia mas epistrefei to plhthos ton stratopedon*/
int Game::get_armies(void)
{
	return m_armies;
}

int Game::get_soldiers(int army_id)
{
	return m_soldiers[army_id-1];
}

/*dinei tyxaies times stis syntetagmenes twn kastrwn. tha xrisimopoihthei apo tin soldier klasi*/
void Game::set_castle_positions(int num_of_armies, int map_size)
{
	int same_cas_flag=0;
	for(int i=0; i<num_of_armies ; i++)
	{
		for(int j=0; j<2 ; j++)
		{
			m_castle_positions[i][j]= randomness(map_size);
		}
	
		/*ginetai elegxos an exoun dothei kai se allo kastro oi idies sintetagmenes*/
		if(i>0)
		{
			for (int k=i;k>0;k--)
			{
				if(m_castle_positions[i][0]==m_castle_positions[k-1][0]&&m_castle_positions[i][1]==m_castle_positions[k-1][1])
					same_cas_flag=1;
			}
		}
		if(same_cas_flag==1){i--; same_cas_flag=0;}	
	}
}


