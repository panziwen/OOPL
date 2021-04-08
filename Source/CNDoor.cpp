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
		isInDDoor = isInNDoor = isInADoor = isInDDoor = false;
	}
	void CNDoor::LoadBitmap()
	{
		//namp.LoadBitmap();
		//dmap.LoadBitmap();
	}
	void CNDoor::OnShow()
	{
		if (isInDDoor)
		{
			//dmap.OnShow();
		}
		else
		{
			//namp.OnShow();
		}
	}
	bool CNDoor::IsInSize()
	{
		return isInSize;
	}
	void CNDoor::IsInDoor()
	{
		if (x == SIZE_X / 2 && y == 50)
		{
			isInDDoor = true;
			
		}
	}
	void CNDoor::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
}