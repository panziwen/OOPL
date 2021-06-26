#include "CAttack.h"
#pragma once
namespace game_framework 
{
	class CBoss
	{
	public:
		CBoss();
		~CBoss();
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
		bool GetCtrPos();
		bool GetAttack();
		bool GetDead();
		void Reset();
	private:
		int healty, bodynub;
		CAnimation animation, isaacWalkUp, isaacWalkDonw, isaacWalkRight, isaacWalkLeft;
		vector <CAnimation*>body;

		int x, y, bx, by;
		int posx, posy;
		bool isMovingDown, isMovingLeft, isMovingRight, isMovingUp;
		bool isInSize, isdead;
		bool isAttack;
		bool isAttack2;
	};
}