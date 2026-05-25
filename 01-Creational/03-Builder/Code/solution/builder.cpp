#include<iostream>
#include<map>

using namespace std;


class HttpRequest{
    private:
        string url;
        string method;
        int timeout;
        map<string, string> body;
        map<string, string> queryParams;
        map<string, string> headers;

        //constructor telescoping problem: no more use of constructor to build the object
        HttpRequest() {};

        //delegating the object construction
        friend class HttpRequestBuilder;

        public: 
            void print(){
                cout<<"url: "<<url<<endl;
                cout<<"method: "<<method<<endl;
                cout<<"timeout: "<<timeout<<endl;

            }
};

class HttpRequestBuilder{
    HttpRequest req;


    //consistent validation
    void validate(){
        if(req.url.empty()){
            throw runtime_error("url is missing");
        }

        if(req.method.empty()){
            throw runtime_error("method is missing");
        }

        // if(req.body.empty()){
        //     throw runtime_error("body is missing");
        // }

        // if(req.headers.empty()){
        //     throw runtime_error("headers is missing");
        // }

        // if(req.queryParams.empty()){
        //     throw runtime_error("queryParams is missing");
        // }
    }
    public:
        HttpRequestBuilder withURL(string url){
            req.url = url;
            return *this;
        }

        HttpRequestBuilder withMethod(string method){
            req.method = method;
            return *this;
        }

        HttpRequestBuilder withBody(map<string, string> body){
            req.body = body;
            return *this;
        }

        HttpRequestBuilder withQueryParams(map<string, string> queryParams){
            req.queryParams = queryParams;
            return *this;
        }


        HttpRequestBuilder withHeaders(map<string, string> headers){
            req.headers = headers;
            return *this;
        }

        HttpRequestBuilder withTimeout(int t){
            req.timeout = t;
            return *this;
        }
        
        //consistent build
        HttpRequest build(){
            validate();
            return req;
        }
};

class BuilderWithDirector{
    public:
        static HttpRequest createGetRequest(string url){
            return HttpRequestBuilder()
                .withURL(url)
                .withMethod("GET")
                .withTimeout(10)
                .build();
        }

        static HttpRequest createPostRequest(string url){
          return HttpRequestBuilder()
                .withURL(url)
                .withMethod("POST")
                .withTimeout(100)
                .build();
        }
};

int main(){
    map<string, string> headers = {{"content-type", "application/json"}}, body ={ {"data" , "somedata"}}, queryParams ={ {"query", "params"}};
    HttpRequest req = HttpRequestBuilder()
        .withURL("www.example.com")
        .withMethod("Post")
         
        .withQueryParams(queryParams)
        .build();

        req.print();
    
    req = BuilderWithDirector::createGetRequest("www.example.com");
    req = BuilderWithDirector::createPostRequest("www.example2.com");
    req.print();
    return 0;
}