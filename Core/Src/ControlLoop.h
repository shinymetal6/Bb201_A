/*
 * ControlTask.h
 *
 *  Created on: Sep 11, 2019
 *      Author: fil
 */

#ifndef CONTROLTASK_H_
#define CONTROLTASK_H_

#include "main.h"


typedef struct {
	uint16_t sigin4;
	uint16_t sigin5;
	uint16_t anlgin0;
	uint16_t anlgin1;
	uint16_t anlgin2;
	uint16_t anlgin3;
	uint16_t anlgin4;
	uint16_t anlgin5;
	uint16_t analog_digital;
} s_control_buf;

#define	CONTROLBUF_SAMPLES	16
#define	CONTROLBUF_LEN		sizeof(s_control_buf)*CONTROLBUF_SAMPLES

/*
 defines for a dual vco configuration
 */
#define	POT_LEFT	2
#define	POT_RIGHT	3
#define	JOY_X		4
#define	JOY_Y		5
#define	JOY_BTN		6

#endif /* CONTROLTASK_H_ */
