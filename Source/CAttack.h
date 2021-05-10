#pragma once
namespace game_framework
{
	class CAttack
	{
	public:
		CAttack();
		~CAttack();
		int  GetX();
		int  GetY();
		int Width();
		bool GetDead();
		bool GetAttack();
		void SetAttack(bool flag);
		void SetFR(bool flag);
		void SetFL(bool flag);
		void SetFD(bool flag);
		void SetFU(bool flag);
		void SetDead(bool flag);
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetXY(int nx, int ny);
		//void SetXY2();
	private:
		int max_bulletNmu;
		CMovingBitmap bullet;
		CMovingBitmap bullet1;
		CAnimation bulletDisappear;
		int x, y, nx, ny, posr, posl, posu, posd;
		bool isAttack, isdead;
		bool faceL, faceR, faceU, faceD;
	};

}
