#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGamemap.h"
namespace game_framework
{
	CGamemap::CGamemap()
	{
		srand((unsigned)time(NULL));
		fx = rand() % 3;
		fy = rand() % 4;
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
				a[i][j]->Initialize();
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
				if (i%2==0&&j%2==0)
				{
					a[i][j]->LoadBitmap();
				}
				else 
				{
					a[i][j]->LoadBitmap2();
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
				a[i][j]->CreateEn();
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				a[i][j]->SetAimPos(x, y);
			}
		}

		
		ctr.OnMove();
	}
	void CGamemap::OnShow()
	{
		WhichMap();
		a[fx][fy]->SetCPos(ctr.GetX1(), ctr.GetY1(), ctr.GetX2(), ctr.GetY2());
		if (fx%2==0&&fy%2==0)
		{
			a[fx][fy]->OnShow();
		}
		else
		{
			a[fx][fy]->OnShow2();
		}
		ctr.OnShow();
		
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
					ctr.SetPos(SIZE_PUX, SIZE_PUY);
				}
			}
			if (a[fx][fy]->Down())
			{
				if (fx >= 0 && fx < 3)
				{
					fx += 1;
					ctr.SetPos(SIZE_PDX, SIZE_PDY);
				}
			}
			if (a[fx][fy]->Left())
			{
				if (fy > 0 && fy <= 4)
				{
					fy -= 1;
					ctr.SetPos(SIZE_PLX, SIZE_PLY);
				}

			}
			if (a[fx][fy]->Right())
			{
				if (fy >= 0 && fy < 4)
				{
					fy += 1;
					ctr.SetPos(SIZE_PRX, SIZE_PRY);
				}
			}
		}
		a[fx][fy]->SetDoor(fx, fy);
	}
}