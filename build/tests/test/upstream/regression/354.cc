// auto-generated by yaml_to_cxx.py from test/upstream/regression/354.yaml
#include "testlib.h"
void test_upstream_regression_354() {
    enter_section("test_upstream_regression_354: Regression tests for issue");
    TEST_DO(auto arr = (R::expr(R::array(1, 2, 3, 4, 5))));
    TEST_EQ(arr.skip(2).run(*conn), (R::Array{3, 4, 5}));
    TEST_EQ(arr.skip("a").run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found STRING.", R::Array{1})));
    TEST_EQ(arr.skip(R::array(1, 2, 3)).run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found ARRAY.", R::Array{1})));
    TEST_EQ(arr.skip(R::object()).count().run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found OBJECT.", R::Array{0, 1})));
    TEST_EQ(arr.skip(R::Nil()).run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found NULL.", R::Array{1})));
    exit_section();
}