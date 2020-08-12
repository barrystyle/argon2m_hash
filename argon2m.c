#include "argon2m/argon2/argon2.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

//! argon2m hashing algorithm
static const unsigned int DEFAULT_ARGON2_FLAG = 2;

void argon2m_hash(const char* input, char* output)
{
    argon2_context context;
    context.out = (uint8_t*)(output);
    context.outlen = 32;
    context.pwd = (uint8_t*)(input);
    context.pwdlen = 80;
    context.salt = (uint8_t*)(input);
    context.saltlen = 80;
    context.secret = NULL;
    context.secretlen = 0;
    context.ad = NULL;
    context.adlen = 0;
    context.allocate_cbk = NULL;
    context.free_cbk = NULL;
    context.flags = DEFAULT_ARGON2_FLAG;
    context.m_cost = 2;
    context.lanes = 1;
    context.threads = 1;
    context.t_cost = 1;
    context.version = ARGON2_VERSION_13;
    argon2_ctx(&context, Argon2_id );
}
