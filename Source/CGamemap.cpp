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
		isInDDoor = isInNDoor = isInADoor = isInPDoor = false;
		nmap.Initialize();
		dmap.Initialize();
		door.Initialize();
	}
	void CGamemap::LoadBitmap()
	{
		nmap.LoadBitmap();
		dmap.LoadBitmap();
		door.LoadBitmap();
		amap.LoadBitmap();
	}
	void CGamemap::OnMove()
	{
		const int dx = SIZE_X / 2 - 50;
		const int dy = 50;
		door.SetAimPos(dx, dy);
		door.SetCPos(x, y);
		IsInDoor();
		if (isInDDoor)
		{
			nmap.SetBulPos(bx, by);
			/*amap.SetAimPos(x, y);
			amap.CreateEn();*/
			dmap.SetAimPos(x, y);
			dmap.CreateEn();
		}
		else
		{
			nmap.SetBulPos(bx, by);
			nmap.SetAimPos(x, y);
			nmap.CreateEn();
		}
	}
	void CGamemap::OnShow()
	{
		if (isInDDoor)
		{
			//amap.OnShow();
			dmap.OnShow();
		}
		else
		{
			nmap.OnShow();
		}
		door.OnShow();
	}
	bool CGamemap::IsInSize()
	{
		return isInSize;
	}
	void CGamemap::IsInDoor()
	{
		isInNDoor = door.IsInNDoor();
		isInDDoor = door.IsInDDoor();
		isInADoor = door.IsInADoor();
		isInPDoor = door.IsInPDoor();
	}
	void CGamemap::SetAimPos(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void CGamemap::SetBulPos(int nx, int ny)
	{
		bx = nx;
		by = ny;
	}
	bool CGamemap::GetAimPos()
	{
		if (isInDDoor)
		{
			isdead = dmap.GetAimPos();
		}
		else
		{
			isdead = nmap.GetAimPos();
		}
		return isdead;
	}
}