#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharaterCtrol.h"
#include "CAmap.h"

namespace game_framework
{
	CAmap::CAmap()
	{
		isInSize = true;
	}
	void CAmap::Initialize()
	{
		isInDDoor = isInNDoor = isInADoor = isInDDoor = false;
	}
	void CAmap::LoadBitmap()
	{
		map1.LoadBitmap(".\\bitmaps\\map\\angle\\1.bmp");
		map2.LoadBitmap(".\\bitmaps\\map\\angle\\2.bmp");
		map3.LoadBitmap(".\\bitmaps\\map\\angle\\3.bmp");
		map4.LoadBitmap(".\\bitmaps\\map\\angle\\4.bmp");
		enemy.LoadBitmap();
	}
	void CAmap::CreateEn()
	{
		enemy.SetXY(x, y);
		enemy.OnMove();
	}
	void CAmap::OnShow()
	{
		map1.SetTopLeft(SIZE_X/3-100, 50);
		map1.ShowBitmap();
		map2.SetTopLeft(SIZE_X / 3 - 100 + map1.Width(), 50);
		map2.ShowBitmap();
		map3.SetTopLeft(SIZE_X / 3 - 100, 50+map3.Height());
		map3.ShowBitmap();
		map4.SetTopLeft(SIZE_X / 3 - 100 + map1.Width(), 50 + map3.Height());
		map4.ShowBitmap();
		enemy.OnShow();
	}
	bool CAmap::IsInSize()
	{
		return isInSize;
	}
	void CAmap::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CAmap::SetBulPos(int nx, int ny)
	{
		bx = nx;
		by = ny;
	}
	bool CAmap::GetAimPos()
	{
		return enemy.GetAimPos();
	}
}