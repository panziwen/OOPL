#include "CCharaterCtrol.h"
#include "CDmap.h"
#include "CNmap.h"
#include "CAmap.h"
#include "CPmap.h"
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
		bool GetAimPos();
		void WhichMap();
		void SetAimPos(int x, int y);
		void SetBulPos(int x, int y);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag, bool flag2);
		void Reset();

	private:
		int x, y, bx, by;
		CCharaterCtrol ctr;
		CDmap dmap;
		CAmap amap;
		CNmap nmap;
		CPmap pmap;
		bool isdead;
		bool isDoor;
		bool isInNMap, isInDMap, isInAMap, isInPMap;
		bool isMovingDown, isMovingLeft, isMovingRight, isMovingUp;
	};
}