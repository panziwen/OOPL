#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharaterCtrol.h"
#include "CDoor.h"

namespace game_framework
{
	CDoor::CDoor()
	{
		isInSize = true;
	}
	int CDoor::GetX1()
	{
		return dx;
	}
	int CDoor::GetY1()
	{
		return dy;
	}
	int CDoor::GetX2()
	{
		return dnx;
	}
	int CDoor::GetY2()
	{
		return dny;
	}
	void CDoor::Initialize()
	{
		tmp = 1 + rand() % 100;
		isInDDoor = isInNDoor = isInADoor = isInPDoor = false;
		ddoor.Initialize();
		ndoor.Initialize();
		adoor.Initialize();
		pdoor.Initialize();
	}
	void CDoor::LoadBitmap()
	{
		ddoor.LoadBitmap();
		ndoor.LoadBitmap();
		adoor.LoadBitmap();
		pdoor.LoadBitmap();
	}
	bool CDoor::IsInADoor()
	{
		return isInADoor;
	}
	bool CDoor::IsInDDoor()
	{
		return isInDDoor;
	}
	bool CDoor::IsInNDoor()
	{
		return isInNDoor;
	}
	bool CDoor::IsInPDoor()
	{
		return isInPDoor;
	}
	void CDoor::OnShow()
	{
		if (tmp <= 70 && tmp >= 1)
		{
			ndoor.OnShow();
			isInNDoor = true;
			GetDPos(ndoor.GetX1(), ndoor.GetY1(), ndoor.GetX2(), ndoor.GetY2());
			isInDDoor = isInADoor = isInPDoor = false;
		}
		if (tmp <= 90 && tmp > 70)
		{
			pdoor.OnShow();
			isInPDoor = true;
			GetDPos(pdoor.GetX1(), pdoor.GetY1(), pdoor.GetX2(), pdoor.GetY2());
			isInDDoor = isInNDoor = isInADoor = false;
		}
		if (tmp <= 95 && tmp >= 90)
		{
			ddoor.OnShow();
			isInDDoor = true;
			GetDPos(ddoor.GetX1(), ddoor.GetY1(), ddoor.GetX2(), ddoor.GetY2());
			isInNDoor = isInADoor = isInPDoor = false;
		}
		if (tmp <= 100 && tmp > 95)
		{
			adoor.OnShow();
			isInADoor = true;
			GetDPos(adoor.GetX1(), adoor.GetY1(), adoor.GetX2(), adoor.GetY2());
			isInDDoor = isInNDoor = isInPDoor = false;
		}
	}
	void CDoor::SetAimPos(int nx, int ny)
	{
		ddoor.SetAimPos(nx, ny);
	}
	void CDoor::SetCPos(int cx, int cy)
	{
		ddoor.SetCPos(cx, cy);
	}
	void CDoor::GetDPos(int dx, int dy, int dnx, int dny)
	{
		this->dx = dx;
		this->dy = dy;
		this->dnx = dnx;
		this->dny = dny;
	}
}