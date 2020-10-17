#include <pybind11/pybind11.h>

#include "item.hpp"

PYBIND11_MODULE(modpyb, mod)
{
    namespace pyb = pybind11;

    mod.doc() = "extension module by pybind11";

    pyb::class_<ItemPyb>(mod, "ItemPyb")
        .def(pyb::init<>())
        .def("take_pyb", &ItemPyb::take_pyb)
        .def("take_bpy", &ItemPyb::take_bpy)
    ;
}

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
