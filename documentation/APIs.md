API breakage
------------

version 0.98
- Some directories have been shifted around
- You only need to include <SmartServoFramework/SimpleAPI.h> or <SmartServoFramework/ManagedAPI.h> directly in your project now

version 0.97
- DynamixelController() and HerkuleXController() params order have changed (now in line with the SimpleAPI)
- GUI settings folder has changed
- library name is not lowercase (smartservoframework)

version 0.96
- Needs more recent compiler (more C++11)
- Needs Qt5 for the SmartServoGui
