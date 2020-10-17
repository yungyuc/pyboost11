#include "pyboost11.hpp"

#include "item.hpp"

BOOST_PYTHON_MODULE(modbpy)
{
    namespace bpy = boost::python;

    bpy::class_<ItemBpy>("ItemBpy")
        .def(bpy::init<>())
        .def("set_pyb", &ItemBpy::set_pyb)
        .def("set_bpy", &ItemBpy::set_bpy)
        // FIXME: need boost.python conversion for pybind11.
        //.def("get_pyb", &ItemBpy::get_pyb)
        .def("get_bpy", &ItemBpy::get_bpy)
    ;
}

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
