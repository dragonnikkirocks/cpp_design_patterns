#include<iostream>
#include<string>
#include<list>

// Composite pattern 
// Composite pattern lets clients treat the individual objects in a uniform manner.


class FileComponent{
  protected:
  FileComponent(std::string name ): name{name}{}
  FileComponent* parent;
  std::string name;
  
  public:
  virtual  ~FileComponent() {}

  void setParent(FileComponent* newParent){
    parent = newParent;
  }

  FileComponent* getParent(){
    return parent;
  }
 
virtual std::string getName() const{return name;}

  virtual bool isDirectory() const { return false;} 

  virtual void addFileComponent(FileComponent* component)
  {

  }
  virtual void removeFileComponent(FileComponent* component)
  {

  }
  virtual void Display() const = 0;

};

class File: public FileComponent{
public:

File(const std::string& name) : FileComponent(name) {}
virtual void Display() const override {

              std::cout<<"FileName is "<<this->getName()<<std::endl;
}

};

class Directory: public FileComponent{

  private:
  std::list<FileComponent*> files;

  public:
  Directory(const std::string& name) : FileComponent(name) {}
std::list<FileComponent*> getFiles(){return files;}
  virtual void addFileComponent(FileComponent* component) override{
    component->setParent(this);
    files.push_back(component);
  }
  virtual bool isDirectory() const override{ return true;}
  virtual void Display() const override{
    std::cout<<"Directory name is "<<this->getName()<<std::endl;
   for(FileComponent* f: files){
      if(!f->isDirectory())
      {
        
        f->Display();
      }
      else{
        std::cout<<"Its has a direvctory with name "<<f->getName()<<std::endl;

      /*   const auto subfiles = f->getFiles();
        std::cout<<"The dir has " <<subfiles.size()<<" files";
        if(subfiles.size()!=0)
        {

        } */
       
      }
   }
    
   
  
  }

};

int main(){
    
    File f1("File1");
        File f2("File2");

    Directory d("Dir1");
    d.addFileComponent(&f1);
    d.addFileComponent(&f2);
    d.Display();
    Directory d_main("Main Dir");

    d_main.addFileComponent(&d);
    d_main.Display();

    return 0;
}