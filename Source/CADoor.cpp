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
	}
	void CADoor::Initialize()
	{
		isInDoor = false;
	}
	void CADoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\angle\\door3.bmp", RGB(109, 33, 115));
	}
	void CADoor::OnShow()
	{
		const int posx = 110;
		const int posy = SIZE_Y/2;
		door.SetTopLeft(posx, posy);
		door.ShowBitmap();
	}
	bool CADoor::IsInSize()
	{
		return isInSize;
	}
	bool CADoor::IsInDoor()
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