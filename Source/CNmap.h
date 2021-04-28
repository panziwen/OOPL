#include "CEnemy.h"
#include "CDoor.h"
namespace game_framework
{
	class CNmap
	{
	public:
		CNmap();
		~CNmap();
		void Initialize();
		void LoadBitmap();
		void LoadBitmap2();
		void OnShow();
		void OnShow2();
		void CreateEn();
		bool IsInDDoor();
		bool Up();
		bool Down();
		bool Left();
		bool Right();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		bool IsInDoor();
		void SetDoor(int x, int y);
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y, int nx, int ny);
		void SetBulPos(int x, int y);
		bool GetAimPos();
	private:
		int px, py, pnx, pny, enemyNum, item;
		int x, y, bx, by;
		vector<CEnemy*> enemy;
		CDoor *door;
		CMovingBitmap map1, map2, map3, map4, map5, map6, map7, map8, map9;
		CMovingBitmap map11, map22, map33, map44, map55, map66, map77, map88, map99;

		bool isDoor;
		bool isInNDoor, isInDDoor, isInADoor, isInPDoor;
		void GetDoor();
	};
}