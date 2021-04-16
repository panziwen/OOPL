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
	}
	void CPDoor::Initialize()
	{
		tmp = 1 + rand() % 4;
		isInDoor = false;
	}
	void CPDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\price\\door2.bmp", RGB(109, 33, 115));
	}
	void CPDoor::OnShow()
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
	bool CPDoor::IsInSize()
	{
		return isInSize;
	}
	bool CPDoor::IsInDoor()
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