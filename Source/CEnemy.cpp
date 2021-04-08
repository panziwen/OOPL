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
		srand((unsigned)time(NULL));
		Initialize();
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
		int X_POS = 150 + rand() % (SIZE_X - 180);
		int Y_POS = 50 + rand() % (SIZE_Y - 150);
		x = X_POS;
		y = Y_POS;
		isaacAttack.SetXY(x, y);
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = false;
	}
	void CEnemy::LoadBitmap()
	{
		char *filename0 =  ".\\bitmaps\\isaac_origin\\isaac3.bmp";

		char *filename1[9] = { ".\\bitmaps\\isaac_origin\\isaac3.bmp", ".\\bitmaps\\isaac_origin\\isaac4.bmp",".\\bitmaps\\isaac_origin\\isaac5.bmp",
								".\\bitmaps\\isaac_origin\\isaac6.bmp",".\\bitmaps\\isaac_origin\\isaac7.bmp", ".\\bitmaps\\isaac_origin\\isaac8.bmp",
								".\\bitmaps\\isaac_origin\\isaac9.bmp",".\\bitmaps\\isaac_origin\\isaac1.bmp",".\\bitmaps\\isaac_origin\\isaac2.bmp",};

		char *filename2[10] = {".\\bitmaps\\isaac_origin\\isaac10.bmp", ".\\bitmaps\\isaac_origin\\isaac11.bmp",".\\bitmaps\\isaac_origin\\isaac12.bmp",
								".\\bitmaps\\isaac_origin\\isaac13.bmp",".\\bitmaps\\isaac_origin\\isaac14.bmp", ".\\bitmaps\\isaac_origin\\isaac15.bmp",
								".\\bitmaps\\isaac_origin\\isaac16.bmp",".\\bitmaps\\isaac_origin\\isaac17.bmp",".\\bitmaps\\isaac_origin\\isaac18.bmp",".\\bitmaps\\isaac_origin\\isaac19.bmp" };

		char *filename3[10] = { ".\\bitmaps\\isaac_origin\\isaac30.bmp", ".\\bitmaps\\isaac_origin\\isaac31.bmp",".\\bitmaps\\isaac_origin\\isaac32.bmp",
								".\\bitmaps\\isaac_origin\\isaac33.bmp",".\\bitmaps\\isaac_origin\\isaac34.bmp", ".\\bitmaps\\isaac_origin\\isaac35.bmp",
								".\\bitmaps\\isaac_origin\\isaac36.bmp",".\\bitmaps\\isaac_origin\\isaac37.bmp",".\\bitmaps\\isaac_origin\\isaac38.bmp",".\\bitmaps\\isaac_origin\\isaac39.bmp" };

		char *filename4[10] = { ".\\bitmaps\\isaac_origin\\isaac20.bmp", ".\\bitmaps\\isaac_origin\\isaac21.bmp",".\\bitmaps\\isaac_origin\\isaac22.bmp",
								".\\bitmaps\\isaac_origin\\isaac23.bmp",".\\bitmaps\\isaac_origin\\isaac24.bmp", ".\\bitmaps\\isaac_origin\\isaac25.bmp",
								".\\bitmaps\\isaac_origin\\isaac26.bmp",".\\bitmaps\\isaac_origin\\isaac27.bmp",".\\bitmaps\\isaac_origin\\isaac28.bmp",".\\bitmaps\\isaac_origin\\isaac29.bmp"};

		animation.AddBitmap(filename0, RGB(109, 33, 115));
		for (int i = 0; i < 9; i++)
		{
			isaacWalkDonw.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 10; i++)
		{
			isaacWalkUp.AddBitmap(filename2[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 10; i++)
		{
			isaacWalkLeft.AddBitmap(filename3[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 10; i++)
		{
			isaacWalkRight.AddBitmap(filename4[i], RGB(109, 33, 115));
		}
		
	}
	void CEnemy::OnMove()
	{
		const int STEP_SIZE = 1;
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
	void CEnemy::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CEnemy::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CEnemy::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CEnemy::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	void CEnemy::SetAttack(bool flag, bool flag2)
	{
		isAttack = flag;
		isAttack2 = flag2;
		isaacAttack.SetAttack(isAttack2);

	}
	void CEnemy::SetInSize(bool flag)
	{
		isInSize = flag;
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
		if (x >= posx && y >= posy && x <= posx+10 && y <= posy+20 )
		{
			return true;
		}
		else if (bx >= x && by >= y && bx <= x + 5 && by <= y + 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}