#include "pyboost11.hpp"

#include "item.hpp"

namespace pybind11 { namespace detail {

template <> struct type_caster<ItemBpy> : pyboost11_type_caster<ItemBpy>
{
public:
    PYBIND11_TYPE_CASTER(ItemBpy, _("ItemBpy"));
    bool load(handle src, bool)
    {
        value = from_python(src);
        return true;
    }
    static handle cast(ItemBpy src, return_value_policy /* policy */, handle /* parent */)
    {
        return to_python(src);
    }
};

}} // end namespace pybind11::detail

PYBIND11_MODULE(modpyb, mod)
{
    namespace pyb = pybind11;

    mod.doc() = "extension module by pybind11";

    pyb::class_<ItemPyb>(mod, "ItemPyb")
        .def(pyb::init<>())
        .def("set_pyb", &ItemPyb::set_pyb)
        .def("set_bpy", &ItemPyb::set_bpy)
        .def("get_pyb", &ItemPyb::get_pyb)
        .def("get_bpy", &ItemPyb::get_bpy)
    ;
}

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
