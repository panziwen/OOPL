#include "CEnemy.h"
#include "CDoor.h"
namespace game_framework
{
	class CNmap
	{
	public:
		CNmap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void CreateEn();
		bool IsInDDoor();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		bool IsInDoor();
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y, int nx, int ny);
		void SetBulPos(int x, int y);
		bool GetAimPos();
	private:
		int px, py, pnx, pny;
		int x, y, bx, by;
		CEnemy enemy;
		CDoor door;
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
		bool isDoor;

		void GetDoor();
	};
}