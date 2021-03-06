#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
  Bls12,
  Bn256,
} EngineType;

typedef struct {
  bool value;
  char *error;
} VerificationResult;

void free_memory(VerificationResult verification_result);

VerificationResult verify(const char *file_with_vk,
                          const uint8_t *inputs_array,
                          uintptr_t inputs_array_size,
                          EngineType engine);

VerificationResult verify_with_precompiled_proof(const char *file_with_vk,
                                                 const uint8_t *inputs_array,
                                                 uintptr_t inputs_array_size,
                                                 EngineType engine,
                                                 const uint8_t *proof_vec,
                                                 uintptr_t proof_vec_size);
