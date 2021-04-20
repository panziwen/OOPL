#include "CEnemy.h"
//#include "CDoor.h"
namespace game_framework
{
	class CDmap
	{
	public:
		CDmap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInDoor();
		bool IsInDDoor();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		bool IsInSize();
		void CreateEn();
		void SetAimPos(int x, int y);
		void SetBulPos(int x, int y);
		bool GetAimPos();
	private:
		bool isInSize;
		int px, py, pnx, pny;
		int x, y, bx, by;
		CEnemy enemy;
		//CDoor door;
		CMovingBitmap map1;
		CMovingBitmap map2;
		CMovingBitmap map3;
		CMovingBitmap map4;
		CMovingBitmap map5;
		CMovingBitmap map6;
		CMovingBitmap map7;
		CMovingBitmap map8;
		CMovingBitmap map9;
		CMovingBitmap mapd;

		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
		bool isDoor;
	};
}