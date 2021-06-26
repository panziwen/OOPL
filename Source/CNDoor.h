namespace game_framework
{
	class CNDoor
	{
	public:
		CNDoor();
		int  GetUX1();
		int  GetUY1();
		int  GetUX2();
		int  GetUY2();
		int  GetDX1();
		int  GetDY1();
		int  GetDX2();
		int  GetDY2();
		int  GetRX1();
		int  GetRY1();
		int  GetRX2();
		int  GetRY2();
		int  GetLX1();
		int  GetLY1();
		int  GetLX2();
		int  GetLY2();
		void ReSet();
		void Initialize(bool flag, bool flag2, bool flag3, bool flag4);
		void LoadBitmap();
		void OnShow();
		void OnMove();
		void SetDoor(int x, int y);
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y);
		bool Up();
		bool Down();
		bool Right();
		bool Left();
	private:
		CMovingBitmap door;
		CMovingBitmap door1;
		CMovingBitmap door2;
		CMovingBitmap door3;
		CMovingBitmap door4;
		bool isInSize;
		int x, y, cx, cy, tmp, dx, dy;
		int posxu, posyu, posxr, posyr, posxl, posyl, posxd, posyd;
		bool isInDoor, u, d, l, r;
	};
}