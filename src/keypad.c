#include "keypad.h"
#include "verbose.h"
#include "pgpio.h"
#include "machine_specific.h"

#include <string.h>

void keypad_setup(struct keypad *keypad, int pins[]) {
	ASSERTDO((keypad != NULL), print_error("keypad_setup: keypad is null.\n"); return);
	ASSERTDO((pins != NULL), print_error("keypad_setup: pins is null.\n"); return);

	for (int i = 0; i < N_PINS; ++i) {
		ASSERTDO((rows[i] >= 0), print_error("keypad_setup: pins[%d] cannot be under zero.\n", i); return);
	}

	/* initialize */
	keypad->initialized = false;

	memset(keypad->pins, 0, sizeof(int) * N_PINS);
	
	keypad->callback = NULL;

	/* assign */
	for (int i = 0; i < N_PINS; ++i) {
		keypad->pins[i] = pins[i];
	}

	gpio_setup();

	// Newly added
	pinv_mode(keypad->pins, N_PIN, PGPIO_INPUT_PULLUP);

	keypad->initialized = true;
}

void keypad_set_listener(struct keypad *keypad, keypad_listener listener) {
	ASSERTDO((keypad != NULL), print_error("keypad_set_listener: keypad is null.\n"); return);
	
	if (listener != NULL) {
		keypad->callback = listener;
	}
}

int keypad_read(struct keypad *keypad) {
	ASSERTDO((keypad != NULL), print_error("keypad_read: keypad is null.\n"); return -1);
	
	for (int i = 0; i < N_PINS; ++i) {
		if (digital_read(keypad->pins[i]) == 0) {
			return i;
		}
	}

	return -1;
}
	

bool keypad_loop(struct keypad *keypad) {
	ASSERTDO((keypad != NULL), print_error("keypad_loop: keypad is null.\n"); return false);

	static bool pressed = false;

	if (keypad->callback != NULL) {
		int read = keypad_read(keypad);
		
		if (read != -1) { 
			/* something is pressed. */

			if (!pressed) {
				/* has something pushed just now. */
				keypad->callback(read);
		
				pressed = true;
			} else {
				/* being kept pressed. do nothing. */
			}

		} else {
			/* read nothing. of cource not pressed. */
			pressed = false;
		}
	}

	return true;
}
