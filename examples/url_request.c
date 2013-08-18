#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

#if 0
static size_t function( char *ptr, size_t size, size_t nmemb, void *userdata) {
    printf("writing %zu data\n", size *nmemb);
    return size * nmemb;
}
#endif

int main(int argc, char** argv) {
    CURL* curl = NULL;
    FILE* fp = fopen("/tmp/url_request_test_file.html", "w");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }
    curl_easy_cleanup(curl);
    return 0;
}
