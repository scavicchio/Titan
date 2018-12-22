#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>

namespace py = pybind11;

#include "pymass.h"

void bind_mass(py::module &m){
    py::class_<pyMass>(m, "Mass")
            .def(py::init<>(), py::return_value_policy::reference)
//            .def(py::init<Mass *>(), py::return_value_policy::reference)

            //properties
            .def_readwrite("pointer", &pyMass::pointer)
//            .def("m", &pyMass::m)

            .def("m", (double (pyMass::*)()) &pyMass::m, py::return_value_policy::reference)
            .def("m", (void (pyMass::*)(double m)) &pyMass::m, py::return_value_policy::reference)
            .def("pos", (py::array_t<double>  (pyMass::*)()) &pyMass::pos, py::return_value_policy::reference)
            .def("pos", (void  (pyMass::*)(py::array_t<double> arr)) &pyMass::pos, py::return_value_policy::reference)
            .def("vel", &pyMass::vel)
            .def("acc", &pyMass::acc)
            .def("force", &pyMass::force)
            .def("dt", &pyMass::dt)
            .def("T", &pyMass::T);


//MAYBE USEFUL IN THE FUTURE
//            .def_readwrite("pos", &Mass::pos)
//            .def_readwrite("vel", &Mass::vel)
//            .def_readwrite("acc", &Mass::acc)
//            .def_readwrite("force", &Mass::force)
//            .def_readwrite("dt", &Mass::dt)
//            .def_readwrite("T", &Mass::T);

//Methods (Legacy)
//            .def("setMass", &Mass::setMass)
//            .def("setPos", &Mass::setPos)
//            .def("setVel", &Mass::setVel)
//            .def("setAcc", &Mass::setAcc)
//            .def("setForce", &Mass::setForce)
//            .def("setDeltaT", &Mass::setDeltaT)
//            .def("translate", &Mass::translate)
//            .def("makeFixed", &Mass::makeFixed)
//            .def("makeMovable", &Mass::makeMovable)
//            .def("isFixed", &Mass::isFixed)
//            .def("getMass", &Mass::getMass)
//            .def("getPosition", &Mass::getPosition)
//            .def("getVelocity", &Mass::getVelocity)
//            .def("getAcceleration", &Mass::getAcceleration)
//            .def("getForce", &Mass::getForce)
//            .def("time", &Mass::time)
//            .def("deltat", &Mass::deltat)
//            .def("stepTime", &Mass::stepTime);
}