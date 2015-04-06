// auto-generated by yaml_to_cxx.py from test/upstream/changefeeds/table.yaml
#include "testlib.h"
void test_upstream_changefeeds_table() {
    enter_section("test_upstream_changefeeds_table: Test changefeeds on a table");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_DO(auto all = (tbl.changes().run_cursor(*conn)));
    TEST_EQ(tbl.insert(R::array(R::object("id", 1), R::object("id", 2))).run(*conn), (partial(R::Object{{"errors",0}, {"inserted",2}})));
    TEST_EQ(fetch(all, 2).run(*conn), (bag(R::Array{R::Object{{"old_val",R::Nil()}, {"new_val",R::Object{{"id",1}}}}, R::Object{{"old_val",R::Nil()}, {"new_val",R::Object{{"id",2}}}}})));
    TEST_EQ(tbl.get(1).update(R::object("version", 1)).run(*conn), (partial(R::Object{{"errors",0}, {"replaced",1}})));
    TEST_EQ(fetch(all, 1).run(*conn), (R::Array{R::Object{{"old_val",R::Object{{"id",1}}}, {"new_val",R::Object{{"id",1}, {"version",1}}}}}));
    TEST_EQ(tbl.get(1).delete_().run(*conn), (partial(R::Object{{"errors",0}, {"deleted",1}})));
    TEST_EQ(fetch(all, 1).run(*conn), (R::Array{R::Object{{"old_val",R::Object{{"id",1}, {"version",1}}}, {"new_val",R::Nil()}}}));
    TEST_DO(auto pluck = (tbl.changes().pluck(R::object("new_val", R::array("version"))).run_cursor(*conn)));
    TEST_EQ(tbl.insert(R::array(R::object("id", 5, "version", 5))).run(*conn), (partial(R::Object{{"errors",0}, {"inserted",1}})));
    TEST_EQ(fetch(pluck, 1).run(*conn), (R::Array{R::Object{{"new_val",R::Object{{"version",5}}}}}));
    TEST_DO(auto vtbl = (R::db("rethinkdb").table("_debug_scratch")));
    TEST_DO(auto allVirtual = (vtbl.changes().run_cursor(*conn)));
    TEST_EQ(vtbl.insert(R::array(R::object("id", 1), R::object("id", 2))).run(*conn), (partial(R::Object{{"errors",0}, {"inserted",2}})));
    TEST_EQ(fetch(allVirtual, 2).run(*conn), (bag(R::Array{R::Object{{"old_val",R::Nil()}, {"new_val",R::Object{{"id",1}}}}, R::Object{{"old_val",R::Nil()}, {"new_val",R::Object{{"id",2}}}}})));
    TEST_EQ(vtbl.get(1).update(R::object("version", 1)).run(*conn), (partial(R::Object{{"errors",0}, {"replaced",1}})));
    TEST_EQ(fetch(allVirtual, 1).run(*conn), (R::Array{R::Object{{"old_val",R::Object{{"id",1}}}, {"new_val",R::Object{{"id",1}, {"version",1}}}}}));
    TEST_EQ(vtbl.get(1).delete_().run(*conn), (partial(R::Object{{"errors",0}, {"deleted",1}})));
    TEST_EQ(fetch(allVirtual, 1).run(*conn), (R::Array{R::Object{{"old_val",R::Object{{"id",1}, {"version",1}}}, {"new_val",R::Nil()}}}));
    TEST_DO(auto vpluck = (vtbl.changes().pluck(R::object("new_val", R::array("version"))).run_cursor(*conn)));
    TEST_EQ(vtbl.insert(R::array(R::object("id", 5, "version", 5))).run(*conn), (partial(R::Object{{"errors",0}, {"inserted",1}})));
    TEST_EQ(fetch(vpluck, 1).run(*conn), (R::Array{R::Object{{"new_val",R::Object{{"version",5}}}}}));
    exit_section();
}