#include "librador.h"

void main()
{
	librador_init();
	librador_setup_usb();
	librador_jump_to_bootloader();
}