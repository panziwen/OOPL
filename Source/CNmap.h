#include "CEnemy.h"
namespace game_framework
{
	class CNmap
	{
	public:
		CNmap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInSize();
		void CreateEn();
		void SetAimPos(int x, int y);
		void SetBulPos(int x, int y);
		bool GetAimPos();
	private:
		bool isInSize;
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

		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
	};
}