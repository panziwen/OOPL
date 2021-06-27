#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGamemap.h"

int b[4][5];
const int b1[4][5] = { 1,1,0,0,0,
					   0,1,1,0,0,
					   1,1,1,1,1,
					   0,1,1,1,0 };
const int b2[4][5] = { 1,0,1,0,0,
					   1,1,1,0,0,
					   0,0,1,1,1,
					   0,1,1,1,0 };
const int b3[4][5] = { 1,1,1,0,0,
					   0,0,1,0,0,
					   1,0,1,1,1,
					   1,1,1,1,0 };

namespace game_framework
{
	CGamemap::CGamemap()
	{
		ctr = new CCharaterCtrol();
		isboss = ispdead = isKey =false;
		doorNum = 0;
		srand((unsigned)time(NULL));
		mapnub = rand() % 3;
		//mapnub = 0;
		fx = 0;
		fy = 0;
		if (mapnub == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					b[i][j] = b1[i][j];
				}
			}
		}
		if (mapnub == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					b[i][j] = b2[i][j];
				}
			}
		}
		if (mapnub == 2)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					b[i][j] = b3[i][j];
				}
			}
		}
	}
	CGamemap::~CGamemap()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				delete a[i][j];
			}
		}
		delete ctr;
	}
	void CGamemap::Initialize()
	{
		vector<CNmap*> tmp1;
		vector<CNmap*> tmp2;
		vector<CNmap*> tmp3;
		vector<CNmap*> tmp4;
		for (int j = 0; j < 5; j++)
		{
			tmp1.push_back(new CNmap());
			tmp2.push_back(new CNmap());
			tmp3.push_back(new CNmap());
			tmp4.push_back(new CNmap());
		}
		a.push_back(tmp1);
		a.push_back(tmp2);
		a.push_back(tmp3);
		a.push_back(tmp4);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == 1 && j == 2)
				{
					isboss = true;
				}
				else
				{
					isboss = false;
				}
				if (b[i][j]==1)
				{
					SetDoor(i, j);
					a[i][j]->Initialize(u, d, l, r, isboss);
				}
				else
				{
					a[i][j] = NULL;
				}
			}
		}
		isInNMap = isInDMap = isInAMap = isInPMap = isDoor = false;
		ctr->Initialize();
	}
	void CGamemap::LoadBitmap()
	{
		ui1[0].LoadBitmap(".\\bitmaps\\map\\ui\\1.bmp", RGB(109, 33, 115));
		ui1[1].LoadBitmap(".\\bitmaps\\map\\ui\\1.bmp", RGB(109, 33, 115));
		ui1[2].LoadBitmap(".\\bitmaps\\map\\ui\\1.bmp", RGB(109, 33, 115));
		ui1[3].LoadBitmap(".\\bitmaps\\map\\ui\\5.bmp", RGB(109, 33, 115));
		ui1[4].LoadBitmap(".\\bitmaps\\map\\ui\\6.bmp", RGB(109, 33, 115));
		ui1[5].LoadBitmap(".\\bitmaps\\map\\ui\\7.bmp", RGB(109, 33, 115));
		ui1[6].LoadBitmap(".\\bitmaps\\map\\ui\\2.bmp", RGB(109, 33, 115));
		ui1[7].LoadBitmap(".\\bitmaps\\map\\ui\\3.bmp", RGB(109, 33, 115));
		ui1[8].LoadBitmap(".\\bitmaps\\map\\ui\\4.bmp", RGB(109, 33, 115));
		ui1[9].LoadBitmap(".\\bitmaps\\map\\ui\\8.bmp", RGB(109, 33, 115));
		ui1[10].LoadBitmap(".\\bitmaps\\map\\ui\\9.bmp", RGB(109, 33, 115));
		ui1[11].LoadBitmap(".\\bitmaps\\map\\ui\\10.bmp", RGB(109, 33, 115));
		ui1[12].LoadBitmap(".\\bitmaps\\map\\ui\\11.bmp", RGB(109, 33, 115));
		ui1[13].LoadBitmap(".\\bitmaps\\map\\ui\\12.bmp", RGB(109, 33, 115));
		map.LoadBitmap(".\\bitmaps\\map\\nomal\\10.bmp", RGB(109, 33, 115));
		ctr->LoadBitmap();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (b[i][j]==1)
				{
					a[i][j]->LoadBitmap();
				}
			}
		}
	}
	void CGamemap::OnMove()
	{
		SetAimPos();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (b[i][j]==1)
				{
					a[i][j]->IsPdead(ispdead);
					a[i][j]->CreateEn();
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (b[i][j] == 1)
				{
					a[i][j]->IsPdead(ispdead);
					a[i][j]->SetAimPos(x, y);
				}
			}
		}

		ctr->OnMove();
	}
	void CGamemap::OnShow()
	{
		WhichMap();
		a[fx][fy]->SetCPos(ctr->GetX1(), ctr->GetY1(), ctr->GetX2(), ctr->GetY2());
		a[fx][fy]->OnShow();
		UI();
		ctr->OnShow();
		ctr->SetDead(a[fx][fy]->GetAimPos());
		if (isKey&&!a[fx][fy]->IsBoss())
		{
			fx = 1;
			fy = 2;
			a[fx][fy]->BossIntetface();
		}
		if (a[fx][fy]->GetCtrPos())
		{
			fx = 0;
			fy = 0;
			a[fx][fy]->Reset();
			a[fx][fy]->SetCPos(ctr->GetX1(), ctr->GetY1(), ctr->GetX2(), ctr->GetY2());
			ctr->Reset();
			SetDoor(fx, fy);
			ctr->ReSetPos();
			ispdead = true;
		}

		a[fx][fy]->Reset();
	}
	void CGamemap::SetAimPos()
	{
		x = (ctr->GetX2() + ctr->GetX1())/2;
		y = (ctr->GetY2() + ctr->GetY1()-32) / 2;
	}
	void CGamemap::SetBulPos()
	{
		a[fx][fy]->SetBulPos(ctr->GetBulltX(), ctr->GetBulltY());
	}
	bool CGamemap::GetAimPos()
	{
		SetBulPos();
		isdead = a[fx][fy]->GetAimPos();
		return isdead;
	}	
	void CGamemap::SetMovingDown(bool flag)
	{
		ctr->SetMovingDown(flag);
	}

	void CGamemap::SetMovingLeft(bool flag)
	{
		ctr->SetMovingLeft(flag);
	}

	void CGamemap::SetMovingRight(bool flag)
	{
		ctr->SetMovingRight(flag);
	}

	void CGamemap::SetMovingUp(bool flag)
	{
		ctr->SetMovingUp(flag);
	}
	void CGamemap::Key(bool flag)
	{
		isKey = flag;
	}
	void CGamemap::SetAttack(bool flag, bool flag2)
	{
		if (ctr->GetDead())
		{
			a[fx][fy]->SetDead(!ctr->GetDead());
		}
		ctr->SetAttack(flag, flag2);
	}
	void CGamemap::Reset()
	{
		ctr->Reset();
	}

	void CGamemap::WhichMap()
	{
		if (a[fx][fy]->IsInDoor())
		{
			if (a[fx][fy]->Up())
			{
				if (fx > 0 && fx <= 3)
				{
					fx -= 1;
					if (fx == 1 && fy == 2)
					{
						a[fx][fy]->BossIntetface();
					}
					a[fx+1][fy]->Reset();
					ctr->SetPos(SIZE_PUX, SIZE_PUY);
				}
			}
			else if (a[fx][fy]->Down())
			{
				if (fx >= 0 && fx < 3)
				{
					fx += 1;
					if (fx == 1 && fy == 2)
					{
						a[fx][fy]->BossIntetface();
					}
					a[fx - 1][fy]->Reset();
					ctr->SetPos(SIZE_PDX, SIZE_PDY);
				}
			}
			else if (a[fx][fy]->Left())
			{
				if (fy > 0 && fy <= 4)
				{
					fy -= 1;
					if (fx == 1 && fy == 2)
					{
						a[fx][fy]->BossIntetface();
					}
					a[fx][fy + 1]->Reset();
					ctr->SetPos(SIZE_PLX, SIZE_PLY);
				}

			}
			else if (a[fx][fy]->Right())
			{
				if (fy >= 0 && fy < 4)
				{
					fy += 1;
					if (fx == 1 && fy == 2)
					{
						a[fx][fy]->BossIntetface();
					}
					a[fx][fy - 1]->Reset();
					ctr->SetPos(SIZE_PRX, SIZE_PRY);
				}
			}
		}
		a[fx][fy]->Reset();
		a[fx][fy]->SetDoor(fx, fy);
	}
	void CGamemap::SetDoor(int i, int j)
	{
		d = r = l = u = false;
		if (i != 3)
		{
			if (b[i + 1][j] == 1)
			{
				d = true;
			}
		}
		if (j != 4)
		{
			if (b[i][j + 1] == 1)
			{
				r = true;
			}
		}
		if (i != 0)
		{
			if (b[i - 1][j] == 1)
			{
				u = true;
			}
		}
		if (j != 0)
		{
			if (b[i][j - 1] == 1)
			{
				l = true;
			}
		}
	}
	bool CGamemap::IsPDead()
	{
		return ispdead;
	}
	void CGamemap::SetPAlive(bool flag)
	{
		ispdead = flag;
	}
	void CGamemap::Delete()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				delete a[i][j];
			}
		}
		delete ctr;
	}
	bool CGamemap::MapE()
	{
		if (a.size()==0)
		{
			return true;
		}
		return false;
	}
	bool CGamemap::IsBDead()
	{
		return a[fx][fy]->IsBDead();
	}
	void CGamemap::UI()
	{
		ui1[0].SetTopLeft(100, 80);
		ui1[0].ShowBitmap(2);
		ui1[1].SetTopLeft(130, 80);
		ui1[1].ShowBitmap(2);
		ui1[2].SetTopLeft(160, 80);
		ui1[2].ShowBitmap(2);

		ui1[3].SetTopLeft(20, 90);
		ui1[3].ShowBitmap();
		ui1[4].SetTopLeft(20, 120);
		ui1[4].ShowBitmap();
		ui1[5].SetTopLeft(20, 160);
		ui1[5].ShowBitmap();
		ui1[6].SetTopLeft(20, 190);
		ui1[6].ShowBitmap(2);
		ui1[7].SetTopLeft(20, 220);
		ui1[7].ShowBitmap(2);
		ui1[8].SetTopLeft(20, 250);
		ui1[8].ShowBitmap(2);
		ui1[9].SetTopLeft(20, 280);
		ui1[9].ShowBitmap(2);
		ui1[10].SetTopLeft(20, 310);
		ui1[10].ShowBitmap(2);
		ui1[11].SetTopLeft(20, 340);
		ui1[11].ShowBitmap(2);
		ui1[12].SetTopLeft(20, 370);
		ui1[12].ShowBitmap(2);
		ui1[13].SetTopLeft(20, 400);
		ui1[13].ShowBitmap(2);
	}
}