/**
 * @file sha-256.c
 * @author seed 
 * @brief Calculate SHA-256 hash in C
 * @version 0.1
 * @date 2022-07-18
 * 
 * @compile gcc sha-256.c -lcrypto
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(void) {
    SHA256_CTX ctx;
    u_int8_t results[SHA256_DIGEST_LENGTH]; /* 256 b = 32 B */

    char *msg_part1 = "Part One ";
    char *msg_part2 = "Part Two ";
    char *msg_part3 = "Part Three";

    SHA256_Init(&ctx); /* Initialize a context data structure */
    
    /**
     * @brief
     * feed our message pieces to SHA256_Update()
     * SHA256_Update() breaks the message into blocks(64-Bytes for SHA-256)
     * and performs the compression function on each block in an order described in the Merkle-Damgard construction
     * The intermediate results are stored in the context
     */
    SHA256_Update(&ctx, msg_part1, strlen(msg_part1));
    SHA256_Update(&ctx, msg_part2, strlen(msg_part2));
    SHA256_Update(&ctx, msg_part3, strlen(msg_part3));

    /* Call SHA256_Final() to get the final hash value */ 
    SHA256_Final(results, &ctx);

    /* Print the message and the hash */
    printf("%s%s%s\n", msg_part1, msg_part2, msg_part3);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i ++) {
        printf("%02x", results[i]);
    }
    
    printf("\n");
}