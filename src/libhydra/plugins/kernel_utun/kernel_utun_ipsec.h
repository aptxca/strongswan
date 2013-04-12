/*
 * Copyright (C) 2013 Martin Willi
 * Copyright (C) 2013 revosec AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup kernel_utun_ipsec_i kernel_utun_ipsec
 * @{ @ingroup kernel_utun
 */

#ifndef KERNEL_UTUN_IPSEC_H_
#define KERNEL_UTUN_IPSEC_H_

#include <kernel/kernel_ipsec.h>

typedef struct kernel_utun_ipsec_t kernel_utun_ipsec_t;

/**
 * Implementation of the kernel ipsec interface using OS X utun devices.
 */
struct kernel_utun_ipsec_t {

	/**
	 * Implements kernel_ipsec_t interface
	 */
	kernel_ipsec_t interface;

	/**
	 * Add a virtual IP to the prefiously created utun device.
	 *
	 * @param vip			virtual IP
	 * @param prefix		network prefix
	 * @reuturn				SUCCESS if IP added
	 */
	status_t (*add_ip)(kernel_utun_ipsec_t *this, host_t *vip, int prefix);

	/**
	 * Remove a virtual IP from an utun device.
	 *
	 * @param vip			virtual IP
	 * @param prefix		network prefix
	 * @reuturn				SUCCESS if IP deleted
	 */
	status_t (*del_ip)(kernel_utun_ipsec_t *this, host_t *vip, int prefix);
};

/**
 * Create a utun kernel ipsec interface instance.
 *
 * @return			kernel_utun_ipsec_t instance
 */
kernel_utun_ipsec_t *kernel_utun_ipsec_create();

/**
 * Get the single instance of kernel_utun_ipsec_t, once created.
 *
 * @return			single instance of utun_ipsec
 */
kernel_utun_ipsec_t *kernel_utun_ipsec_get();

#endif /** KERNEL_UTUN_IPSEC_H_ @}*/
