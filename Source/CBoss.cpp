#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBoss.h"
namespace game_framework
{
	CBoss::CBoss()
	{
		bodynub = 4;
		for (int i = 0; i < bodynub; i++)
		{
			body.push_back(new CAnimation());
		}
		healty = 5;
	}
	CBoss::~CBoss()
	{
		if (body.size()!=0)
		{
			for (int i = 0; i < bodynub; i++)
			{
				delete body[i];
			}

		}
	}
	int CBoss::GetX1()
	{
		return x;
	}
	int CBoss::GetY1()
	{
		return y;
	}
	int CBoss::GetX2()
	{
		return x + animation.Width();
	}
	int CBoss::GetY2()
	{
		return y + animation.Height();
	}
	void CBoss::Initialize()
	{
		int X_POS = 170 + rand() % 700;
		int Y_POS = 80 + rand() % 320;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isAttack = isdead = false;
	}
	void CBoss::LoadBitmap()
	{
		char *filename0 =  ".\\bitmaps\\e\\boss1\\h1.bmp";
		char *filename1[2] = { ".\\bitmaps\\e\\boss1\\h1.bmp",".\\bitmaps\\e\\boss1\\h2.bmp" };
		char *filename2[2] = { ".\\bitmaps\\e\\boss1\\h3.bmp",".\\bitmaps\\e\\boss1\\h4.bmp" };
		char *filename3[2] = { ".\\bitmaps\\e\\boss1\\h5.bmp",".\\bitmaps\\e\\boss1\\h6.bmp" };
		char *filename4[2] = { ".\\bitmaps\\e\\boss1\\h8.bmp",".\\bitmaps\\e\\boss1\\h7.bmp" };
		char *filename5[2] = { ".\\bitmaps\\e\\boss1\\b1.bmp",".\\bitmaps\\e\\boss1\\b2.bmp" };
		
		animation.AddBitmap(filename0, RGB(109, 33, 115));
		for (int i = 0; i < 2; i++)
		{
			isaacWalkDonw.AddBitmap(filename4[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkUp.AddBitmap(filename3[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkLeft.AddBitmap(filename2[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; i++)
		{
			isaacWalkRight.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < bodynub; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				body[i]->AddBitmap(filename5[j], RGB(109, 33, 115));
			}
		}


		
	}
	void CBoss::OnMove()
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
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX2() - 15 + i * 15, y + 10);
				body[i]->OnMove();
			}
			x -= STEP_SIZE;
			y -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y > posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX1() - 12 - i * 15, y + 10);
				body[i]->OnMove();
			}
			x += STEP_SIZE;
			y -= STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x > posx&&y < posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX2() - 15 + i * 15, y + 10);
				body[i]->OnMove();
			}
			x -= STEP_SIZE;
			y += STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y < posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX1() - 12 - i * 15, y + 10);
				body[i]->OnMove();
			}
			x += STEP_SIZE;
			y += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x > posx&&y == posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX2() - 15 + i * 15, y + 10);
				body[i]->OnMove();
			}
			x -= STEP_SIZE;
			isaacWalkLeft.SetDelayCount(2);
			isaacWalkLeft.OnMove();
		}
		if (x < posx&&y == posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX1() - 12 - i * 15, y + 10);
				body[i]->OnMove();
			}
			x += STEP_SIZE;
			isaacWalkRight.SetDelayCount(2);
			isaacWalkRight.OnMove();
		}
		if (x == posx&&y < posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX2() - 15 + i * 15, y + 10);
				body[i]->OnMove();
			}
			y += STEP_SIZE;
			isaacWalkDonw.SetDelayCount(2);
			isaacWalkDonw.OnMove();
		}
		if (x == posx&&y > posy)
		{
			for (int i = 0; i < bodynub; i++)
			{
				body[i]->SetTopLeft(GetX2() - 15 + i * 15, y + 10);
				body[i]->OnMove();
			}
			y -= STEP_SIZE;
			isaacWalkUp.SetDelayCount(2);
			isaacWalkUp.OnMove();
		}
	}
	void CBoss::OnShow()
	{
		for (int i = 0; i < bodynub; i++)
		{
			body[i]->OnShow();
		}
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
	
	bool CBoss::GetAttack()
	{
		return isAttack2;
	}
	void CBoss::Reset()
	{
		animation.Reset();
		isaacWalkDonw.Reset();
		isaacWalkRight.Reset();
		isaacWalkUp.Reset();
		isaacWalkLeft.Reset();
	}
	void CBoss::SetXY(int x, int y)
	{
		posx = x;
		posy = y;
	}
	void CBoss::SetBulXY(int x, int y)
	{
		bx = x;
		by = y;
	}
	void CBoss::Healty()
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
	bool CBoss::GetAimPos()
	{
		CAnimation *t;
		/*if (x >= posx && y >= posy && x <= posx+10 && y <= posy+20 )
		{
			return true;
		}*/
		if (bx >= x && by >= y && bx <= x + animation.Width() && by <= y + animation.Height())
		{
			//Healty();
			if (body.size()==0)
			{
				return true;
			}
			else
			{
				t = body.back();
				body.pop_back();
				bodynub -= 1;
				delete t;
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool CBoss::GetDead()
	{
		return isdead;
	}
	bool CBoss::GetCtrPos()
	{
		if (x >= posx && y >= posy && x <= posx + 10 && y <= posy + 20)
		{
			return true;
		}
		return false;
	}
}