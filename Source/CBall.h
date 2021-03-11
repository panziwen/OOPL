namespace game_framework {
	
	class CBall
	{
	public:
		CBall();
		bool HitEraser(CEraser *eraser);					
		bool IsAlive();											
		void LoadBitmap();							
		void OnMove();							
		void OnShow();									
		void SetXY(int nx, int ny);					
		void SetIsAlive(bool alive);						
		void SetDelay(int d);								
	protected:
		CMovingBitmap bmp;			
		CMovingBitmap bmp_center;		
		int x, y;					
		int dx, dy;				
		int index;				
		int delay_counter;
		int delay;		
		bool is_alive;	
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	
	};
}