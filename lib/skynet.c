#include <ruby.h>
#include "extconf.h"

char **getWordsArray(VALUE rarray);
char *getString(void);
double findDistance(char*,char*);

VALUE create_hash() {
  return rb_str_new2("test");
}

VALUE distance(VALUE self,VALUE str,VALUE rarray,VALUE cutoff) {
	int arrayLen =  RARRAY_LEN(rarray);
	int stringLength = RSTRING_LEN(str);
	long i =0;
	long j=0;
	long finalCount = 0;
	char *searchWord;
	char *data[1000];
	double  cutoffScore = NUM2DBL(cutoff);
	VALUE finalResult[1000];
	if(NIL_P(rarray) || cutoffScore < 0){
		cutoffScore= 0.5;
	}
	if(!NIL_P(rarray) && arrayLen > 0 && arrayLen < 1000 && stringLength > 0 && stringLength <= 100){
		while(i < arrayLen){
			VALUE element = rb_ary_entry(rarray,i);
			data[i] = StringValuePtr(element);
			i++;
		}
		searchWord = (char*)StringValuePtr(str);
		while(j<i){
			if(findDistance(data[j],searchWord) <= cutoffScore){
				finalResult[finalCount++] = rb_str_new_cstr(data[j]);
			}
			j++;
		}
		// char *st = (char*)(StringValuePtr(str1));
		// VALUE tt = rb_ary_entry(rarray,0);
		// int len = RSTRING_LEN(tt);
		// st = (char*)(StringValuePtr(len)); 
	}else{
		//raise error
	}
	return rb_ary_new4(finalCount,finalResult);
}

// VALUE fonk(int argc,VALUE* argv,VALUE self) {
//   VALUE str;
//   VALUE block;
//   rb_scan_args(argc, argv, "1&", &str,&block);
//   if (NIL_P(block)) block = rb_ary_new();
//   char *st = (char*)(StringValuePtr(str)); 
//   return rb_str_new2(st);
// }

double findDistance(char* dataStr,char* searchWord){
	return 0.0;
}

VALUE bulkDistance(VALUE self,VALUE rstr,VALUE rarray) {
	//int arrayLen = RARRAY_LEN(rarray);
	char **word_list;
	word_list = getWordsArray(rarray);
	//VALUE rfirstElement = rb_ary_entry(rarray,0);
	//int eleLength = RSTRING_LEN(rfirstElement);
	//char snum[100];
	//sprintf(snum,"%d",eleLength);
	//return rb_str_new2(getString());
	//return rb_str_new2("hello");
	return rb_str_new2(*word_list);
}

char *getString(void){
    char *str;
    str = (char*)"Hello";
	return str;
}

char **getWordsArray(VALUE rarray){
	// char **res;
	// int i =0;
	// res = NULL;
	// if(!NIL_P(rarray)){
	// 	int arrayLen = RARRAY_LEN(rarray);
	// 	if(arrayLen <= 1000){
	// 		//accepting only 1000 words array at the moment
	// 		while(i < arrayLen){
	// 			VALUE element = rb_ary_entry(rarray,i);
	// 			int eleLength = RSTRING_LEN(element);
	// 			if(eleLength <= 100){
	// 				*(res + i) = (char*)StringValuePtr(element);
	// 			}
	// 			i++;
	// 		}
	// 	}
	// }
	// return res;
	char word[] = "Hello";
	char *w1 = &word;
	char **w2 = &w1;
	return w2;
}

VALUE rb_return_nil() {
  return Qnil;
}
void Init_skynet()
{
  VALUE mod = rb_define_module("RubyGuides");
 
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
  rb_define_method(mod, "create_hash", create_hash, 0);
  rb_define_global_function("distance",distance,3);
  //rb_define_global_function("fonk",fonk,2);
  rb_define_global_function("get_distance",bulkDistance,2);
}

int main()
{
	/* code */
	printf("Hello World\n");
	return 0;
}