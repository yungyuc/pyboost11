#include "pyboost11.hpp"

#include "item.hpp"

namespace pybind11
{

namespace detail
{

PYBOOST11_TYPE_CASTER(ItemBpy, _("ItemBpy"));
PYBOOST11_TYPE_CASTER(boost::shared_ptr<ItemBpyBS>, _("ItemBpyBS"));

} // end namespace detail

} // end namespace pybind11

PYBIND11_MODULE(modpyb, mod)
{

    namespace pyb = pybind11;

    mod.doc() = "extension module by pybind11";

    pyb::class_<ItemPyb>(mod, "ItemPyb")
        .def(pyb::init<>())
        .def(pyb::init<int>())
        .def_property("value", &ItemPyb::value, &ItemPyb::set_value)
        .def_property_readonly("address", &ItemPyb::address)
        .def("take_pyb", &ItemPyb::take_pyb)
        .def("take_bpy", &ItemPyb::take_bpy)
        .def("make_pyb", &ItemPyb::make_pyb)
        .def("make_bpy", &ItemPyb::make_bpy)
    ;

    pyb::class_<ItemPybSS, std::shared_ptr<ItemPybSS>>(mod, "ItemPybSS")
        .def(pyb::init([](int v) { return ItemPybSS::make(v); }))
        .def_property("value", &ItemPybSS::value, &ItemPybSS::set_value)
        .def_property_readonly("address", &ItemPybSS::address)
        .def("take_pybss", &ItemPybSS::take_pybss)
        .def("take_bpybs", &ItemPybSS::take_bpybs)
        .def("make_pybss", &ItemPybSS::make_pybss)
        .def("make_bpybs", &ItemPybSS::make_bpybs)
    ;

    pyb::class_<ContainerPyb>(mod, "ContainerPyb")
        .def
        (
            pyb::init
            <
                ItemPyb const &, ItemBpy const &
              , std::shared_ptr<ItemPybSS> const &
              , boost::shared_ptr<ItemBpyBS> const &
            >()
        )
        .def_property_readonly("pyb", &ContainerPyb::pyb)
        .def_property_readonly("bpy", &ContainerPyb::bpy)
        .def_property_readonly("pybss", &ContainerPyb::pybss)
        .def_property_readonly("bpybs", &ContainerPyb::bpybs)
        .def("take_pyb", &ContainerPyb::take_pyb)
        .def("take_bpy", &ContainerPyb::take_bpy)
        .def("set_pybss", &ContainerPyb::set_pybss)
        .def("set_bpybs", &ContainerPyb::set_bpybs)
    ;

}

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
