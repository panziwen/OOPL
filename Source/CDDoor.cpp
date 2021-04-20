#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CDDoor.h"

namespace game_framework
{
	CDDoor::CDDoor()
	{
		tmp = 1 + rand() % 4;
	}
	int CDDoor::GetX1()
	{
		return posx;
	}
	int CDDoor::GetY1()
	{
		return posy;
	}
	int CDDoor::GetX2()
	{
		return posx + door1.Width();
	}
	int CDDoor::GetY2()
	{
		return posy + door1.Height();
	}
	void CDDoor::Initialize()
	{
		isInDoor = false;
	}
	void CDDoor::LoadBitmap()
	{
		door1.LoadBitmap(".\\bitmaps\\map\\demo\\door1.bmp", RGB(109, 33, 115));
		door2.LoadBitmap(".\\bitmaps\\map\\demo\\door2.bmp", RGB(109, 33, 115));
		door3.LoadBitmap(".\\bitmaps\\map\\demo\\door3.bmp", RGB(109, 33, 115));
		door4.LoadBitmap(".\\bitmaps\\map\\demo\\door4.bmp", RGB(109, 33, 115));
	}
	void CDDoor::OnShow()
	{
		switch (tmp)
		{
		case 1:
			posx = SIZE_X / 2 - 50;
			posy = 50;
			door1.SetTopLeft(posx, posy);
			posy -= 50;
			door1.ShowBitmap();
			break;
		case 2:
			posx = SIZE_X / 2 - 50;
			posy = SIZE_Y - 110;
			door2.SetTopLeft(posx, posy);
			door2.ShowBitmap();
			break;
		case 3:
			posx = 95;
			posy = SIZE_Y / 2;
			door3.SetTopLeft(posx, posy);
			posx += 10;
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
	
	void CDDoor::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CDDoor::SetCPos(int nx, int ny)
	{
		cx = nx;
		cy = ny;
	}
}