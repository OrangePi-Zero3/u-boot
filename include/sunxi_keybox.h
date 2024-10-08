/*
 * (C) Copyright 2018-2020
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * wangwei <wangwei@allwinnertech.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#define KEYBOX_ENC_MASK   0x1
#define KEYBOX_ENC_OFFSET 0
#define KEYBOX_ENC_PARAM_MASK   0xF
#define KEYBOX_ENC_PARAM_OFFSET 28
#define KEYBOX_ENC_PARAM_ECB_256_SSK 0
#define KEYBOX_ENC_PARAM_CBC_128_HUK 1
#define KEYBOX_ENC_PARAM_CBC_192_HUK 2

int sunxi_keybox_has_key(char *key_name);
int sunxi_keybox_init(void);
int sunxi_keybox_burn_key(const char *name, char *buf, int key_len, int encrypt,
			  int write_protect);

struct sunxi_key_t{
	char *name;/*key name*/
	int (*key_burn_cb)(const char *name, char *buf, int key_len, int encrypt,
			  int write_protect);
	int (*key_load_cb)(const char *name);
};

#define SUNXI_KEYBOX_KEY(_name, _burn_cb, _install_cb) \
	ll_entry_declare(struct sunxi_key_t, _name, sunxi_keys) =			\
			{ #_name, _burn_cb, _install_cb };
