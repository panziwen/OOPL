#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGamemap.h"

const int b[4][5] = { 1,0,1,0,0,
					  1,1,1,0,0,
					  0,0,1,1,1,
					  0,1,1,1,0 };

namespace game_framework
{
	CGamemap::CGamemap()
	{
		isboss = false;
		doorNum = 0;
		srand((unsigned)time(NULL));
		//fx = rand() % 3;
		//fy = rand() % 4;
		fx = 0;
		fy = 0;
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
				if (i == 1 && j == 0)
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
		ctr.Initialize();
	}
	void CGamemap::LoadBitmap()
	{
		ctr.LoadBitmap();
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
					a[i][j]->SetAimPos(x, y);
				}
			}
		}

		
		ctr.OnMove();
	}
	void CGamemap::OnShow()
	{
		WhichMap();
		a[fx][fy]->SetCPos(ctr.GetX1(), ctr.GetY1(), ctr.GetX2(), ctr.GetY2());
		a[fx][fy]->OnShow();
		ctr.OnShow();
		ctr.SetDead(a[fx][fy]->GetAimPos());
		
	}
	void CGamemap::SetAimPos()
	{
		x = (ctr.GetX2() + ctr.GetX1())/2;
		y = (ctr.GetY2() + ctr.GetY1()-32) / 2;
	}
	void CGamemap::SetBulPos()
	{
		a[fx][fy]->SetBulPos(ctr.GetBulltX(), ctr.GetBulltY());
	}
	bool CGamemap::GetAimPos()
	{
		SetBulPos();
		isdead = a[fx][fy]->GetAimPos();
		return isdead;
	}	
	void CGamemap::SetMovingDown(bool flag)
	{
		ctr.SetMovingDown(flag);
	}

	void CGamemap::SetMovingLeft(bool flag)
	{
		ctr.SetMovingLeft(flag);
	}

	void CGamemap::SetMovingRight(bool flag)
	{
		ctr.SetMovingRight(flag);
	}

	void CGamemap::SetMovingUp(bool flag)
	{
		ctr.SetMovingUp(flag);
	}
	void CGamemap::SetAttack(bool flag, bool flag2)
	{
		if (ctr.GetDead())
		{
			a[fx][fy]->SetDead(!ctr.GetDead());
		}
		ctr.SetAttack(flag, flag2);
	}
	void CGamemap::Reset()
	{
		ctr.Reset();
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
					a[fx+1][fy]->Reset();
					ctr.SetPos(SIZE_PUX, SIZE_PUY);
				}
			}
			else if (a[fx][fy]->Down())
			{
				if (fx >= 0 && fx < 3)
				{
					fx += 1;
					a[fx - 1][fy]->Reset();
					ctr.SetPos(SIZE_PDX, SIZE_PDY);
				}
			}
			else if (a[fx][fy]->Left())
			{
				if (fy > 0 && fy <= 4)
				{
					fy -= 1;
					a[fx][fy + 1]->Reset();
					ctr.SetPos(SIZE_PLX, SIZE_PLY);
				}

			}
			else if (a[fx][fy]->Right())
			{
				if (fy >= 0 && fy < 4)
				{
					fy += 1;
					a[fx][fy - 1]->Reset();
					ctr.SetPos(SIZE_PRX, SIZE_PRY);
				}
			}
		}
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
}