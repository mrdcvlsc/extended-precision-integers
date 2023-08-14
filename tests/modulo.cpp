#include "../include/epi/epi.hpp"

#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
  smlts::test t;

  constexpr uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, v = 0xfffffffffffffff;
  constexpr uint64_t d = 0xdeadbeef, e = 0xcafebabe, f = 0xdeed, g = 0xdeadcafebeef, h = 0xfeedbabedeadbeef;

  constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, b_8t = {0x1},
                      c_8t = {0xff, 0xff, 0xff, 0xff}, v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, d_8t = d,
                      e_8t = e, f_8t = f, g_8t = g, h_8t = h;

  constexpr uint64_16t a_16t = {0xffff, 0xffff, 0xffff, 0xffff}, b_16t = {0x1}, c_16t = {0xffff, 0xffff},
                       v_16t = {0xfff, 0xffff, 0xffff, 0xffff}, d_16t = d, e_16t = e, f_16t = f, g_16t = g, h_16t = h;

  constexpr uint64_32t a_32t = {0xffffffff, 0xffffffff}, b_32t = {0x1}, c_32t = {0xffffffff},
                       v_32t = {0xfffffff, 0xffffffff}, d_32t = d, e_32t = e, f_32t = f, g_32t = g, h_32t = h;

  // operations
  constexpr uint64_t x = a % b, y = a % c, z = a % a, m = b % c, av = a % v, ad = a % d, ae = a % e, af = a % f,
                     ag = a % g, ah = a % h, hv = h % v, hd = h % d, he = h % e, hf = h % f, hg = h % g, gv = g % v,
                     gd = g % d, ge = g % e, gf = g % f, gh = g % h, dv = d % v, de = d % e, df = d % f, dg = d % g,
                     dh = d % h, vd = v % d, ve = v % e, vf = v % f, vg = v % g, vh = v % h, ev = e % v, ed = e % d,
                     ef = e % f, eg = e % g, eh = e % h;

  constexpr uint64_8t x_8t = a_8t % b_8t, y_8t = a_8t % c_8t, z_8t = a_8t % a_8t, m_8t = b_8t % c_8t,
                      av_8t = a_8t % v_8t, ad_8t = a_8t % d_8t, ae_8t = a_8t % e_8t, af_8t = a_8t % f_8t,
                      ag_8t = a_8t % g_8t, ah_8t = a_8t % h_8t, hv_8t = h_8t % v_8t, hd_8t = h_8t % d_8t,
                      he_8t = h_8t % e_8t, hf_8t = h_8t % f_8t, hg_8t = h_8t % g_8t, gv_8t = g_8t % v_8t,
                      gd_8t = g_8t % d_8t, ge_8t = g_8t % e_8t, gf_8t = g_8t % f_8t, gh_8t = g_8t % h_8t,
                      dv_8t = d_8t % v_8t, de_8t = d_8t % e_8t, df_8t = d_8t % f_8t, dg_8t = d_8t % g_8t,
                      dh_8t = d_8t % h_8t, vd_8t = v_8t % d_8t, ve_8t = v_8t % e_8t, vf_8t = v_8t % f_8t,
                      vg_8t = v_8t % g_8t, vh_8t = v_8t % h_8t, ev_8t = e_8t % v_8t, ed_8t = e_8t % d_8t,
                      ef_8t = e_8t % f_8t, eg_8t = e_8t % g_8t, eh_8t = e_8t % h_8t;

  constexpr uint64_16t x_16t = a_16t % b_16t, y_16t = a_16t % c_16t, z_16t = a_16t % a_16t, m_16t = b_16t % c_16t,
                       av_16t = a_16t % v_16t, ad_16t = a_16t % d_16t, ae_16t = a_16t % e_16t, af_16t = a_16t % f_16t,
                       ag_16t = a_16t % g_16t, ah_16t = a_16t % h_16t, hv_16t = h_16t % v_16t, hd_16t = h_16t % d_16t,
                       he_16t = h_16t % e_16t, hf_16t = h_16t % f_16t, hg_16t = h_16t % g_16t, gv_16t = g_16t % v_16t,
                       gd_16t = g_16t % d_16t, ge_16t = g_16t % e_16t, gf_16t = g_16t % f_16t, gh_16t = g_16t % h_16t,
                       dv_16t = d_16t % v_16t, de_16t = d_16t % e_16t, df_16t = d_16t % f_16t, dg_16t = d_16t % g_16t,
                       dh_16t = d_16t % h_16t, vd_16t = v_16t % d_16t, ve_16t = v_16t % e_16t, vf_16t = v_16t % f_16t,
                       vg_16t = v_16t % g_16t, vh_16t = v_16t % h_16t, ev_16t = e_16t % v_16t, ed_16t = e_16t % d_16t,
                       ef_16t = e_16t % f_16t, eg_16t = e_16t % g_16t, eh_16t = e_16t % h_16t;

  constexpr uint64_32t x_32t = a_32t % b_32t, y_32t = a_32t % c_32t, z_32t = a_32t % a_32t, m_32t = b_32t % c_32t,
                       av_32t = a_32t % v_32t, ad_32t = a_32t % d_32t, ae_32t = a_32t % e_32t, af_32t = a_32t % f_32t,
                       ag_32t = a_32t % g_32t, ah_32t = a_32t % h_32t, hv_32t = h_32t % v_32t, hd_32t = h_32t % d_32t,
                       he_32t = h_32t % e_32t, hf_32t = h_32t % f_32t, hg_32t = h_32t % g_32t, gv_32t = g_32t % v_32t,
                       gd_32t = g_32t % d_32t, ge_32t = g_32t % e_32t, gf_32t = g_32t % f_32t, gh_32t = g_32t % h_32t,
                       dv_32t = d_32t % v_32t, de_32t = d_32t % e_32t, df_32t = d_32t % f_32t, dg_32t = d_32t % g_32t,
                       dh_32t = d_32t % h_32t, vd_32t = v_32t % d_32t, ve_32t = v_32t % e_32t, vf_32t = v_32t % f_32t,
                       vg_32t = v_32t % g_32t, vh_32t = v_32t % h_32t, ev_32t = e_32t % v_32t, ed_32t = e_32t % d_32t,
                       ef_32t = e_32t % f_32t, eg_32t = e_32t % g_32t, eh_32t = e_32t % h_32t;

  t.cmp_eq(x_8t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(y_8t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(z_8t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(m_8t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(av_8t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(ad_8t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(ae_8t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(af_8t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(ag_8t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(ah_8t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(hv_8t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(hd_8t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(he_8t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(hf_8t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(hg_8t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(gv_8t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(gd_8t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(ge_8t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(gf_8t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(gh_8t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(dv_8t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(de_8t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(df_8t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(dg_8t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(dh_8t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(vd_8t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(ve_8t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(vf_8t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(vg_8t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(vh_8t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(ev_8t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(ed_8t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(ef_8t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(eg_8t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(eh_8t, eh, 8, __FILE__, __LINE__);

  t.cmp_eq(x_16t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(y_16t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(z_16t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(m_16t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(av_16t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(ad_16t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(ae_16t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(af_16t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(ag_16t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(ah_16t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(hv_16t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(hd_16t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(he_16t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(hf_16t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(hg_16t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(gv_16t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(gd_16t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(ge_16t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(gf_16t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(gh_16t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(dv_16t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(de_16t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(df_16t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(dg_16t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(dh_16t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(vd_16t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(ve_16t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(vf_16t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(vg_16t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(vh_16t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(ev_16t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(ed_16t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(ef_16t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(eg_16t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(eh_16t, eh, 8, __FILE__, __LINE__);

  t.cmp_eq(x_32t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(y_32t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(z_32t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(m_32t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(av_32t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(ad_32t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(ae_32t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(af_32t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(ag_32t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(ah_32t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(hv_32t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(hd_32t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(he_32t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(hf_32t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(hg_32t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(gv_32t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(gd_32t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(ge_32t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(gf_32t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(gh_32t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(dv_32t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(de_32t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(df_32t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(dg_32t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(dh_32t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(vd_32t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(ve_32t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(vf_32t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(vg_32t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(vh_32t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(ev_32t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(ed_32t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(ef_32t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(eg_32t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(eh_32t, eh, 8, __FILE__, __LINE__);

  // self operations assign

  uint64_8t self_x_8t = a_8t;
  self_x_8t %= b_8t;
  uint64_8t self_y_8t = a_8t;
  self_y_8t %= c_8t;
  uint64_8t self_z_8t = a_8t;
  self_z_8t %= a_8t;
  uint64_8t self_m_8t = b_8t;
  self_m_8t %= c_8t;
  uint64_8t self_av_8t = a_8t;
  self_av_8t %= v_8t;
  uint64_8t self_ad_8t = a_8t;
  self_ad_8t %= d_8t;
  uint64_8t self_ae_8t = a_8t;
  self_ae_8t %= e_8t;
  uint64_8t self_af_8t = a_8t;
  self_af_8t %= f_8t;
  uint64_8t self_ag_8t = a_8t;
  self_ag_8t %= g_8t;
  uint64_8t self_ah_8t = a_8t;
  self_ah_8t %= h_8t;
  uint64_8t self_hv_8t = h_8t;
  self_hv_8t %= v_8t;
  uint64_8t self_hd_8t = h_8t;
  self_hd_8t %= d_8t;
  uint64_8t self_he_8t = h_8t;
  self_he_8t %= e_8t;
  uint64_8t self_hf_8t = h_8t;
  self_hf_8t %= f_8t;
  uint64_8t self_hg_8t = h_8t;
  self_hg_8t %= g_8t;
  uint64_8t self_gv_8t = g_8t;
  self_gv_8t %= v_8t;
  uint64_8t self_gd_8t = g_8t;
  self_gd_8t %= d_8t;
  uint64_8t self_ge_8t = g_8t;
  self_ge_8t %= e_8t;
  uint64_8t self_gf_8t = g_8t;
  self_gf_8t %= f_8t;
  uint64_8t self_gh_8t = g_8t;
  self_gh_8t %= h_8t;
  uint64_8t self_dv_8t = d_8t;
  self_dv_8t %= v_8t;
  uint64_8t self_de_8t = d_8t;
  self_de_8t %= e_8t;
  uint64_8t self_df_8t = d_8t;
  self_df_8t %= f_8t;
  uint64_8t self_dg_8t = d_8t;
  self_dg_8t %= g_8t;
  uint64_8t self_dh_8t = d_8t;
  self_dh_8t %= h_8t;
  uint64_8t self_vd_8t = v_8t;
  self_vd_8t %= d_8t;
  uint64_8t self_ve_8t = v_8t;
  self_ve_8t %= e_8t;
  uint64_8t self_vf_8t = v_8t;
  self_vf_8t %= f_8t;
  uint64_8t self_vg_8t = v_8t;
  self_vg_8t %= g_8t;
  uint64_8t self_vh_8t = v_8t;
  self_vh_8t %= h_8t;
  uint64_8t self_ev_8t = e_8t;
  self_ev_8t %= v_8t;
  uint64_8t self_ed_8t = e_8t;
  self_ed_8t %= d_8t;
  uint64_8t self_ef_8t = e_8t;
  self_ef_8t %= f_8t;
  uint64_8t self_eg_8t = e_8t;
  self_eg_8t %= g_8t;
  uint64_8t self_eh_8t = e_8t;
  self_eh_8t %= h_8t;

  uint64_16t self_x_16t = a_16t;
  self_x_16t %= b_16t;
  uint64_16t self_y_16t = a_16t;
  self_y_16t %= c_16t;
  uint64_16t self_z_16t = a_16t;
  self_z_16t %= a_16t;
  uint64_16t self_m_16t = b_16t;
  self_m_16t %= c_16t;
  uint64_16t self_av_16t = a_16t;
  self_av_16t %= v_16t;
  uint64_16t self_ad_16t = a_16t;
  self_ad_16t %= d_16t;
  uint64_16t self_ae_16t = a_16t;
  self_ae_16t %= e_16t;
  uint64_16t self_af_16t = a_16t;
  self_af_16t %= f_16t;
  uint64_16t self_ag_16t = a_16t;
  self_ag_16t %= g_16t;
  uint64_16t self_ah_16t = a_16t;
  self_ah_16t %= h_16t;
  uint64_16t self_hv_16t = h_16t;
  self_hv_16t %= v_16t;
  uint64_16t self_hd_16t = h_16t;
  self_hd_16t %= d_16t;
  uint64_16t self_he_16t = h_16t;
  self_he_16t %= e_16t;
  uint64_16t self_hf_16t = h_16t;
  self_hf_16t %= f_16t;
  uint64_16t self_hg_16t = h_16t;
  self_hg_16t %= g_16t;
  uint64_16t self_gv_16t = g_16t;
  self_gv_16t %= v_16t;
  uint64_16t self_gd_16t = g_16t;
  self_gd_16t %= d_16t;
  uint64_16t self_ge_16t = g_16t;
  self_ge_16t %= e_16t;
  uint64_16t self_gf_16t = g_16t;
  self_gf_16t %= f_16t;
  uint64_16t self_gh_16t = g_16t;
  self_gh_16t %= h_16t;
  uint64_16t self_dv_16t = d_16t;
  self_dv_16t %= v_16t;
  uint64_16t self_de_16t = d_16t;
  self_de_16t %= e_16t;
  uint64_16t self_df_16t = d_16t;
  self_df_16t %= f_16t;
  uint64_16t self_dg_16t = d_16t;
  self_dg_16t %= g_16t;
  uint64_16t self_dh_16t = d_16t;
  self_dh_16t %= h_16t;
  uint64_16t self_vd_16t = v_16t;
  self_vd_16t %= d_16t;
  uint64_16t self_ve_16t = v_16t;
  self_ve_16t %= e_16t;
  uint64_16t self_vf_16t = v_16t;
  self_vf_16t %= f_16t;
  uint64_16t self_vg_16t = v_16t;
  self_vg_16t %= g_16t;
  uint64_16t self_vh_16t = v_16t;
  self_vh_16t %= h_16t;
  uint64_16t self_ev_16t = e_16t;
  self_ev_16t %= v_16t;
  uint64_16t self_ed_16t = e_16t;
  self_ed_16t %= d_16t;
  uint64_16t self_ef_16t = e_16t;
  self_ef_16t %= f_16t;
  uint64_16t self_eg_16t = e_16t;
  self_eg_16t %= g_16t;
  uint64_16t self_eh_16t = e_16t;
  self_eh_16t %= h_16t;

  uint64_32t self_x_32t = a_32t;
  self_x_32t %= b_32t;
  uint64_32t self_y_32t = a_32t;
  self_y_32t %= c_32t;
  uint64_32t self_z_32t = a_32t;
  self_z_32t %= a_32t;
  uint64_32t self_m_32t = b_32t;
  self_m_32t %= c_32t;
  uint64_32t self_av_32t = a_32t;
  self_av_32t %= v_32t;
  uint64_32t self_ad_32t = a_32t;
  self_ad_32t %= d_32t;
  uint64_32t self_ae_32t = a_32t;
  self_ae_32t %= e_32t;
  uint64_32t self_af_32t = a_32t;
  self_af_32t %= f_32t;
  uint64_32t self_ag_32t = a_32t;
  self_ag_32t %= g_32t;
  uint64_32t self_ah_32t = a_32t;
  self_ah_32t %= h_32t;
  uint64_32t self_hv_32t = h_32t;
  self_hv_32t %= v_32t;
  uint64_32t self_hd_32t = h_32t;
  self_hd_32t %= d_32t;
  uint64_32t self_he_32t = h_32t;
  self_he_32t %= e_32t;
  uint64_32t self_hf_32t = h_32t;
  self_hf_32t %= f_32t;
  uint64_32t self_hg_32t = h_32t;
  self_hg_32t %= g_32t;
  uint64_32t self_gv_32t = g_32t;
  self_gv_32t %= v_32t;
  uint64_32t self_gd_32t = g_32t;
  self_gd_32t %= d_32t;
  uint64_32t self_ge_32t = g_32t;
  self_ge_32t %= e_32t;
  uint64_32t self_gf_32t = g_32t;
  self_gf_32t %= f_32t;
  uint64_32t self_gh_32t = g_32t;
  self_gh_32t %= h_32t;
  uint64_32t self_dv_32t = d_32t;
  self_dv_32t %= v_32t;
  uint64_32t self_de_32t = d_32t;
  self_de_32t %= e_32t;
  uint64_32t self_df_32t = d_32t;
  self_df_32t %= f_32t;
  uint64_32t self_dg_32t = d_32t;
  self_dg_32t %= g_32t;
  uint64_32t self_dh_32t = d_32t;
  self_dh_32t %= h_32t;
  uint64_32t self_vd_32t = v_32t;
  self_vd_32t %= d_32t;
  uint64_32t self_ve_32t = v_32t;
  self_ve_32t %= e_32t;
  uint64_32t self_vf_32t = v_32t;
  self_vf_32t %= f_32t;
  uint64_32t self_vg_32t = v_32t;
  self_vg_32t %= g_32t;
  uint64_32t self_vh_32t = v_32t;
  self_vh_32t %= h_32t;
  uint64_32t self_ev_32t = e_32t;
  self_ev_32t %= v_32t;
  uint64_32t self_ed_32t = e_32t;
  self_ed_32t %= d_32t;
  uint64_32t self_ef_32t = e_32t;
  self_ef_32t %= f_32t;
  uint64_32t self_eg_32t = e_32t;
  self_eg_32t %= g_32t;
  uint64_32t self_eh_32t = e_32t;
  self_eh_32t %= h_32t;

  t.cmp_eq(self_x_8t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(self_y_8t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(self_z_8t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(self_m_8t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(self_av_8t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ad_8t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ae_8t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(self_af_8t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ag_8t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ah_8t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hv_8t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hd_8t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_he_8t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hf_8t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hg_8t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gv_8t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gd_8t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ge_8t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gf_8t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gh_8t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dv_8t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_de_8t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(self_df_8t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dg_8t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dh_8t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vd_8t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ve_8t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vf_8t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vg_8t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vh_8t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ev_8t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ed_8t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ef_8t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eg_8t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eh_8t, eh, 8, __FILE__, __LINE__);

  t.cmp_eq(self_x_16t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(self_y_16t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(self_z_16t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(self_m_16t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(self_av_16t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ad_16t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ae_16t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(self_af_16t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ag_16t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ah_16t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hv_16t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hd_16t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_he_16t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hf_16t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hg_16t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gv_16t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gd_16t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ge_16t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gf_16t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gh_16t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dv_16t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_de_16t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(self_df_16t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dg_16t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dh_16t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vd_16t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ve_16t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vf_16t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vg_16t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vh_16t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ev_16t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ed_16t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ef_16t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eg_16t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eh_16t, eh, 8, __FILE__, __LINE__);

  t.cmp_eq(self_x_32t, x, 8, __FILE__, __LINE__);
  t.cmp_eq(self_y_32t, y, 8, __FILE__, __LINE__);
  t.cmp_eq(self_z_32t, z, 8, __FILE__, __LINE__);
  t.cmp_eq(self_m_32t, m, 8, __FILE__, __LINE__);
  t.cmp_eq(self_av_32t, av, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ad_32t, ad, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ae_32t, ae, 8, __FILE__, __LINE__);
  t.cmp_eq(self_af_32t, af, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ag_32t, ag, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ah_32t, ah, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hv_32t, hv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hd_32t, hd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_he_32t, he, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hf_32t, hf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_hg_32t, hg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gv_32t, gv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gd_32t, gd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ge_32t, ge, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gf_32t, gf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_gh_32t, gh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dv_32t, dv, 8, __FILE__, __LINE__);
  t.cmp_eq(self_de_32t, de, 8, __FILE__, __LINE__);
  t.cmp_eq(self_df_32t, df, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dg_32t, dg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_dh_32t, dh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vd_32t, vd, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ve_32t, ve, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vf_32t, vf, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vg_32t, vg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_vh_32t, vh, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ev_32t, ev, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ed_32t, ed, 8, __FILE__, __LINE__);
  t.cmp_eq(self_ef_32t, ef, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eg_32t, eg, 8, __FILE__, __LINE__);
  t.cmp_eq(self_eh_32t, eh, 8, __FILE__, __LINE__);

  return t.get_final_verdict("MODULO");
}