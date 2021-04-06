#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharaterCtrol.h"
#include "CGamemap.h"
namespace game_framework
{
	CGamemap::CGamemap()
	{
		isInSize = true;
	}
	void CGamemap::Initialize()
	{
		
	}
	void CGamemap::LoadBitmap()
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
	}
	void CGamemap::OnShow()
	{
		for (int j = 1; j < SIZE_Y / map5.Height(); j++)
		{
			map5.SetTopLeft(0, j*map5.Height());
			map5.ShowBitmap();
		}
		for (int j = 1; j < SIZE_Y / map6.Height(); j++)
		{
			map6.SetTopLeft(SIZE_X - map6.Width(), j*map5.Height());
			map6.ShowBitmap();
		}
		for (int j = 1; j < SIZE_X / map7.Width(); j++)
		{
			map7.SetTopLeft(j*map7.Width(), 0);
			map7.ShowBitmap();
		}
		for (int j = 1; j < SIZE_X / map8.Width(); j++)
		{
			map8.SetTopLeft(j* map8.Width(), SIZE_Y - map8.Height());
			map8.ShowBitmap();
		}
		for (int i = 1; i < SIZE_X / map9.Width(); i++)
		{
			for (int j = 1; j < SIZE_Y / map9.Height(); j++)
			{

				map9.SetTopLeft(i* map8.Width(), j*map9.Height());
				map9.ShowBitmap();
			}
		}
		map1.SetTopLeft(0, 0);
		map1.ShowBitmap();
		map2.SetTopLeft(SIZE_X - map1.Width(), 0);
		map2.ShowBitmap();
		map3.SetTopLeft(0, SIZE_Y - map3.Height());
		map3.ShowBitmap();
		map4.SetTopLeft(SIZE_X - map4.Width(), SIZE_Y - map3.Height());
		map4.ShowBitmap();
	}
	bool CGamemap::IsInSize()
	{
		return isInSize;
	}
}