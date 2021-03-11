#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CIsaac.h"
namespace game_framework
{
	CIsaac::CIsaac()
	{

	}
	int CIsaac::GetX1()
	{
		return x;
	}
	int CIsaac::GetY1()
	{
		return y;
	}
	int CIsaac::GetX2()
	{
		return x + animation.Width();
	}
	int CIsaac::GetY2()
	{
		return y + animation.Height();
	}
	void CIsaac::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}
	void CIsaac::LoadBitmap()
	{
		char *filename[9] = { ".\\bitmaps\\isaac3.bmp", ".\\bitmaps\\isaac4.bmp",".\\bitmaps\\isaac5.bmp",
								".\\bitmaps\\isaac6.bmp",".\\bitmaps\\isaac7.bmp", ".\\bitmaps\\isaac8.bmp",
								".\\bitmaps\\isaac9.bmp",".\\bitmaps\\isaac1.bmp",".\\bitmaps\\isaac2.bmp" };

		for (int i = 0; i < 9; i++)
		{
			animation.AddBitmap(filename[i], RGB(255, 255, 255));
		}

		/*char *filename2[10] = { ".\\bitmaps\\isaac10.bmp", ".\\bitmaps\\isaac11.bmp",".\\bitmaps\\isaac12.bmp",
								".\\bitmaps\\isaac13.bmp",".\\bitmaps\\isaac14.bmp", ".\\bitmaps\\isaac15.bmp",
								".\\bitmaps\\isaac16.bmp",".\\bitmaps\\isaac17.bmp",".\\bitmaps\\isaac18.bmp",".\\bitmaps\\isaac19.bmp" };

		for (int i = 0; i < 10; i++)
		{
			animation2.AddBitmap(filename2[i], RGB(255, 255, 255));
		}*/
	}
	void CIsaac::OnMove()
	{
		const int STEP_SIZE = 5;
		animation.SetDelayCount(2);
		//animation2.SetDelayCount(1);
		if (isMovingLeft)
		{
			x -= STEP_SIZE;
		}
		if (isMovingRight)
		{
			x += STEP_SIZE;
		}
		if (isMovingUp)
		{
			y -= STEP_SIZE;
			//animation2.OnMove();
		}
		if (isMovingDown)
		{
			y += STEP_SIZE;
			animation.OnMove();
		}
	}
	void CIsaac::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CIsaac::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CIsaac::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CIsaac::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	void CIsaac::SetXY(int nx, int ny)
	{
		x = nx; 
		y = ny;
	}
	void CIsaac::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
		/*animation2.SetTopLeft(x, y);
		animation2.OnShow();*/
	}

	void CIsaac::Reset()
	{
		animation.Reset();
		//animation2.Reset();
		//animation3.Reset();
		//animation4.Reset();
	}
}