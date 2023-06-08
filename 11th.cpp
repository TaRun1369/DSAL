#include<iostream>
#include<fstream>
using namespace std;

class Student{
  int rollno;
  char name[30];
  public:
  
  void getStudentInfo(){
      cout<<"Enter roll number : "<<endl;
      cin>>rollno;
      cout<<"Enter name : "<<endl;
      cin>>name;
  }
  
  void display(){
      cout<<"Roll NO. - "<<rollno<<endl;
      cout<<"Name is - "<<name<<endl;
  }
  
  int getrollno(){
      return rollno;
  }
};

class FileHandling{
  ifstream ifile;
  ofstream ofile;
  fstream iofile;
  public: 
  void writerecord(){
      cout<<"----------Writing--------"<<endl;
      ofile.open("file.dat",ios::binary | ios::app);
      if(!ofile){
          cout<<"NHI KHUL RAHI FILE"<<endl;
      }
      else{
          Student std;
          std.getStudentInfo();
          ofile.write((char*)&std,sizeof(std));
      }
      ofile.close();
  }
  void readrecord(){
      cout<<"-------Reading---------"<<endl;
      ifile.open("file.dat",ios::binary | ios :: in);
      if(!ifile){
            cout<<"NI KHUL RAHI FILE"<<endl;
      }
      else{
          Student std;
          while(ifile.read((char*)&std,sizeof(std))){
              std.display();
          }
      }
      ifile.close();
  }
  
  void search(){
      cout<<"------Search--------"<<endl;
      ifile.open("file.dat",ios::binary | ios :: in);
          if(!ifile){
              cout<<"NHI khul rahi file"<<endl;
          }
          else{
              int rn;
              cout<<"Enter roll number to search"<<endl;
              cin>>rn;
              int flag = 0;
              Student std;
              while(ifile.read((char*)&std,sizeof(std))){
                  
                  if(std.getrollno() == rn){
                      cout<<"=------MIL gaya------= "<<endl;
                      std.display();
                      flag = 1;
                  }
              }
              if(flag == 0){
                  cout<<"-------------Record doesnt exist bro---------"<<endl;
              }
          }
          ifile.close();
    }
    
    void modify(){
        cout<<"---------Modify--------"<<endl;
      iofile.open("file.dat",ios::binary | ios :: in | ios::out);
      iofile.seekg(0);
          if(!iofile){
              cout<<"NHI khul rahi file"<<endl;
          }
          else{
              int rn;
              cout<<"Enter roll number to modify"<<endl;
              cin>>rn;
              int flag = 0;
              Student std;
              while(iofile.read((char*)&std,sizeof(std))){
                  
                  if(std.getrollno() == rn){
                      cout<<"Found element "<<endl;
                      std.display();
                      flag = 1;
                      cout<<"Enter new data"<<endl;
                        std.getStudentInfo();
                        iofile.seekp(-sizeof(std),ios::cur);
                        iofile.write((char*)&std,sizeof(std));
                  }
              }
              if(flag == 0){
                  cout<<"-------------Record doesnt exist bro---------"<<endl;
              }
          }
          ifile.close();
    }
    
    void deletion(){
        ifile.open("file.dat",ios::binary|ios::in);
        ofile.open("temp.dat",ios::binary|ios::app);
        if(!ifile || !ofile){
            cout<<"NHI khul rahi file"<<endl;
            
        }
        else{
            int rn;
            
            cout<<"Enter roll number to delete"<<endl;
            cin>>rn;
            Student std;
            while(ifile.read((char*)&std,sizeof(std))){
                if(rn != std.getrollno()){
                    ofile.write((char*)&std,sizeof(std));
                }
            }
            ifile.close();
            ofile.close();
            remove("file.dat");
            rename("temp.dat","file.dat");
        }
       
    }
    
  
};


int main(){
    FileHandling f1;    
    int choice=1;
    int choose;
    while(choice){
        cout<<"1-Write in a File"<<endl;
        cout<<"2-Read in a File"<<endl;
        cout<<"3-Search in a File"<<endl;
        cout<<"4-Modify in a File"<<endl;
        cout<<"5-Delete in a File"<<endl;
        cout<<"Enter your choice:";
        cin>>choose;
        if(choose==1){
            f1.writerecord();
        }       
        else if(choose==2){
            f1.readrecord();
        }
        else if(choose==3){
            f1.search();
        }
        else if(choose==4){
            f1.modify();
        }
        else if(choose==5){
            f1.deletion();
        }
        cout<<"Do you want to continue(0,1):";
        cin>>choice;
    }
       
    // remove("file.dat");

    return 0;
}
