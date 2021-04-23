#include "CAttack.h"
#pragma once
namespace game_framework 
{
	class CCharaterCtrol
	{
	public:
		CCharaterCtrol();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		bool GetAttack();
		int GetBulltX();
		int GetBulltY();
		void SetInSize(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag, bool flag2);
		void SetPos(int x, int y);
		void Reset();
		void MP();
	private:
		CAnimation animation;
		CAnimation isaacWalkUp;
		CAnimation isaacWalkDonw;
		CAnimation isaacWalkRight;
		CAnimation isaacWalkLeft;
		CAttack isaacAttack;

		int x, y, nx, ny, bullt;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isInSize;
		bool isAttack;
		bool isAttack2;
	};
}