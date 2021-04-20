#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPDoor.h"

namespace game_framework
{
	CPDoor::CPDoor()
	{
		tmp = 1 + rand() % 4;
	}
	int CPDoor::GetX1()
	{
		return posx;
	}
	int CPDoor::GetY1()
	{
		return posy;
	}
	int CPDoor::GetX2()
	{
		return posx + door1.Width();
	}
	int CPDoor::GetY2()
	{
		return posy + door1.Height();;
	}
	void CPDoor::Initialize()
	{
		isInDoor = false;
	}
	void CPDoor::LoadBitmap()
	{
		door1.LoadBitmap(".\\bitmaps\\map\\price\\door1.bmp", RGB(109, 33, 115));
		door2.LoadBitmap(".\\bitmaps\\map\\price\\door2.bmp", RGB(109, 33, 115));
		door3.LoadBitmap(".\\bitmaps\\map\\price\\door3.bmp", RGB(109, 33, 115));
		door4.LoadBitmap(".\\bitmaps\\map\\price\\door4.bmp", RGB(109, 33, 115));
	}
	void CPDoor::OnShow()
	{
		switch (tmp)
		{
		case 1:
			posx = SIZE_X / 2 - 50;
			posy = 60;
			door1.SetTopLeft(posx, posy);
			posy -= 45;
			door1.ShowBitmap();
			break;
		case 2:
			posx = SIZE_X / 2 - 50;
			posy = SIZE_Y - 110;
			door2.SetTopLeft(posx, posy);
			door2.ShowBitmap();
			break;
		case 3:
			posx = 110;
			posy = SIZE_Y / 2;
			door3.SetTopLeft(posx, posy);
			door3.ShowBitmap();
			break;
		case 4:
			posx = SIZE_X - 160;
			posy = SIZE_Y / 2;
			door4.SetTopLeft(posx, posy);
			posx += 15;
			door4.ShowBitmap();
			break;
		default:
			break;
		}
	}
	void CPDoor::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CPDoor::SetCPos(int nx, int ny)
	{
		cx = nx;
		cy = ny;
	}
}