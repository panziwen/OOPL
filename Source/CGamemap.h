#include "CDmap.h"
#include "CNmap.h"
#include "CDoor.h"
namespace game_framework
{
	class CGamemap
	{
	public:
		CGamemap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void OnMove();
		bool IsInSize();
		void IsInDoor();
		bool GetAimPos();
		void SetAimPos(int x, int y);
		void SetBulPos(int x, int y);

	private:
		bool isInSize;
		int x, y, bx, by;
		CDmap dmap;
		CNmap nmap;
		CDoor door;
		bool isdead;
		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
	};
}