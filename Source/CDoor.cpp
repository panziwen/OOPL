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
	void CDoor::Initialize()
	{
		isInDDoor = isInNDoor = isInADoor = isInDDoor = false;
		ddoor.Initialize();
		ndoor.Initialize();
	}
	void CDoor::LoadBitmap()
	{
		ddoor.LoadBitmap();
		ndoor.LoadBitmap();
	}
	void CDoor::OnShow()
	{
		if (isInDDoor)
		{
			ddoor.OnShow();
		}
		else
		{
			ddoor.OnShow();
		}
	}
	bool CDoor::IsInSize()
	{
		return isInSize;
	}
	bool CDoor::IsInADoor()
	{
		return isInADoor;
	}
	bool CDoor::IsInDDoor()
	{
		return ddoor.IsInDoor();
	}
	bool CDoor::IsInNDoor()
	{

		return isInNDoor;
	}
	bool CDoor::IsInPDoor()
	{
		return isInPDoor;
	}

	void CDoor::SetAimPos(int nx, int ny)
	{
		ddoor.SetAimPos(nx, ny);
	}
	void CDoor::SetCPos(int cx, int cy)
	{
		ddoor.SetCPos(cx, cy);
	}
}