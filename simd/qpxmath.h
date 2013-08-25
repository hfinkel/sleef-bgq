/*===---- qpxmath.h - QPX SLEEF functions ----------------------------------===
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

#ifndef _QPXMATH_H_INCLUDED
#define _QPXMATH_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif
vector4double __xldexp(vector4double x, const int *q);
void __xilogb(vector4double d, int *l);

vector4double __xsin(vector4double d);
vector4double __xcos(vector4double d);
void __xsincos(vector4double d, vector4double *ds, vector4double *dc);
vector4double __xtan(vector4double d);
vector4double __xasin(vector4double s);
vector4double __xacos(vector4double s);
vector4double __xatan(vector4double s);
vector4double __xatan2(vector4double y, vector4double x);
vector4double __xlog(vector4double d);
vector4double __xexp(vector4double d);
vector4double __xpow(vector4double x, vector4double y);

vector4double __xsinh(vector4double d);
vector4double __xcosh(vector4double d);
vector4double __xtanh(vector4double d);
vector4double __xasinh(vector4double s);
vector4double __xacosh(vector4double s);
vector4double __xatanh(vector4double s);

vector4double __xcbrt(vector4double d);

vector4double __xexp2(vector4double a);
vector4double __xexp10(vector4double a);
vector4double __xexpm1(vector4double a);
vector4double __xlog10(vector4double a);
vector4double __xlog1p(vector4double a);

vector4double __xsin_u1(vector4double d);
vector4double __xcos_u1(vector4double d);
void __xsincos_u1(vector4double d, vector4double *ds, vector4double *dc);
vector4double __xtan_u1(vector4double d);
vector4double __xasin_u1(vector4double s);
vector4double __xacos_u1(vector4double s);
vector4double __xatan_u1(vector4double s);
vector4double __xatan2_u1(vector4double y, vector4double x);
vector4double __xlog_u1(vector4double d);
vector4double __xcbrt_u1(vector4double d);

vector4double __xldexpf(vector4double x, const int *q);
void __xilogbf(vector4double d, int *l);

vector4double __xsinf(vector4double d);
vector4double __xcosf(vector4double d);
void __xsincosf(vector4double d, vector4double *ds, vector4double *dc);
vector4double __xtanf(vector4double d);
vector4double __xasinf(vector4double s);
vector4double __xacosf(vector4double s);
vector4double __xatanf(vector4double s);
vector4double __xatan2f(vector4double y, vector4double x);
vector4double __xlogf(vector4double d);
vector4double __xexpf(vector4double d);
vector4double __xcbrtf(vector4double s);
vector4double __xsqrtf(vector4double s);

vector4double __xpowf(vector4double x, vector4double y);
vector4double __xsinhf(vector4double x);
vector4double __xcoshf(vector4double x);
vector4double __xtanhf(vector4double x);
vector4double __xasinhf(vector4double x);
vector4double __xacoshf(vector4double x);
vector4double __xatanhf(vector4double x);
vector4double __xexp2f(vector4double a);
vector4double __xexp10f(vector4double a);
vector4double __xexpm1f(vector4double a);
vector4double __xlog10f(vector4double a);
vector4double __xlog1pf(vector4double a);

vector4double __xsinf_u1(vector4double d);
vector4double __xcosf_u1(vector4double d);
void __xsincosf_u1(vector4double d, vector4double *ds, vector4double *dc);
vector4double __xtanf_u1(vector4double d);
vector4double __xasinf_u1(vector4double s);
vector4double __xacosf_u1(vector4double s);
vector4double __xatanf_u1(vector4double s);
vector4double __xatan2f_u1(vector4double y, vector4double x);
vector4double __xlogf_u1(vector4double d);
vector4double __xcbrtf_u1(vector4double s);
#ifdef __cplusplus
}
#endif

#if !QPXMATH_NO_GLOBAL_POLLUTION
static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xldexp(vector4double x, const int *q) {
  return __xldexp(x, q);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xilogb(vector4double d, int *l) {
  __xilogb(d, l);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsin(vector4double d) {
  return __xsin(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcos(vector4double d) {
  return __xcos(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xsincos(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincos(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtan(vector4double d) {
  return __xtan(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasin(vector4double s) {
  return __xasin(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacos(vector4double s) {
  return __xacos(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan(vector4double s) {
  return __xatan(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan2(vector4double y, vector4double x) {
  return __xatan2(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog(vector4double d) {
  return __xlog(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexp(vector4double d) {
  return __xexp(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xpow(vector4double x, vector4double y) {
  return __xpow(x, y);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsinh(vector4double d) {
  return __xsinh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcosh(vector4double d) {
  return __xcosh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtanh(vector4double d) {
  return __xtanh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasinh(vector4double s) {
  return __xasinh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacosh(vector4double s) {
  return __xacosh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatanh(vector4double s) {
  return __xatanh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcbrt(vector4double d) {
  return __xcbrt(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexp2(vector4double a) {
  return __xexp2(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexp10(vector4double a) {
  return __xexp10(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexpm1(vector4double a) {
  return __xexpm1(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog10(vector4double a) {
  return __xlog10(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog1p(vector4double a) {
  return __xlog1p(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsin_u1(vector4double d) {
  return __xsin_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcos_u1(vector4double d) {
  return __xcos_u1(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xsincos_u1(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincos_u1(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtan_u1(vector4double d) {
  return __xtan_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasin_u1(vector4double s) {
  return __xasin_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacos_u1(vector4double s) {
  return __xacos_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan_u1(vector4double s) {
  return __xatan_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan2_u1(vector4double y, vector4double x) {
  return __xatan2_u1(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog_u1(vector4double d) {
  return __xlog_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcbrt_u1(vector4double d) {
  return __xcbrt_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xldexpf(vector4double x, const int *q) {
  return __xldexpf(x, q);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xilogbf(vector4double d, int *l) {
  __xilogbf(d, l);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsinf(vector4double d) {
  return __xsinf(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcosf(vector4double d) {
  return __xcosf(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xsincosf(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincosf(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtanf(vector4double d) {
  return __xtanf(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasinf(vector4double s) {
  return __xasinf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacosf(vector4double s) {
  return __xacosf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatanf(vector4double s) {
  return __xatanf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan2f(vector4double y, vector4double x) {
  return __xatan2f(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlogf(vector4double d) {
  return __xlogf(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexpf(vector4double d) {
  return __xexpf(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcbrtf(vector4double s) {
  return __xcbrtf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsqrtf(vector4double s) {
  return __xsqrtf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xpowf(vector4double x, vector4double y) {
  return __xpowf(x, y);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsinhf(vector4double x) {
  return __xsinhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcoshf(vector4double x) {
  return __xcoshf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtanhf(vector4double x) {
  return __xtanhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasinhf(vector4double x) {
  return __xasinhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacoshf(vector4double x) {
  return __xacoshf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatanhf(vector4double x) {
  return __xatanhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexp2f(vector4double a) {
  return __xexp2f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexp10f(vector4double a) {
  return __xexp10f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xexpm1f(vector4double a) {
  return __xexpm1f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog10f(vector4double a) {
  return __xlog10f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlog1pf(vector4double a) {
  return __xlog1pf(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xsinf_u1(vector4double d) {
  return __xsinf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcosf_u1(vector4double d) {
  return __xcosf_u1(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
xsincosf_u1(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincosf_u1(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xtanf_u1(vector4double d) {
  return __xtanf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xasinf_u1(vector4double s) {
  return __xasinf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xacosf_u1(vector4double s) {
  return __xacosf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatanf_u1(vector4double s) {
  return __xatanf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xatan2f_u1(vector4double y, vector4double x) {
  return __xatan2f_u1(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xlogf_u1(vector4double d) {
  return __xlogf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
xcbrtf_u1(vector4double s) {
  return __xcbrtf_u1(s);
}
#endif

#ifdef QPXMATH_MASS_SIMD_FUNCTIONS
static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
sind4(vector4double d) {
  return __xsin(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
cosd4(vector4double d) {
  return __xcos(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
sincosd4(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincos(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
tand4(vector4double d) {
  return __xtan(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
asind4(vector4double s) {
  return __xasin(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
acosd4(vector4double s) {
  return __xacos(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atand4(vector4double s) {
  return __xatan(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atan2d4(vector4double y, vector4double x) {
  return __xatan2(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
logd4(vector4double d) {
  return __xlog(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
expd4(vector4double d) {
  return __xexp(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
powd4(vector4double x, vector4double y) {
  return __xpow(x, y);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
sinhd4(vector4double d) {
  return __xsinh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
coshd4(vector4double d) {
  return __xcosh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
tanhd4(vector4double d) {
  return __xtanh(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
asinhd4(vector4double s) {
  return __xasinh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
acoshd4(vector4double s) {
  return __xacosh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atanhd4(vector4double s) {
  return __xatanh(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
cbrtd4(vector4double d) {
  return __xcbrt(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
exp2d4(vector4double a) {
  return __xexp2(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
exp10d4(vector4double a) {
  return __xexp10(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
expm1d4(vector4double a) {
  return __xexpm1(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
log10d4(vector4double a) {
  return __xlog10(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
log1pd4(vector4double a) {
  return __xlog1p(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
sinf4(vector4double d) {
  return __xsinf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
cosf4(vector4double d) {
  return __xcosf_u1(d);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
sincosf4(vector4double d, vector4double *ds, vector4double *dc) {
  __xsincosf_u1(d, ds, dc);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
tanf4(vector4double d) {
  return __xtanf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
asinf4(vector4double s) {
  return __xasinf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
acosf4(vector4double s) {
  return __xacosf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atanf4(vector4double s) {
  return __xatanf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atan2f4(vector4double y, vector4double x) {
  return __xatan2f_u1(y, x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
logf4(vector4double d) {
  return __xlogf_u1(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
expf4(vector4double d) {
  return __xexpf(d);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
cbrtf4(vector4double s) {
  return __xcbrtf_u1(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
sqrtf4(vector4double s) {
  return __xsqrtf(s);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
powf4(vector4double x, vector4double y) {
  return __xpowf(x, y);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
sinhf4(vector4double x) {
  return __xsinhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
coshf4(vector4double x) {
  return __xcoshf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
tanhf4(vector4double x) {
  return __xtanhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
asinhf4(vector4double x) {
  return __xasinhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
acoshf4(vector4double x) {
  return __xacoshf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
atanhf4(vector4double x) {
  return __xatanhf(x);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
exp2f4(vector4double a) {
  return __xexp2f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
exp10f4(vector4double a) {
  return __xexp10f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
expm1f4(vector4double a) {
  return __xexpm1f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
log10f4(vector4double a) {
  return __xlog10f(a);
}

static __inline__ vector4double __attribute__((__always_inline__, __nodebug__))
log1pf4(vector4double a) {
  return __xlog1pf(a);
}
#endif

#endif

