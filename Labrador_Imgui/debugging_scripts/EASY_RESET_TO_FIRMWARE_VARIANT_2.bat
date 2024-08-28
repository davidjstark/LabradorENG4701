start ..\..\JumpToBootloader\x64\Release\JumpToBootloader.exe
TIMEOUT /T 3
cd "C:\Program Files\EspoTek\EspoTek Labrador\firmware"
dfu-programmer atxmega32a4u erase --force
dfu-programmer atxmega32a4u flash labrafirm_0006_02.hex
dfu-programmer atxmega32a4u launch
TIMEOUT /T 2
dfu-programmer atxmega32a4u launch