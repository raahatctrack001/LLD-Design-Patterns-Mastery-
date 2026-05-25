#include<iostream>
#include<map>

using namespace std;


class HttpRequest{
    private:
        string url;
        string method;
        int timeout;
        string body;
        map<string, string> queryParams;
        map<string, string> headers;

        //constructor telescoping problem: no more use of constructor to build the object
        HttpRequest() {};

        //delegating the object construction
        friend class HttpRequestStepBuilder;

        public: 
            void print(){
                cout<<"url: "<<url<<endl;
                cout<<"method: "<<method<<endl;
                cout<<"timeout: "<<timeout<<endl;
                cout<<"body: "<<body<<endl;

            }
};

class MethodStep;
class URLStep;
class OptionalStep;

class URLStep{
    public:
        virtual MethodStep& withURL(string url) = 0;
};

class MethodStep{
    public: 
        virtual OptionalStep& WithMethod (string method) = 0;    
};


class  OptionalStep {
    public:
        ~OptionalStep() {};
        virtual OptionalStep& WithBody(string body) = 0;
        virtual OptionalStep& WithQueryParams(map<string, string> queryParams) = 0;
        virtual OptionalStep& WithHeaders(map<string, string> headers) = 0;
        virtual OptionalStep& WithTimeout( int tiemout) = 0;
        virtual HttpRequest build() = 0;
};

class HttpRequestStepBuilder:
    public URLStep,
    public MethodStep,
    public OptionalStep    
{
    private:
        HttpRequest req;
        void validate(){
            cout<<"validated"<<endl;
            return;
        }

    public: 
        MethodStep& withURL(string url) override {
            req.url = url;
            return *this;
        }

        OptionalStep& WithMethod(string method) override{
            req.method = method;
            return *this;
        }

        OptionalStep& WithTimeout(int time) override {
            req.timeout = time;
            return *this;
        }

        OptionalStep& WithBody(string body) override {
            req.body = body;
            return *this;
        }

        OptionalStep& WithHeaders(map<string, string> headers) override{
            req.headers = headers;
            return *this;
        }

        OptionalStep &WithQueryParams(map<string, string> queryParams) override{
            req.queryParams = queryParams;
            return *this;
        }

        HttpRequest build(){
            validate();
            return req;
        }
};

int main(){

    HttpRequest req = HttpRequestStepBuilder()
        .withURL("www.example.com")
        .WithMethod("GET")
        .WithBody("this is data bro")
        .build();

    req.print();
    return 0;
}

