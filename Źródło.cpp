#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>

//using namespace std;
//using namespace std::this_thread; // sleep_for, sleep_until
//using namespace std::chrono; // nanoseconds, system_clock, seconds

char map[10][10] = {
	"#  o    #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#   @   #", };

class Object
{
protected:
	int positionX, positionY;
	int health = 1;
	int points;
	std::string name;	//???
	char sign;

public:
	void reduceHealth()
	{
		health--;
	}
	int getHealth()
	{
		return health;
	}
	int getPoints()
	{
		return points;
	}
	char getSign()
	{
		return sign;
	}
};

class Movable : public Object
{
public:
	void move(int vertical, int horizontal)
	{
		map[positionY][positionX] = ' ';
		positionY += vertical;
		positionX += horizontal;
		map[positionY][positionX] = sign;
	}
};

class Static : public Object
{
public:
	void down()
	{
		map[positionY][positionX] = ' ';
		positionY += 1;
		map[positionY][positionX] = sign;
	}
};

class Helicopter : public Movable
{
	char side;
public:
	Helicopter(int posX, int posY, char sid)	//rand side eg 0-left 1-right
	{
		positionX = posX;
		positionY = posY;
		side = sid;
		points = 60;
		sign = 'H';
	};
	~Helicopter() {};
};

class Airplane : public Movable
{
	char side;
public:
	Airplane(int posX, int posY, char sid)
	{
		positionX = posX;
		positionY = posY;
		side = sid;
		points = 100;
		sign = 'A';
	};
	~Airplane() {};
};

class Bullet : public Movable
{
public:

};

class Player : public Movable
{
	std::string playerName;
public:
	Player(std::string name)
	{
		playerName = name;
	}
};

class Tank : public Static
{
	char side;
public:

};

class Fuel : public Static
{
public:

};

class Bridge : public Static
{
public:


};



bool gamerunning = true;

int main()
{
	int playerX = 4;

	while (gamerunning)
	{
		system("cls");

		for (int i = 0; i < 10; i++)
		{
			std::cout << map[i] << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::nanoseconds(400000000));
		
		if (GetAsyncKeyState(VK_RIGHT))
		{
			playerX++;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			playerX--;
		}

		for (int i = 9; i > 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				map[i][j] = map[i - 1][j];
			}
		}
		
		//map[0][0] = '#';
		map[0][3] = ' ';
		//map[10][10] = '#';
		map[9][playerX] = '@';

	}
	return 0;
}