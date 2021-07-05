#pragma once

#include <pybind11/pybind11.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <boost/python.hpp>
#pragma GCC diagnostic pop

namespace pyboost11
{

template <typename T> struct type_caster
{

public:

    // From-Python conversion.
    static T from_python(pybind11::handle src)
    {
        namespace bpy = boost::python;
        bpy::object bpyo(bpy::handle<>(bpy::borrowed(src.ptr())));
        return bpy::extract<T>(bpyo);
    }

    // To-Python conversion.
    static pybind11::handle to_python(T & src)
    {
        namespace bpy = boost::python;
        return bpy::incref(bpy::object(src).ptr());
    }

};

template <typename T> struct converter
{

public:

    converter() { init(); }

    void init()
    {
        static bool initialized = false;
        if (!initialized)
        {
            namespace bpy = boost::python;
            // From-Python conversion.
            bpy::converter::registry::push_back
            (
                &convertible
              , &construct
              , bpy::type_id<T>()
            );
            // To-Python conversion.
            bpy::to_python_converter<T, converter>();

            initialized = true;
        }
    }

    // From-Python convertibility.
    static void * convertible(PyObject * objptr)
    {
        namespace pyb = pybind11;
        try
        {
            pyb::handle(objptr).cast<T>();
            return objptr;
        }
        catch (pyb::cast_error const &)
        {
            return nullptr;
        }
    }

    // From-Python conversion.
    static void construct
    (
        PyObject * objptr
      , boost::python::converter::rvalue_from_python_stage1_data * data
    )
    {
        namespace pyb = pybind11;
        void * storage = reinterpret_cast
        <
            boost::python::converter::rvalue_from_python_storage<T> *
        >(data)->storage.bytes;
        new (storage) T(pyb::handle(objptr).cast<T>());
        data->convertible = storage;
    }

    // To-Python conversion.
    static PyObject * convert(T const & t)
    {
        return pybind11::cast(t).inc_ref().ptr();
    }

};

} // end namespace pyboost11

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
