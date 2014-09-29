/*===---- fastmath.h - Scalar SLEEF functions ------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

/*
 * The implementation of these functions is derived from SLEEF (SIMD Library
 * for Evaluating Elementary Functions) by Naoki Shibata. For more information
 * on SLEEF, see: http://shibatch.sourceforge.net/
 */

#ifndef _FASTMATH_H_INCLUDED
#define _FASTMATH_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif
double __fast_ldexp(double x, const int *q);
void __fast_ilogb(double d, int *l);

double __fast_sin(double d);
double __fast_cos(double d);
void __fast_sincos(double d, double *ds, double *dc);
double __fast_tan(double d);
double __fast_asin(double s);
double __fast_acos(double s);
double __fast_atan(double s);
double __fast_atan2(double y, double x);
double __fast_log(double d);
double __fast_exp(double d);
double __fast_pow(double x, double y);

double __fast_sinh(double d);
double __fast_cosh(double d);
double __fast_tanh(double d);
double __fast_asinh(double s);
double __fast_acosh(double s);
double __fast_atanh(double s);

double __fast_cbrt(double d);

double __fast_exp2(double a);
double __fast_exp10(double a);
double __fast_expm1(double a);
double __fast_log10(double a);
double __fast_log1p(double a);

double __fast_sin_u1(double d);
double __fast_cos_u1(double d);
void __fast_sincos_u1(double d, double *ds, double *dc);
double __fast_tan_u1(double d);
double __fast_asin_u1(double s);
double __fast_acos_u1(double s);
double __fast_atan_u1(double s);
double __fast_atan2_u1(double y, double x);
double __fast_log_u1(double d);
double __fast_cbrt_u1(double d);

float __fast_ldexpf(float x, const int *q);
void __fast_ilogbf(float d, int *l);

float __fast_sinf(float d);
float __fast_cosf(float d);
void __fast_sincosf(float d, float *ds, float *dc);
float __fast_tanf(float d);
float __fast_asinf(float s);
float __fast_acosf(float s);
float __fast_atanf(float s);
float __fast_atan2f(float y, float x);
float __fast_logf(float d);
float __fast_expf(float d);
float __fast_cbrtf(float s);
float __fast_sqrtf(float s);

float __fast_powf(float x, float y);
float __fast_sinhf(float x);
float __fast_coshf(float x);
float __fast_tanhf(float x);
float __fast_asinhf(float x);
float __fast_acoshf(float x);
float __fast_atanhf(float x);
float __fast_exp2f(float a);
float __fast_exp10f(float a);
float __fast_expm1f(float a);
float __fast_log10f(float a);
float __fast_log1pf(float a);

float __fast_sinf_u1(float d);
float __fast_cosf_u1(float d);
void __fast_sincosf_u1(float d, float *ds, float *dc);
float __fast_tanf_u1(float d);
float __fast_asinf_u1(float s);
float __fast_acosf_u1(float s);
float __fast_atanf_u1(float s);
float __fast_atan2f_u1(float y, float x);
float __fast_logf_u1(float d);
float __fast_cbrtf_u1(float s);
#ifdef __cplusplus
}
#endif

#if !FASTMATH_NO_GLOBAL_POLLUTION
static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_ldexp(double x, const int *q) {
  return __fast_ldexp(x, q);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_ilogb(double d, int *l) {
  __fast_ilogb(d, l);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_sin(double d) {
  return __fast_sin(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_cos(double d) {
  return __fast_cos(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_sincos(double d, double *ds, double *dc) {
  __fast_sincos(d, ds, dc);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_tan(double d) {
  return __fast_tan(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_asin(double s) {
  return __fast_asin(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_acos(double s) {
  return __fast_acos(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_atan(double s) {
  return __fast_atan(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_atan2(double y, double x) {
  return __fast_atan2(y, x);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_log(double d) {
  return __fast_log(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_exp(double d) {
  return __fast_exp(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_pow(double x, double y) {
  return __fast_pow(x, y);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_sinh(double d) {
  return __fast_sinh(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_cosh(double d) {
  return __fast_cosh(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_tanh(double d) {
  return __fast_tanh(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_asinh(double s) {
  return __fast_asinh(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_acosh(double s) {
  return __fast_acosh(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_atanh(double s) {
  return __fast_atanh(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_cbrt(double d) {
  return __fast_cbrt(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_exp2(double a) {
  return __fast_exp2(a);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_exp10(double a) {
  return __fast_exp10(a);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_expm1(double a) {
  return __fast_expm1(a);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_log10(double a) {
  return __fast_log10(a);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_log1p(double a) {
  return __fast_log1p(a);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_sin_u1(double d) {
  return __fast_sin_u1(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_cos_u1(double d) {
  return __fast_cos_u1(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_sincos_u1(double d, double *ds, double *dc) {
  __fast_sincos_u1(d, ds, dc);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_tan_u1(double d) {
  return __fast_tan_u1(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_asin_u1(double s) {
  return __fast_asin_u1(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_acos_u1(double s) {
  return __fast_acos_u1(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_atan_u1(double s) {
  return __fast_atan_u1(s);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_atan2_u1(double y, double x) {
  return __fast_atan2_u1(y, x);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_log_u1(double d) {
  return __fast_log_u1(d);
}

static __inline__ double __attribute__((__always_inline__, __nodebug__))
fast_cbrt_u1(double d) {
  return __fast_cbrt_u1(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_ldexpf(float x, const int *q) {
  return __fast_ldexpf(x, q);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_ilogbf(float d, int *l) {
  __fast_ilogbf(d, l);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_sinf(float d) {
  return __fast_sinf(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_cosf(float d) {
  return __fast_cosf(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_sincosf(float d, float *ds, float *dc) {
  __fast_sincosf(d, ds, dc);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_tanf(float d) {
  return __fast_tanf(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_asinf(float s) {
  return __fast_asinf(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_acosf(float s) {
  return __fast_acosf(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_atanf(float s) {
  return __fast_atanf(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_atan2f(float y, float x) {
  return __fast_atan2f(y, x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_logf(float d) {
  return __fast_logf(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_expf(float d) {
  return __fast_expf(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_cbrtf(float s) {
  return __fast_cbrtf(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_sqrtf(float s) {
  return __fast_sqrtf(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_powf(float x, float y) {
  return __fast_powf(x, y);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_sinhf(float x) {
  return __fast_sinhf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_coshf(float x) {
  return __fast_coshf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_tanhf(float x) {
  return __fast_tanhf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_asinhf(float x) {
  return __fast_asinhf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_acoshf(float x) {
  return __fast_acoshf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_atanhf(float x) {
  return __fast_atanhf(x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_exp2f(float a) {
  return __fast_exp2f(a);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_exp10f(float a) {
  return __fast_exp10f(a);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_expm1f(float a) {
  return __fast_expm1f(a);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_log10f(float a) {
  return __fast_log10f(a);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_log1pf(float a) {
  return __fast_log1pf(a);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_sinf_u1(float d) {
  return __fast_sinf_u1(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_cosf_u1(float d) {
  return __fast_cosf_u1(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
fast_sincosf_u1(float d, float *ds, float *dc) {
  __fast_sincosf_u1(d, ds, dc);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_tanf_u1(float d) {
  return __fast_tanf_u1(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_asinf_u1(float s) {
  return __fast_asinf_u1(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_acosf_u1(float s) {
  return __fast_acosf_u1(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_atanf_u1(float s) {
  return __fast_atanf_u1(s);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_atan2f_u1(float y, float x) {
  return __fast_atan2f_u1(y, x);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_logf_u1(float d) {
  return __fast_logf_u1(d);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
fast_cbrtf_u1(float s) {
  return __fast_cbrtf_u1(s);
}
#endif

#endif

