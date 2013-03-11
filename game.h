#ifndef GAME_H
#define GAME_H

class Game
{
private:
	
	int m_dim, m_armies, m_soldiers[4];
	int m_posMaxX, m_posMaxY;
	int m_castle_positions[4][2];

public:

	/* dhlosh tou constructor o opoios pairnei san orisma ena string */
	Game(string path)
	{
		start(path);
	}	
	
	/* dhlosh ton methodon pou xrhsimopoiei h klash */
	void start(string path);

	void printGameSettings(void);
	
	void set_dim(int d);

	void set_armies(int a);

	void set_soldiers(int *array, int arrlen);

	void set_posmax(int x, int y);

	int get_dim(void);

	int get_armies(void);

	int get_soldiers(int army_id);

	void set_castle_positions(int num_of_armies, int map_size);

	int getCastleX(int castle_id){return m_castle_positions[castle_id-1][0];}

	int getCastleY(int castle_id){return m_castle_positions[castle_id-1][1];}

	friend class Army;

};

#endif
