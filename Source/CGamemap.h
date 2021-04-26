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
		void WhichMap();
		void SetAimPos();
		void SetBulPos(int x, int y);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag, bool flag2);
		void Reset();

	private:
		int x, y, bx, by, fx, fy;
		vector<vector<CNmap*>> a;
		CCharaterCtrol ctr;
		bool isdead;
		bool isDoor;
		bool isInNMap, isInDMap, isInAMap, isInPMap;
		bool isMovingDown, isMovingLeft, isMovingRight, isMovingUp;
	};
}