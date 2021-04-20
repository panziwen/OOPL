#include "CEnemy.h"
namespace game_framework
{
	class CPmap
	{
	public:
		CPmap();
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