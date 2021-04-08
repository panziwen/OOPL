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
	}
	void CDDoor::Initialize()
	{
		isInDoor = false;
	}
	void CDDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\demo\\door1.bmp", RGB(109, 33, 115));
	}
	void CDDoor::OnShow()
	{
		door.SetTopLeft(x, y);
		door.ShowBitmap();
	}
	bool CDDoor::IsInSize()
	{
		return isInSize;
	}
	bool CDDoor::IsInDoor()
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