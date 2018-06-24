#include <ruby.h>
#include "extconf.h"

VALUE create_hash() {
  return rb_str_new2("test");
}

VALUE distance() {
  return rb_str_new2("test");
}

VALUE rb_return_nil() {
  return Qnil;
}
void Init_skynet()
{
  VALUE mod = rb_define_module("RubyGuides");
 
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
  rb_define_method(mod, "create_hash", create_hash, 0);
  rb_define_global_function("distance",distance,0);
}

int main()
{
	/* code */
	printf("Hello World\n");
	return 0;
}