#include "CEnemy.h"
#include "CEnemy1.h"
#include "CEnemy2.h"
#include "CEnemy3.h"
#include "CBoss.h"
#include "CDoor.h"
namespace game_framework
{
	class CNmap
	{
	public:
		CNmap();
		~CNmap();
		void Initialize(bool flag, bool flag2, bool flag3, bool flag4, bool flag5);
		void LoadBitmap();
		void OnShow();
		void Reset();
		void BossIntetface();
		void CreateEn();
		void IsPdead(bool flag);
		bool IsInDDoor();
		bool Up();
		bool Down();
		bool Left();
		bool Right();
		bool IsBoss();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		bool IsInDoor();
		bool IsBDead();
		void SetDead(bool falg);
		void SetDoor(int x, int y);
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y, int nx, int ny);
		void SetBulPos(int x, int y);
		bool GetAimPos();
		bool GetCtrPos();
	private:
		int px, py, pnx, pny, enemyNum, item,k1,k2,k3,k4,k5;
		int x, y, bx, by;
		int enemyType;
		vector<CEnemy*> enemy;
		vector<CEnemy1*> enemy1;
		vector<CEnemy2*> enemy2;
		vector<CBoss*>boss;
		CDoor *door;
		CAnimation bossInterface;
		CMovingBitmap map1, map2, map3, map4, map5, map6, map7, map8, map9;
		CMovingBitmap map11, map22, map33, map44, map55, map66, map77, map88, map99;

		bool isDoor;
		bool isdead, isbdead, ispdead;
		bool isInNDoor, isInDDoor, isInADoor, isInPDoor, isboss;
		void KillBoss(int x);
		void KillEnemy(int x);
		void KillEnemy1(int x);
		void KillEnemy2(int x);
	};
}