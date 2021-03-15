namespace game_framework
{
	class CInterface
	{
	public:
		CInterface();
		void OnMove();
		void BackgroundOnShow();
		void LogoOnShow();
		void LoadBitmap();
	private:
		CMovingBitmap background;
		CAnimation logo;
		CAnimation bugs;
		CAnimation start;

	};
}