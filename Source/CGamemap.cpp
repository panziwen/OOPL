#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGamemap.h"
namespace game_framework
{
	CGamemap::CGamemap()
	{
	}
	void CGamemap::Initialize()
	{
		isInNMap = isInDMap = isInAMap = isInPMap = isDoor = false;
		nmap.Initialize();
		dmap.Initialize();
		ctr.Initialize();
	}
	void CGamemap::LoadBitmap()
	{
		nmap.LoadBitmap();
		dmap.LoadBitmap();
		pmap.LoadBitmap();
		amap.LoadBitmap();
		ctr.LoadBitmap();
	}
	void CGamemap::OnMove()
	{
		ctr.OnMove();
		nmap.CreateEn();
	}
	void CGamemap::OnShow()
	{
		nmap.SetCPos(ctr.GetX1(), ctr.GetY1(), ctr.GetX2(), ctr.GetY2());
		WhichMap();
		if (isInPMap && isDoor)
		{
			pmap.OnShow();
		}
		else if (isInDMap && isDoor)
		{
			dmap.OnShow();
		}
		else if (isInAMap && isDoor)
		{
			amap.OnShow();
		}
		else 
		{
			nmap.OnShow();
		}
		ctr.OnShow();
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
		isdead = false;
		return isdead;
	}	
	void CGamemap::SetMovingDown(bool flag)
	{
		ctr.SetMovingDown(flag);
	}

	void CGamemap::SetMovingLeft(bool flag)
	{
		ctr.SetMovingLeft(flag);
	}

	void CGamemap::SetMovingRight(bool flag)
	{
		ctr.SetMovingRight(flag);
	}

	void CGamemap::SetMovingUp(bool flag)
	{
		ctr.SetMovingUp(flag);
	}
	void CGamemap::SetAttack(bool flag, bool flag2)
	{
		ctr.SetAttack(flag, flag2);

	}
	void CGamemap::Reset()
	{
		ctr.Reset();
	}

	void CGamemap::WhichMap()
	{
		if (nmap.IsInADoor())
		{
			isInAMap = nmap.IsInADoor();
		}
		if (nmap.IsInDDoor())
		{
			isInDMap = nmap.IsInDDoor();
		}
		if (nmap.IsInPDoor())
		{
			isInPMap = nmap.IsInPDoor();
		}
		if (nmap.IsInNDoor())
		{
			isInNMap = nmap.IsInNDoor();
		}
		isDoor = nmap.IsInDoor();
	}
}