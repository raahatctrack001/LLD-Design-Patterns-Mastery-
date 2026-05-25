#include<iostream>
#include<map>

using namespace std;

class HttpRequest{
    string url;
    string method;
    map<string, string> headers;
    map<string, string> body;
    map<string, string> queryParams;
    int timeout;
    
    //problem 1: constructor overloading: constructor telescoping
    public:
        HttpRequest(string url): url(url), method("GET"), timeout(30) {};

        HttpRequest(string url, string method): url(url), method(method), timeout(30) {};

        HttpRequest(string url, string method, map<string, string> headers): url(url), method(method), headers(headers) {};

        HttpRequest(string url, string method, map<string, string> headers, map<string, string> body): url(url), method(method), headers(headers), body(body) {};

        HttpRequest(string url, string method, map<string, string> headers, map<string, string> body, map<string, string> queryParams): url(url), method(method), headers(headers), body(body), queryParams(queryParams) {};

        HttpRequest(string url, string method, map<string, string> headers, map<string, string> body, map<string, string> queryParams, int timeout): url(url), method(method), headers(headers), body(body), queryParams(queryParams), timeout(timeout) {};

    //problem 2: field can be modified using setters;

        void setURL(string url){
            this->url = url;
        }

        void setMethod(string method){
            this->method = method;
        }

        void setTimeout(int time){
            this->timeout = time;
        }

        void setHeaders(map<string, string> headers){
            this->headers = headers;
        }

        void setQueryParams(map<string, string> queryParams){
            this->queryParams = queryParams;
        }

        void setBody(map<string, string> body){
            this->body = body;
        }

        //problem 3: scattered validations
        void execute(){
            if(this->url == "") {
                cout<<"error";
            }
            if(this->method == ""){
                cout<<"error";
            }

            if(this->headers.empty()){
                cout<<"error";
            }

            /*
            .
            .
            .
            .
            .
            .
            */

            //send request

            cout<<"sending request\n url:"<<url<<"\nmethod: "<<method<<"\ntimeout: "<<timeout<<endl;;
        }
};  

int main(){
    HttpRequest *req = new HttpRequest("www.api.example.com", "POST");
    req->execute();
    return 0;
}