#include "Translator.hh"

#include "TranslatorImpl.hh"

namespace Craeft {

Translator::Translator(std::string module_name, std::string filename,
                       std::string triple)
    : pimpl(new TranslatorImpl(module_name, filename, triple)) {}

Translator::~Translator() {}

Value Translator::cast(Value val, const Type &t, SourcePos pos) {
    return pimpl->cast(val, t, pos);
}

Value Translator::add_load(Value pointer, SourcePos pos) {
    return pimpl->add_load(pointer, pos);
}

void Translator::add_store(Value pointer, Value new_val, SourcePos pos) {
    pimpl->add_store(pointer, new_val, pos);
}

Value Translator::left_shift(Value val, Value nbits, SourcePos pos) {
    return pimpl->left_shift(val, nbits, pos);
}

Value Translator::right_shift(Value val, Value nbits, SourcePos pos) {
    return pimpl->right_shift(val, nbits, pos);
}

Value Translator::bit_and(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->bit_and(lhs, rhs, pos);
}

Value Translator::bit_or(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->bit_or(lhs, rhs, pos);
}

Value Translator::bit_xor(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->bit_xor(lhs, rhs, pos);
}

Value Translator::bit_not(Value val, SourcePos pos) {
    return pimpl->bit_not(val, pos);
}

Value Translator::add(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->add(lhs, rhs, pos);
}

Value Translator::sub(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->add(lhs, rhs, pos);
}

Value Translator::mul(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->mul(lhs, rhs, pos);
}

Value Translator::div(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->div(lhs, rhs, pos);
}

Value Translator::equal(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->equal(lhs, rhs, pos);
}

Value Translator::nequal(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->nequal(lhs, rhs, pos);
}

Value Translator::less(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->less(lhs, rhs, pos);
}

Value Translator::lesseq(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->lesseq(lhs, rhs, pos);
}

Value Translator::greater(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->greater(lhs, rhs, pos);
}

Value Translator::greatereq(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->greatereq(lhs, rhs, pos);
}

Value Translator::bool_and(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->bool_and(lhs, rhs, pos);
}

Value Translator::bool_or(Value lhs, Value rhs, SourcePos pos) {
    return pimpl->bool_or(lhs, rhs, pos);
}

Value Translator::bool_not(Value val, SourcePos pos) {
    return pimpl->bool_not(val, pos);
}

Value Translator::call(std::string func, std::vector<Value> &args, SourcePos pos) {
    return pimpl->call(func, args, pos);
}

Variable Translator::declare(const std::string &name, const Type &t) {
    return pimpl->declare(name, t);
}

void Translator::assign(const std::string &varname, Value val,
                        SourcePos pos) {
    return pimpl->assign(varname, val, pos);
}

void Translator::return_(Value val, SourcePos pos) {
    return pimpl->return_(val, pos);
}

void Translator::create_function_prototype(Function f, std::string name) {
    pimpl->create_function_prototype(f, name);
}
void Translator::create_and_start_function(Function f,
                                           std::vector<std::string> args,
                                           std::string name) {
    pimpl->create_and_start_function(f, args, name);
}

void Translator::end_function(void) {
    pimpl->end_function();
}

void Translator::validate(std::ostream &out) {
    pimpl->validate(out);
}
void Translator::optimize(int opt_level) {
    pimpl->optimize(opt_level);
}
void Translator::emit_ir(std::ostream &fd) {
    pimpl->emit_ir(fd);
}
void Translator::emit_obj(int fd) {
    pimpl->emit_obj(fd);
}
void Translator::emit_asm(int fd) {
    pimpl->emit_asm(fd);
}

llvm::IRBuilder<> &Translator::get_builder(void) {
    return pimpl->get_builder();
}

Environment &Translator::get_env(void) {
    return pimpl->get_env();
}

llvm::LLVMContext &Translator::get_ctx(void) {
    return pimpl->get_ctx();
}

}