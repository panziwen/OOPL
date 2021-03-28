namespace game_framework
{
	class CInterface
	{
	public:
		CInterface();
		void OnMove();
		void BackgroundOnShow();
		void LoadBitmap();
		void BackOnMove();
	private:
		CMovingBitmap background;
		CAnimation logo;
		CAnimation bugs;
		CAnimation start;
		CAnimation a;
	};
}