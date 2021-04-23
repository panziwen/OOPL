#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CNmap.h"

namespace game_framework
{
	CNmap::CNmap()
	{
		
		door = new CDoor();
		door->Initialize();
		isDoor = isInADoor = isInDDoor = isInNDoor = isInPDoor = false;
	}
	CNmap::~CNmap()
	{
		delete door;
	}
	bool CNmap::IsInADoor()
	{
		return isInADoor;
	}
	bool CNmap::IsInDDoor()
	{
		return isInDDoor;
	}
	bool CNmap::IsInNDoor()
	{

		return isInNDoor;
	}
	bool CNmap::IsInPDoor()
	{
		return isInPDoor;
	}

	bool CNmap::Up()
	{
		return door->Up();
	}
	bool CNmap::Down()
	{
		return door->Down();
	}
	bool CNmap::Left()
	{
		return door->Left();
	}
	bool CNmap::Right()
	{
		return door->Right();
	}

	void CNmap::Initialize()
	{
	}
	void CNmap::LoadBitmap()
	{
		map1.LoadBitmap(".\\bitmaps\\map\\nomal\\1.bmp");
		map2.LoadBitmap(".\\bitmaps\\map\\nomal\\2.bmp");
		map3.LoadBitmap(".\\bitmaps\\map\\nomal\\3.bmp");
		map4.LoadBitmap(".\\bitmaps\\map\\nomal\\4.bmp");
		map5.LoadBitmap(".\\bitmaps\\map\\nomal\\6.bmp");
		map6.LoadBitmap(".\\bitmaps\\map\\nomal\\7.bmp");
		map7.LoadBitmap(".\\bitmaps\\map\\nomal\\8.bmp");
		map8.LoadBitmap(".\\bitmaps\\map\\nomal\\9.bmp");
		map9.LoadBitmap(".\\bitmaps\\map\\nomal\\5.bmp");
		enemy.LoadBitmap();
		door->LoadBitmap();
	}
	void CNmap::LoadBitmap2()
	{
		map11.LoadBitmap(".\\bitmaps\\map\\demo\\1.bmp");
		map22.LoadBitmap(".\\bitmaps\\map\\demo\\2.bmp");
		map33.LoadBitmap(".\\bitmaps\\map\\demo\\3.bmp");
		map44.LoadBitmap(".\\bitmaps\\map\\demo\\4.bmp");
		map55.LoadBitmap(".\\bitmaps\\map\\demo\\6.bmp");
		map66.LoadBitmap(".\\bitmaps\\map\\demo\\7.bmp");
		map77.LoadBitmap(".\\bitmaps\\map\\demo\\8.bmp");
		map88.LoadBitmap(".\\bitmaps\\map\\demo\\9.bmp");
		map99.LoadBitmap(".\\bitmaps\\map\\demo\\5.bmp");
		enemy.LoadBitmap();
		door->LoadBitmap();
	}
	void CNmap::CreateEn()
	{
		enemy.SetXY(x, y);
		enemy.SetBulXY(bx, by);
		enemy.OnMove();
		GetAimPos();
	}
	void CNmap::OnShow()
	{
		for (int i = 2; i < 4; i++)
		{
			map5.SetTopLeft(100, i*map5.Height());
			map5.ShowBitmap();
		}
		for (int i = 2; i < 4; i++)
		{
			map6.SetTopLeft(SIZE_X - map6.Width() - 100, i*map6.Height());
			map6.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map7.SetTopLeft(i*map7.Width(), 50);
			map7.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map8.SetTopLeft(i*map8.Width(), SIZE_Y - map8.Height() - 50);
			map8.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				map9.SetTopLeft(i * map9.Width(), j * map9.Height());
				map9.ShowBitmap();
			}
		}
		map1.SetTopLeft(100, 50);
		map1.ShowBitmap();
		map2.SetTopLeft(SIZE_X - map1.Width() - 100, 50);
		map2.ShowBitmap();
		map3.SetTopLeft(100, SIZE_Y - map3.Height() - 50);
		map3.ShowBitmap();
		map4.SetTopLeft(SIZE_X - map4.Width() - 100, SIZE_Y - map3.Height() - 50);
		map4.ShowBitmap();

		door->OnShow();
		enemy.OnShow();
		GetDoor();
	}
	void CNmap::OnShow2()
	{
		for (int i = 2; i < 4; i++)
		{
			map55.SetTopLeft(100, i*map55.Height());
			map55.ShowBitmap();
		}
		for (int i = 2; i < 4; i++)
		{
			map66.SetTopLeft(SIZE_X - map66.Width() - 100, i*map66.Height());
			map66.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map77.SetTopLeft(i*map77.Width(), 50);
			map77.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			map88.SetTopLeft(i*map88.Width(), SIZE_Y - map88.Height() - 50);
			map88.ShowBitmap();
		}
		for (int i = 1; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				map99.SetTopLeft(i * map99.Width(), j * map99.Height());
				map99.ShowBitmap();
			}
		}
		map11.SetTopLeft(100, 50);
		map11.ShowBitmap();
		map22.SetTopLeft(SIZE_X - map11.Width() - 100, 50);
		map22.ShowBitmap();
		map33.SetTopLeft(100, SIZE_Y - map33.Height() - 50);
		map33.ShowBitmap();
		map44.SetTopLeft(SIZE_X - map44.Width() - 100, SIZE_Y - map33.Height() - 50);
		map44.ShowBitmap();

		door->OnShow();
		enemy.OnShow();
		GetDoor();
	}
	void CNmap::SetCPos(int x, int y, int nx, int ny)
	{
		px = x;
		py = y;
		pnx = nx;
		pny = ny;
	}
	void CNmap::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CNmap::SetBulPos(int nx, int ny)
	{
		bx = nx;
		by = ny;
	}
	void CNmap::GetDoor()
	{
		/*isInADoor = door->IsInADoor();
		isInNDoor = door->IsInNDoor();
		isInPDoor = door->IsInPDoor();
		isInDDoor = door->IsInDDoor();*/
	}
	bool CNmap::GetAimPos()
	{
		return enemy.GetAimPos();
	}
	bool CNmap::IsInDoor()
	{
		if (((px >= door->GetX1() && px <= door->GetX2()) && (py > door->GetY1() && py <= door->GetY2())) || ((pnx >= door->GetX1() && pnx <= door->GetX2()) && (pny > door->GetY1() && pny <= door->GetY2())))
		{
			isDoor = true;
		}
		return isDoor;
	}
}