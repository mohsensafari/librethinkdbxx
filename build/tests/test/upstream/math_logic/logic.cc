// auto-generated by yaml_to_cxx.py from test/upstream/math_logic/logic.yaml
#include "testlib.h"
void test_upstream_math_logic_logic() {
    enter_section("test_upstream_math_logic_logic: These tests are aimed at &&, ||, and !");
    TEST_EQ((R::expr(true) && true).run(*conn), (true));
    TEST_EQ((R::expr(true) && R::expr(true)).run(*conn), (true));
    TEST_EQ(R::and_(true, true).run(*conn), (true));
    TEST_EQ(R::expr(true).and_(true).run(*conn), (true));
    TEST_EQ((R::expr(true) && false).run(*conn), (false));
    TEST_EQ((R::expr(false) && false).run(*conn), (false));
    TEST_EQ((R::expr(true) && R::expr(false)).run(*conn), (false));
    TEST_EQ((R::expr(false) && R::expr(false)).run(*conn), (false));
    TEST_EQ(R::and_(true, false).run(*conn), (false));
    TEST_EQ(R::and_(false, false).run(*conn), (false));
    TEST_EQ(R::expr(true).and_(false).run(*conn), (false));
    TEST_EQ(R::expr(false).and_(false).run(*conn), (false));
    TEST_EQ((R::expr(true) || true).run(*conn), (true));
    TEST_EQ((R::expr(true) || false).run(*conn), (true));
    TEST_EQ((R::expr(true) || R::expr(true)).run(*conn), (true));
    TEST_EQ((R::expr(true) || R::expr(false)).run(*conn), (true));
    TEST_EQ(R::or_(true, true).run(*conn), (true));
    TEST_EQ(R::or_(true, false).run(*conn), (true));
    TEST_EQ(R::expr(true).or_(true).run(*conn), (true));
    TEST_EQ(R::expr(true).or_(false).run(*conn), (true));
    TEST_EQ((R::expr(false) || false).run(*conn), (false));
    TEST_EQ((R::expr(false) || R::expr(false)).run(*conn), (false));
    TEST_EQ(R::and_(false, false).run(*conn), (false));
    TEST_EQ(R::expr(false).and_(false).run(*conn), (false));
    TEST_EQ((!R::expr(true)).run(*conn), (false));
    TEST_EQ(R::not_(true).run(*conn), (false));
    TEST_EQ((!R::expr(false)).run(*conn), (true));
    TEST_EQ(R::not_(false).run(*conn), (true));
    TEST_EQ(R::expr(true).not_().run(*conn), (false));
    TEST_EQ(R::expr(false).not_().run(*conn), (true));
    TEST_EQ((!R::and_(true, true)==R::or_(!R::expr(true), !R::expr(true))).run(*conn), (true));
    TEST_EQ((!R::and_(true, false)==R::or_(!R::expr(true), !R::expr(false))).run(*conn), (true));
    TEST_EQ((!R::and_(false, false)==R::or_(!R::expr(false), !R::expr(false))).run(*conn), (true));
    TEST_EQ((!R::and_(false, true)==R::or_(!R::expr(false), !R::expr(true))).run(*conn), (true));
    TEST_EQ(R::and_(true, true, true, true, true).run(*conn), (true));
    TEST_EQ(R::and_(true, true, true, false, true).run(*conn), (false));
    TEST_EQ(R::and_(true, false, true, false, true).run(*conn), (false));
    TEST_EQ(R::or_(false, false, false, false, false).run(*conn), (false));
    TEST_EQ(R::or_(false, false, false, true, false).run(*conn), (true));
    TEST_EQ(R::or_(false, true, false, true, false).run(*conn), (true));
    TEST_EQ(R::expr(R::expr("a")["b"]).default_(2).run(*conn), (err("RqlRuntimeError", "Cannot perform bracket on a non-object non-sequence `\"a\"`.", R::Array{})));
    TEST_EQ(R::expr((R::expr(true) && R::expr(false))==(R::expr(false) || R::expr(true))).run(*conn), (err("RqlDriverError", "Calling '==' on result of infix bitwise operator.", R::Array{})));
    TEST_EQ(R::expr(R::and_(true, false)==R::or_(false, true)).run(*conn), (false));
    TEST_EQ((R::expr(1) && true).run(*conn), (true));
    TEST_EQ((R::expr(false) || "str").run(*conn), ("str"));
    TEST_EQ((!R::expr(1)).run(*conn), (false));
    TEST_EQ((!R::expr(R::Nil())).run(*conn), (true));
    exit_section();
}