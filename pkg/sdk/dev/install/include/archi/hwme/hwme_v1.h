/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * Authors:  Francesco Conti <fconti@iis.ee.ethz.ch>
 */

#ifndef __ARCHI_HWME_V1_H__
#define __ARCHI_HWME_V1_H__

/*
 * Control and generic configuration register layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0000  |  31: 0  |  0xffffffff  ||  TRIGGER
 *     1  |  0x0004  |  31: 0  |  0xffffffff  ||  ACQUIRE
 *     2  |  0x0008  |  31: 0  |  0xffffffff  ||  EVT_ENABLE
 *     3  |  0x000c  |  31: 0  |  0xffffffff  ||  STATUS
 *     4  |  0x0010  |  31: 0  |  0xffffffff  ||  RUNNING_JOB
 *     5  |  0x0014  |  31: 0  |  0xffffffff  ||  SOFT_CLEAR
 *   6-7  |          |         |              ||  Reserved
 *     8  |  0x0020  |  31: 0  |  0xffffffff  ||  BYTECODE0 [31:0]
 *     9  |  0x0024  |  31: 0  |  0xffffffff  ||  BYTECODE1 [63:32]
 *    10  |  0x0028  |  31: 0  |  0xffffffff  ||  BYTECODE2 [95:64]
 *    11  |  0x002c  |  31: 0  |  0xffffffff  ||  BYTECODE3 [127:96]
 *    12  |  0x0030  |  31: 0  |  0xffffffff  ||  BYTECODE4 [159:128]
 *    13  |  0x0034  |  31:16  |  0xffff0000  ||  LOOPS0    [15:0]
 *        |          |  15: 0  |  0x0000ffff  ||  BYTECODE5 [175:160]
 *    14  |  0x0038  |  31: 0  |  0xffffffff  ||  LOOPS1    [47:16]
 *    15  |          |  31: 0  |  0xffffffff  ||  Reserved
 * ================================================================================
 *
 * Job-dependent registers layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0040  |  31: 0  |  0xffffffff  ||  A_ADDR
 *     1  |  0x0044  |  31: 0  |  0xffffffff  ||  B_ADDR
 *     2  |  0x0048  |  31: 0  |  0xffffffff  ||  C_ADDR
 *     3  |  0x004c  |  31: 0  |  0xffffffff  ||  D_ADDR
 *     4  |  0x0050  |  31: 0  |  0xffffffff  ||  NB_ITER
 *     5  |  0x0054  |  31: 0  |  0xffffffff  ||  LEN_ITER
 *     6  |  0x0058  |  31:16  |  0xffff0000  ||  SHIFT
 *        |          |   0: 0  |  0x00000001  ||  SIMPLEMUL
 *     7  |  0x005c  |  31: 0  |  0xffffffff  ||  VECTSTRIDE
 *     8  |  0x0060  |  31: 0  |  0xffffffff  ||  VECTSTRIDE2
 * ================================================================================
 *
 */

#define HWME_TRIGGER          0x00
#define HWME_ACQUIRE          0x04
#define HWME_FINISHED         0x08
#define HWME_STATUS           0x0c
#define HWME_RUNNING_JOB      0x10
#define HWME_SOFT_CLEAR       0x14

#define HWME_BYTECODE         0x20
#define HWME_BYTECODE0_OFFS        0x00
#define HWME_BYTECODE1_OFFS        0x04
#define HWME_BYTECODE2_OFFS        0x08
#define HWME_BYTECODE3_OFFS        0x0c
#define HWME_BYTECODE4_OFFS        0x10
#define HWME_BYTECODE5_LOOPS0_OFFS 0x14
#define HWME_LOOPS1_OFFS           0x18

//#define HWME_A_ADDR          0x40
//#define HWME_B_ADDR          0x44
//#define HWME_C_ADDR          0x48
//#define HWME_D_ADDR          0x4c
//#define HWME_NB_ITER         0x50
//#define HWME_LEN_ITER        0x54
//#define HWME_SHIFT_SIMPLEMUL 0x58
//#define HWME_VECTSTRIDE      0x5c
//#define HWME_VECTSTRIDE2     0x60

// digital core registers
#define HWME_WT_CONV_ADDR          0x40
#define HWME_WT_CONV_N             0x44
#define HWME_WT_FC_ADDR            0x48
#define HWME_WT_FC_N               0x4c
#define HWME_IM_ADDR               0x50
#define HWME_IM_N                  0x54
#define HWME_ACT_ADDR              0x58
#define HWME_ACT_N                 0x5c
#define HWME_CONF_ADDR             0x60
#define HWME_CONF_N                0x64
#define HWME_WT_CONV_A_ADDR        0x68
#define HWME_WT_FC_A_ADDR          0x6c
#define HWME_IM_A_ADDR             0x70
#define HWME_ACT_A_ADDR            0x74
#define HWME_CONF_A_ADDR           0x78
#define HWME_OUT_DATA              0x7c
#define HWME_OUT_DATA_N            0x80
#define HWME_NB_TILE               0x84
#define HWME_LUT_ADDR              0x88
#define HWME_LUT_N                 0x8c
#define HWME_LUT_A_ADDR            0x90
#define HWME_SPAR_ADDR             0x94
#define HWME_SPAR_N                0x98
#define HWME_SPAR_A_ADDR           0x9c
#define HWME_MEMCPY_OP             0xa0
#define HWME_MEMCPY_ADDR           0xa4
#define HWME_MEMCPY_N              0xa8
#define HWME_L1ADDR                0xac
#define HWME_MEMCPY_BANK_LENGTH    0xb0
#define HWME_MEMCPY_ROW_LENGTH     0xb4
#define HWME_WT_MEM_ADDR           0xb8

// analog core registers
#define HWME_ANA_WT_CONV_ADDR          0x40
#define HWME_ANA_WT_SIMD_ADDR          0x44
#define HWME_ANA_IM_ADDR               0x48
#define HWME_ANA_IM_N                  0x4c
#define HWME_ANA_ACT_ADDR              0x50
#define HWME_ANA_ACT_N                 0x54
#define HWME_ANA_CONF_ADDR             0x58
#define HWME_ANA_CONF_N                0x5c
#define HWME_ANA_OUT_DATA              0x60
#define HWME_ANA_OUT_DATA_N            0x64
#define HWME_ANA_NB_TILE               0x68
#define HWME_ANA_MEMCPY_OP             0x6c
#define HWME_ANA_MEMCPY_ADDR           0x70
#define HWME_ANA_MEMCPY_N              0x74
#define HWME_ANA_L1ADDR                0x78
#define HWME_ANA_MEMCPY_BANK_LENGTH    0x7c
#define HWME_ANA_MEMCPY_ROW_LENGTH     0x80

#endif
