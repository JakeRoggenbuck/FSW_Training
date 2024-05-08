#include <globals.h>

#include <LED/led.h>
#include <Buttons/buttons.h>
#include <print_scan.h>

#define __NOP()                             __ASM volatile ("nop")

void branch_main() {
	// space for initializations
	printer_init();

	buttons_init();

	int led_pin = 0;

	bool light_status = true;

	// infinite loop
	while (1) {
		//if (getSysTime() % 10000 < 20) {

		light_status = !light_status;
		led_pin++;

		if (led_pin > 7) {
			led_pin = 0;
			led_dx(7, 0);
		}

		for (int i = 0; i < 10000; i++) {
			nop(100);
		}
		//}

		led_a(light_status);

		led_b(!light_status);

		led_dx(led_pin - 1, 0);
		led_dx(led_pin, 1);

		/*
		if (get_buttonStatus_0()) {
			printMsg("Button 1 pressed!\r\n");
		}

		if (get_buttonStatus_1()) {
			printMsg("Button 2 pressed!\r\n");
		}
		*/
	}
	// NOTE
	// Always keep the system in the infinite while loop. Never break out of it
	// There is no place for the computer to go once you break out of this loop
}
