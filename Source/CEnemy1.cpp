#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEnemy1.h"
namespace game_framework
{
	CEnemy1::CEnemy1()
	{
		healty = 5;
	}
	int CEnemy1::GetX1()
	{
		return x;
	}
	int CEnemy1::GetY1()
	{
		return y;
	}
	int CEnemy1::GetX2()
	{
		return x + animation.Width();
	}
	int CEnemy1::GetY2()
	{
		return y + animation.Height();
	}
	void CEnemy1::Initialize()
	{
		int X_POS = 170 + rand() % 700;
		int Y_POS = 80 + rand() % 320;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = isdead = false;
	}
	void CEnemy1::LoadBitmap()
	{
		char *filename0 =  ".\\bitmaps\\e\\enemy7\\1.bmp";
		char *filename1[2] = { ".\\bitmaps\\e\\enemy7\\1.bmp",".\\bitmaps\\e\\enemy7\\2.bmp" };
		animation.AddBitmap(filename0, RGB(109, 33, 115));
		for (int i = 0; i < 2; i++)
		{
			isaacWalkDonw.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkUp.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkLeft.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkRight.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
	}
	void CEnemy1::OnMove()
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
	void CEnemy1::OnShow()
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
	
	bool CEnemy1::GetAttack()
	{
		return isAttack2;
	}
	void CEnemy1::Reset()
	{
		animation.Reset();
		isaacWalkDonw.Reset();
		isaacWalkRight.Reset();
		isaacWalkUp.Reset();
		isaacWalkLeft.Reset();
	}
	void CEnemy1::SetXY(int x, int y)
	{
		posx = x;
		posy = y;
	}
	void CEnemy1::SetBulXY(int x, int y)
	{
		bx = x;
		by = y;
	}
	void CEnemy1::Healty()
	{
		if (healty==0)
		{
			isdead = true;
		}
		else
		{
			healty -= 1;
			isdead = false;
		}
	}
	bool CEnemy1::GetAimPos()
	{
		/*if (x >= posx && y >= posy && x <= posx+10 && y <= posy+20 )
		{
			return true;
		}*/
		if (bx >= x && by >= y && bx <= x + animation.Width() && by <= y + animation.Height())
		{
			//Healty();
			return true;
		}
		else
		{
			return false;
		}
	}
	bool CEnemy1::GetDead()
	{
		return isdead;
	}
}