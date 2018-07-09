#include <ruby.h>
#include <extconf.h>

char **getWordsArray(VALUE rarray);
char *getString(void);
double findDistance(char*,char*,int,int);
int min(int,int,int);
int findMin(int,int);

VALUE distance(VALUE self,VALUE str,VALUE rarray,VALUE cutoff) {
	int arrayLen =  RARRAY_LEN(rarray);
	int stringLength = RSTRING_LEN(str);
	long i =0;
	long j=0;
	long finalCount = 0;
	char *searchWord;
	char *data[1000];
	int dataLen[1000];
	VALUE finalResult[1000];
	double  cutoffScore = -1.0;
	if(!NIL_P(cutoff)){
		cutoffScore = NUM2DBL(cutoff);
	}
	if(cutoffScore < 0.0){
		cutoffScore = 0.5;
	}
	if(!NIL_P(rarray) && arrayLen > 0 && arrayLen <= 1000 && stringLength > 0 && stringLength <= 100){
		while(i < arrayLen){
			VALUE element = rb_ary_entry(rarray,i);
			data[i] = StringValuePtr(element);
			dataLen[i] = RSTRING_LEN(element);
			i++;
		}
		searchWord = (char*)StringValuePtr(str);
		while(j<i){
			if(findDistance(data[j],searchWord,dataLen[j],stringLength) <= cutoffScore){
				finalResult[finalCount] = rb_str_new_cstr(data[j]);
				finalCount++;
			}
			j++;
		}
	}else{
		return rb_str_new2("Error:null value passed");
	}
	return rb_ary_new4(finalCount,finalResult);
}

double findDistance(char* dataStr,char* searchWord,int dataLen,int searchWordLen){
	int k = 0 ,l = 0;
    int dp[1001][101];
	if (dataLen <= 1000 && searchWordLen <= 100){
		char *a =dataStr;
		char *b =searchWord;
	   	for (k=0; k<=dataLen; k++){
	   		b =searchWord;
	        for (l=0; l<=searchWordLen; l++){
	            if (k==0){
	                dp[k][l] = l;
	            }
	            else if (l==0){
	                dp[k][l] = k;
	            }
	            else if ( *a == *b){
	                dp[k][l] = dp[k-1][l-1];
	            }

	            else{
	                dp[k][l] = 1 + min(dp[k][l-1],  // Insert
	                                   dp[k-1][l],  // Remove
	                                   dp[k-1][l-1]); // Replace
	            }
	            b++;
	        }
	        a++;
	    }
	}
    return ((double)dp[k-1][l-1]/searchWordLen);
}

int min(int x,int y,int z){
	return findMin(x,findMin(x,y));
}
int findMin(int r,int s){
	if (r < s){
		return r;
	}
	else{
		return s;
	}
}

void Init_skynet()
{
  VALUE mod = rb_define_module("PercentSearch");
  rb_define_global_function("distance",distance,3);
}

int main()
{
	/* code */
	printf("Hello World\n");
	return 0;
}