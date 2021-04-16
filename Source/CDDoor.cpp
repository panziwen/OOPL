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
		return posx + door.Width();
	}
	int CDDoor::GetY2()
	{
		return posy + door.Height();;
	}
	void CDDoor::Initialize()
	{
		tmp = 1 + rand() % 4;
		isInDoor = false;
	}
	void CDDoor::LoadBitmap()
	{
		door.LoadBitmap(".\\bitmaps\\map\\demo\\door1.bmp", RGB(109, 33, 115));
	}
	void CDDoor::OnShow()
	{
		/*switch (tmp)
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
		}*/
		posx = SIZE_X / 2 - 50;
		posy = 50;
		door.SetTopLeft(posx, posy);
		door.ShowBitmap();
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