// auto-generated by yaml_to_cxx.py from test/upstream/changefeeds/delme.yaml
#include "testlib.h"
void test_upstream_changefeeds_delme() {
    enter_section("test_upstream_changefeeds_delme: include_states test debugging");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_EQ(tbl.order_by(R::OptArgs{{"index", R::expr("id")}}).limit(10).changes(R::OptArgs{{"squash", R::expr(true)}, {"include_states", R::expr(true)}}).limit(2).run(*conn), (R::Array{R::Object{{"state","initializing"}}, R::Object{{"state","ready"}}}));
    exit_section();
}