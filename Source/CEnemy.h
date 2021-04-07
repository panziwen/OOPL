#include "CAttack.h"
#pragma once
namespace game_framework 
{
	class CEnemy
	{
	public:
		CEnemy();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		bool GetAttack();
		void SetInSize(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag, bool flag2);
		void Reset();
	private:
		CAnimation animation;
		CAnimation isaacWalkUp;
		CAnimation isaacWalkDonw;
		CAnimation isaacWalkRight;
		CAnimation isaacWalkLeft;
		CAttack isaacAttack;

		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isInSize;
		bool isMovingUp;
		bool isAttack;
		bool isAttack2;
	};
}