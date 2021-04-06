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
		void AttackReset();
		void SetInSize(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetAttack(bool flag);
		void Reset();
	private:
		CAnimation animation;
		CAnimation isaacWalkUp;
		CAnimation isaacWalkDonw;
		CAnimation isaacWalkRight;
		CAnimation isaacWalkLeft;
		CAttack isaacAttack;

		int x, y, bullt;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isInSize;
		bool isMovingUp;
		bool isAttack;
	};
}