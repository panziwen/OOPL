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
		isInDoor = false;
	}
	void CNDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\nomal\\door4.bmp", RGB(109, 33, 115));
	}
	void CNDoor::OnShow()
	{
		const int posx = SIZE_X - 160;
		const int posy = SIZE_Y/2;
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