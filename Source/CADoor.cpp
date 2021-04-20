#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CADoor.h"

namespace game_framework
{
	CADoor::CADoor()
	{
		tmp = 1 + rand() % 4;
	}
	int CADoor::GetX1()
	{
		return posx;
	}
	int CADoor::GetY1()
	{
		return posy;
	}
	int CADoor::GetX2()
	{
		return posx + door1.Width();
	}
	int CADoor::GetY2()
	{
		return posy + door1.Height();;
	}
	void CADoor::Initialize()
	{
		isInDoor = false;
	}
	void CADoor::LoadBitmap()
	{
		door1.LoadBitmap(".\\bitmaps\\map\\angle\\door1.bmp", RGB(109, 33, 115));
		door2.LoadBitmap(".\\bitmaps\\map\\angle\\door2.bmp", RGB(109, 33, 115));
		door3.LoadBitmap(".\\bitmaps\\map\\angle\\door3.bmp", RGB(109, 33, 115));
		door4.LoadBitmap(".\\bitmaps\\map\\angle\\door4.bmp", RGB(109, 33, 115));
	}
	void CADoor::OnShow()
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
	void CADoor::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CADoor::SetCPos(int nx, int ny)
	{
		cx = nx;
		cy = ny;
	}
}