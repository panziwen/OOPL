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
		return x + animation.Height();
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
		char *filename0 =  ".\\bitmaps\\isaac3.bmp";
		char *filename1[9] = { ".\\bitmaps\\isaac3.bmp", ".\\bitmaps\\isaac4.bmp",".\\bitmaps\\isaac5.bmp",
								".\\bitmaps\\isaac6.bmp",".\\bitmaps\\isaac7.bmp", ".\\bitmaps\\isaac8.bmp",
								".\\bitmaps\\isaac9.bmp",".\\bitmaps\\isaac1.bmp",".\\bitmaps\\isaac2.bmp",};
		char *filename2[10] = {".\\bitmaps\\isaac10.bmp", ".\\bitmaps\\isaac11.bmp",".\\bitmaps\\isaac12.bmp",
								".\\bitmaps\\isaac13.bmp",".\\bitmaps\\isaac14.bmp", ".\\bitmaps\\isaac15.bmp",
								".\\bitmaps\\isaac16.bmp",".\\bitmaps\\isaac17.bmp",".\\bitmaps\\isaac18.bmp",".\\bitmaps\\isaac19.bmp" };
		char *filename3[19] = { ".\\bitmaps\\isaac3.bmp", ".\\bitmaps\\isaac4.bmp",".\\bitmaps\\isaac5.bmp",
								".\\bitmaps\\isaac6.bmp",".\\bitmaps\\isaac7.bmp", ".\\bitmaps\\isaac8.bmp",
								".\\bitmaps\\isaac9.bmp",".\\bitmaps\\isaac1.bmp",".\\bitmaps\\isaac2.bmp",
								".\\bitmaps\\isaac10.bmp", ".\\bitmaps\\isaac11.bmp",".\\bitmaps\\isaac12.bmp",
								".\\bitmaps\\isaac13.bmp",".\\bitmaps\\isaac14.bmp", ".\\bitmaps\\isaac15.bmp",
								".\\bitmaps\\isaac16.bmp",".\\bitmaps\\isaac17.bmp",".\\bitmaps\\isaac18.bmp",".\\bitmaps\\isaac19.bmp" };
		char *filename4[19] = { ".\\bitmaps\\isaac3.bmp", ".\\bitmaps\\isaac4.bmp",".\\bitmaps\\isaac5.bmp",
								".\\bitmaps\\isaac6.bmp",".\\bitmaps\\isaac7.bmp", ".\\bitmaps\\isaac8.bmp",
								".\\bitmaps\\isaac9.bmp",".\\bitmaps\\isaac1.bmp",".\\bitmaps\\isaac2.bmp",
								".\\bitmaps\\isaac10.bmp", ".\\bitmaps\\isaac11.bmp",".\\bitmaps\\isaac12.bmp",
								".\\bitmaps\\isaac13.bmp",".\\bitmaps\\isaac14.bmp", ".\\bitmaps\\isaac15.bmp",
								".\\bitmaps\\isaac16.bmp",".\\bitmaps\\isaac17.bmp",".\\bitmaps\\isaac18.bmp",".\\bitmaps\\isaac19.bmp" };
		animation.AddBitmap(filename0, RGB(255, 255, 255));
		for (int i = 0; i < 9; i++)
		{
			isaacWalkDonw.AddBitmap(filename1[i], RGB(255, 255, 255));
		}
		for (int i = 0; i < 10; i++)
		{
			isaacWalkUp.AddBitmap(filename2[i], RGB(255, 255, 255));
		}
		for (int i = 0; i < 19; i++)
		{
			isaacWalkLeft.AddBitmap(filename3[i], RGB(255, 255, 255));
		}
		for (int i = 0; i < 19; i++)
		{
			isaacWalkRight.AddBitmap(filename4[i], RGB(255, 255, 255));
		}
		
	}
	void CIsaac::OnMove()
	{
		const int STEP_SIZE = 5;
		if (isMovingLeft)
		{
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (isMovingRight)
		{
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (isMovingUp)
		{
			y -= STEP_SIZE;
			isaacWalkUp.SetDelayCount(2);
			isaacWalkUp.OnMove();
		}
		if (isMovingDown)
		{
			y += STEP_SIZE;
			isaacWalkDonw.SetDelayCount(2);
			isaacWalkDonw.OnMove();
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
		if (isMovingLeft)
		{
			isaacWalkLeft.SetTopLeft(x,y);
			isaacWalkLeft.OnShow();
			animation = isaacWalkLeft;
		}
		if (isMovingRight)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow();
			animation = isaacWalkRight;
		}
		if (isMovingUp)
		{
			isaacWalkUp.SetTopLeft(x, y);
			isaacWalkUp.OnShow();
			animation = isaacWalkUp;
		}
		if (isMovingDown)
		{
			isaacWalkDonw.SetTopLeft(x, y);
			isaacWalkDonw.OnShow();
			animation = isaacWalkDonw;
		}
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}

	void CIsaac::Reset()
	{
		animation.Reset();
		isaacWalkDonw.Reset();
		isaacWalkRight.Reset();
		isaacWalkUp.Reset();
		isaacWalkLeft.Reset();
	}
}