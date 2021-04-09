#include "CDDoor.h"
#include "CNDoor.h"
#include "CADoor.h"
#include "CPDoor.h"
namespace game_framework
{
	class CDoor
	{
	public:
		CDoor();
		void Initialize();
		void LoadBitmap();
		void OnShow();
		bool IsInSize();
		bool IsInDDoor();
		bool IsInNDoor();
		bool IsInPDoor();
		bool IsInADoor();
		void SetCPos(int x, int y);
		void SetAimPos(int x, int y);
	private:
		bool isInSize;
		int x, y;
		CDDoor ddoor;
		CNDoor ndoor;
		CADoor adoor;
		CPDoor pdoor;
		bool isInNDoor;
		bool isInDDoor;
		bool isInADoor;
		bool isInPDoor;
	};
}