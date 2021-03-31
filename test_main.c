#include <stdio.h>

#include "sha2_wrap.h"

int test_sha2_256();						//  sha2_test.cpp
int test_sha2_512();
int test_sha2_hmac();

// int test_sm3();								//  test_sm3.cpp

int main(int argc, char** argv)
{
	//// rv32b_clmulh函数测试
	char s[33];
	printf("******************\t[TEST] rv32b_clmul \t********************\n");

	uint32_t a3 = 0b01001100000000000000000000000000;
	a3 = 1275068416;
	uint32_t b3 = 0b11001000000000000000000000000000;
	uint32_t test_c3;
	printf("a3 is 0x%8x\t", a3);
	printf("b3 is 0x%8x\t", b3);
	test_c3 = rv32b_clmulh(a3, b3);
	printf("c3 is 0x%8x\n", test_c3);

	printf("a3 is 0x%8x\t", a3);
	printf("b3 is 0x%8x\t", b3);
	test_c3 = rv32b_clmulr(a3, b3);
	printf("c3 is 0x%8x\n", test_c3);
	
	printf("******************\t[TEST] rv32b_clmul \t********************\n\n");

	int fail = 0;
	//printf("[INFO] === sing")
	//uint8_t md[32];
	//sha2_256(md, "abc", 3);

	printf("[INFO] === SHA2-256 using rv32_sha256_compress() ===\n");
	sha256_compress = rv32_sha256_compress;
	fail += test_sha2_256();

	printf("\n\n\n[INFO] === SHA2-512 using rv32_sha512_compress() ===\n");
	sha512_compress = rv32_sha512_compress;
	fail += test_sha2_512();

	printf("\n\n\n[INFO] === rv32_sha256_compress() rv64_sha512_compress() ===\n");
	sha256_compress = rv32_sha256_compress;
	fail += test_sha2_hmac();

	
	//printf("[INFO] === SM3 tests ===\n");
	//fail += test_sm3();
	
	
	printf("\n[%s] === finished with %d unit test failures ===\n",
		fail == 0 ? "PASS" : "FAIL", fail);
	
	return 0;
}
