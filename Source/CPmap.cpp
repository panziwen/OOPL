#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharaterCtrol.h"
#include "CPmap.h"

namespace game_framework
{
	CPmap::CPmap()
	{
		isInSize = true;
	}
	void CPmap::Initialize()
	{
		isInDDoor = isInNDoor = isInADoor = isInDDoor = false;
	}
	void CPmap::LoadBitmap()
	{
		map1.LoadBitmap(".\\bitmaps\\map\\demo\\1.bmp");
		map2.LoadBitmap(".\\bitmaps\\map\\demo\\2.bmp");
		map3.LoadBitmap(".\\bitmaps\\map\\demo\\3.bmp");
		map4.LoadBitmap(".\\bitmaps\\map\\demo\\4.bmp");
		map5.LoadBitmap(".\\bitmaps\\map\\demo\\6.bmp");
		map6.LoadBitmap(".\\bitmaps\\map\\demo\\7.bmp");
		map7.LoadBitmap(".\\bitmaps\\map\\demo\\8.bmp");
		map8.LoadBitmap(".\\bitmaps\\map\\demo\\9.bmp");
		map9.LoadBitmap(".\\bitmaps\\map\\demo\\5.bmp");
		mapd.LoadBitmap(".\\bitmaps\\map\\demo\\d.bmp", RGB(109, 33, 115));
		enemy.LoadBitmap();
	}
	void CPmap::CreateEn()
	{
		enemy.SetXY(x, y);
		enemy.OnMove();
	}
	void CPmap::OnShow()
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
		map2.SetTopLeft(SIZE_X - map1.Width()-100, 50);
		map2.ShowBitmap();
		map3.SetTopLeft(100, SIZE_Y - map3.Height()-50);
		map3.ShowBitmap();
		map4.SetTopLeft(SIZE_X - map4.Width() - 100, SIZE_Y - map3.Height() - 50);
		map4.ShowBitmap();
		mapd.SetTopLeft((SIZE_X / 2), (SIZE_Y / 3));
		mapd.ShowBitmap();
		enemy.OnShow();
	}
	bool CPmap::IsInSize()
	{
		return isInSize;
	}
	void CPmap::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CPmap::SetBulPos(int nx, int ny)
	{
		bx = nx;
		by = ny;
	}
	bool CPmap::GetAimPos()
	{
		return enemy.GetAimPos();
	}
	bool CPmap::IsInDoor()
	{
		/*if (((px >= door.GetX1() && px <= door.GetX2()) && (py > door.GetY1() && py <= door.GetY2())) || ((pnx >= door.GetX1() && pnx <= door.GetX2()) && (pny > door.GetY1() && pny <= door.GetY2())))
		{
			isDoor = true;
		}*/
		return isDoor;
	}
}