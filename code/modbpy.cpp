#include <boost/python.hpp>

#include "item.hpp"

BOOST_PYTHON_MODULE(modbpy)
{
    namespace bpy = boost::python;

    bpy::class_<ItemBpy>("ItemBpy")
        .def(bpy::init<>())
        .def("take_pyb", &ItemBpy::take_pyb)
        .def("take_bpy", &ItemBpy::take_bpy)
    ;
}

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
