// Copyright 2023 Disintar LLP / andrey@head-labs.com

#include "vm/vm.h"
#include "PyCellSlice.h"
#include "PyCell.h"

#ifndef TON_PYCELLBUILDER_H
#define TON_PYCELLBUILDER_H

class PyCellBuilder {
 public:
  vm::CellBuilder my_builder;
  ~PyCellBuilder() = default;

  // constructor
  explicit PyCellBuilder() {
    my_builder = vm::CellBuilder();
  }

  explicit PyCellBuilder(vm::CellSlice old_builder) {
    // Todo: fix
    my_builder = vm::CellBuilder();
    my_builder.append_cellslice(old_builder);
  }

  PyCellBuilder(const PyCellBuilder& other){
    // todo: fix
    my_builder = other.my_builder;
  }

  PyCellBuilder* store_uint_str(const std::string& str, unsigned int bits);
  PyCellBuilder* store_256uint_str(const std::string& str, unsigned int bits);
  PyCellBuilder* store_int_str(const std::string& str, unsigned int bits);
  PyCellBuilder* store_bitstring(const std::string& s);
  PyCellBuilder* store_slice(const PyCellSlice& cs);
  PyCellBuilder* store_grams_str(const std::string& str);
  PyCellBuilder* store_var_integer(const std::string& str, unsigned int varu, bool sgnd);
  PyCellBuilder* store_ref(const PyCell& c);
  PyCellBuilder* store_zeroes(unsigned int bits);
  PyCellBuilder* store_ones(unsigned int bits);
  PyCellBuilder* store_builder(const PyCellBuilder& cb);
  PyCellBuilder* store_address(const std::string& addr);
  PyCellBuilder* store_uint_less(unsigned int bits, std::string value);
  PyCellBuilder* store_uint_leq(unsigned int bits, std::string value);
  unsigned get_refs() const;
  unsigned get_bits() const;
  unsigned get_remaining_refs() const;
  unsigned get_remaining_bits() const;
  PyCell get_cell(bool special);
  std::string toString() const;
  std::string dump() const;
  std::string get_hash() const;
  std::string dump_as_tlb(std::string tlb_type) const;
  std::string to_boc() const;

  static void dummy_set() {
    throw std::invalid_argument("Not settable");
  }
};

#endif  //TON_PYCELLBUILDER_H
