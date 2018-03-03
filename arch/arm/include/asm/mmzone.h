/* 2010-10-15: File added and changed by Sony Corporation */
/*
 *  arch/arm/include/asm/mmzone.h
 *
 *  1999-12-29	Nicolas Pitre		Created
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __ASM_MMZONE_H
#define __ASM_MMZONE_H

#if defined (CONFIG_NEED_MULTIPLE_NODES) && !defined (CONFIG_DISCONTIGMEM)
extern  pg_data_t node_data[];
/*
 * Return a pointer to the node data for node n.
 */
#define NODE_DATA(nid)		(&node_data[nid])

#else
/*
 * Currently defined in arch/arm/mm/discontig.c
 */
extern pg_data_t discontig_node_data[];

/*
 * Return a pointer to the node data for node n.
 */
#define NODE_DATA(nid)		(&discontig_node_data[nid])
#endif

/*
 * NODE_MEM_MAP gives the kaddr for the mem_map of the node.
 */
#define NODE_MEM_MAP(nid)	(NODE_DATA(nid)->node_mem_map)

#include <mach/memory.h>

#endif
