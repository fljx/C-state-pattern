#include <stdio.h>
#include "fsm.h"


// ======================================


int main ( int argc, char *argv[] )
{
	fsm_state	state = { .action = printer_setup };
	event		evt	= { .id = 0, .arg = NULL };


	printf ( "| == ----      State Pattern FSM.       ---- == |\n" );

	for ( int i = 0; state.action != printer_error && 100 > i; ++i )
	{
// 		printf ( "| == ---- FSM run #%d. ---- == |\n", i );
		state = state.action( &evt );

// 		if ( state.action == printer_idle )
// 			state = { .action = printer_setup };
	}
}

/*
-----------------------------------------
/home/jaques/projects/ControlID/iDPrint/software/git/idprint-sw/testing/state_pattern/build> /home/jaques/projects/ControlID/iDPrint/software/git/idprint-sw/testing/state_pattern/build/state_pattern

| == ----      State Pattern FSM.       ---- == |
[printer_setup] Setup. evt->id = 0.
[printer_idle] Idle. evt->id = 0.
[printer_idle] Idle. evt->id = 1.
[printer_idle] Idle. evt->id = 2.
[printer_idle] Idle. evt->id = 3.
[printer_print_line] Print. evt->id = 4.
[prepare_to_print] Prepare to print. evt->id = 4.
[run_printing] Run printing. evt->id = 4.
[run_printing] Run printing. evt->id = 5.
[run_printing] Run printing. evt->id = 6.
[run_printing] Run printing. evt->id = 7.
[stop_printing] Stop printing. evt->id = 8.
[printer_cut] Cut. evt->id = 8.
[printer_idle] Idle. evt->id = 9.
[printer_idle] Idle. evt->id = 10.
[printer_idle] Idle. evt->id = 11.
[printer_print_line] Print. evt->id = 12.
[prepare_to_print] Prepare to print. evt->id = 12.
[run_printing] Run printing. evt->id = 12.
[run_printing] Run printing. evt->id = 13.
[run_printing] Run printing. evt->id = 14.
[run_printing] Run printing. evt->id = 15.
[stop_printing] Stop printing. evt->id = 16.
[printer_cut] Cut. evt->id = 16.
[printer_idle] Idle. evt->id = 17.
[printer_idle] Idle. evt->id = 18.
[printer_idle] Idle. evt->id = 19.
[printer_print_line] Print. evt->id = 20.
[prepare_to_print] Prepare to print. evt->id = 20.
[run_printing] Run printing. evt->id = 20.
[run_printing] Run printing. evt->id = 21.
[run_printing] Run printing. evt->id = 22.
[run_printing] Run printing. evt->id = 23.
[stop_printing] Stop printing. evt->id = 24.
[printer_cut] Cut. evt->id = 24.
[printer_idle] Idle. evt->id = 25.
[printer_idle] Idle. evt->id = 26.
[printer_idle] Idle. evt->id = 27.
[printer_print_line] Print. evt->id = 28.
[prepare_to_print] Prepare to print. evt->id = 28.
[run_printing] Run printing. evt->id = 28.
[run_printing] Run printing. evt->id = 29.
[run_printing] Run printing. evt->id = 30.
[run_printing] Run printing. evt->id = 31.
[stop_printing] Stop printing. evt->id = 32.
[printer_cut] Cut. evt->id = 32.
[printer_idle] Idle. evt->id = 33.
[printer_idle] Idle. evt->id = 34.
[printer_idle] Idle. evt->id = 35.
[printer_print_line] Print. evt->id = 36.
[prepare_to_print] Prepare to print. evt->id = 36.
[run_printing] Run printing. evt->id = 36.
[run_printing] Run printing. evt->id = 37.
[run_printing] Run printing. evt->id = 38.
[run_printing] Run printing. evt->id = 39.
[stop_printing] Stop printing. evt->id = 40.
[printer_cut] Cut. evt->id = 40.
[printer_idle] Idle. evt->id = 41.
[printer_idle] Idle. evt->id = 42.
[printer_idle] Idle. evt->id = 43.
[printer_print_line] Print. evt->id = 44.
[prepare_to_print] Prepare to print. evt->id = 44.
[run_printing] Run printing. evt->id = 44.
[run_printing] Run printing. evt->id = 45.
[run_printing] Run printing. evt->id = 46.
[run_printing] Run printing. evt->id = 47.
[stop_printing] Stop printing. evt->id = 48.
[printer_cut] Cut. evt->id = 48.
[printer_idle] Idle. evt->id = 49.
[printer_idle] Idle. evt->id = 50.
[printer_idle] Idle. evt->id = 51.
[printer_print_line] Print. evt->id = 52.
[prepare_to_print] Prepare to print. evt->id = 52.
[run_printing] Run printing. evt->id = 52.
[run_printing] Run printing. evt->id = 53.
[run_printing] Run printing. evt->id = 54.
[run_printing] Run printing. evt->id = 55.
[stop_printing] Stop printing. evt->id = 56.
[printer_cut] Cut. evt->id = 56.
[printer_idle] Idle. evt->id = 57.
[printer_idle] Idle. evt->id = 58.
[printer_idle] Idle. evt->id = 59.
[printer_print_line] Print. evt->id = 60.
[prepare_to_print] Prepare to print. evt->id = 60.
[run_printing] Run printing. evt->id = 60.
[run_printing] Run printing. evt->id = 61.
[run_printing] Run printing. evt->id = 62.
[run_printing] Run printing. evt->id = 63.
[stop_printing] Stop printing. evt->id = 64.
[printer_cut] Cut. evt->id = 64.
[printer_idle] Idle. evt->id = 65.
[printer_idle] Idle. evt->id = 66.
[printer_idle] Idle. evt->id = 67.
[printer_print_line] Print. evt->id = 68.
[prepare_to_print] Prepare to print. evt->id = 68.
[run_printing] Run printing. evt->id = 68.
[run_printing] Run printing. evt->id = 69.
[run_printing] Run printing. evt->id = 70.
[run_printing] Run printing. evt->id = 71.
[stop_printing] Stop printing. evt->id = 72.
*** Concluído ***

*/
