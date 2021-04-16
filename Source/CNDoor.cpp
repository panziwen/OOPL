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
	void CNDoor::Initialize()
	{
		tmp = 1 + rand() % 4;
		isInDoor = false;
	}
	void CNDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\nomal\\door4.bmp", RGB(109, 33, 115));
	}
	void CNDoor::OnShow()
	{
		int posx;
		int posy;
		switch (tmp)
		{
		case 1:
			posx = SIZE_X / 2 - 50;
			posy = SIZE_Y - 110;
			break;
		case 2:
			posx = SIZE_X - 160;
			posy = SIZE_Y / 2;
			break;
		case 3:
			posx = SIZE_X / 2 - 50;
			posy = 50;
			break;
		case 4:
			posx = 110;
			posy = SIZE_Y / 2;
			break;
		default:
			break;
		}
		door.SetTopLeft(posx, posy);
		door.ShowBitmap();
	}
	bool CNDoor::IsInSize()
	{
		return isInSize;
	}
	bool CNDoor::IsInDoor()
	{
		if (isInDoor)
		{
			if (cx >= x + 15 && cx < x + 20 && cy>y && cy < y + 10)
			{
				isInDoor = false;

			}

		}
		else if (!isInDoor)
		{
			if (cx >= x + 15 && cx < x + 20 && cy>y && cy < y + 10)
			{
				isInDoor = true;

			}

		}
		return isInDoor;
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