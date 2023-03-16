#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace std;

// g++ src/main.cpp -o json2 -ljsoncpp -L/usr/include/curl/lib -lcurl -Db_pie=true -Wl,-e, -shared para compilar


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// faz requisições HTTP retornando uma estrutura
int main(){
    CURL *curl;
    CURLcode res;
    string readBuffer;
    // string body = "{\"mensagem\" : \"aied gosta de programar em c++\"}";
    Json::Value rootJsonValue;
    rootJsonValue["name"] = "anotação";
    string body = rootJsonValue.toStyledString();


    curl = curl_easy_init();
    string path_full = "http://localhost:8000/categories/";
    long http_code = 0;

    curl_easy_setopt(curl, CURLOPT_URL, path_full.c_str());
    struct curl_slist *hs=NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);

    int method = 2;
    if(curl) {
        
        if (method == 1){
            // post
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
            curl_easy_setopt(curl, CURLOPT_POST, 1);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            curl_easy_cleanup(curl);
        }else if(method == 2){
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            curl_easy_cleanup(curl);
        }

        

        cout << "Código HTTP: " << http_code << "\n";
        cout << readBuffer << endl;
    }
    return 0;
}


// CURL *hnd = curl_easy_init();
// curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "DELETE");
// curl_easy_setopt(hnd, CURLOPT_URL, "http://some/url/");
// curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"key\": \"value\"}");
// struct curl_slist *headers = NULL;
// headers = curl_slist_append(headers, "content-type: application/json");
// curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
// CURLcode ret = curl_easy_perform(hnd);
// // do something...
// curl_slist_free_all(headers);
// curl_easy_cleanup(hnd);