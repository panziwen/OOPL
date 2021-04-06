#pragma once
namespace game_framework
{
	class CAttack
	{
	public:
		CAttack();
		int Width();
		bool GetAttack();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void BulletDisapear();
		void SetXY(int nx, int ny);
		void Reset();
	private:
		CMovingBitmap leftBullet;
		CMovingBitmap rightBullet;
		CAnimation bulletDisappear;
		int x, y;
		bool isAttack;
		int pos;
	};

}
