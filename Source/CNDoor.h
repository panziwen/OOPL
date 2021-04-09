namespace game_framework
{
	class CNDoor
	{
	public:
		CNDoor();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInSize();
		bool IsInDoor();
		void SetAimPos(int x, int y);
		void SetCPos(int x, int y);
	private:
		CMovingBitmap door;
		bool isInSize;
		int x, y, cx, cy;
		bool isInDoor;
	};
}