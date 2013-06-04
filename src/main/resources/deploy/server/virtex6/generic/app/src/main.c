/**
 * Main of the board-side application.
 *
 * Initialises the boards components and starts the scheduling loop.
 *
 * @file
 * @author Thomas Fischer
 * @since 01.02.2013
 */

// forward declarations
void init_platform();
void init_medium();
void init_components();
void init_queue();

void start_application();
void schedule();

void reset_components();
void reset_queues();

void cleanup_platform();

/**
 * Resets all components and corresponding queues.
 */
void reset() {
    reset_components();
    reset_queues();
}

/**
 * Initialises components and starts scheduling loop.
 * @return 0 if terminated succesfully, 1 otherwise.
 */
int main() {
	// initialise the platform. This also sets up the interrupt controller
	init_platform();

	// initialise Ethernet
	init_medium();

	// initialise all components
	init_components();

	// perform medium-specific startup operations (TODO merge with init?)
	start_application();

	// start the scheduler
	schedule();

	// never reached
	cleanup_platform();

	return 0;
}
