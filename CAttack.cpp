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
		const int X_POS = SIZE_X / 2;
		const int Y_POS = (SIZE_Y / 5) * 4;
		x = X_POS;
		y = Y_POS;
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
	void CAttack::SetAttack(bool flag)
	{
		isAttack = flag;
	}
	void CAttack::OnMove()
	{
		const int STEP_SIZE = 5;
		leftBullet.SetTopLeft(x, y);
		if (isAttack)
		{
			bulletDisappear.SetDelayCount(1);
			bulletDisappear.OnMove();
		}
	}

	void CAttack::OnShow()
	{
		leftBullet.SetTopLeft(x + 1, y);
		leftBullet.ShowBitmap(2);
		if (isAttack)
		{
			bulletDisappear.SetTopLeft(x, y);
			bulletDisappear.OnShow();
		}
	}
	void CAttack::BulletDisapear()
	{
		bulletDisappear.SetTopLeft(x, y);
		bulletDisappear.OnShow(2);
	}
	void CAttack::Reset()
	{
		bulletDisappear.Reset();
	}
	void CAttack::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	int CAttack::Width()
	{
		return leftBullet.Width();
	}

}