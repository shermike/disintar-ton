// Copyright 2023 Disintar LLP / andrey@head-labs.com

#include "third-party/pybind11/include/pybind11/pybind11.h"
#include "vm/vm.h"
#include "tvm-python/PyCell.h"
#include "tvm-python/PyCellSlice.h"

#ifndef TON_PYTOOLS_H
#define TON_PYTOOLS_H

namespace py = pybind11;

std::string code_disassemble(const td::Ref<vm::Cell>& codeCell, const std::string& basePath);
std::string code_dissemble_str(const std::string& code, const std::string& basePath);
std::string code_dissemble_cell(const PyCell& codeCell, const std::string& basePath);
py::dict parse_token_data(const PyCell& codeCell);
PyCell run_asm(const std::string& code, const std::string& base_path);
PyCellSlice pack_address(const std::string& address);

#endif  //TON_PYTOOLS_H
