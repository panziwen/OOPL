#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CAttack.h"
#include <iostream> 

namespace game_framework
{
	CAttack::CAttack()
	{
		attTimes = 0;
		max_bulletNmu = 2;
		for (int i = 0; i < max_bulletNmu; i++)
		{
			bullet.push_back(new CMovingBitmap());
		}
		Initialize();
	}
	CAttack::~CAttack()
	{
		for (int i = 0; i < max_bulletNmu; i++)
		{
			delete bullet[i];
		}
	}
	int CAttack::GetX()
	{
		return x;
	}
	int CAttack::GetY()
	{
		return y;
	}
	void CAttack::Initialize()
	{
		faceD = true;
		faceL = faceR = faceU = isAttack = false;
	}

	void CAttack::SetAttack(bool flag)
	{
		isAttack = flag;
	}
	void CAttack::SetFL(bool flag)
	{
		faceL = flag;
	}
	void CAttack::SetFR(bool flag)
	{
		faceR = flag;
	}
	void CAttack::SetFD(bool flag)
	{
		faceD = flag;
	}
	void CAttack::SetFU(bool flag)
	{
		faceU = flag;
	}
	
	void CAttack::LoadBitmap()
	{
		char *filename0 = ".\\bitmaps\\attack\\attack1.bmp";

		char *filename1[15] = { ".\\bitmaps\\attack\\attack1.bmp",".\\bitmaps\\attack\\attack2.bmp", ".\\bitmaps\\attack\\attack3.bmp", 
								".\\bitmaps\\attack\\attack4.bmp",".\\bitmaps\\attack\\attack5.bmp",".\\bitmaps\\attack\\attack6.bmp",
								".\\bitmaps\\attack\\attack7.bmp",".\\bitmaps\\attack\\attack8.bmp",".\\bitmaps\\attack\\attack9.bmp",
								".\\bitmaps\\attack\\attack10.bmp",".\\bitmaps\\attack\\attack11.bmp", ".\\bitmaps\\attack\\attack12.bmp",
								".\\bitmaps\\attack\\attack13.bmp",".\\bitmaps\\attack\\attack14.bmp",".\\bitmaps\\attack\\attack15.bmp"};

		bullet[0]->LoadBitmap(filename0, RGB(109, 33, 115));
		bullet[1]->LoadBitmap(filename0, RGB(109, 33, 115));

		for (int i = 0; i < 15; i++)
		{
			bulletDisappear.AddBitmap(filename1[i], RGB(109, 33, 115));
		}

	}
	void CAttack::OnMove()
	{
		const int STEP_SIZE = 5;
		bulletDisappear.SetDelayCount(1);
		bulletDisappear.OnMove();
	}

	void CAttack::OnShow()
	{
		if (faceR)
		{
			if (x <= posr)
			{
				for (int i = 0; i < 8; i++)
				{
					x += 1;
				}
				bullet[attTimes]->SetTopLeft(x, y);
				bullet[attTimes]->ShowBitmap();

			}
			else
			{
				bulletDisappear.SetTopLeft(x, y);
				bulletDisappear.SetDelayCount(1);
				bulletDisappear.OnShow();
				if (bulletDisappear.IsFinalBitmap())
				{
					bulletDisappear.Reset();
					faceD = faceL = faceR = faceU = isAttack = false;
				}
			}
		}
		if (faceL)
		{
			if (x >= posl)
			{
				for (int i = 0; i < 8; i++)
				{
					x -= 1;
				}

				bullet[attTimes]->SetTopLeft(x, y);
				bullet[attTimes]->ShowBitmap();
			}
			else
			{
				bulletDisappear.SetTopLeft(x, y);
				bulletDisappear.SetDelayCount(1);
				bulletDisappear.OnShow();
				if (bulletDisappear.IsFinalBitmap())
				{
					bulletDisappear.Reset();
					faceD = faceL = faceR = faceU = isAttack = false;
				}
			}
		}
		if (faceU)
		{
			if (y >= posu)
			{
				for (int i = 0; i < 8; i++)
				{
					y -= 1;
				}

				bullet[attTimes]->SetTopLeft(x, y);
				bullet[attTimes]->ShowBitmap();
			}
			else
			{
				bulletDisappear.SetTopLeft(x, y);
				bulletDisappear.SetDelayCount(1);
				bulletDisappear.OnShow();
				if (bulletDisappear.IsFinalBitmap())
				{
					bulletDisappear.Reset();
					faceD = faceL = faceR = faceU = isAttack = false;
				}
			}
		}
		if (faceD)
		{
			if (y <= posd)
			{
				for (int i = 0; i < 8; i++)
				{
					y += 1;
				}

				bullet[attTimes]->SetTopLeft(x, y);
				bullet[attTimes]->ShowBitmap();
			}
			else
			{
				bulletDisappear.SetTopLeft(x, y);
				bulletDisappear.SetDelayCount(1);
				bulletDisappear.OnShow();
				if (bulletDisappear.IsFinalBitmap())
				{
					bulletDisappear.Reset();
					faceD = faceL = faceR = faceU = isAttack = false;
				}
			}
		}
	}
	void CAttack::SetXY(int nx, int ny)
	{
		posr = x + 150;
		posl = x - 150;
		posu = y - 150;
		posd = y + 150;
		x = nx-32;
		y = ny-32;
	}
	int CAttack::Width()
	{
		return bullet[0]->Width();
	}
	bool CAttack::GetAttack()
	{
		return isAttack;
	}

}