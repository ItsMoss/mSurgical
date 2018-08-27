#ifndef __SCREENS_H__
#define __SCREENS_H__

// enumeration for each of the screen types (i.e. pages) for mSurgical
// order matters as it corresponds with page index in ui.screensStackWidget
enum class mScreen {
	Login,				// surgeon login
	Menu,				// menu
	OR,					// operating room (main gameplay)
	Learn,				// learn new surgeries
	HiScore				// view high scores
};

#endif // __SCREENS_H__