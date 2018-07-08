#include <ruby.h>
#include "extconf.h"

VALUE create_hash() {
  return rb_str_new2("test");
}

VALUE distance(VALUE self,VALUE str) {
  char *st = (char*)(StringValuePtr(str)); 
  return rb_str_new2(st);
}

// VALUE fonk(int argc,VALUE* argv,VALUE self) {
//   VALUE str;
//   VALUE block;
//   rb_scan_args(argc, argv, "1&", &str,&block);
//   if (NIL_P(block)) block = rb_ary_new();
//   char *st = (char*)(StringValuePtr(str)); 
//   return rb_str_new2(st);
// }


VALUE bulkDistance(VALUE self,VALUE rstr,VALUE rarray) {
	//int arrayLen = RARRAY_LEN(rarray);
	VALUE rfirstElement = rb_ary_entry(rarray,0);
	int eleLength = RSTRING_LEN(rfirstElement);
	char snum[100];
	sprintf(snum,"%d",eleLength); 
	return rb_str_new2(snum);
}

VALUE rb_return_nil() {
  return Qnil;
}
void Init_skynet()
{
  VALUE mod = rb_define_module("RubyGuides");
 
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
  rb_define_method(mod, "create_hash", create_hash, 0);
  rb_define_global_function("distance",distance,1);
  //rb_define_global_function("fonk",fonk,2);
  rb_define_global_function("get_distance",bulkDistance,2);
}

int main()
{
	/* code */
	printf("Hello World\n");
	return 0;
}