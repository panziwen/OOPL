#include "CEnemy.h"
//#include "CDoor.h"
namespace game_framework
{
	class CAmap
	{
	public:
		CAmap();
		void Initialize();
		void LoadBitmap();
		bool IsInDoor();
		void OnShow();
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

		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
		bool isDoor;
	};
}