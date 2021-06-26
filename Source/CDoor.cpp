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
		ndoor = new CNDoor();
		tmp = 1 + rand() % 100;
		tmp = 65;
		isInSize = true;
	}
	CDoor::~CDoor()
	{
		delete ndoor;
	}
	void CDoor::Initialize(bool flag, bool flag2, bool flag3, bool flag4)
	{
		GetDPos(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		isInDDoor = isInNDoor = isInADoor = isInPDoor = false;
		isUp = isDown = isLeft = isRight = false;
		ddoor.Initialize();
		ndoor->Initialize(flag, flag2, flag3, flag4);
		adoor.Initialize();
		pdoor.Initialize();
	}
	void CDoor::LoadBitmap()
	{
		ddoor.LoadBitmap();
		ndoor->LoadBitmap();
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

	bool CDoor::Up()
	{
		return isUp;
	}
	bool CDoor::Down()
	{
		return isDown;
	}
	bool CDoor::Left()
	{
		return isLeft;
	}
	bool CDoor::Right()
	{
		return isRight;
	}
	void CDoor::SetDoor(int x, int y)
	{
		ndoor->SetDoor(x, y);
	}
	void CDoor::OnMove()
	{
		ndoor->OnMove();
	}
	void CDoor::OnShow()
	{
		if (tmp <= 70 && tmp >= 1)
		{
			ndoor->OnShow();
			isInNDoor = true;
			GetDPos(ndoor->GetUX1(), ndoor->GetUY1(), ndoor->GetUX2(), ndoor->GetUY2(), ndoor->GetDX1(), ndoor->GetDY1(), ndoor->GetDX2(), ndoor->GetDY2(), ndoor->GetRX1(), ndoor->GetRY1(), ndoor->GetRX2(), ndoor->GetRY2(), ndoor->GetLX1(), ndoor->GetLY1(), ndoor->GetLX2(), ndoor->GetLY2());
			isInDDoor = isInADoor = isInPDoor = false;
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
	void CDoor::GetDPos(int dx, int dy, int dnx, int dny, int dx2, int dy2, int dnx2, int dny2, int dx3, int dy3, int dnx3, int dny3, int dx4, int dy4, int dnx4, int dny4)
	{
		this->dx1 = dx;
		this->dy1 = dy;
		this->dnx1 = dnx;
		this->dny1 = dny;
		this->dx2 = dx2;
		this->dy2 = dy2;
		this->dnx2 = dnx2;
		this->dny2 = dny2;
		this->dx3 = dx3;
		this->dy3 = dy3;
		this->dnx3 = dnx3;
		this->dny3 = dny3;
		this->dx4 = dx4;
		this->dy4 = dy4;
		this->dnx4 = dnx4;
		this->dny4 = dny4;
		if (dx1 == (SIZE_X / 2 - 50) && dy1 == 15)
		{
			isUp = true;
			isDown = isLeft = isRight = false;
		}
		else if (this->dx2 == (SIZE_X / 2 - 50) && this->dy2 == (SIZE_Y - 110))
		{
			isDown = true;
			isUp = isLeft = isRight = false;
		}
		else if (this->dx3 == (SIZE_X - 145) && this->dy3 == (SIZE_Y / 2))
		{
			isRight = true;
			isUp = isDown = isLeft = false;
		}
		else if (this->dx4 == 110 && this->dy4 == (SIZE_Y / 2))
		{
			isLeft = true;
			isUp = isDown = isRight = false;
		}
	}
	int CDoor::GetUX1()
	{
		return dx1;
	}
	int CDoor::GetUY1()
	{
		return dy1;
	}
	int CDoor::GetUX2()
	{
		return dnx1;
	}
	int CDoor::GetUY2()
	{
		return dny1;
	}
	int CDoor::GetDX1()
	{
		return dx2;
	}
	int CDoor::GetDY1()
	{
		return dy2;
	}
	int CDoor::GetDX2()
	{
		return dnx2;
	}
	int CDoor::GetDY2()
	{
		return dny2;
	}
	int CDoor::GetRX1()
	{
		return dx3;
	}
	int CDoor::GetRY1()
	{
		return dy3;
	}
	int CDoor::GetRX2()
	{
		return dnx3;
	}
	int CDoor::GetRY2()
	{
		return dny3;
	}
	int CDoor::GetLX1()
	{
		return dx4;
	}
	int CDoor::GetLY1()
	{
		return dy4;
	}
	int CDoor::GetLX2()
	{
		return dnx4;
	}
	int CDoor::GetLY2()
	{
		return dny4;
	}
}