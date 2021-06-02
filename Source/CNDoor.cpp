#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CNDoor.h"

namespace game_framework
{
	CNDoor::CNDoor()
	{
	}
	int CNDoor::GetX1()
	{
		return posx;
	}
	int CNDoor::GetY1()
	{
		return posy;
	}
	int CNDoor::GetX2()
	{
		return posx + door1.Width();
	}
	int CNDoor::GetY2()
	{
		return posy + door1.Height();;
	}
	void CNDoor::SetDoor(int x, int y)
	{
		dx = x;
		dy = y;
	}
	void CNDoor::Initialize(bool flag, bool flag2, bool flag3, bool flag4)
	{
		u = flag;
		d = flag2;
		l = flag3;
		r = flag4;
		isInDoor = false;
	}
	void CNDoor::LoadBitmap()
	{
		door1.LoadBitmap(".\\bitmaps\\map\\nomal\\door1.bmp", RGB(109, 33, 115));
		door2.LoadBitmap(".\\bitmaps\\map\\nomal\\door2.bmp", RGB(109, 33, 115));
		door3.LoadBitmap(".\\bitmaps\\map\\nomal\\door3.bmp", RGB(109, 33, 115));
		door4.LoadBitmap(".\\bitmaps\\map\\nomal\\door4.bmp", RGB(109, 33, 115));
	}
	void CNDoor::OnMove()
	{
		
	}
	void CNDoor::OnShow()
	{
		if (u)
		{
			posx = SIZE_X / 2 - 50;
			posy = 60;
			door1.SetTopLeft(posx, posy);
			posy -= 45;
			door1.ShowBitmap();
		}
		if (d)
		{
			posx = SIZE_X / 2 - 50;
			posy = SIZE_Y - 110;
			door2.SetTopLeft(posx, posy);
			door2.ShowBitmap();
		}
		if (l)
		{
			posx = 110;
			posy = SIZE_Y / 2;
			door3.SetTopLeft(posx, posy);
			door3.ShowBitmap();
		}
		if (r)
		{
			posx = SIZE_X - 160;
			posy = SIZE_Y / 2;
			door4.SetTopLeft(posx, posy);
			posx += 15;
			door4.ShowBitmap();
		}
	}
	void CNDoor::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CNDoor::SetCPos(int nx, int ny)
	{
		cx = nx;
		cy = ny;
	}
}