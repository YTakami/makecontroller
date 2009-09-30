/*********************************************************************************

 Copyright 2006-2009 MakingThings

 Licensed under the Apache License, 
 Version 2.0 (the "License"); you may not use this file except in compliance 
 with the License. You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0 
 
 Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for
 the specific language governing permissions and limitations under the License.

*********************************************************************************/

#ifndef PWM_H
#define PWM_H

#include "types.h"

#define PWM_COUNT 4

/**
  Control the 4 Pulse Width Modulation outputs.

  The Make Controller has 4 PWM signals.  Each be configured separately, and can control
  up to 2 output lines.  These lines can be driven with the pwm signal in parallel or they can
  be inverted from one another.  , the 2 lines running either parallel or inverted.  For a very simple
  start, just see Pwm_Set( ) and Pwm_Get( ) as these will start driving your PWMs immediately with
  very little hassle.

  \section Hardware
  The PWM lines on the Make Controller are located on the following signal lines:
  - channel 0 is PB19
  - channel 1 is PB20
  - channel 2 is PB21
  - channel 3 is PB22
  
  The \ref PwmOut system relies on the Pwm system, and provides control of the output lines associated with
  a given Pwm signal.
  
  \ingroup io
*/

void pwmInit(void);
void pwmDeinit(void);
bool pwmSetFrequency(int freq);
bool pwmEnableChannel( int channel );
void pwmDisableChannel( int channel );
void pwmSetDuty( int channel, int duty );
void pwmSetWaveform( int channel, bool left_aligned, bool starts_low );
bool pwmSetPeriod( int channel, int period );

#endif