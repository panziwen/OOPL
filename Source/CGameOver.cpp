#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameOver.h"
namespace game_framework
{
	CGameOver::CGameOver()
	{
	}
	void CGameOver::LoadBitmap()
	{
		char *filename[3] = { ".\\Bitmaps\\gameover\\1.bmp",".\\Bitmaps\\gameover\\2.bmp",".\\Bitmaps\\gameover\\3.bmp" };
		char *filename2[8] = { ".\\Bitmaps\\gameover\\6.bmp",".\\Bitmaps\\gameover\\7.bmp" ,
								".\\Bitmaps\\gameover\\8.bmp",".\\Bitmaps\\gameover\\9.bmp",".\\Bitmaps\\gameover\\10.bmp" ,
								".\\Bitmaps\\gameover\\11.bmp",".\\Bitmaps\\gameover\\12.bmp",".\\Bitmaps\\gameover\\13.bmp"  };

		

		for (int i = 0; i < 3; ++i)
		{
			background.AddBitmap(filename[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 8; ++i)
		{
			background2.AddBitmap(filename2[i], RGB(0, 0, 0));
		}
		a.LoadBitmap(".\\Bitmaps\\gameover\\4.bmp");
	}
	void CGameOver::OnMove()
	{
		background.SetDelayCount(4);
		background.OnMove();
		background2.SetDelayCount(9);
		background2.OnMove();
	}
	void CGameOver::BackOnShow()
	{
		background.SetTopLeft(0, 0);
		background.OnShow(2);
	}
	void CGameOver::BackOnShow2()
	{
		a.ShowBitmap(3);
		background2.SetTopLeft(380, 0);
		background2.OnShow();
	}
}