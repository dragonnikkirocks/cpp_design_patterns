#include<iostream>

//Good example might be to create an HTTP REQUEST

struct HTTP_request{
  
    public:
    std::string version;
    std::string endpoint_url;
    std::string http_verb;
    void print(){
        std::cout<<"1 "<<version<<" 2 "<<endpoint_url<<" 3 "<<http_verb<<std::endl;
      }
    

};

class HTTP_request_builder{
    private:
    HTTP_request test;
    public:
    void setVersion(std::string version_){test.version = version_; }
    void setEnd(std::string end){test.endpoint_url=end;  }
    void setVerb(std::string httpverb){test.http_verb=httpverb; }


    HTTP_request build(){

        return test;
    }
};
int main(){
    
    std::cout<<" Builder design pattern "<<std::endl;
    HTTP_request_builder b;

    //this is without chaining 
    //sometimes for building a part a modified Product should be passed to next stage - then function calls should be chained
   b.setVerb("Post");
   b.setEnd("www.google.com");
   b.setVersion(" HTTP2 ");
      auto test =  b.build();
      test.print();
    return 0;
}