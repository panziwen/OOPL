#pragma once
namespace game_framework
{
	class CAttack
	{
	public:
		CAttack();
		int  GetX();
		int  GetY();
		int Width();
		bool GetAttack();
		void SetAttack(bool flag);
		void SetFR(bool flag);
		void SetFL(bool flag);
		void SetFD(bool flag);
		void SetFU(bool flag);
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void BulletDisapear();
		void SetXY(int nx, int ny);
		void SetXY2();
	private:
		CMovingBitmap leftBullet;
		CMovingBitmap rightBullet;
		CAnimation bulletDisappear;
		int x, y, nx, ny, posr, posl, posu, posd;
		bool isAttack;
		bool faceL;
		bool faceR;
		bool faceU;
		bool faceD;
	};

}
