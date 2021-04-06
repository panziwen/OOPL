namespace game_framework
{
	class CGamemap
	{
	public:
		CGamemap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInSize();
	private:
		bool isInSize;
		CMovingBitmap map1;
		CMovingBitmap map2;
		CMovingBitmap map3;
		CMovingBitmap map4;
		CMovingBitmap map5;
		CMovingBitmap map6;
		CMovingBitmap map7;
		CMovingBitmap map8;
		CMovingBitmap map9;
	};
}