#include "CAttack.h"
#pragma once
namespace game_framework 
{
	class CEnemy2
	{
	public:
		CEnemy2();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Healty();
		void Initialize();
		void LoadBitmap();
		bool GetAimPos();
		void SetXY(int x, int y);
		void SetBulXY(int x, int y);
		void OnMove();
		void OnShow();
		bool GetAttack();
		bool GetDead();
		/*void SetInSize(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag, bool flag2);*/
		void Reset();
	private:
		int healty;
		CAnimation animation, isaacWalkUp, isaacWalkDonw, isaacWalkRight, isaacWalkLeft;

		int x, y, bx, by;
		int posx, posy;
		bool isMovingDown, isMovingLeft, isMovingRight, isMovingUp;
		bool isInSize, isdead;
		bool isAttack;
		bool isAttack2;
	};
}