namespace game_framework
{
	class CDDoor
	{
	public:
		CDDoor();
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
		CMovingBitmap door;
		int x, y, cx, cy, tmp, posx, posy;
		bool isInDoor;
	};
}