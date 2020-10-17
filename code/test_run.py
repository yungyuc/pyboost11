import unittest

import modpyb
import modbpy


class ItemTest(unittest.TestCase):

    def setUp(self):

        self.ipyb = modpyb.ItemPyb()
        self.ibpy = modbpy.ItemBpy()

    def test_pyb_set_pyb(self):

        self.ipyb.set_pyb(self.ipyb)

    def test_pyb_set_bpy(self):

        self.ipyb.set_bpy(self.ibpy)

    def test_pyb_get_pyb(self):

        self.ipyb.set_pyb(self.ipyb)
        self.assertIsInstance(self.ipyb.get_pyb(), modpyb.ItemPyb)

    def test_pyb_get_bpy(self):

        self.ipyb.set_bpy(self.ibpy)
        self.assertIsInstance(self.ipyb.get_bpy(), modbpy.ItemBpy)

    def test_bpy_set_pyb(self):

        # FIXME: resolve this from-python conversion issue!
        with self.assertRaises(TypeError):
            self.ibpy.set_pyb(self.ipyb)

    def test_bpy_set_bpy(self):

        self.ibpy.set_bpy(self.ibpy)

# vim: set fenc=utf8 ff=unix et sw=4 ts=4 sts=4:
