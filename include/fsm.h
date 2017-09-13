#ifndef	FSM_H
#	define	FSM_H


typedef struct _event
{
	int	id;
	void	*arg;
}
	event;


typedef struct _fsm_state fsm_state;

typedef	fsm_state ( *state_func )( event *evt );

struct _fsm_state
{
	state_func	action;
};


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


fsm_state	printer_idle ( event *evt );

fsm_state	printer_print_line ( event *evt );
fsm_state	prepare_to_print ( event *evt );
fsm_state	run_printing ( event *evt );
fsm_state	stop_printing ( event *evt );

fsm_state	printer_cut ( event *evt );
fsm_state	printer_setup ( event *evt );
fsm_state	printer_error ( event *evt );


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// FSM_H
