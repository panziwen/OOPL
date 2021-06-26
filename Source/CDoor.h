#include "CDDoor.h"
#include "CNDoor.h"
#include "CADoor.h"
#include "CPDoor.h"
namespace game_framework
{
	class CDoor
	{
	public:
		CDoor();
		~CDoor();
		int  GetUX1();
		int  GetUY1();
		int  GetUX2();
		int  GetUY2();
		int  GetDX1();
		int  GetDY1();
		int  GetDX2();
		int  GetDY2();
		int  GetRX1();
		int  GetRY1();
		int  GetRX2();
		int  GetRY2();
		int  GetLX1();
		int  GetLY1();
		int  GetLX2();
		int  GetLY2();
		void Initialize(bool flag, bool flag2, bool flag3, bool flag4);
		void LoadBitmap();
		void OnShow();
		void OnMove();
		bool IsInDDoor();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		bool Up();
		bool Down();
		bool Left();
		bool Right();
		void SetDoor(int x, int y);
		void SetCPos(int x, int y);
		void SetAimPos(int x, int y);
	private:
		bool isInSize;
		int x, y, tmp;
		int  dx1, dy1, dnx1, dny1;
		int  dx2, dy2, dnx2, dny2;
		int  dx3, dy3, dnx3, dny3;
		int  dx4, dy4, dnx4, dny4;
		CDDoor ddoor;
		CNDoor *ndoor;
		CADoor adoor;
		CPDoor pdoor;
		bool isInNDoor, isInDDoor, isInADoor, isInPDoor;
		bool isUp, isDown, isLeft, isRight;
		void GetDPos(int dx, int dy, int dnx, int dny, int dx2, int dy2, int dnx2, int dny2, int dx3, int dy3, int dnx3, int dny3, int dx4, int dy4, int dnx4, int dny4);
	};
}