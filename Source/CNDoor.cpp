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
			posxu = SIZE_X / 2 - 50;
			posyu = 60;
			door1.SetTopLeft(posxu, posyu);
			posyu -= 45;
			door1.ShowBitmap();
		}
		if (d)
		{
			posxd = SIZE_X / 2 - 50;
			posyd = SIZE_Y - 110;
			door2.SetTopLeft(posxd, posyd);
			door2.ShowBitmap();
		}
		if (l)
		{
			posxl = 110;
			posyl = SIZE_Y / 2;
			door3.SetTopLeft(posxl, posyl);
			door3.ShowBitmap();
		}
		if (r)
		{
			posxr = SIZE_X - 160;
			posyr = SIZE_Y / 2;
			door4.SetTopLeft(posxr, posyr);
			posxr += 15;
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
	int CNDoor::GetUX1()
	{
		return posxu;
	}
	int CNDoor::GetUY1()
	{
		return posyu;
	}
	int CNDoor::GetUX2()
	{
		return posxu + door1.Width();
	}
	int CNDoor::GetUY2()
	{
		return posyu + door1.Height();
	}
	int CNDoor::GetDX1()
	{
		return posxd;
	}
	int CNDoor::GetDY1()
	{
		return posyd;
	}
	int CNDoor::GetDX2()
	{
		return posxd + door2.Width();
	}
	int CNDoor::GetDY2()
	{
		return posyd + door2.Height();
	}int CNDoor::GetRX1()
	{
		return posxr;
	}
	int CNDoor::GetRY1()
	{
		return posyr;
	}
	int CNDoor::GetRX2()
	{
		return posxr + door4.Width();
	}
	int CNDoor::GetRY2()
	{
		return posyr + door4.Height();
	}int CNDoor::GetLX1()
	{
		return posxl;
	}
	int CNDoor::GetLY1()
	{
		return posyl;
	}
	int CNDoor::GetLX2()
	{
		return posxl + door3.Width();
	}
	int CNDoor::GetLY2()
	{
		return posyl + door3.Height();
	}
	bool CNDoor::Up()
	{
		return u;
	}
	bool CNDoor::Down()
	{
		return d;
	}
	bool CNDoor::Left()
	{
		return l;
	}
	bool CNDoor::Right()
	{
		return r;
	}
}