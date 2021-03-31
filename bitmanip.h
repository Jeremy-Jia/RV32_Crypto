#ifndef _BITMANIP_H_
#define _BITMANIP_H_

#include <stdint.h>

//  rotate right ROR / RORI ����ѭ����λ
uint32_t rv32b_ror(uint32_t rs1, uint32_t rs2);

//  and with negate ANDN ��ǲ���
uint64_t rv32b_andn(uint32_t rs1, uint32_t rs2);

//  generalized reverse GREV / GREVI 
uint32_t rv32b_grev(uint32_t rs1, uint32_t rs2);

//  generalized shuffle SHFL / SHFLI
uint32_t rv32b_shfl(uint32_t rs1, uint32_t rs2);

//  generalized unshuffle UNSHFL / UNSHFLI
uint32_t rv32b_unshfl(uint32_t rs1, uint32_t rs2);

//  carryless multiply �޽�λ�˷�
uint32_t rv32b_clmul(uint32_t rs1, uint32_t rs2);
uint32_t rv32b_clmulh(uint32_t rs1, uint32_t rs2);
uint32_t rv32b_clmulr(uint32_t rs1, uint32_t rs2);

#endif										//  _BITMANIP_H_