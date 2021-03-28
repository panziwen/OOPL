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
	void CIsaac::Initialize()
	{
		const int X_POS = SIZE_X/2;
		const int Y_POS = (SIZE_Y / 5) * 4;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = false;
	}
	void CIsaac::LoadBitmap()
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
	void CIsaac::OnMove()
	{
		const int STEP_SIZE = 5;
		if (isMovingLeft && !isMovingUp && !isMovingDown)
		{
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x-isaacAttack.Width(), y);
		}
		if (isMovingRight && !isMovingUp && !isMovingDown)
		{
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingUp && !isMovingLeft && !isMovingRight)
		{
			y -= STEP_SIZE;
			isaacWalkUp.SetDelayCount(2);
			isaacWalkUp.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingDown && !isMovingLeft && !isMovingRight)
		{
			y += STEP_SIZE;
			isaacWalkDonw.SetDelayCount(2);
			isaacWalkDonw.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingUp && isMovingLeft)
		{
			y -= STEP_SIZE;
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x - isaacAttack.Width(), y);
		}
		if (isMovingUp && isMovingRight)
		{
			y -= STEP_SIZE;
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isMovingDown && isMovingLeft)
		{
			y += STEP_SIZE;
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
			isaacAttack.SetXY(x - isaacAttack.Width(), y);
		}
		if (isMovingDown && isMovingRight)
		{
			y += STEP_SIZE;
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
			isaacAttack.SetXY(x, y);
		}
		if (isAttack)
		{
			isaacAttack.SetAttack(isAttack);
 			isaacAttack.OnMove();
		}
	}
	void CIsaac::OnShow()
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
			isaacAttack.OnShow();
		}
		animation.SetTopLeft(x, y);
		animation.OnShow(2);
	}
	void CIsaac::BulletDisapear()
	{
		isaacAttack.BulletDisapear();
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
	void CIsaac::SetAttack(bool flag)
	{
		isAttack = flag;
	}
	void CIsaac::AttackReset()
	{
		isaacAttack.Reset();
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