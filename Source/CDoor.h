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
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInDDoor();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		void SetCPos(int x, int y);
		void SetAimPos(int x, int y);
	private:
		bool isInSize;
		int x, y, tmp, dx, dy, dnx, dny;
		CDDoor ddoor;
		CNDoor ndoor;
		CADoor adoor;
		CPDoor pdoor;
		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
		void GetDPos(int x, int y, int nx, int ny);
	};
}