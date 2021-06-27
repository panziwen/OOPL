#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CInterface.h"
namespace game_framework
{
	CInterface::CInterface()
	{
	}
	void CInterface::LoadBitmap()
	{
		char *filename = ".\\bitmaps\\interface\\interface_background.bmp";

		char *filename2[7] = { ".\\Bitmaps\\interface\\interface_logo1.bmp",".\\Bitmaps\\interface\\interface_logo2.bmp",
								".\\Bitmaps\\interface\\interface_logo3.bmp",".\\Bitmaps\\interface\\interface_logo4.bmp" ,
								".\\Bitmaps\\interface\\interface_logo5.bmp",".\\Bitmaps\\interface\\interface_logo6.bmp" ,".\\Bitmaps\\interface\\interface_logo7.bmp" };

		char *filename3[7] = { ".\\Bitmaps\\interface\\interface_start1.bmp",".\\Bitmaps\\interface\\interface_start2.bmp", };

		char *filename4[7] = { ".\\Bitmaps\\interface\\interface_bug1.bmp",".\\Bitmaps\\interface\\interface_bug2.bmp", };

		
		background.LoadBitmap(filename, RGB(109, 33, 115));

		for (int i = 0; i < 7; ++i)
		{
			logo.AddBitmap(filename2[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; ++i)
		{
			start.AddBitmap(filename3[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 2; ++i)
		{
			bugs.AddBitmap(filename4[i], RGB(109, 33, 115));
		}
	}
	void CInterface::OnMove()
	{
		logo.SetDelayCount(4);
		logo.OnMove();

		bugs.OnMove();

		start.OnMove();
	}
	void CInterface::BackgroundOnShow()
	{
		background.SetTopLeft(0,0);
		background.ShowBitmap(2);
		logo.SetTopLeft((SIZE_X - logo.Width()) / 3, (SIZE_Y - logo.Height()) / 17);
		logo.OnShow(1.5);

		bugs.SetTopLeft((SIZE_X - 5 * bugs.Width()), (SIZE_Y - bugs.Height()) / 3);
		bugs.OnShow(1.5);

		start.SetTopLeft((SIZE_X - 2 * start.Width()) / 2, (SIZE_Y - start.Height()) / 3);
		start.OnShow(2);
	}
	void CInterface::BackOnMove()
	{
		a.AddBitmap(IDB_CONTINUE);
		a.OnMove();
		a.OnShow();
	}
}