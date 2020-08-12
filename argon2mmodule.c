#include <Python.h>

#include "argon2m.h"

static PyObject *argon2m_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    argon2m_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    argon2m_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Argon2mMethods[] = {
    { "getPoWHash", argon2m_getpowhash, METH_VARARGS, "Returns the proof of work hash using argon2m hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Argon2mModule = {
    PyModuleDef_HEAD_INIT,
    "argon2m_hash",
    "...",
    -1,
    Argon2mMethods
};

PyMODINIT_FUNC PyInit_argon2m_hash(void) {
    return PyModule_Create(&Argon2mModule);
}

#else

PyMODINIT_FUNC initargon2m_hash(void) {
    (void) Py_InitModule("argon2m_hash", Argon2mMethods);
}
#endif
