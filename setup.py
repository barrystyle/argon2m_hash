from distutils.core import setup, Extension

argon2m_hash_module = Extension('argon2m_hash',
                                 sources = ['argon2mmodule.c',
                                            'argon2m.c',
                                            'argon2m/argon2/argon2.c',
                                            'argon2m/argon2/core.c',
                                            'argon2m/argon2/encoding.c',
                                            'argon2m/argon2/opt.c',
                                            'argon2m/blake2/blake2b.c'],
                               include_dirs=['.', './argon2m/blake2', './argon2m/argon2'])

setup (name = 'argon2m_hash',
       version = '1.0',
       description = 'Binding for Argon2M proof of work hashing.',
       ext_modules = [argon2m_hash_module])
