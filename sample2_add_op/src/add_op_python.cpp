#include <pybind11/pybind11.h>
#include "add_op.h"

PYBIND11_MODULE(add_op_python, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
}