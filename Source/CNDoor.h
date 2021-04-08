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
		void IsInDoor();
		void SetAimPos(int x, int y);
	private:
		bool isInSize;
		int x, y;
		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
	};
}