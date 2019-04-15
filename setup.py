from distutils.core import setup, Extension

argon2m_hash_module = Extension('argon2m_hash',
                 sources = ['argon2m.c',
                            'argon2m_module.c',
                            'argon2m/argon2.c',
                            'argon2m/core.c',
                            'argon2m/encoding.c',
                            'argon2m/opt.c',
                            'argon2m/thread.c',
                            'blake2/blake2b.c'],
                            include_dirs = ['.'])
setup (name = 'argon2m_hash',
       version = '1.0',
       description = 'argon2m hashing module',
       ext_modules = [argon2m_hash_module])
