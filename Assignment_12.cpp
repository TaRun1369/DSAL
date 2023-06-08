#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    int rollno;
    char name[30];
//    int div;
//    string address;
    public:
    void getStudentInfo()
    {
        cout << "Enter The name of the student:";
        cin >> name;
        cout << "Enter the roll no of the student:";
        cin >> rollno;
//        cout << "Enter the divison of the student:";
//        cin >> div;
//        cout << "Enter the address of the student:";
//        cin >> address;
    }
    void display()
    {
        cout <<"-----------------------------------"<<endl;
        cout << "Name of the student is:" << name << endl;
        cout << "Roll Number of the student is:" << rollno << endl;
//        cout << "Divison of the student is:" << div << endl;
//        cout << "Address of the student is:" << address << endl;
        cout <<"-----------------------------------"<<endl;
    }
//    string getadd(){
//        return address;
//    }
    int getrollno(){
        return rollno;
    }
};
class Index{
    public:
    int index;
    int rollno;
    void dis(){
        cout<<index<<" "<<rollno<<endl;
    }
};
class FileHandling{
    string filename;
    ofstream ofs;
    ofstream ofs1;
    ifstream ifs;
    ifstream ifs1;
    fstream f;
    fstream f1;
    int ind;
    public:
    FileHandling(){
        cout<<"********OPERATIONS ON FILE********"<<endl;
        // cout<<endl;
        // cout<<"Enter the filename:";
        // cin>>filename;
        // filename+=".dat";
        ind=0;
    }
    void writerecord(){
        cout<<"********WRITING IN FILE********"<<endl;
        ofs.open("file.dat",ios::binary|ios::app);
        ofs1.open("index.dat",ios::binary|ios::app);
        Index i;
        i.index=ind+1;
        ind+=1;
        if(!ofs){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            st.getStudentInfo();
            i.rollno=st.getrollno();
            ofs.write((char*)&st,sizeof(st));
            ofs1.write((char*)&i,sizeof(i));
        }
        ofs.close();
        ofs1.close();
    }
    void readrecord(){
        cout<<"********READING IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        ifs1.open("index.dat",ios::binary|ios::in);
        if(!ifs || !ifs1){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            Index i;
            ifs.seekg(0);
            ifs1.seekg(0);
            while(ifs1.read((char*)&i,sizeof(i))){
                ifs.seekg(sizeof(st)*(i.index-1),ios::beg);                
                ifs.read((char*)&st,sizeof(st));
                st.display();
            }
        }
        ifs.close();
        ifs1.close();
    }
    void search(){
        cout<<"********SEARCHING IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        ifs1.open("index.dat",ios::binary|ios::in);
        if(!ifs || !ifs1){
            cout<<"File could not be opened"<<endl;
        }
        else{
            ifs.seekg(0);
            ifs1.seekg(0);
            Student st;
            Index i;
            int rn;
            int flag=0;
            cout<<"Enter the Roll Number to search:";
            cin>>rn;
            while(ifs1.read((char*)&i,sizeof(i))){
                if(i.rollno==rn){
                    ifs.seekg(sizeof(st)*(i.index-1),ios::beg);                
                    ifs.read((char*)&st,sizeof(st));
                    st.display();
                    flag=1;
                }
            }   
            if(flag==0){
                cout<<"Record Dosenot Exist!!!!"<<endl;
            }
        }
        ifs.close();
        ifs1.close();
    }
    void modify(){
        cout<<"********MODIFY THE FILE********"<<endl;
        f.open("file.dat",ios::binary|ios::in|ios::out);
        f1.open("index.dat",ios::binary|ios::in|ios::out);
        f.seekg(0);
        f1.seekg(0);
        if(!f || !f1){
            cout<<"File could not be opened"<<endl;
        }
        else{
           
            Student st;
            Index i;
            int rn;
            int flag=0;
            cout<<"Enter the Roll Number to Update:";
            cin>>rn;
            while(f1.read((char*)&i,sizeof(i))){
                if(i.rollno==rn){
                    cout<<"********Record is Found********"<<endl;
                    f.seekg(sizeof(st)*(i.index-1),ios::beg); 
                    f.read((char*)&st,sizeof(st));               
                    st.display();
                    flag=1;
                    cout<<"Enter the new updated record:"<<endl;
                    st.getStudentInfo();
                    f.seekp(-sizeof(st),ios::cur);
                    f.write((char*)&st,sizeof(st));
                    i.rollno=st.getrollno();
                    f1.seekp(-sizeof(i),ios::cur);
                    f1.write((char*)&i,sizeof(i));
                }
            }   
            if(flag==0){
                cout<<"Record Dosenot Exist!!!!"<<endl;
            }
        }
        f.close();
        f1.close();
    }
    void deletion(){
        cout<<"********DELETION IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        ifs1.open("index.dat",ios::binary|ios::in);
        ofs.open("temp.dat",ios::binary|ios::out);
        ofs1.open("temp1.dat",ios::binary|ios::out);
        if(!ifs || !ofs || !ifs1){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            Index i;
            int rn;
            int it=1;
            cout<<"Enter the Roll Number to Delete:";
            cin>>rn;
            while(ifs1.read((char*)&i,sizeof(i))){
                if(i.rollno!=rn){                    
                    ifs.seekg(sizeof(st)*(i.index-1),ios::beg);                
                    ifs.read((char*)&st,sizeof(st));
                    ifs1.seekg(-sizeof(i),ios::cur);
                    ifs1.read((char*)&i,sizeof(i));
                    i.index=it;
                    it+=1;
                    ofs.write((char*)&st,sizeof(st));
                    ofs1.write((char*)&i,sizeof(i));
                }
            }
            ifs.close();
            ofs.close();
            ifs1.close();
            ofs1.close();
            remove("file.dat");
            rename("temp.dat","file.dat");
            remove("index.dat");
            rename("temp1.dat","index.dat");
        }
        ifs.close();
        ifs1.close();
        ofs.close();
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
    // f1.writerecord();
    // f1.writerecord();
    // f1.writerecord();
    // f1.writerecord();
    // f1.readrecord(); 
    //f1.modify();
    //f1.readrecord(); 
    //f1.search();
    //f1.readrecord();
    // f1.deletion();
    // f1.readrecord(); 
    // f1.deletion();
    // f1.readrecord();
    // remove("file.dat");
    // remove("index.dat");
    return 0;
}

