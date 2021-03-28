#include "CAttack.h"
#pragma once
namespace game_framework 
{
	class CIsaac
	{
	public:
		CIsaac();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void BulletDisapear();
		void AttackReset();
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

		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isAttack;
	};
}