#pragma once

struct Data {};

struct ItemBpy;

/* To be wrapped by pybind11 */
struct ItemPyb
{
    ItemPyb(Data const & data_in) : data(data_in) {}

    ItemPyb() = default;

    void set_pyb(ItemPyb const & other);
    void set_bpy(ItemBpy const & other);

    ItemPyb get_pyb();
    ItemBpy get_bpy();

    Data data;
};

/* To be wrapped by boost.python */
struct ItemBpy
{
    ItemBpy(Data const & data_in) : data(data_in) {}

    ItemBpy() = default;

    void set_pyb(ItemPyb const & other);
    void set_bpy(ItemBpy const & other);

    ItemPyb get_pyb();
    ItemBpy get_bpy();

    Data data;
};

inline void ItemBpy::set_pyb(ItemPyb const & other) { data = other.data; }
inline void ItemBpy::set_bpy(ItemBpy const & other) { data = other.data; }

inline ItemPyb ItemBpy::get_pyb() { return ItemPyb(data); }
inline ItemBpy ItemBpy::get_bpy() { return ItemBpy(data); }

inline void ItemPyb::set_pyb(ItemPyb const & other) { data = other.data; }
inline void ItemPyb::set_bpy(ItemBpy const & other) { data = other.data; }

inline ItemPyb ItemPyb::get_pyb() { return ItemPyb(data); }
inline ItemBpy ItemPyb::get_bpy() { return ItemBpy(data); }

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
