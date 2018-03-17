#  pyFLAT

A wrapper for a C++-written module.  


The simplest behavior of an `import mymodule` statement in python, is for python to look for a file called `mymodule.py` in a directory that's listed in your `${PYTHONPATH}`.  However, if one wishes to organize the contents of the files that make up "mymodule" into a directory structure (perhaps there are many components of mymodule), one would create a directory called "mymodule", and place inside it a file called `__init__.py`.  The `import mymodule` statement, in addition to its aforementioned simple behavior, will ALSO search for a __directory__ under `${PYTHONPATH}` called `mymodule`, containing a file called `__init__.py`.

In the case of the current `pyFLAT` module, a `python setup.py install` puts the pyFLAT.py file __directly__ into the `site-packages` folder of the python system library.  It also copies the compiled `cpp_python_module.so` directly into that folder.  This isn't ideal in terms of organization, but it works.  If `pyFLAT` had many files to it, our python `site-packages` folder would soon become messy.