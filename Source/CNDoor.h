namespace game_framework
{
	class CNDoor
	{
	public:
		CNDoor();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void ReSet();
		void Initialize(bool flag, bool flag2, bool flag3, bool flag4);
		void LoadBitmap();
		void OnShow();
		void OnMove();
		void SetDoor(int x, int y);
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y);
	private:
		CMovingBitmap door;
		CMovingBitmap door1;
		CMovingBitmap door2;
		CMovingBitmap door3;
		CMovingBitmap door4;
		bool isInSize;
		int x, y, cx, cy, posx, posy, tmp, dx, dy;
		bool isInDoor, u, d, l, r;
	};
}