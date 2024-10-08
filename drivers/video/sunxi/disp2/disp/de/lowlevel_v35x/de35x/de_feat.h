/*
 * Allwinner SoCs display driver.
 *
 * Copyright (C) 2017 Allwinner.
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef _DE_FEAT_H_
#define _DE_FEAT_H_

#include <linux/types.h>


#define SUPPORT_FEAT_INIT_CONFIG
#define RTMX_USE_RCQ (0)
/*2 mean wb use de rcq for DE35x */
#define RTWB_USE_RCQ (0)
#define WB_HAS_CSC
#ifdef CONFIG_MACH_SUN55IW3
#define SUPPORT_RTWB
#endif

#define DE_NUM (2)
#define DE_RTWB_NUM (2)
#define GLB_MAX_CDC_NUM (3)

/* #define SUPPORT_SMBL */

#define VI_CHN_NUM (3)
#define MAX_CHN_NUM (7)
#define MAX_LAYER_NUM_PER_CHN (4)

#ifndef IOMMU_DE0_MASTOR_ID
#define IOMMU_DE0_MASTOR_ID 5
#define IOMMU_DE1_MASTOR_ID 5
#endif

enum {
	DE_SCALER_TYPE_NONE = 0,
	DE_SCALER_TYPE_VSU8,
	DE_SCALER_TYPE_VSU10,
	DE_SCALER_TYPE_VSU_ED,
	DE_SCALER_TYPE_GSU,
	DE_SCALER_TYPE_ASU,
};

struct de_feat_init {
	u32 chn_cfg_mode;
};

struct de_feat {
	s32 num_screens;
	const s32 *num_chns;
	const s32 *num_vi_chns;
	const s32 *num_layers;
	const s32 *is_support_vep;
	const s32 *is_support_smbl;
	const s32 *is_support_deband;
	const s32 *is_support_gamma;
	const s32 *is_support_dither;
	const s32 *is_support_wb;
	const s32 *is_support_scale;
	const s32 *scale_line_buffer_rgb;
	const s32 *scale_line_buffer_yuv;
	const s32 *scale_line_buffer_ed;
	const s32 *is_support_edscale;
	const s32 *is_support_asuscale;
	const s32 *is_support_dci;
	const s32 *is_support_fcm;
	const s32 *is_support_sharp;
	const s32 *is_support_de_noise;
	const s32 *is_support_cdc;
	const s32 *is_support_fbd;
	const s32 *is_support_atw;
	const s32 *is_support_snr;
	const s32 *is_support_ksc;

	const u32 *scaler_type;

	const s32 *chn_id_lut; /* phy chn id */
};

s32 de_feat_init_config(struct de_feat_init *feat_init);
s32 de_feat_get_num_screens(void);
s32 de_feat_get_num_chns(u32 disp);
s32 de_feat_get_num_vi_chns(u32 disp);
s32 de_feat_get_num_ui_chns(u32 disp);
s32 de_feat_get_num_layers(u32 disp);
s32 de_feat_get_num_layers_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_vep(u32 disp);
s32 de_feat_is_support_vep_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_smbl(u32 disp);
s32 de_feat_is_support_deband(u32 disp);
s32 de_feat_is_support_dither(u32 disp);
s32 de_feat_is_support_gamma(u32 disp);
s32 de_feat_is_support_wb(u32 disp);
s32 de_feat_is_support_scale(u32 disp);
s32 de_feat_is_support_scale_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_edscale(u32 disp);
s32 de_feat_is_support_edscale_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_asuscale(u32 disp);
s32 de_feat_is_support_asuscale_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_fcm_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_dci_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_sharp_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_de_noise(u32 disp);
s32 de_feat_is_support_de_noise_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_cdc_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_snr_by_chn(u32 disp, u32 chn);
s32 de_feat_is_support_fbd_by_layer(u32 disp, u32 chn,
	u32 layno);
s32 de_feat_is_support_atw_by_layer(u32 disp, u32 chn,
	u32 layno);
s32 de_feat_get_scale_linebuf_for_yuv(u32 disp, u32 chn);
s32 de_feat_get_scale_linebuf_for_rgb(u32 disp, u32 chn);
s32 de_feat_get_scale_linebuf_for_ed(u32 disp, u32 chn);

u32 de_feat_get_scaler_type(u32 disp, u32 chn);
s32 de_feat_get_phy_chn_id(u32 disp, u32 chn);

s32 de_feat_is_using_rcq(u32 disp);
s32 de_feat_is_using_wb_rcq(u32 wb);
unsigned int de_feat_get_number_of_vdpo(void);


#endif /* #ifndef _DE_FEAT_H_ */
