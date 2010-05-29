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

#include "led.h"
#include "pin.h"
#include "config.h"

#if ( CONTROLLER_VERSION == 50 )
  #define LED_IO PIN_PB25
#elif ( CONTROLLER_VERSION == 90 )
  #define LED_IO PIN_PB12
#else // ( CONTROLLER_VERSION >= 95 )
  #define LED_IO PIN_PA12
#endif

/**
  \defgroup led LED
  Controls the single green LED on the MAKE Controller Board.
  There are two LEDs on the MAKE Controller Board - one green and one red.  The red LED is simply
  a power indicator and cannot be controlled by the Controller.  The green LED can be used for
  program feedback.  In many MakingThings applications, for example, it is set to blink once a
  second, showing the board's "heartbeat" and letting the user know that the board is running.

  If you're looking to control the LEDs on the Application Board, check \ref appled.
  \ingroup Core
  @{
*/

/**
  Turn the LED on or off.
  @param on True to turn it on, false to turn it off.
  
  \b Example
  \code
  ledSetValue(ON); // turn it on
  \endcode
*/
void ledSetValue(bool on)
{
  pinSetValue(LED_IO, on ? 0 : 1); // inverted since it's tied to 3.3V
}

/**
  Read whether the LED is on or off.
  
  \b Example
  \code
  if (ledValue() == ON) {
    // then it's on
  }
  \endcode
*/
bool ledValue()
{
  return pinValue(LED_IO);
}

/** @} */

#ifdef OSC

// #include "osc.h"
// #include "string.h"
// #include "stdio.h"
// 
// // Need a list of property names
// // MUST end in zero
// static char* LedOsc_Name = "led";
// static char* LedOsc_PropertyNames[] = { "active", "state", 0 }; // must have a trailing 0
// 
// int LedOsc_PropertySet( int property, int value );
// int LedOsc_PropertyGet( int property );
// 
// // Returns the name of the subsystem
// const char* LedOsc_GetName( )
// {
//   return LedOsc_Name;
// }
// 
// // Now getting a message.  This is actually a part message, with the first
// // part (the subsystem) already parsed off.
// int LedOsc_ReceiveMessage( int channel, char* message, int length )
// {
//   int status = Osc_IntReceiverHelper( channel, message, length, 
//                                 LedOsc_Name,
//                                 LedOsc_PropertySet, LedOsc_PropertyGet, 
//                                 LedOsc_PropertyNames );
// 
//   if ( status != CONTROLLER_OK )
//     Osc_SendError( channel, LedOsc_Name, status );
//   return CONTROLLER_OK;
// }
// 
// // Set the index LED, property with the value
// int LedOsc_PropertySet( int property, int value )
// {
//   switch ( property )
//   {
//     case 0: 
//       Led_SetActive( value );
//       break;      
//     case 1:
//       Led_SetState( value );
//       break;
//   }
//   return CONTROLLER_OK;
// }
// 
// // Get the index LED, property
// int LedOsc_PropertyGet( int property )
// {
//   int value = 0;
//   switch ( property )
//   {
//     case 0:
//       value = Led_GetActive( );
//       break;
//     case 1:
//       value = Led_GetState( );
//       break;
//   }
//   
//   return value;
// }

#endif
