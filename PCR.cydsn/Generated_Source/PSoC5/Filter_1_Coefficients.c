#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 3 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xE7u, 0x2Au, 0x01u, 0x00u, /* Section(0)_A0, 0.0182435512542725 */

 0xE7u, 0x2Au, 0x01u, 0x00u, /* Section(0)_A1, 0.0182435512542725 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(0)_A2, 0 */

 0x42u, 0xA9u, 0x36u, 0x00u, /* Section(0)_B1, -0.854080677032471 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(0)_B2, 0 */

 /* Coefficients of Section 1 */
 0x8Au, 0x59u, 0x00u, 0x00u, /* Section(1)_A0, 0.00546503067016602 */

 0x13u, 0xB3u, 0x00u, 0x00u, /* Section(1)_A1, 0.0109298229217529 */

 0x8Au, 0x59u, 0x00u, 0x00u, /* Section(1)_A2, 0.00546503067016602 */

 0xB8u, 0x38u, 0x70u, 0x00u, /* Section(1)_B1, -1.75346183776855 */

 0x2Du, 0x61u, 0xCEu, 0x00u, /* Section(1)_B2, 0.77531886100769 */

 /* Coefficients of Section 2 */
 0xB4u, 0x80u, 0x01u, 0x00u, /* Section(2)_A0, 0.0234804153442383 */

 0x67u, 0x01u, 0x03u, 0x00u, /* Section(2)_A1, 0.0469605922698975 */

 0xB4u, 0x80u, 0x01u, 0x00u, /* Section(2)_A2, 0.0234804153442383 */

 0x2Fu, 0x98u, 0x78u, 0x00u, /* Section(2)_B1, -1.88428854942322 */

 0xFEu, 0xE6u, 0xC5u, 0x00u, /* Section(2)_B2, 0.907776355743408 */
};

