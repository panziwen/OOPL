#include "CCharaterCtrol.h"
#include "CNmap.h"
namespace game_framework
{
	class CGamemap
	{
	public:
		CGamemap();
		~CGamemap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void OnMove();
		bool GetAimPos();
		bool IsPDead();
		bool IsBDead();
		bool MapE();
		void WhichMap();
		void SetAimPos();
		void SetBulPos();
		void SetDoor(int i, int j);
		void SetPAlive(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void Key(bool flag);
		void Delete();
		void SetAttack(bool flag, bool flag2);
		void Reset();

	private:
		void UI();
		int x, y, bx, by, fx, fy, doorNum, mapnub;
		CMovingBitmap map,ui1[14];
		vector<vector<CNmap*>> a;
		CCharaterCtrol *ctr;
		bool isdead, ispdead, isKey;
		bool isDoor, u, d, l, r, isboss;
		bool isInNMap, isInDMap, isInAMap, isInPMap;
		bool isMovingDown, isMovingLeft, isMovingRight, isMovingUp;
	};
}