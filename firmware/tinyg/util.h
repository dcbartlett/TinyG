/*
 * util.h - a random assortment of useful functions
 * Part of TinyG project
 *
 * Copyright (c) 2011 - 2012 Alden S. Hart Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/* util.c/.h contains a dog's breakfast of supporting functions that are 
 * not specific to tinyg: including:
 *
 *	  - math and min/max utilities and extensions 
 *	  - vector manipulation utilities
 *	  - support for debugging routines
 */  

#ifndef util_h
#define util_h

/****** Global Scope Variables and Functions ******/

double vector[AXES];				// vector of axes for passing to subroutines

double min3(double x1, double x2, double x3);
double min4(double x1, double x2, double x3, double x4);
double max3(double x1, double x2, double x3);
double max4(double x1, double x2, double x3, double x4);
uint8_t isnumber(char c);
uint8_t read_double(char *buf, uint8_t *i, double *double_ptr);
uint16_t compute_checksum(char const *string, const uint16_t length);

void copy_vector(double dest[], const double src[], uint8_t length);
void copy_axis_vector(double dest[], const double src[]);
double get_axis_vector_length(const double a[], const double b[]);
double *set_vector(double x, double y, double z, double a, double b, double c);
double *set_vector_by_axis(double value, uint8_t axis);
#define clear_vector(a) memset(a,0,sizeof(a))

// ritorno is a handy way to provide exception returns - it returns only if an error occurred
// (ritorno is Italian for return) 
#define ritorno(a) { uint8_t status; if((status = a) != TG_OK) return(status);}

/***** Math Support *****/

// side-effect safe forms of min and max
#ifndef max
#define max(a,b) \
   ({ __typeof__ (a) termA = (a); \
      __typeof__ (b) termB = (b); \
	  termA>termB ? termA:termB; })
#endif

#ifndef min
#define min(a,b) \
   ({ __typeof__ (a) termA = (a); \
      __typeof__ (b) termB = (b); \
      termA<termB ? termA:termB; })
#endif

#ifndef avg
#define avg(a,b) ((a+b)/2)
#endif

#ifndef EPSILON
#define EPSILON 0.00001						// rounding error for floats
#endif
#ifndef fp_EQ
#define fp_EQ(a,b) (fabs(a-b) < EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_NE
#define fp_NE(a,b) (fabs(a-b) > EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_ZERO
#define fp_ZERO(a) (fabs(a) < EPSILON)		// requires math.h to be included in each file used
#endif
#ifndef fp_NOT_ZERO
#define fp_NOT_ZERO(a) (fabs(a) > EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_FALSE
#define fp_FALSE(a) (a < EPSILON)			// float is interpreted as FALSE (equals zero)
#endif
#ifndef fp_TRUE
#define fp_TRUE(a) (a > EPSILON)			// float is interpreted as TRUE (not equal to zero)
#endif

// Constants
#define MAX_LONG (2147483647)
#define MAX_ULONG (4294967295)
#define MM_PER_INCH (25.4)
#define INCH_PER_MM (1/25.4)
#define MICROSECONDS_PER_MINUTE ((double)60000000)
#define uSec(a) ((double)(a * MICROSECONDS_PER_MINUTE))

#define RADIAN (57.2957795)
//		M_PI is pi as defined in math.h
//		M_SQRT2 is radical2 as defined in math.h
#define M_SQRT3 (1.73205080756888)

#endif	// util_h
