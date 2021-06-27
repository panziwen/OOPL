/*
 * mygame.cpp: ¥»ÀÉ®×Àx¹CÀ¸¥»¨­ªºclassªºimplementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ³o­Óclass¬°¹CÀ¸ªº¹CÀ¸¶}ÀYµe­±ª«¥ó
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g)
	: CGameState(g)
	{
		isbdead = false;
	}

	void CGameStateInit::OnInit()
	{		
		ShowInitProgress(0);
		gameinterface.LoadBitmap();
		Sleep(300);
	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
		{
			GotoGameState(GAME_STATE_RUN);
		}// ¤Á´«¦ÜGAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo Ãö³¬¹CÀ¸ªº¤èªk
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// Ãö³¬¹CÀ¸
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// ¤Á´«¦ÜGAME_STATE_RUN
	}
	void CGameStateInit::OnMove()
	{
		gameinterface.OnMove();
	}

	void CGameStateInit::OnShow()
	{
		gameinterface.BackgroundOnShow();


		CDC *pDC = CDDraw::GetBackCDC();			// ¨ú±o Back Plain ªº CDC 
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");	// ²£¥Í font f; 160ªí¥Ü16 pointªº¦r
		fp=pDC->SelectObject(&f);					// ¿ï¥Î font f
		pDC->SetBkColor(RGB(0,0,0));
		pDC->SetTextColor(RGB(255,255,0));
		pDC->TextOut(5, 220, "Please click mouse or press SPACE to begin.");
		pDC->TextOut(5, 245, "Instructor: ê´Th");
		pDC->TextOut(5, 275, "Author: ÅË×ÓÎÄ&„¢˜s");
		pDC->TextOut(5, 305, "Press W A S D to move");
		pDC->TextOut(5, 335, "Press K to the BOOS");
		pDC->TextOut(5, 365, "After entering the game, press the SPACE bar to shoot.");
		pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
		pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);						// ©ñ±¼ font f (¤d¸U¤£­nº|¤F©ñ±¼)
		CDDraw::ReleaseBackCDC();					// ©ñ±¼ Back Plain ªº CDC
	}								

	/////////////////////////////////////////////////////////////////////////////
	// ³o­Óclass¬°¹CÀ¸ªºµ²§ôª¬ºA(Game Over)
	/////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame *g)
	: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		gameover.OnMove();
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 5; // 5 seconds
	}

	void CGameStateOver::OnInit()
	{
		gameover.LoadBitmapA();
		ShowInitProgress(66);	
		Sleep(300);		
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		Sleep(100);
		gameover.BackOnShow2();
	}


	CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g), NUMBALLS(28)
	{
	}

	CGameStateRun::~CGameStateRun()
	{

	}

	void CGameStateRun::OnBeginState()
	{
		CAudio::Instance()->Play(AUDIO_ISAAC2, true);
		gamemap.SetPAlive(false);
		counter = 30 * 5; // 5 seconds
	}

	void CGameStateRun::OnMove()
	{
		gameover.OnMove();
		counter--;
		if (counter < 0)
		{
			gamemap.SetPAlive(false);
			GotoGameState(GAME_STATE_RUN);
		}

		gamemap.OnMove();
		if (gamemap.GetAimPos())
		{
			if (gamemap.IsBDead())
			{
				GotoGameState(GAME_STATE_OVER);
			}
		}
	}

	void CGameStateRun::OnInit()  			
	{
		gamemap.Initialize();
		gameover.LoadBitmap();
		gamemap.LoadBitmap();
		Sleep(300); 							
		CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	
		CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");
		CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");
		CAudio::Instance()->Load(AUDIO_ISAAC, "sounds\\walk.mp3");
		CAudio::Instance()->Load(AUDIO_ISAAC2, "sounds\\isaac2.mid");
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; 
		const char KEY_UP = 0x26; 
		const char KEY_RIGHT = 0x27; 
		const char KEY_DOWN = 0x28;
		const char KEY_SPACE = ' ';
		const char KEY_W = 'W'; 
		const char KEY_A = 'A'; 
		const char KEY_S = 'S';
		const char KEY_D = 'D';
		const char KEY_K = 'K';
		CAudio::Instance()->Play(AUDIO_ISAAC);

		if (nChar == KEY_LEFT || nChar == KEY_A)
		{
			gamemap.SetMovingLeft(true);
		}
		if (nChar == KEY_RIGHT || nChar == KEY_D)
		{
			gamemap.SetMovingRight(true);
		}
		if (nChar == KEY_UP || nChar == KEY_W)
		{
			gamemap.SetMovingUp(true);
		}
		if (nChar == KEY_DOWN || nChar == KEY_S)
		{
			gamemap.SetMovingDown(true);
		}
		if (nChar == KEY_K)
		{
			gamemap.Key(true);
		}
		if (nChar == KEY_SPACE)
		{
			gamemap.SetAttack(true, true);
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25; 
		const char KEY_UP    = 0x26; 
		const char KEY_RIGHT = 0x27; 
		const char KEY_DOWN  = 0x28;
		const char KEY_SPACE = ' ';
		const char KEY_W = 'W';
		const char KEY_A = 'A';
		const char KEY_S = 'S';
		const char KEY_D = 'D';
		const char KEY_K = 'K';

		CAudio::Instance()->Stop(AUDIO_ISAAC);
		if (nChar == KEY_LEFT || nChar == KEY_A)
		{
			gamemap.SetMovingLeft(false);
		}
		if (nChar == KEY_RIGHT || nChar == KEY_D)
		{
			gamemap.SetMovingRight(false);
		}
		if (nChar == KEY_UP || nChar == KEY_W)
		{
			gamemap.SetMovingUp(false);
		}
		if (nChar == KEY_DOWN || nChar == KEY_S)
		{
			gamemap.SetMovingDown(false);
		}
		if (nChar == KEY_SPACE)
		{
			gamemap.SetAttack(false, true);
		}
		if (nChar == KEY_K)
		{
			gamemap.Key(false);
		}
		gamemap.Reset();
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // ³B²z·Æ¹«ªº°Ê§@
	{
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// ³B²z·Æ¹«ªº°Ê§@
	{
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// ³B²z·Æ¹«ªº°Ê§@
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // ³B²z·Æ¹«ªº°Ê§@
	{
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// ³B²z·Æ¹«ªº°Ê§@
	{
	}

	void CGameStateRun::OnShow()
	{
		gamemap.OnShow();
		CDC *pDC = CDDraw::GetBackCDC();			// ¨ú±o Back Plain ªº CDC 
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// ²£¥Í font f; 160ªí¥Ü16 pointªº¦r
		fp = pDC->SelectObject(&f);					// ¿ï¥Î font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(133, 132, 132));
		pDC->TextOut(50, 100, "00 ");
		pDC->TextOut(50, 130, "00 ");
		pDC->TextOut(50, 160, "00 ");
		pDC->TextOut(50, 190, "1.00 ");
		pDC->TextOut(50, 220, "23.75 ");
		pDC->TextOut(50, 250, "10 ");
		pDC->TextOut(50, 280, "1.00 ");
		pDC->TextOut(50, 310, "3.5 ");
		pDC->TextOut(50, 340, "0.00 ");
		pDC->TextOut(50, 370, "0.00% ");
		pDC->TextOut(50, 400, "0.00% ");
		pDC->SelectObject(fp);						// ©ñ±¼ font f (¤d¸U¤£­nº|¤F©ñ±¼)
		CDDraw::ReleaseBackCDC();
		if (gamemap.IsPDead())
		{
			gameover.BackOnShow();
			CDC *pDC = CDDraw::GetBackCDC();
			CFont f, *fp;
			f.CreatePointFont(160, "Times New Roman");
			fp = pDC->SelectObject(&f);
			pDC->SetBkColor(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(255, 255, 0));
			char str[80];
			sprintf(str, "You Dead ! (%d)", counter / 30);
			pDC->TextOut(440, 250, str);
			pDC->SelectObject(fp);
			CDDraw::ReleaseBackCDC();
		}
	}
}