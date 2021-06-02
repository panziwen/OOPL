#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CNmap.h"

namespace game_framework
{
	CNmap::CNmap()
	{
		//enemyNum = 1 + rand() % 8;
		enemyNum = 2;
		k1 = k2 = enemyNum / 2;
		//item = enemyNum;
		if (enemyNum%2==0)
		{
			for (int i = 0; i < k1; i++)
			{
				enemy.push_back(new CEnemy());
			}
			for (int i = 0; i < k2; i++)
			{
				enemy1.push_back(new CEnemy1());
			}
		}
		else
		{
			for (int i = 0; i < enemyNum; i++)
			{
				enemy2.push_back(new CEnemy2());
			}
		}
		boss = new CBoss();
		door = new CDoor();
		isDoor = isInADoor = isInDDoor = isInNDoor = isInPDoor = isdead = false;
	}
	CNmap::~CNmap()
	{
		if (enemyNum % 2 == 0)
		{
			for (int i = 0; i < k1; i++)
			{
				delete enemy[i];
			}
			for (int i = 0; i < k2; i++)
			{
				delete enemy1[i];
			}
		}
		else
		{
			for (int i = 0; i < enemyNum; i++)
			{
				delete enemy2[i];
			}
		}
		delete door;
	}
	bool CNmap::IsInADoor()
	{
		return isInADoor;
	}
	bool CNmap::IsInDDoor()
	{
		return isInDDoor;
	}
	bool CNmap::IsInNDoor()
	{

		return isInNDoor;
	}
	bool CNmap::IsInPDoor()
	{
		return isInPDoor;
	}

	bool CNmap::Up()
	{
		return door->Up();
	}
	bool CNmap::Down()
	{
		return door->Down();
	}
	bool CNmap::Left()
	{
		return door->Left();
	}
	bool CNmap::Right()
	{
		return door->Right();
	}
	void CNmap::SetDoor(int x, int y)
	{
		door->SetDoor(x, y);
	}
	void CNmap::Initialize(bool flag, bool flag2, bool flag3, bool flag4, bool flag5)
	{
		isboss = flag5;
		x = SIZE_X / 2;
		y = (SIZE_Y / 5) * 4 - 50;
		if (isboss)
		{
			boss->Initialize();
		}
		else
		{
			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < enemyNum / 2; i++)
				{
					enemy[i]->Initialize();
				}
				for (int i = 0; i < enemyNum / 2; i++)
				{
					enemy1[i]->Initialize();
				}
			}
			else
			{
				for (int i = 0; i < enemyNum; i++)
				{
					enemy2[i]->Initialize();
				}
			}
		}
		door->Initialize(flag, flag2, flag3, flag4);
	}
	void CNmap::LoadBitmap()
	{
		map1.LoadBitmap(".\\bitmaps\\map\\nomal\\1.bmp");
		map2.LoadBitmap(".\\bitmaps\\map\\nomal\\2.bmp");
		map3.LoadBitmap(".\\bitmaps\\map\\nomal\\3.bmp");
		map4.LoadBitmap(".\\bitmaps\\map\\nomal\\4.bmp");
		map5.LoadBitmap(".\\bitmaps\\map\\nomal\\6.bmp");
		map6.LoadBitmap(".\\bitmaps\\map\\nomal\\7.bmp");
		map7.LoadBitmap(".\\bitmaps\\map\\nomal\\8.bmp");
		map8.LoadBitmap(".\\bitmaps\\map\\nomal\\9.bmp");
		map9.LoadBitmap(".\\bitmaps\\map\\nomal\\5.bmp");
		if (isboss)
		{
			boss->LoadBitmap();
		}
		else
		{
			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < enemyNum / 2; i++)
				{
					enemy[i]->LoadBitmap();
				}
				for (int i = 0; i < enemyNum / 2; i++)
				{
					enemy1[i]->LoadBitmap();
				}
			}
			else
			{
				for (int i = 0; i < enemyNum; i++)
				{
					enemy2[i]->LoadBitmap();
				}
			}
		}
		door->LoadBitmap();
	}
	
	void CNmap::CreateEn()
	{
		door->OnMove();
		if (isboss)
		{
			boss->SetXY(x, y);
			boss->SetBulXY(bx, by);
			boss->OnMove();
		}
		else
		{
			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < k1; i++)
				{
					enemy[i]->SetXY(x, y);
					enemy[i]->SetBulXY(bx, by);
					enemy[i]->OnMove();
				}
				for (int i = 0; i < k2; i++)
				{
					enemy1[i]->SetXY(x, y);
					enemy1[i]->SetBulXY(bx, by);
					enemy1[i]->OnMove();
				}
			}
			else
			{
				for (int i = 0; i < enemyNum; i++)
				{
					enemy2[i]->SetXY(x, y);
					enemy2[i]->SetBulXY(bx, by);
					enemy2[i]->OnMove();
				}
			}
		}
	}
	void CNmap::OnShow()
	{
		for (int i = 2; i < 4; i++)
		{
			map5.SetTopLeft(100, i*map5.Height());
			map5.ShowBitmap();
		}
		for (int i = 2; i < 4; i++)
		{
			map6.SetTopLeft(SIZE_X - map6.Width() - 100, i*map6.Height());
			map6.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map7.SetTopLeft(i*map7.Width(), 50);
			map7.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map8.SetTopLeft(i*map8.Width(), SIZE_Y - map8.Height() - 50);
			map8.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				map9.SetTopLeft(i * map9.Width(), j * map9.Height());
				map9.ShowBitmap();
			}
		}
		map1.SetTopLeft(100, 50);
		map1.ShowBitmap();
		map2.SetTopLeft(SIZE_X - map1.Width() - 100, 50);
		map2.ShowBitmap();
		map3.SetTopLeft(100, SIZE_Y - map3.Height() - 50);
		map3.ShowBitmap();
		map4.SetTopLeft(SIZE_X - map4.Width() - 100, SIZE_Y - map3.Height() - 50);
		map4.ShowBitmap();

		door->OnShow();
		if (isboss)
		{
			boss->OnShow();
		}
		else
		{
			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < k1; i++)
				{
					enemy[i]->OnShow();
				}
				for (int i = 0; i < k2; i++)
				{
					enemy1[i]->OnShow();
				}
			}
			else
			{
				for (int i = 0; i < enemyNum; i++)
				{
					enemy2[i]->OnShow();
				}
			}
		}

	}
	
	void CNmap::SetCPos(int x, int y, int nx, int ny)
	{
		px = x;
		py = y;
		pnx = nx;
		pny = ny;
	}
	void CNmap::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CNmap::SetBulPos(int nx, int ny)
	{
		if (isboss)
		{
			boss->SetBulXY(nx, ny);
			if (boss->GetAimPos())
			{
				delete boss;
				isdead = true;
			}
		}
		else
		{
			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < k1; i++)
				{
					enemy[i]->SetBulXY(nx, ny);
					if (enemy[i]->GetAimPos())
					{
						KillEnemy(i);
						isdead = true;
					}
				}
				for (int i = 0; i < k2; i++)
				{
					enemy1[i]->SetBulXY(nx, ny);
					if (enemy1[i]->GetAimPos())
					{
						KillEnemy1(i);
						isdead = true;
					}
				}
			}
			else
			{

				for (int i = 0; i < enemyNum; i++)
				{
					enemy2[i]->SetBulXY(nx, ny);
					if (enemy2[i]->GetAimPos())
					{
						KillEnemy2(i);
						isdead = true;
					}
				}
			}
		}
	}
	void CNmap::KillEnemy(int x)
	{
		CEnemy *t;
		if (enemy.size() == 1 && x == 0)
		{
			t = enemy[x];
			enemy.pop_back();
			k1 -= 1;
		}
		else
		{
			if (x == enemy.size() - 1)
			{
				t = enemy[x];
				enemy.pop_back();
				k1 -= 1;
			}
			else
			{
				t = enemy[x];
				enemy.erase(enemy.begin() + x);
				k1 -= 1;
			}
		}
		delete t;

	}
	void CNmap::KillEnemy1(int x)
	{
		CEnemy1 *t;
		if (enemy1.size() == 1 && x == 0)
		{
			t = enemy1[x];
			enemy1.pop_back();
			k2 -= 1;
		}
		else
		{
			if (x == enemy1.size() - 1)
			{
				t = enemy1[x];
				enemy1.pop_back();
				k2 -= 1;
			}
			else
			{
				t = enemy1[x];
				enemy1.erase(enemy1.begin() + x);
				k2 -= 1;
			}
		}
		delete t;

	}
	void CNmap::KillEnemy2(int x)
	{
		CEnemy2 *t;
		if (enemy2.size() == 1 && x == 0)
		{
			t = enemy2[x];
			enemy2.pop_back();
			enemyNum -= 1;
		}
		else
		{
			if (x == enemy2.size() - 1)
			{
				t = enemy2[x];
				enemy2.pop_back();
				enemyNum -= 1;
			}
			else
			{
				t = enemy2[x];
				enemy2.erase(enemy2.begin() + x);
				enemyNum -= 1;
			}
		}
		delete t;

	}
	void CNmap::SetDead(bool flag)
	{
		isdead = flag;
	}
	void CNmap::Reset()
	{
		isDoor = false;
	}
	bool CNmap::GetAimPos()
	{
		return isdead;
	}
	bool CNmap::IsInDoor()
	{
		if (((px >= door->GetX1() && px <= door->GetX2()) && (py > door->GetY1() && py <= door->GetY2())) || ((pnx >= door->GetX1() && pnx <= door->GetX2()) && (pny > door->GetY1() && pny <= door->GetY2())))
		{
			isDoor = true;
		}
		return isDoor;
	}
}