#include "fsm.h"
#include <stdio.h>


fsm_state	printer_idle ( event *evt )
{
	printf ( "[%s] Idle. evt->id = %d.\n", __func__, evt->id );

	if ( 0 == ( ++( evt->id ) & 0x03 ) )
		return ( fsm_state ){ .action = printer_print_line };

	return ( fsm_state ){ .action = printer_idle };
}

// --------------------------------------
fsm_state	printer_print_line ( event *evt )
{
	printf ( "[%s] Print. evt->id = %d.\n", __func__, evt->id );

	return ( fsm_state ){ .action = prepare_to_print };
}

fsm_state	prepare_to_print ( event *evt )
{
	printf ( "[%s] Prepare to print. evt->id = %d.\n", __func__, evt->id );

	return ( fsm_state ){ .action = run_printing };
}

fsm_state	run_printing ( event *evt )
{
	printf ( "[%s] Run printing. evt->id = %d.\n", __func__, evt->id );

	if ( 0 == ( ++( evt->id ) & 0x07 ) )
		return ( fsm_state ){ .action = stop_printing };

	return ( fsm_state ){ .action = run_printing };
}

fsm_state	stop_printing ( event *evt )
{
	printf ( "[%s] Stop printing. evt->id = %d.\n", __func__, evt->id );

	return ( fsm_state ){ .action = printer_cut };
}

// --------------------------------------
fsm_state	printer_cut ( event *evt )
{
	printf ( "[%s] Cut. evt->id = %d.\n", __func__, evt->id );

	if ( 0 == ( ++( evt->id ) & 0x03 ) )
		return ( fsm_state ){ .action = printer_print_line };

	if ( 0x03 == ( evt->id & 0x03 ) )
		return ( fsm_state ){ .action = printer_error };

	return ( fsm_state ){ .action = printer_idle };
}

// --------------------------------------
fsm_state	printer_setup ( event *evt )
{
	printf ( "[%s] Setup. evt->id = %d.\n", __func__, evt->id );

	return ( fsm_state ){ .action = printer_idle };
}

// --------------------------------------
fsm_state	printer_error ( event *evt )
{
	printf ( "[%s] Error. evt->id = %d.\n", __func__, evt->id );

	return ( fsm_state ){ .action = printer_idle };
}
