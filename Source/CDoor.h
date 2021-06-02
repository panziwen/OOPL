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
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
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
		int x, y, tmp, dx, dy, dnx, dny;
		CDDoor ddoor;
		CNDoor *ndoor;
		CADoor adoor;
		CPDoor pdoor;
		bool isInNDoor, isInDDoor, isInADoor, isInPDoor;
		bool isUp, isDown, isLeft, isRight;
		void GetDPos(int x, int y, int nx, int ny);
	};
}