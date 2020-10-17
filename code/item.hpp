struct ItemBpy;

/* To be wrapped by pybind11 */
struct ItemPyb
{
    void take_pyb(ItemPyb * ptr) { other_pyb = ptr; }
    void take_bpy(ItemBpy * ptr) { other_bpy = ptr; }

    ItemPyb * other_pyb;
    ItemBpy * other_bpy;
};

/* To be wrapped by boost.python */
struct ItemBpy
{
    void take_pyb(ItemPyb * ptr) { other_pyb = ptr; }
    void take_bpy(ItemBpy * ptr) { other_bpy = ptr; }

    ItemPyb * other_pyb;
    ItemBpy * other_bpy;
};

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
