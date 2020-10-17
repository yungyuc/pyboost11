#pragma once

#include <pybind11/pybind11.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <boost/python.hpp>
#pragma GCC diagnostic pop

namespace pybind11 { namespace detail {

template <typename T> struct pyboost11_type_caster
{

public:

    // From-Python conversion.
    static T from_python(handle src)
    {
        namespace bpy = boost::python;
        return bpy::extract<T>(bpy::object(bpy::handle<>(src.ptr())));
    }

    // To-Python conversion.
    static handle to_python(T & src)
    {
        namespace bpy = boost::python;
        return bpy::incref(bpy::object(src).ptr());
    }

};

}} // end namespace pybind11::detail

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
