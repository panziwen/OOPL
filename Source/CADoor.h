namespace game_framework
{
	class CADoor
	{
	public:
		CADoor();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y);
	private:
		CMovingBitmap door1;
		CMovingBitmap door2;
		CMovingBitmap door3;
		CMovingBitmap door4;
		bool isInSize;
		int x, y, cx, cy, posx, posy, tmp;
		bool isInDoor;
	};
}