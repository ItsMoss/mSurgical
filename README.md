# mSurgical
A game where you compete to be the best surgeon using the Mona Laser robotic system

## Gameplay
* Play as a surgeon to perform multiple surgeries
* Surgeries are 2-button sequences that you must memorize
* Four (4) buttons (i.e. tools) are available for surgeon to use
* Player has option for 4 buttons to be `IJKL` OR `WASD`
* Learn and memorize up to 16 surgeries and their 2-button sequences
* Head to the Operating Room and execute the correct surgery for continuously incoming patients
* Time is of the essence, you have 10 seconds to execute a surgery's 2-button sequence correctly
* Earn more points for performing surgeries quickly and for knowing more surgeries
* Timeout or incorrect surgery results in game over
* Compete to be on top 3
* Surgeon data is saved in database, including name, known surgeries, and high score
* Good luck!

## Running .exe
The `deploy/` folder has everything necessary to run the application.  There is an `generateSurgery.py` file that can optionally be used within the app to generate new surgeries. If you turn on this option within the game make sure to have Python3 installed on your system and it's install path added to system path environment variable. Successfully tested running app on multiple Windows platforms with and without Python option.

## Tools
App built via Visual Studio 2017, Qt 5.10.1, SQLite

## Folder Organization
* `deploy` - folder containing all files necessary to run app (`mSurgical.exe`)
* `mSurgical` - project folder containing project files and `main.cpp`
* `resource` - contains images used in app
* `src` - all header and source files for the app
* `src/mvc` - files related to model, view, controlller
* `src/util` - all other files for app

