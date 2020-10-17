================================================
Interoperation between pybind11 and boost.python
================================================

.. _pybind11: https://pybind11.readthedocs.io/
.. _boost.python: https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/index.html

pybind11_ and boost.python_ are wrapping tool between C++ and Python and
provide comprehensive extending and embedding capabilities.  Both have
dedicated type conversion systems for the two languages.  This article and the
associated repository are set up to show how to make the two conversion
registries know each other.
