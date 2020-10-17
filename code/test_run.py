import unittest

import modpyb
import modbpy


class ItemTest(unittest.TestCase):

    def setUp(self):

        self.ipyb = modpyb.ItemPyb()
        self.ibpy = modbpy.ItemBpy()

    def test_pyb_take_pyb(self):

        self.ipyb.take_pyb(self.ipyb)

    def test_pyb_take_bpy(self):

        # FIXME: resolve this from-python conversion issue!
        with self.assertRaises(TypeError):
            self.ipyb.take_bpy(self.ibpy)

    def test_bpy_take_pyb(self):

        # FIXME: resolve this from-python conversion issue!
        with self.assertRaises(TypeError):
            self.ibpy.take_pyb(self.ipyb)

    def test_bpy_take_bpy(self):

        self.ibpy.take_bpy(self.ibpy)

# vim: set fenc=utf8 ff=unix et sw=4 ts=4 sts=4:
