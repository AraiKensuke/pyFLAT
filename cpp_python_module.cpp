////////////////////////////////////////////////////////////////////////////////

// Copyright 2014 Kensuke Arai, Scott 
// Copyright 2012 Nick Polson, James Scott, and Jesse Windle.

// This file is part of BayesLogit.

// BayesLogit is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or any later version.

// BayesLogit is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with
// BayesLogit.  If not, see <http://www.gnu.org/licenses/>.

////////////////////////////////////////////////////////////////////////////////

#include <Python.h>
#include <cstdio>

static PyObject *cpmError;

static PyObject *say_hi(PyObject *self, PyObject *args)
{
  printf("Hello world\n");

  Py_RETURN_NONE;
}

static PyMethodDef cpmMethods[] = {
    {"say_hi",  say_hi, METH_VARARGS,
     "just say hi"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initcpp_python_module(void)
{
  //  This gets called when "import spam" called.
  PyObject *m;

  m = Py_InitModule("cpp_python_module", cpmMethods);
  if (m == NULL)
    return;

  cpmError = PyErr_NewException("cpm.error", NULL, NULL);
  Py_INCREF(cpmError);
  PyModule_AddObject(m, "error", cpmError);
}
