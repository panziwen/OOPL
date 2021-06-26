namespace game_framework
{
	class CGameOver
	{
	public:
		CGameOver();
		void OnMove();
		void LoadBitmap();
		void BackOnShow();
		void BackOnShow2();
	private:
		CAnimation background;
		CAnimation background2;
		CMovingBitmap a, b;
	};
}