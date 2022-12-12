#include <stdio.h>
#include <curl/curl.h>

static char* GET_RESULT;
static void get_result(void *ptr){
	GET_RESULT = ptr;
}
 
int main(void){
	CURL *curl;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://api64.ipify.org/");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_result);

		curl_easy_perform(curl);

		printf("IP is: %s\n", GET_RESULT);

		curl_easy_cleanup(curl);
	}
	return 0;
}