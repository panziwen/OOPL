#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CAttack.h"

namespace game_framework
{
	CAttack::CAttack()
	{
		Initialize();
	}
	void CAttack::Initialize()
	{
		isAttack = false;
	}
	
	void CAttack::LoadBitmap()
	{
		char *filename0 = ".\\bitmaps\\attack\\attack1.bmp";

		char *filename1[15] = { ".\\bitmaps\\attack\\attack1.bmp",".\\bitmaps\\attack\\attack2.bmp", ".\\bitmaps\\attack\\attack3.bmp", 
								".\\bitmaps\\attack\\attack4.bmp",".\\bitmaps\\attack\\attack5.bmp",".\\bitmaps\\attack\\attack6.bmp",
								".\\bitmaps\\attack\\attack7.bmp",".\\bitmaps\\attack\\attack8.bmp",".\\bitmaps\\attack\\attack9.bmp",
								".\\bitmaps\\attack\\attack10.bmp",".\\bitmaps\\attack\\attack11.bmp", ".\\bitmaps\\attack\\attack12.bmp",
								".\\bitmaps\\attack\\attack13.bmp",".\\bitmaps\\attack\\attack14.bmp",".\\bitmaps\\attack\\attack15.bmp"};

		leftBullet.LoadBitmap(filename0, RGB(109, 33, 115));
		rightBullet.LoadBitmap(filename0, RGB(109, 33, 115));

		for (int i = 0; i < 15; i++)
		{
			bulletDisappear.AddBitmap(filename1[i], RGB(109, 33, 115));
		}

	}
	void CAttack::OnMove()
	{
		const int STEP_SIZE = 5;
		bulletDisappear.SetDelayCount(2);
		bulletDisappear.OnMove();
	}

	void CAttack::OnShow()
	{
		if (x != pos)
		{
			x += 1;
			leftBullet.SetTopLeft(x, y);
			leftBullet.ShowBitmap(2);
		}
		else
		{
			BulletDisapear();
		}
	}
	void CAttack::BulletDisapear()
	{
		bulletDisappear.SetTopLeft(x, y);
		bulletDisappear.OnShow(2);
		isAttack = false;
	}
	void CAttack::Reset()
	{
		bulletDisappear.Reset();
	}
	void CAttack::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
		pos = x + 150;
	}
	int CAttack::Width()
	{
		return leftBullet.Width();
	}
	bool CAttack::GetAttack()
	{
		return isAttack;
	}

}