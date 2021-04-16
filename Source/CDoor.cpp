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
		tmp = 1 + rand() % 4;
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
		/*switch (tmp)
		{
		case 1:
			ddoor.OnShow();
			isInDDoor = true;
			isInNDoor = isInADoor = isInPDoor = false;
			break;
		case 2:
			ndoor.OnShow();
			isInNDoor = true;
			isInDDoor = isInADoor = isInPDoor = false;
			break;
		case 3:
			adoor.OnShow();
			isInADoor = true;
			isInDDoor = isInNDoor = isInPDoor = false;
			break;
		case 4:
			pdoor.OnShow();
			isInPDoor = true;
			isInDDoor = isInNDoor = isInADoor = false;
			break;
		default:
			break;
		}*/
		ddoor.OnShow();
		GetDPos(ddoor.GetX1(), ddoor.GetY1(), ddoor.GetX2(), ddoor.GetY2() - 50);
		isInDDoor = true;
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