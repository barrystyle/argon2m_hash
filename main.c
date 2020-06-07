#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <argon2m.h>

int main()
{
	char blockhdr[80] = {0};
        char hash[32] = {0};

        argon2m_hash(blockhdr, hash);

        for (int i=0; i<32; i++)
           printf("%02hhx",hash[i]);
        printf("\n");

	return 0;
}
