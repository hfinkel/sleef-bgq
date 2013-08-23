#ifndef __VECTOR4DOUBLE__
#error Please build with support for QPX vector intrinsics
#endif

#include <stdint.h>
#include <string.h>

typedef vector4double vdouble;
typedef struct { int v[4] __attribute__((aligned(16))); } vint;
#define vmask vdouble

#define vfloat vdouble
typedef struct { long v[4] __attribute__((aligned(32))); } vint2;

#define ENABLE_FMA_DP
#define ENABLE_FMA_SP

//

#define F04(i) for (int i = 0; i < 4; ++i)

// FIXME: vec_ctid may not have the correct rounding mode on bgxlc for rint.
static INLINE vint vrint_vi_vd(vdouble vd) { vint r; vec_st(vec_ctid(vd), 0, r.v); return r; }
static INLINE vint vtruncate_vi_vd(vdouble vd) { vint r; vec_st(vec_ctidz(vd), 0, r.v); return r; }
static INLINE vdouble vcast_vd_vi(vint vi) { return vec_cfid(vec_ldia(0, vi.v)); }
static INLINE vdouble vcast_vd_d(double d) { return vec_splats(d); }
static INLINE vint vcast_vi_i(int i) { vint r; F04(j) r.v[j] = i; return r; }

static INLINE vmask vreinterpret_vm_vd(vdouble vd) { return vd; }
static INLINE vdouble vreinterpret_vd_vm(vmask vm) { return vm; }

static INLINE vmask vreinterpret_vm_vf(vfloat vf) { return vf; }
static INLINE vfloat vreinterpret_vf_vm(vmask vm) { return vm; }

//

static INLINE vint vadd_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = x.v[j] + y.v[j]; return r; }
static INLINE vint vsub_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = x.v[j] - y.v[j]; return r; }
static INLINE vint vneg_vi_vi(vint e) { vint r; F04(j) r.v[j] = -e.v[j]; return r; }

static INLINE vint vand_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = x.v[j] & y.v[j]; return r; }
static INLINE vint vandnot_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = ~x.v[j] & y.v[j]; return r; }
static INLINE vint vor_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = x.v[j] | y.v[j]; return r; }
static INLINE vint vxor_vi_vi_vi(vint x, vint y) { vint r; F04(j) r.v[j] = x.v[j] ^ y.v[j]; return r; }

static INLINE vint vsll_vi_vi_i(vint x, int c) { vint r; F04(j) r.v[j] = x.v[j] << c; return r; }
static INLINE vint vsrl_vi_vi_i(vint x, int c) { vint r; F04(j) r.v[j] = ((unsigned int) x.v[j]) >> c; return r; }
static INLINE vint vsra_vi_vi_i(vint x, int c) { vint r; F04(j) r.v[j] = x.v[j] >> c; return r; }

//

static INLINE vmask vand_vm_vm_vm(vmask x, vmask y) { return vec_and(x, y); }
static INLINE vmask vandnot_vm_vm_vm(vmask x, vmask y) { return vec_andc(y, x); }
static INLINE vmask vor_vm_vm_vm(vmask x, vmask y) { return vec_or(x, y); }
static INLINE vmask vxor_vm_vm_vm(vmask x, vmask y) { return vec_xor(x, y); }

static INLINE vmask veq_vm_vd_vd(vdouble x, vdouble y) { return vec_cmpeq(x, y); }
static INLINE vmask vneq_vm_vd_vd(vdouble x, vdouble y) { return vec_not(vec_cmpeq(x, y)); }
static INLINE vmask vlt_vm_vd_vd(vdouble x, vdouble y) { return vec_cmplt(x, y); }
static INLINE vmask vle_vm_vd_vd(vdouble x, vdouble y) { return vec_or(vec_cmplt(x, y), vec_cmpeq(x, y)); }
static INLINE vmask vgt_vm_vd_vd(vdouble x, vdouble y) { return vec_cmpgt(x, y); }
static INLINE vmask vge_vm_vd_vd(vdouble x, vdouble y) { return vec_or(vec_cmpgt(x, y), vec_cmpeq(x, y)); }

#define veq_vm_vf_vf veq_vm_vd_vd
#define vneq_vm_vf_vf vneq_vm_vd_vd
#define vlt_vm_vf_vf vlt_vm_vd_vd
#define vle_vm_vf_vf vle_vm_vd_vd
#define vgt_vm_vf_vf vgt_vm_vd_vd
#define vge_vm_vf_vf vge_vm_vd_vd

//

static INLINE vfloat vcast_vf_f(float f) { return vec_splats((double)f); }

static INLINE vfloat vadd_vf_vf_vf(vfloat x, vfloat y) { return vec_add(x, y); }
static INLINE vfloat vsub_vf_vf_vf(vfloat x, vfloat y) { return vec_sub(x, y); }
static INLINE vfloat vmul_vf_vf_vf(vfloat x, vfloat y) { return vec_mul(x, y); }
static INLINE vfloat vmax_vf_vf_vf(vfloat x, vfloat y) { return vec_sel(y, x, vec_cmpgt(x, y)); }
static INLINE vfloat vmin_vf_vf_vf(vfloat x, vfloat y) { return vec_sel(x, y, vec_cmpgt(x, y)); }

static INLINE vfloat vmla_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_madd(x, y, z); }
static INLINE vfloat vmlapn_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_msub(x, y, z); }
static INLINE vfloat vmlanp_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_nmsub(x, y, z); }
static INLINE vfloat vabs_vf_vf(vfloat f) { return vec_abs(f); }
static INLINE vfloat vneg_vf_vf(vfloat d) { return vec_neg(d); }

static INLINE vfloat vfma_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_madd(x, y, z); }
static INLINE vfloat vfmapp_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_madd(x, y, z); }
static INLINE vfloat vfmapn_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_msub(x, y, z); }
static INLINE vfloat vfmanp_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_nmsub(x, y, z); }
static INLINE vfloat vfmann_vf_vf_vf_vf(vfloat x, vfloat y, vfloat z) { return vec_nmadd(x, y, z); }

static INLINE vfloat vrecsqrt_vf_vf(vfloat d) {
  vfloat e = vec_rsqrtes(d), c = vec_splats(1.5);
  vfloat h = vec_sub(vec_mul(d, c), d);
  return vec_mul(e, vec_sub(c, vec_mul(h, vec_mul(e, e))));
}

#define ENABLE_RECSQRT_SP

static INLINE vfloat vrec_vf_vf(vfloat x) {
  vfloat e = vec_res(x), c = vec_splats(1.0);
  e = vec_add(e, vec_mul(e, vec_sub(c, vec_mul(x, e))));
  return vec_sel(e, vec_cpsgn(x, vec_splats(0.0)), vec_cmpeq(vec_abs(x), vec_splats(INFINITY)));
}

static INLINE vfloat vdiv_vf_vf_vf(vfloat x, vfloat y) { return vec_mul(x, vrec_vf_vf(y)); }
static INLINE vfloat vsqrt_vf_vf(vfloat x) {
  return vec_sel(vrec_vf_vf(vrecsqrt_vf_vf(x)), vec_splats(0.0), vec_cmpeq(x, vec_splats(0.0)));
}


//

#define vadd_vd_vd_vd vadd_vf_vf_vf
#define vsub_vd_vd_vd vsub_vf_vf_vf
#define vmul_vd_vd_vd vmul_vf_vf_vf
#define vabs_vd_vd vabs_vf_vf
#define vneg_vd_vd vneg_vf_vf

#define vmla_vd_vd_vd_vd vmla_vf_vf_vf_vf
#define vmlapn_vd_vd_vd_vd vmlapn_vf_vf_vf_vf

#define vmax_vd_vd_vd vmax_vf_vf_vf
#define vmin_vd_vd_vd vmin_vf_vf_vf

#define vfma_vd_vd_vd_vd vfma_vf_vf_vf_vf
#define vfmapp_vd_vd_vd_vd vfmapp_vf_vf_vf_vf
#define vfmapn_vd_vd_vd_vd vfmapn_vf_vf_vf_vf
#define vfmanp_vd_vd_vd_vd vfmanp_vf_vf_vf_vf
#define vfmann_vd_vd_vd_vd vfmann_vf_vf_vf_vf

static INLINE vdouble vrecsqrt_vd_vd(vdouble d) {
  vdouble e = vec_rsqrte(d), c = vec_splats(1.5);
  vdouble h = vec_sub(vec_mul(d, c), d);
  for (int i = 0; i < 3; ++i)
    e = vec_mul(e, vec_sub(c, vec_mul(h, vec_mul(e, e))));
  return e;
}

#define ENABLE_RECSQRT_DP

static INLINE vdouble vrec_vd_vd(vdouble x) {
  vdouble e = vec_re(x), c = vec_splats(1.0);
  for (int i = 0; i < 2; ++i)
    e = vec_add(e, vec_mul(e, vec_sub(c, vec_mul(x, e))));
  return vec_sel(e, vec_cpsgn(x, vec_splats(0.0)), vec_cmpeq(vec_abs(x), vec_splats(INFINITY)));
}

static INLINE vdouble vdiv_vd_vd_vd(vdouble x, vdouble y) { return vec_mul(x, vrec_vd_vd(y)); }
static INLINE vdouble vsqrt_vd_vd(vdouble x) {
  return vec_sel(vrec_vd_vd(vrecsqrt_vd_vd(x)), vec_splats(0.0), vec_cmpeq(x, vec_splats(0.0)));
}

//

static INLINE vmask veq_vm_vi_vi(vint x, vint y) {
  return vec_cmpeq(vcast_vd_vi(x), vcast_vd_vi(y));
}

static INLINE vdouble vsel_vd_vm_vd_vd(vmask mask, vdouble x, vdouble y) {
  return vec_sel(y, x, mask);
}

#define vsel_vf_vm_vf_vf vsel_vd_vm_vd_vd

static INLINE vint vsel_vi_vd_vd_vi_vi(vdouble d0, vdouble d1, vint x, vint y) {
  vint r;

  F04(j) r.v[j] = (d0[j] < d1[j]) ? x.v[j] : y.v[j];
  return r;
}

//

static INLINE vint2 vrint_vi2_vf(vfloat vd) { vint2 r; vec_st(vec_ctid(vd), 0, r.v); return r; }
static INLINE vint2 vtruncate_vi2_vf(vfloat vd) { vint2 r; vec_st(vec_ctidz(vd), 0, r.v); return r; }
static INLINE vfloat vcast_vf_vi2(vint2 vi) { return vec_cfid(vec_ld(0, vi.v)); }

#define vcast_vi2_vm vtruncate_vi2_vf
#define vcast_vm_vi2 vcast_vf_vi2

#define vcast_vd_vi2 vcast_vf_vi2

static INLINE vint2 vcast_vi2_i(int i) { vint2 r; F04(j) r.v[j] = i; return r; }

static INLINE vint2 vadd_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] + y.v[j]; return r; }
static INLINE vint2 vsub_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] - y.v[j]; return r; }
static INLINE vint2 vneg_vi2_vi2(vint2 e) { vint2 r; F04(j) r.v[j] = -e.v[j]; return r; }

static INLINE vint2 vand_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] & y.v[j]; return r; }
static INLINE vint2 vandnot_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] & ~y.v[j]; return r; }
static INLINE vint2 vor_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] | y.v[j]; return r; }
static INLINE vint2 vxor_vi2_vi2_vi2(vint2 x, vint2 y) { vint2 r; F04(j) r.v[j] = x.v[j] ^ y.v[j]; return r; }

static INLINE vint2 vsll_vi2_vi2_i(vint2 x, int c) { vint2 r; F04(j) r.v[j] = x.v[j] << c; return r; }
static INLINE vint2 vsrl_vi2_vi2_i(vint2 x, int c) { vint2 r; F04(j) r.v[j] = ((unsigned long) x.v[j]) >> c; return r; }
static INLINE vint2 vsra_vi2_vi2_i(vint2 x, int c) { vint2 r; F04(j) r.v[j] = x.v[j] >> c; return r; }

static INLINE vmask veq_vm_vi2_vi2(vint2 x, vint2 y) {
  return vec_cmpeq(vcast_vd_vi2(x), vcast_vd_vi2(y));
}

static INLINE vmask vgt_vm_vi2_vi2(vint2 x, vint2 y) {
  return vec_cmpgt(vcast_vd_vi2(x), vcast_vd_vi2(y));
}

static INLINE vint2 vgt_vi2_vi2_vi2(vint2 x, vint2 y) {
  return vcast_vi2_vm(vgt_vm_vi2_vi2(x, y));
}

static INLINE vint2 vsel_vi2_vm_vi2_vi2(vmask m, vint2 x, vint2 y) {
  return vrint_vi2_vf(vsel_vd_vm_vd_vd(m, vcast_vd_vi2(x), vcast_vd_vi2(y)));
}

//

static INLINE double vcast_d_vd(vdouble v) {
  return v[0];
}

#define vcast_f_vf vcast_d_vd

// FIXME: Users of this function are making an assumption about masking not true here!
static INLINE vmask vsignbit_vm_vd(vdouble d) {
  return vec_cpsgn(d, vec_splats(0.0));
}

static INLINE vdouble vsign_vd_vd(vdouble d) {
  return vec_cpsgn(d, vec_splats(1.0));
}

static INLINE vdouble vmulsign_vd_vd_vd(vdouble x, vdouble y) {
  return vec_cpsgn(vec_mul(vsign_vd_vd(x), vsign_vd_vd(y)), x);
}

static INLINE vmask visinf_vm_vd(vdouble d) {
  return vec_cmpeq(vabs_vd_vd(d), vec_splats(INFINITY));
}

static INLINE vmask vispinf_vm_vd(vdouble d) {
  return vec_cmpeq(d, vec_splats(INFINITY));
}

static INLINE vmask visminf_vm_vd(vdouble d) {
  return vec_cmpeq(d, vec_splats(-INFINITY));
}

static INLINE vmask visnan_vm_vd(vdouble d) {
  return vec_tstnan(d, d);
}

static INLINE vdouble visinf(vdouble d) {
  return vsel_vd_vm_vd_vd(visinf_vm_vd(d), vsign_vd_vd(d), vec_splats(0.0));
}

static INLINE vdouble visinf2(vdouble d, vdouble m) {
  return vsel_vd_vm_vd_vd(visinf_vm_vd(d),
                          vsel_vd_vm_vd_vd(vec_cmplt(d, vec_splats(0.0)),
                                           vec_cpsgn(d, m), m), vec_splats(0.0));
}

static INLINE vdouble vpow2i_vd_vi(vint q) {
  vdouble r;
  F04(j) {
    long z = ((long)(q.v[j] + 0x3ff)) << 52;
    double y;
    memcpy(&y, &z, sizeof(double));
    r[j] = y;
  }

  return r;
}

static INLINE vdouble vldexp_vd_vd_vi(vdouble x, vint q) {
  vdouble u, v;
  F04(j) {
    int m;
    long n;
    m = q.v[j] >> 31;
    m = (((m + q.v[j]) >> 9) - m) << 7;
    q.v[j] = q.v[j] - (m << 2);
    m += 0x3ff;
    m = m < 0     ? 0     : m;
    m = m > 0x7ff ? 0x7ff : m;
    n = ((long)m) << 52;
    double y;
    memcpy(&y, &n, sizeof(double));
    u[j] = y;
    n = ((long)(q.v[j] + 0x3ff)) << 52;
    memcpy(&y, &n, sizeof(double));
    v[j] = y;
  }

  x = vec_mul(vec_mul(vec_mul(vec_mul(x, u), u), u), u);
  return vec_mul(x, v);
}

static INLINE vint vilogbp1_vi_vd(vdouble d) {
  vmask m = vec_cmplt(d, vec_splats(4.9090934652977266E-91));
  d = vsel_vd_vm_vd_vd(m, vec_mul(d, vec_splats(2.037035976334486E90)), d);

  vint2 e;
  vec_st(d, 0, e.v);

  vint r;
  F04(j) {
    int q = (e.v[j] >> 52) & 0x7ff;
    r.v[j] = (m[j] >= 0) ? q - (300 + 0x03fe) : q - 0x03fe;
  }

  return r;
}

static INLINE vdouble vupper_vd_vd(vdouble d) {
  vint2 q;
  vec_st(d, 0, q.v);

  F04(j) q.v[j] &= 0xfffffffff8000000;

  return vec_ld(0, q.v);
}

#define vupper_vf_vf vupper_vd_vd

