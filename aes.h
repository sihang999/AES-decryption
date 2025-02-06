/* 
 * aes.h - Header file for AES (Advanced Encryption Standard) decryption implementation
 * 
 * This file defines the function prototypes and constant lookup tables 
 * used in aes.c for AES encryption and decryption. The implementation 
 * primarily focuses on AES decryption in ECB mode.
 *
 * Key features:
 * - Provides function declarations for AES operations, such as Key Expansion, 
 *   SubBytes, ShiftRows, MixColumns, and Round transformations.
 * - Declares constant lookup tables (e.g., S-box, inverse S-box, and RCON) 
 *   used during AES encryption and decryption.
 * 
 * Usage:
 * Include this header in any source file that requires access to AES functions 
 * and lookup tables.
 */
#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

void rotWord(uint8_t * in);
void subWord(uint8_t * in);
void roundCon(uint8_t * in, uint8_t i);
void KeysExpansion(const uint8_t inputKey[16], uint8_t expandedKeys[176]);
void SubRoundKey(uint8_t * state, uint8_t * roundKey);
void InverseMixColumns(uint8_t * state) ;
void ShiftRows(uint8_t * state);
void SubBytes(uint8_t * state);
void Round(uint8_t * state, uint8_t * key, uint8_t *mask_in, uint8_t *mask_out, uint8_t round);
void InitialRound(uint8_t * state, uint8_t * key, uint8_t *mask_in, uint8_t *mask_out);
void AES_ECB_decrypt(uint8_t * expandedKey, uint8_t * buf);
void apply_mask(uint8_t *data, uint8_t *mask, int length);
void remove_mask(uint8_t *data, uint8_t *mask, int length);
void initialize_masked_sbox(uint8_t mask_in, uint8_t mask_out, uint8_t *masked_sbox);
void SubBytes_with_mask(uint8_t *state, uint8_t *mask_in, uint8_t *mask_out);
void random_delay(void);
void inject_noise(void);

extern const uint8_t s[256];
extern const uint8_t rcon[11];
extern const uint8_t inv_s[256];
extern const uint8_t mul9[256];
extern const uint8_t mul11[256];
extern const uint8_t mul13[256];
extern const uint8_t mul14[256];



#endif /* AES_H */