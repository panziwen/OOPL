#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharaterCtrol.h"
namespace game_framework
{
	CCharaterCtrol::CCharaterCtrol()
	{

	}
	int CCharaterCtrol::GetX1()
	{
		return x;
	}
	int CCharaterCtrol::GetY1()
	{
		return y;
	}
	int CCharaterCtrol::GetX2()
	{
		return x+animation.Width();
	}
	int CCharaterCtrol::GetY2()
	{
		return y + animation.Height();;
	}
	void CCharaterCtrol::Initialize()
	{
		bullt = 0;
		const int X_POS = SIZE_X/2;
		const int Y_POS = (SIZE_Y / 5) * 4 - 50;
		x = X_POS;
		y = Y_POS;
		isaacAttack.SetXY(x, y);
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = false;
	}
	void CCharaterCtrol::LoadBitmap()
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
		isaacAttack.LoadBitmap();
		
	}
	void CCharaterCtrol::OnMove()
	{
		const int STEP_SIZE = 5;
		if (isMovingLeft && !isMovingUp && !isMovingDown)
		{
			if (x >= 51)
			{
				x -= STEP_SIZE;
			}
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x-isaacAttack.Width(), y);
		}
		if (isMovingRight && !isMovingUp && !isMovingDown)
		{
			if (x <= SIZE_X - 100)
			{
				x += STEP_SIZE;
			}
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingUp && !isMovingLeft && !isMovingRight)
		{
			if (y >= -20)
			{
				y -= STEP_SIZE;
			}
			isaacWalkUp.SetDelayCount(2);
			isaacWalkUp.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingDown && !isMovingLeft && !isMovingRight)
		{
			if (y <= SIZE_Y - 150)
			{
				y += STEP_SIZE;
			}
			isaacWalkDonw.SetDelayCount(2);
			isaacWalkDonw.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingUp && isMovingLeft)
		{
			if (x >= 51 && y >= -20)
			{
				y -= STEP_SIZE;
				x -= STEP_SIZE;
			}
			if (!(x >= 51) && (y >= -20))
			{
				y -= STEP_SIZE;
			}
			if ((x >= 51) && !(y >= -20))
			{
				x -= STEP_SIZE;
			}
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x - isaacAttack.Width(), y);
		}
		if (isMovingUp && isMovingRight)
		{
			if ((x <= SIZE_X - 100) && (y >= -20))
			{
				y -= STEP_SIZE;
				x += STEP_SIZE;
			}
			if (!(x <= SIZE_X - 100) && (y >= -20))
			{
				y -= STEP_SIZE;
			}
			if ((x <= SIZE_X - 100) && !(y >= -20))
			{
				x += STEP_SIZE;
			}
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingDown && isMovingLeft)
		{
			if ((x >= 51) && (y <= SIZE_Y - 150))
			{
				y += STEP_SIZE;
				x -= STEP_SIZE;
			}
			if (!(x >= 51) && (y <= SIZE_Y - 150))
			{
				y += STEP_SIZE;
			}
			if ((x >= 51) && !(y <= SIZE_Y - 150))
			{
				x -= STEP_SIZE;
			}
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x - isaacAttack.Width(), y);
		}
		if (isMovingDown && isMovingRight)
		{
			if ((x <= SIZE_X - 100) && (y <= SIZE_Y - 150))
			{
				y += STEP_SIZE;
				x += STEP_SIZE;
			}
			if (!(x <= SIZE_X - 100) && (y <= SIZE_Y - 150))
			{
				y += STEP_SIZE;
			}
			if ((x <= SIZE_X - 100) && !(y <= SIZE_Y - 150))
			{
				x += STEP_SIZE;
			}
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		isaacAttack.OnMove();
	}
	void CCharaterCtrol::OnShow()
	{
		if (isMovingLeft && !isMovingUp && !isMovingDown)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow(2);
			animation = isaacWalkLeft;
		}
		if (isMovingRight && !isMovingUp && !isMovingDown)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow(2);
			animation = isaacWalkRight;
		}
		if (isMovingUp && !isMovingLeft && !isMovingRight)
		{
			isaacWalkUp.SetTopLeft(x, y);
			isaacWalkUp.OnShow(2);
			animation = isaacWalkUp;
		}
		if (isMovingDown && !isMovingLeft && !isMovingRight)
		{
			isaacWalkDonw.SetTopLeft(x, y);
			isaacWalkDonw.OnShow(2);
			animation = isaacWalkDonw;
		}
		if (isMovingUp && isMovingLeft)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow(2);
			animation = isaacWalkLeft;
		}
		if (isMovingUp && isMovingRight)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow(2);
			animation = isaacWalkRight;
		}
		if (isMovingDown && isMovingLeft)
		{
			isaacWalkLeft.SetTopLeft(x, y);
			isaacWalkLeft.OnShow(2);
			animation = isaacWalkLeft;
		}
		if (isMovingDown && isMovingRight)
		{
			isaacWalkRight.SetTopLeft(x, y);
			isaacWalkRight.OnShow(2);
			animation = isaacWalkRight;
		}
		if (isAttack)
		{
			for (int i = 0; i < 7; i++)
			{
				isaacAttack.OnShow();

			}
		}
		animation.SetTopLeft(x, y);
		animation.OnShow(2);
	}
	void CCharaterCtrol::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CCharaterCtrol::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CCharaterCtrol::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CCharaterCtrol::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	void CCharaterCtrol::SetAttack(bool flag)
	{
		isAttack = flag;
	}
	void CCharaterCtrol::SetInSize(bool flag)
	{
		isInSize = flag;
	}
	void CCharaterCtrol::AttackReset()
	{
		isaacAttack.Reset();
	}
	void CCharaterCtrol::Reset()
	{
		animation.Reset();
		isaacWalkDonw.Reset();
		isaacWalkRight.Reset();
		isaacWalkUp.Reset();
		isaacWalkLeft.Reset();
	}
}