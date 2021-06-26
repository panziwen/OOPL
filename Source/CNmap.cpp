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
		enemyNum = 4;
		if (enemyNum % 2 == 0)
		{
			k1 = k2 = enemyNum / 2;
		}
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
		boss.push_back(new CBoss());
		door = new CDoor();
		isDoor = isInADoor = isInDDoor = isInNDoor = isInPDoor = isdead = isbdead = false;
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
		if (boss.size()!=0)
		{
			delete boss[0];
		}
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
			boss[0]->Initialize();
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
		char *filename[4] = { ".\\bitmaps\\e\\boss1\\i0.bmp",".\\bitmaps\\e\\boss1\\i1.bmp",
							  ".\\bitmaps\\e\\boss1\\i2.bmp" ,".\\bitmaps\\e\\boss1\\i3.bmp" };
		for (int i = 0; i < 4; i++)
		{
			bossInterface.AddBitmap(filename[i], RGB(109, 33, 115));
		}
		boss[0]->LoadBitmap();
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
		door->LoadBitmap();
	}
	
	void CNmap::CreateEn()
	{
		bossInterface.OnMove();
		door->OnMove();
		if (isboss && boss.size() != 0)
		{
			boss[0]->SetXY(x, y);
			boss[0]->SetBulXY(bx, by);
			boss[0]->OnMove();
		}
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
	void CNmap::BossIntetface()
	{
		bossInterface.OnShow(2);
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
		if (isboss && boss.size() != 0)
		{
			boss[0]->OnShow();
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
		if (isboss && boss.size() != 0)
		{
			boss[0]->SetBulXY(nx, ny);
			if (boss[0]->GetAimPos())
			{
				KillBoss(0);
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
	void CNmap::KillBoss(int x)
	{
		CBoss *t;
		if (boss.size() == 1 && x == 0)
		{
			t = boss[x];
			boss.pop_back();
		}
		delete t;
		isbdead = true;
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
		isDoor = isInADoor = isInDDoor = isInNDoor = isInPDoor = isdead = isbdead = false;
	}
	bool CNmap::GetAimPos()
	{
		return isdead;
	}
	bool CNmap::IsInDoor()
	{
		if (((px >= door->GetUX1() && px <= door->GetUX2()) && (py > door->GetUY1() && py <= door->GetUY2())) || ((pnx >= door->GetUX1() && pnx <= door->GetUX2()) && (pny > door->GetUY1() && pny <= door->GetUY2())))
		{
			isDoor = true;
		}
		else if (((px >= door->GetDX1() && px <= door->GetDX2()) && (py > door->GetDY1() && py <= door->GetDY2())) || ((pnx >= door->GetDX1() && pnx <= door->GetDX2()) && (pny > door->GetDY1() && pny <= door->GetDY2())))
		{
			isDoor = true;
		}
		else if (((px >= door->GetRX1() && px <= door->GetRX2()) && (py > door->GetRY1() && py <= door->GetRY2())) || ((pnx >= door->GetRX1() && pnx <= door->GetRX2()) && (pny > door->GetRY1() && pny <= door->GetRY2())))
		{
			isDoor = true;
		}
		else if (((px >= door->GetLX1() && px <= door->GetLX2()) && (py > door->GetLY1() && py <= door->GetLY2())) || ((pnx >= door->GetRX1() && pnx <= door->GetLX2()) && (pny > door->GetLY1() && pny <= door->GetLY2())))
		{
			isDoor = true;
		}
		return isDoor;
	}
	bool CNmap::GetCtrPos()
	{
		if (isboss && boss.size() != 0)
		{
			if (boss[0]->GetCtrPos())
			{
				return true;
			}
		}
		else
		{

			if (enemyNum % 2 == 0)
			{
				for (int i = 0; i < k1; i++)
				{
					if (enemy[i]->GetCtrPos())
					{
						return true;
					}
				}
				for (int i = 0; i < k2; i++)
				{
					if (enemy1[i]->GetCtrPos())
					{
						return true;
					}
				}
			}
			else
			{
				for (int i = 0; i < enemyNum; i++)
				{
					if (enemy2[i]->GetCtrPos())
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool CNmap::IsBDead()
	{
		return isbdead;
	}
	bool CNmap::IsBoss()
	{
		return isboss;
	}
}