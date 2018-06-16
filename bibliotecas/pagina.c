#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
int main() {
    curl_global_init( CURL_GLOBAL_ALL );
    CURL * myHandle;
    CURLcode result; // We’ll store the result of CURL’s webpage retrieval, for error checking
    myHandle = curl_easy_init();
    // Notice the lack of major error checking, for brevity
    curl_easy_setopt(myHandle, CURLOPT_URL, "http://tonabarrera.github.io/public/main.min.js");
    result = curl_easy_perform( myHandle );
    curl_easy_cleanup( myHandle );
    printf("LibCurl rules!\n");
    return 0;
}