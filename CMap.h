namespace game_framework
{
	class CMap
	{
	public:
		CMap();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		//~CMap();

	private:
		CMovingBitmap map;
	};
}