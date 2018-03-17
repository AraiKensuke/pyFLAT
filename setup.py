import numpy
import sys
import os
from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc


###  import LogitWrapper 
###  LogitWrapper
#  -undefined dynamic_lookup
#  -lgsl
#  -fpic   #  build a shared
#  -bundle

#  OMP_THREAD_NUM

#  use --user  to install in
#  to specify compiler, maybe set CC environment variable
#  or python setup.py build --compiler=g++
incldir = [get_python_inc(plat_specific=1), numpy.get_include(), "pyPG/include/RNG", "/usr/local/include"]

libdir = ["/usr/local/lib"]
os.environ["CC"]  = "g++-6"
os.environ["CXX"] = "g++-6"

#  may also need to set $LD_LIBRARY_PATH in order to use shared libgsl


sources=['cpp_python_module.cpp']

#  Output to be named _LogitWrapper.so
module1 = Extension('cpp_python_module',
                    include_dirs=incldir,
                    library_dirs=libdir,
                    sources=sources)
setup(
    name='pyFLAT',
    version='0.1',
    packages=[''],
    ext_modules=[module1],
    author="Kensuke Arai",
    description="Simple Python Module",
    email="kensuke.y.arai@gmail.com",
    url="http://github.com/AraiKensuke/pySIMPLE"
)
