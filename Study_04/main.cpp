#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define Up 72
#define Down 80
#define Left 75
#define Right 77

int map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,4,2},
	{1,1,1,1,1,1,1,1,1,1},
};

char MapTile[10] = { ' ', '-', '|', 'P', 'G', 'M' };

bool bIsRunning = true;

int PlayerX = 0;
int PlayerY = 0;

int MonsterX = 5;
int MonsterY = 5;

int KeyCode = 0;

int OldPlayerX = PlayerX;
int OldPlayerY = PlayerY;
int OldMonsterX = MonsterX;
int OldMonsterY = MonsterY;

void MapInit()
{
	map[PlayerY][PlayerX] = 3;
	map[MonsterY][MonsterX] = 5;
}

void PlayerInit()
{
	PlayerX = 1;
	PlayerY = 1;
	OldPlayerX = 1;
	OldPlayerY = 1;
}

void PlayerMove()
{
	/*int NewPlayerX = 1;
	int NewPlayerY = 1;*/
	
	//int OldMapTile = map[OldPlayerY][OldPlayerX];

	if (KeyCode == Up)
	{
		PlayerY--;
	}
	else if (KeyCode == Down)
	{
		PlayerY++;
	}
	else if (KeyCode == Left)
	{
		PlayerX--;
	}
	else if (KeyCode == Right)
	{
		PlayerX++;
	}

	int NewPlayerX = PlayerX;
	int NewPlayerY = PlayerY;

	if (map[NewPlayerY][NewPlayerX] == 0)
	{
		//이동
		map[OldPlayerY][OldPlayerX] = 0;
		map[PlayerY][PlayerX] = 3;
		OldPlayerX = PlayerX;
		OldPlayerY = PlayerY;
	}
	else if (map[NewPlayerY][NewPlayerX] == 4)
	{
		/*map[OldPlayerY][OldPlayerX] = 0;
		map[PlayerY][PlayerX] = 3;*/
		bIsRunning = false;
	}
	else
	{
		PlayerX = OldPlayerX;
		PlayerY = OldPlayerY;
	}

	if (OldPlayerX != PlayerX || OldPlayerY != PlayerY)
	{
		map[OldPlayerY][OldPlayerX] = 0;
		map[PlayerY][PlayerX] = 3;
	}
}

void MonsterMove()
{
	int RandomMove = rand() % 4;

	if (RandomMove == 0)
	{
		MonsterY--;
	}
	else if (RandomMove == 1)
	{
		MonsterY++;
	}
	else if (RandomMove == 2)
	{
		MonsterX--;
	}
	else if (RandomMove == 3)
	{
		MonsterX++;
	}

	if (OldMonsterX != MonsterX || OldMonsterY != MonsterY)
	{
		map[OldMonsterY][OldMonsterX] = 0;
		map[MonsterY][MonsterX] = 5;
	}

	int NewMonsterY = MonsterY;
	int NewMonsterX = MonsterX;

	if (map[NewMonsterY][NewMonsterX] == 0)
	{
		//이동
		map[OldMonsterY][OldMonsterX] = 0;
		map[MonsterY][MonsterX] = 5;
		OldMonsterX = MonsterX;
		OldMonsterY = MonsterY;
	}
	else if (map[NewMonsterY][NewMonsterX] == 5)
	{
		/*map[OldPlayerY][OldPlayerX] = 0;
		map[PlayerY][PlayerX] = 3;*/
		bIsRunning = false;
	}
	else
	{
		MonsterX = OldMonsterX;
		MonsterY = OldMonsterY;
	}
	if (OldMonsterX != MonsterX || OldMonsterY != MonsterY)
	{
		map[OldMonsterY][OldMonsterX] = 0;
		map[MonsterY][MonsterX] = 5;
	}
}

void Input()
{
	KeyCode = getch();
}

void Process()
{
	if (KeyCode == 'q')
	{
		bIsRunning = false;
	}
	

	PlayerMove();
	MonsterMove();
}

void Terminate()
{

}

void Render()
{
	system("cls");

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			printf("%c ", MapTile[map[y][x]]);
		}
		printf("\n");
	}
}

int main()
{
	srand(time(nullptr));

	PlayerInit();
	MapInit();

	while (bIsRunning)
	{
		Input();
		Process();
		Render();
	}

	Terminate();

	return 0;
}