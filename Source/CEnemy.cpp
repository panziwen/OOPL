#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEnemy.h"
namespace game_framework
{
	CEnemy::CEnemy()
	{
	}
	int CEnemy::GetX1()
	{
		return x;
	}
	int CEnemy::GetY1()
	{
		return y;
	}
	int CEnemy::GetX2()
	{
		return x + animation.Width();
	}
	int CEnemy::GetY2()
	{
		return y + animation.Height();
	}
	void CEnemy::Initialize()
	{
		int X_POS = 170 + rand() % 700;
		int Y_POS = 80 + rand() % 320;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = false;
	}
	void CEnemy::LoadBitmap()
	{
		char *filename0 =  ".\\bitmaps\\e\\enemy4\\1.bmp";
		char *filename1[9] = { ".\\bitmaps\\e\\enemy4\\1.bmp",".\\bitmaps\\e\\enemy4\\2.bmp",".\\bitmaps\\e\\enemy4\\3.bmp",
								".\\bitmaps\\e\\enemy4\\4.bmp",".\\bitmaps\\e\\enemy4\\5.bmp",".\\bitmaps\\e\\enemy4\\6.bmp",
								".\\bitmaps\\e\\enemy4\\7.bmp",".\\bitmaps\\e\\enemy4\\8.bmp",".\\bitmaps\\e\\enemy4\\9.bmp" };
		
		
		animation.AddBitmap(filename0, RGB(109, 33, 115));
		for (int i = 0; i < 9; i++)
		{
			isaacWalkDonw.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 9; i++)
		{
			isaacWalkUp.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 9; i++)
		{
			isaacWalkLeft.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 9; i++)
		{
			isaacWalkRight.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
	}
	void CEnemy::OnMove()
	{
		const int STEP_SIZE = 1;
		animation.SetTopLeft(x, y);
		isaacWalkDonw.SetTopLeft(x, y);
		isaacWalkUp.SetTopLeft(x, y);
		isaacWalkRight.SetTopLeft(x, y);
		isaacWalkLeft.SetTopLeft(x, y);
		animation.SetDelayCount(2);
		animation.OnMove();
		if (x > posx&&y > posy)
		{
			x -= STEP_SIZE;
			y -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y > posy)
		{
			x += STEP_SIZE;
			y -= STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x > posx&&y < posy)
		{
			x -= STEP_SIZE;
			y += STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y < posy)
		{
			x += STEP_SIZE;
			y += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x > posx&&y == posy)
		{
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y == posy)
		{
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x == posx&&y < posy)
		{
			y += STEP_SIZE;
			isaacWalkDonw.SetDelayCount(2);
			isaacWalkDonw.OnMove();
		}
		if (x == posx&&y > posy)
		{
			y -= STEP_SIZE;
			isaacWalkUp.SetDelayCount(2);
			isaacWalkUp.OnMove();
		}
		if (x == posx && y == posy)
		{

		}
	}
	void CEnemy::OnShow()
	{
		if (x > posx&&y > posy)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow();
		}
		if (x < posx&&y > posy)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow();
		}
		if (x > posx&&y < posy)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow();
		}
		if (x < posx&&y < posy)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow();
		}
		if (x > posx&&y == posy)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow();	
		}
		if (x < posx&&y == posy)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow();
		}
		if (x == posx && y < posy)
		{
			isaacWalkDonw.SetTopLeft(x, y);
			isaacWalkDonw.OnShow();
		}
		if (x == posx && y > posy)
		{
			isaacWalkUp.SetTopLeft(x, y);
			isaacWalkUp.OnShow();
		}
	}
	
	bool CEnemy::GetAttack()
	{
		return isAttack2;
	}
	void CEnemy::Reset()
	{
		animation.Reset();
		isaacWalkDonw.Reset();
		isaacWalkRight.Reset();
		isaacWalkUp.Reset();
		isaacWalkLeft.Reset();
	}
	void CEnemy::SetXY(int x, int y)
	{
		posx = x;
		posy = y;
	}
	void CEnemy::SetBulXY(int x, int y)
	{
		bx = x;
		by = y;
	}
	bool CEnemy::GetAimPos()
	{
		/*if (x >= posx && y >= posy && x <= posx+10 && y <= posy+20 )
		{
			return true;
		}*/
		 if (bx >= x && by >= y && bx <= x + animation.Width() && by <= y + animation.Height())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}