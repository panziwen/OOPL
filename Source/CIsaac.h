#pragma once
namespace game_framework 
{
	class CIsaac
	{
	public:
		CIsaac();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetXY(int nx, int ny);
		void Reset();
	private:
		CAnimation animation;
		CAnimation isaacWalkUp;
		CAnimation isaacWalkDonw;
		CAnimation isaacWalkRight;
		CAnimation isaacWalkLeft;
		list<CMovingBitmap>				bmp;
		list<CMovingBitmap>::iterator	bmp_iter;

		int x, y;
		char *filenameDown[9];
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
	};
}