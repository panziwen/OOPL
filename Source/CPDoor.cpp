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
		isInDoor = false;
	}
	void CPDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\price\\door2.bmp", RGB(109, 33, 115));
	}
	void CPDoor::OnShow()
	{
		const int posx = SIZE_X / 2 - 50;
		const int posy = SIZE_Y-110;
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