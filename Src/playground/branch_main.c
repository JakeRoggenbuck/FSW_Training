#include <globals.h>

#include <LED/led.h>
#include <Buttons/buttons.h>
#include <print_scan.h>

void branch_main() {
	// space for initializations
	printer_init();

	buttons_init();

	bool light_status = true;

	// infinite loop
	while (1) {
		if (getSysTime() % 1000 == 0) {
			light_status = !light_status;
			led_a(light_status);
		}

		if (get_buttonStatus_1()) {
			printMsg("Button 1 pressed!\r\n");
		}

		if (get_buttonStatus_2()) {
			printMsg("Button 2 pressed!\r\n");
		}
	}

	// NOTE
	// Always keep the system in the infinite while loop. Never break out of it
	// There is no place for the computer to go once you break out of this loop
}
