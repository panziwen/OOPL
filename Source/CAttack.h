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
		int  GetX2();
		int  GetY2();
		int Width();
		bool GetAttack();
		void SetAttack(bool flag);
		void SetFR(bool flag);
		void SetFL(bool flag);
		void SetFD(bool flag);
		void SetFU(bool flag);
		void Initialize();
		void LoadBitmap();
		void Times(int times);
		void OnMove();
		void OnShow();
		void SetXY(int nx, int ny);
		//void SetXY2();
	private:
		int max_bulletNmu;
		CMovingBitmap bullet;
		CAnimation bulletDisappear;
		int x, y, nx, ny, posr, posl, posu, posd;
		bool isAttack;
		bool faceL;
		bool faceR;
		bool faceU;
		bool faceD;
	};

}
