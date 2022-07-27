#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <map>
#include <conio.h>
using namespace std;

void mainMenu();
void doctorDatabase();
void Patient_Database();
void avilabilityDatabase();

vector<string>specialities={"Cardiologist","Audiologist","Dentist","ENT Specialist","Gynaecologist","Orthopaedic Surgeon","Neurologist","Nephrologist"};
vector<string>::iterator it;
vector<string>days={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

class password{
string pass="hos123";
string p;
public:
    void getpass(){
    char ch;
    while(true){
        ch=getch();
        if(ch=='\r'){
            break;
        }
        cout<<"*";
        p+=ch;
    }
    cout<<"\n";
    }
    bool checkpass(){
    if(p==pass){
        return true;
    }
    else
        return false;
    }
};

void mainMenu(){
    do{
    int choice2;
	cout<<endl<<right<<setw(66)<<setfill(' ')<<"MAIN MENU"<<endl;
    cout<<right<<setw(103)<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<right<<setw(58)<<"1.Enter Into Doctors' Database"<<endl;
	cout<<right<<setw(59)<<"2.Enter Into Patients' Database"<<endl;
	cout<<right<<setw(65)<<"3.Enter Into Availabilities' Database"<<endl;
	cout<<right<<setw(34)<<"4.Exit"<<endl;
	cout<<right<<setw(103)<<"-----------------------------------------------------------------------------------"<<endl;
    while(true){
	    cout<<right<<setw(46)<<"Enter your choice:";
	    cin>>choice2;
         try{
        if(choice2>4 || choice2<1){
           throw choice2;
        }
        else{
           break;
        }
	    }
	    catch(int x){
	     cout<<right<<setw(53)<<"!! Enter a valid input !!"<<endl;
	    }
    }
          system("cls");
          switch(choice2)
          {
          case 1:
            doctorDatabase();
            break;
          case 2:
            Patient_Database();
            break;
          case 3:
            avilabilityDatabase();
              break;
          case 4:
            exit(0);
          }
    }while(true);
}

class availabilities
{
    string date;
    int beds;
    int oxygen_cylinders;
    int ventilators;
public:
    void display();
    void addAvailabilities();
    friend void updatePatientEntered(bool oxygen_cylinder,bool ventilator);
    friend void showAvailabilities();
    string get_date(){
     return string(date);
 }
}tempobj;




void availabilities::addAvailabilities(){
cout<<endl<<right<<setw(80)<<".....Add Availability Details....."<<endl<<endl<<endl;
cout<<right<<setw(60)<<"Enter Date in format dd/mm/yy : ";
cin>>date;
cout<<right<<setw(59)<<"Add available number of beds : ";
cin>>beds;
cout<<endl<<right<<setw(71)<<"Add available number of oxygen cylinders : ";
cin>>oxygen_cylinders;
cout<<endl<<right<<setw(66)<<"Add available number of ventilators : ";
cin>>ventilators;
}

void availabilities::display(){
cout<<"\n\n"<<right<<setw(78)<<".....Availability Details....."<<endl<<endl<<endl;
cout<<right<<setw(51)<<"Availability Till Date "<<date<<endl<<endl;
cout<<right<<setw(57)<<"Number of Beds             : "<<beds<<endl<<endl;
cout<<right<<setw(57)<<"Number of Oxygen Cylinders : "<<oxygen_cylinders<<endl<<endl;
cout<<right<<setw(57)<<"Number of Ventilators      : "<<ventilators<<endl<<endl;
}

void addData(){
ofstream fout;
fout.open("Availability.txt",ios::binary|ios::out|ios::app);
tempobj.addAvailabilities();
fout.write((char*)&tempobj,sizeof(tempobj));
fout.close();
cout<<"\n\nData Successfully Saved to File....\n";
}

void searchData()
{
 string date_;int flag=0;
 ifstream fin;
 fin.open("Availability.txt",ios::in|ios::binary);
 cout<<right<<setw(68)<<"Enter Date To Search Availability For : ";
 cin>>date_;

 while(fin.read((char*)&tempobj,sizeof(tempobj)))
 {
  if(date_==tempobj.get_date())
  {
   tempobj.display();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<right<<setw(81)<<"!!Availability Details Of Particular Date Not Found!!";
}

void modifyData()
{
 string n;int flag=0, pos;
 fstream fio;

 fio.open("Availability.txt",ios::in|ios::out|ios::binary);

 cout<<right<<setw(68)<<"Enter Date To Update Availability For : ";
 cin>>n;

 while(fio.read((char*)&tempobj,sizeof(tempobj)))
 {
  pos=fio.tellg();
  if(n==tempobj.get_date())
  {
   cout<<"The Following Data will be modified with new data :\n";
   tempobj.display();
   cout<<"\n\nNow Enter the New Details....\n";
   tempobj.addAvailabilities();
   fio.seekg(pos-sizeof(tempobj));
   fio.write((char*)&tempobj,sizeof(tempobj));
   flag++;
  }
 }
 fio.close();

 if(flag==0)
  cout<<right<<setw(81)<<"!!Availability Details Of Particular Date Not Found!!";
}

int chooseAvail(){
int choice3;
cout<<endl<<right<<setw(74)<<"AVAILABILITIES' DATABASE"<<endl;
cout<<right<<setw(103)<<"-----------------------------------------------------------------------------------"<<endl;
cout<<right<<setw(48)<<"1.Check Availability"<<endl;
cout<<right<<setw(46)<<"2.Add Availability"<<endl;
cout<<right<<setw(49)<<"3.Update Availability"<<endl;
cout<<right<<setw(49)<<"4.Return To Main Menu"<<endl;
cout<<right<<setw(34)<<"5.Exit"<<endl;
cout<<right<<setw(103)<<"-----------------------------------------------------------------------------------"<<endl;
while(true){
cout<<right<<setw(46)<<"Enter your choice:";
cin>>choice3;
if(choice3<1 || choice3>5){
    cout.width(53);
    cout<<"!! Enter a valid input !!"<<endl;
}
else{
    return choice3;
}
}
}

 void avilabilityDatabase(){
              int var3=chooseAvail();
              switch(var3)
              {
              case 1:
              system("cls");
                searchData();
                break;
              case 2:
              system("cls");
                addData();
                break;
              case 3:
              system("cls");
                modifyData();
                break;
              case 4:
              system("cls");
                mainMenu();
                break;
              case 5:
              exit(0);
                break;
        }
         cout<<"\n\n\n\n"<<right<<setw(73)<<"Enter 1 to return to Availabilities' Database"<<endl;
         cout<<right<<setw(58)<<"Enter 2 to return to Main Menu"<<endl;
         cout<<right<<setw(43)<<"Enter 3 to Exit"<<endl;
         cout<<right<<setw(46)<<"Enter your choice:";
              int temp;
	          cin>>temp;
              system("cls");
	          if(temp==1){
                avilabilityDatabase();
	          }
	          else if(temp==2){
                mainMenu();
	          }
	          else if(temp==3){
                exit(0);
	          }
	          else {
                cout<<"invalid choice";
                exit(0);
	          }
}

class Person{
    protected:
        char first_name[15],last_name[15];
        int age;
        char gender[8];
        char id[3];
    public:
        void add_record(string assigned_id);
        void display();
};

void Person::add_record(string assigned_id){
    cout.width(41);
    cout<<"First name : ";cin>>first_name;
    cout.width(40);
    cout<<"Last name : ";cin>>last_name;
    cout.width(34);
    cout<<"Age : ";cin>>age;
    cout.width(37);
    cout<<"Gender : ";cin>>gender;
    strcpy(id,assigned_id.c_str());
}

void Person::display(){
    cout<<endl<<endl;
    cout.width(28);
    cout<<"> "<<"ID : "<<id<<endl;
    cout.width(35);
    cout<<"Name : "<<first_name<<" "<<last_name<<endl;
    cout.width(34);
    cout<<"Age : "<<age<<endl;
    cout.width(37);
    cout<<"Gender : "<<gender<<endl;
}

class Doctor:public Person{
    char qualification[5],speciality[20];
    float experience;
    float salary;
    pair<char[10],char[10]>timings_available;
    bool days_available[7];
    public:
        friend Doctor add_record(string assigned_id);
        void display();
        friend void display();
        friend void search(string id_to_search);
        friend void search(int specialitySearch);
        string get_id(){
            return string(id);
        }
        friend void edit_info(string id_to_edit);
        friend void delete_record(string id_to_delete);
};

void Doctor::display(){
    cout.width(44);
    cout<<"Qualification : "<<qualification<<endl;
    cout.width(41);
    cout<<"Experience : "<<experience<<endl;
    cout.width(41);
    cout<<"Speciality : "<<speciality<<endl;
    cout.width(52);
    cout<<"Salary(per month) : Rs. "<<fixed<<setprecision(2)<<salary<<endl;
    cout.width(45);
    cout<<"Days available : ";
    for(int i=0;i<days.size();i++){
        if(days_available[i]){
            cout<<days[i]<<" ";
        }
    }
    cout<<endl;
    cout.width(38);
    cout<<"Timings : "<<timings_available.first<<" to "<<timings_available.second;
}

void display(){
    int flag=0,count=0;
    Doctor d1;
    ifstream fileObj;
    fileObj.open("Doctors.txt",ios::in | ios::binary);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
        flag=1;
    }
    if(!flag){
        while(fileObj.read((char*)&d1,sizeof(d1))){
            flag=1;
            d1.Person::display();
            d1.Doctor::display();
            count++;
        }
        fileObj.close();
        cout<<endl<<endl<<endl<<setw(44)<<"TOTAL DOCTORS : "<<count;
    }
    if(!flag){
        cout<<"\n\n--No record found--";
    }
}

Doctor add_record(string assigned_id){
    Doctor d1;
    d1.Person::add_record(assigned_id);
    int temp;
    cout.width(65);
    cout<<"Choose qualification from following ="<<endl<<setw(34)<<"1.MBBS"<<endl<<setw(32)<<"2.MD"<<endl<<setw(31)<<">> ";cin>>temp;
    if(temp==1){
        strcpy(d1.qualification,"MBBS");
    }
    else{
        strcpy(d1.qualification,"MD");
    }
    cout.width(52);
    cout<<"Experience (in years) : ";cin>>d1.experience;
    cout.width(47);
    cout<<"Choose specilaity ="<<endl;
    int i=1;
    for(i=1;i<=specialities.size();i++){
        cout.width(29);
        cout<<i<<"."<<specialities[i-1]<<"\n";
    }
    cout.width(29);
    cout<<i<<".Others\n";
    cout.width(31);
    cout<<">> ";cin>>temp;
    if(temp==i){
        cout.width(45);
        cout<<"Please specify : ";cin>>d1.speciality;
        specialities.push_back(d1.speciality);
    }
    else{
        strcpy(d1.speciality,specialities[temp-1].c_str());
    }
    cout.width(48);
    cout<<"Salary(per month) : ";cin>>d1.salary;
    bool isAvailable;
    cout.width(89);
    cout<<"Days the doctor is available(Enter 0 for NO and 1 for YES) : "<<endl;
    i=0;
    for(it=days.begin();it<days.end();it++){
        cout.width(30);
        cout<<"> "<<(*it)<<" : ";cin>>isAvailable;
        d1.days_available[i]=isAvailable;
        i++;
    }
    fflush(stdin);
    cout.width(47);
    cout<<"Timings available ="<<endl<<setw(41)<<"Visit time : ";cin.getline(d1.timings_available.first,10);
    fflush(stdin);
    cout.width(48);
    cout<<"Departure timings : ";cin.getline(d1.timings_available.second,10);
    return d1;
}

void delete_record(string id_to_delete){
    Doctor d1;
    int flag=0;
    ifstream fin;
    ofstream fout;
    fin.open("Doctors.txt",ios::in|ios::binary);
    if(!fin){
        cout<<"\n\n--Error in opening the file--";
    }
    else{
    fout.open("tempDoc.txt",ios::app|ios::binary);
    while(fin.read((char*)&d1,sizeof(d1)))
    {
        if(d1.get_id()==id_to_delete){
            flag++;
        }
        else{
            fout.write((char*)&d1,sizeof(d1));
        }
    }
         fout.close();
         fin.close();
         if(flag==0){
            remove("tempDoc.txt");
            cout<<"\n\n--No matching record found--";
         }
         else{
            remove("Doctors.txt");
            rename("tempDoc.txt","Doctors.txt");
            cout<<endl<<"Deletion from file successfully done.....";
         }
    }
}

void edit_info(string id_to_edit){
    int flag=0;
    Doctor d1;
    fstream fileObj;
    fileObj.open("Doctors.txt",ios::in | ios::out);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
    }
    else{
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&d1,sizeof(d1))){
            if(d1.get_id()==id_to_edit){
                cout<<endl<<endl<<setw(50)<<"Current infromation : ";
                d1.Person::display();
                d1.Doctor::display();
                cout<<endl<<endl<<setw(52)<<"Enter new information : "<<endl<<endl;
                Doctor d2=add_record(d1.get_id());
                int pos=-1*sizeof(d2);
                fileObj.seekp(pos,ios::cur);
                fileObj.write((char*)&d2,sizeof(d2));
                flag=1;
                break;
            }
        }
    fileObj.close();
    if(!flag){
        cout<<"\n\nNo matching record found";
    }
    if(flag){
        cout<<"\n.... Information edited succesfully ....";
    }
    }
}

void search(string id_to_search){
    int flag=0;
    Doctor d1;
    ifstream fileObj;
    fileObj.open("Doctors.txt",ios::in | ios::binary);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
        flag=1;
    }
    if(flag==0){
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&d1, sizeof(d1))){
            if(d1.get_id()==id_to_search){
                d1.Person::display();
                d1.Doctor::display();
                flag=1;
                break;
            }
        }
    }
    fileObj.close();

    if(!flag){
        cout<<"\n\n--No matching record found--";
    }
}

void search(int specialitySearch){
    string speciality_to_search=specialities[specialitySearch];
    int flag=0,count=0;
    Doctor d1;
    vector<Doctor>allDoctorsWithSpeciality;
    ifstream fileObj;
    fileObj.open("Doctors.txt",ios::in | ios::binary);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
        flag=1;
    }
    else{
    if(flag==0){
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&d1,sizeof(d1))){
            if(d1.speciality==speciality_to_search){
                flag=1;
                allDoctorsWithSpeciality.push_back(d1);
                count++;
            }
        }
    }
    fileObj.close();
    if(!flag){
        cout<<"\n\n--No doctor with such speciality--";
    }
    else{
        vector<Doctor>::iterator it;
        for(it=allDoctorsWithSpeciality.begin();it<allDoctorsWithSpeciality.end();it++){
            it->Person::display();
            it->Doctor::display();
        }
        cout<<endl<<endl<<endl<<setw(34)<<"TOTAL "<<speciality_to_search<<" : "<<count;
    }
    }
}

void doctorDatabase(){
    int choice;
    cout.setf(ios::right,ios::adjustfield);
    cout.width(70);
    cout<<"DOCTOR'S DATABASE"<<endl;
    cout.width(103);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout.width(57);
    cout<<"1. Add New Doctor Information"<<endl;
    cout.width(65);
    cout<<"2. Search Doctor's Information via ID"<<endl;
    cout.width(60);
    cout<<"3. Search Doctors via Speciality"<<endl;
    cout.width(60);
    cout<<"4. Delete a Doctor's Information"<<endl;
    cout.width(58);
    cout<<"5. Edit a Doctor's Information"<<endl;
    cout.width(61);
    cout<<"6. Display Entire Doctor Database"<<endl;
    cout.width(40);
    cout<<"7. Main Menu"<<endl;
    cout.width(35);
    cout<<"8. Exit"<<endl;
    cout.width(103);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    do{
        cout.width(48);
        cout<<"Enter your choice : ";
        cin>>choice;
        string id_to_search;
        int temp,count;
        int speciality_to_search;
        Doctor dTemp;
        ofstream fileObj;
        ifstream fileIn;
        string assigned_id;
        if(choice==1){
                system("cls");
                cout.width(73);
                cout<<"....Add Doctor detail's...."<<endl<<endl<<endl;
                count=0;
                fileIn.open("Doctors.txt",ios::in | ios::binary);
                while(fileIn.read((char*)&dTemp,sizeof(dTemp))){
                    count++;
                }
                fileIn.close();
                assigned_id="D"+to_string(count+1);
                Doctor d1=add_record(assigned_id);
                fileObj.open("Doctors.txt",ios::app | ios::binary);
                fileObj.write((char*)&d1, sizeof(d1));
                fileObj.close();
                cout<<endl<<setw(44)<<"ASSIGNED ID = "<<d1.get_id();
                cout<<"\n\n.... New Doctor profile created successfully ....";
        }
            else if(choice==2){
                system("cls");
                cout.width(77);
                cout<<"....Search Doctor's details...."<<endl<<endl<<endl;
                cout.width(49);
                cout<<"Enter ID of Doctor : ";cin>>id_to_search;
                search(id_to_search);
            }
            else if(choice ==3){
                system("cls");
                cout.width(77);
                cout<<"....Search Doctor's details...."<<endl<<endl<<endl;
                cout.width(46);
                cout<<"Enter speciality ="<<endl<<endl;
                for(int i=0;i<specialities.size();i++){
                    cout.width(29);
                    cout<<i+1<<"."<<specialities[i]<<endl;
                }
                cout.width(31);
                cout<<endl<<">> ";cin>>speciality_to_search;
                search(speciality_to_search-1);
            }
            else if(choice==4){
                system("cls");
                cout.width(79);
                cout<<"....Delete Doctor's Information...."<<endl<<endl<<endl;
                cout.width(59);
                cout<<"Enter ID of Doctor to delete : ";cin>>id_to_search;
                delete_record(id_to_search);
            }
            else if(choice==5){
                system("cls");
                cout.width(75);
                cout<<"....Edit Doctor's Information...."<<endl<<endl<<endl;
                cout.width(57);
                cout<<"Enter ID of Doctor to edit : ";cin>>id_to_search;
                edit_info(id_to_search);
            }
            else if(choice==6){
                system("cls");
                cout.width(77);
                cout<<"....Entire Doctor Database....";
                display();
            }
            else if(choice==7){
                system("cls");
            }
            else if(choice==8){
                exit(0);
                break;
            }
            else{
                cout.width(53);
                cout<<"!! Enter a valid input !!"<<endl;
            }
        if(choice>=1 && choice<=6){
        cout<<"\n\n\n\n"<<setw(64)<<"Enter 1 to return to Doctor Database"<<endl<<setw(58)  <<"Enter 2 to return to Main Menu"<<endl<<setw(43)<<"Enter 3 to Exit"<<endl<<setw (31)<<">> ";
	            cin>>temp;
                system("cls");
                if(temp==1){
                    choice=7;
                    doctorDatabase();
                }
                else if(temp==2){
                    break;
                }
                else{
                    exit(0);
                }
        }
        }while(choice!=7);
    return;
}

struct HospitalCosts{
    int oxygen_cylinder_cost,ventilator_cost,appointmentFees,bedCost;
};

class Patient:public Person{
    struct HospitalCosts patient_bill;
 char blood_group[3];
 char symptomes[50],medicines[50],diagonosis[30];
 char doctor_assigned[30];
 bool isAdmitted,ventilator_required,oxygen_cylinder_required;
 int no_of_days_admitted;
 int room_no;
 public:
 Patient(){
     patient_bill.appointmentFees=500;
     patient_bill.bedCost=0;
     patient_bill.oxygen_cylinder_cost=0;
     patient_bill.ventilator_cost=0;
     no_of_days_admitted=0;
     room_no=0;
 }
 string get_id(){
     return string(id);
 }
 friend Patient add_patient_record(string assigned_id);
 friend void search_patient_info(string id_to_search);
 friend void display_Patient_record();
 void display();
  friend void update_Patient_info(string id_to_edit);
  friend void delete_Patient_info(string id_to_delete);
  friend void generateBill(Patient p1);
};

void generateBill(Patient p1){
    string s1=p1.get_id()+"_Bill";
    s1+=".txt";
    int sum=p1.patient_bill.appointmentFees+p1.patient_bill.bedCost*p1.no_of_days_admitted+p1.patient_bill.oxygen_cylinder_cost+p1.patient_bill.ventilator_cost;
    ofstream fileObj;
    fileObj.open(s1,ios::out);
    fileObj<<"Patient name             : "<<p1.first_name<<" "<<p1.last_name<<endl;
    fileObj<<"ID                       : "<<p1.get_id()<<endl<<endl<<endl;
    fileObj<<"Appointment Cost         : Rs."<<p1.patient_bill.appointmentFees<<endl;
    fileObj<<"Bed Cost                 : Rs."<<p1.patient_bill.bedCost*p1.no_of_days_admitted<<endl;
    fileObj<<"Oxygen Cylinder Cost     : Rs."<<p1.patient_bill.oxygen_cylinder_cost<<endl;
    fileObj<<"Ventilator Cost          : Rs."<<p1.patient_bill.ventilator_cost<<endl;
    fileObj<<"-------------------------------------------------------"<<endl;
    fileObj<<setw(15)<<"TOTAL"<<"  =  Rs."<<sum;
    fileObj.close();
}

void Patient::display(){
    cout.width(42);
    cout<<"Blood Group : "<<this->blood_group<<endl;
    cout.width(39);
    cout<<"Symptoms : "<<this->symptomes<<endl;
    cout.width(41);
    cout<<"Diagonosis : "<<this->diagonosis<<endl;
    cout.width(40);
    cout<<"Medicines : "<<this->medicines<<endl;
    cout.width(46);
    cout<<"Doctor Assigned : "<<this->doctor_assigned<<endl;
    cout.width(42);
    cout<<"Is Adimtted ? "<<this->isAdmitted<<endl;
    if(isAdmitted){
        cout.width(38);
        cout<<"Room No : "<<this->room_no<<endl;
        cout.width(50);
        cout<<"No of days admitted : "<<this->no_of_days_admitted<<endl;
    }
}

Patient add_patient_record(string assigned_id){
 Patient p1;
 p1.Person::add_record(assigned_id);
    fflush(stdin);
    cout.width(42);
    cout<<"Blood Group : "; cin>>p1.blood_group;
    fflush(stdin);
    cout.width(39);
    cout<<"Symptoms : "; cin.getline(p1.symptomes,1000);
    fflush(stdin);
    cout.width(41);
    cout<<"Diagonosis : ";cin.getline(p1.diagonosis,1000);
    fflush(stdin);
    cout.width(40);
    cout<<"Medicines : ";cin.getline(p1.medicines,1000);
    fflush(stdin);
    cout.width(46);
    cout<<"Doctor Assigned : ";cin.getline(p1.doctor_assigned,30);
    fflush(stdin);
    cout.width(49);
    cout<<"Admission required : ";cin>>p1.isAdmitted;
    if(p1.isAdmitted){
        searchData();
        cout.width(38);
        cout<<"Room No : ";cin>>p1.room_no;
        cout.width(50);
        cout<<"No of days admitted : ";cin>>p1.no_of_days_admitted;
        cout.width(50);
        cout<<"Ventilator required ? ";cin>>p1.ventilator_required;
        cout.width(55);
        cout<<"Oxygen cylinder required ? ";cin>>p1.oxygen_cylinder_required;
        p1.patient_bill.bedCost=10000;
        p1.patient_bill.oxygen_cylinder_cost=(p1.oxygen_cylinder_required)?15000:0;
        p1.patient_bill.ventilator_cost=(p1.ventilator_required)?3500:0;
    }
    generateBill(p1);
    return p1;
}

void display_Paitent_record(){
    int flag=0,count=0;
    Patient p1;
    ifstream fileObj;
    fileObj.open("Patient.txt",ios::in | ios::binary);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
        flag=1;
    }
    if(!flag){
        while(fileObj.read((char*)&p1,sizeof(p1))){
            flag=1;
            p1.Person::display();
            p1.Patient::display();
            count++;
        }
        fileObj.close();
        cout<<endl<<endl<<endl<<setw(44)<<"TOTAL PATIENTS : "<<count;
    }
    if(!flag){
        cout<<"\n\n--No record found--";
    }
}

void update_Patient_info(string id_to_edit){
    int flag=0;
    Patient p1;
    fstream fileObj;
    fileObj.open("Patient.txt",ios::in | ios::out);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
    }
    else{
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&p1,sizeof(p1))){
            if(p1.get_id()==id_to_edit){
                cout<<endl<<endl<<setw(50)<<"Current infromation : ";
                p1.Person::display();
                p1.Patient::display();
                cout<<endl<<endl<<setw(52)<<"Enter new information : "<<endl<<endl;
                p1=add_patient_record(p1.get_id());
                int pos=-1*sizeof(p1);
                fileObj.seekp(pos,ios::cur);
                fileObj.write((char*)&p1,sizeof(p1));
                flag=1;
                break;
            }
        }
    fileObj.close();
    if(!flag){
        cout<<"\n\nNo matching record found";
    }
    if(flag){
        cout<<"\n.... Information edited succesfully ....";
    }
    }
}

void search_Patient_info(string id_to_search){
    int flag=0;
    Patient p1;
    ifstream fileObj;
    fileObj.open("Patient.txt",ios::in | ios::binary);
    if(!fileObj){
        cout<<"\n\n--Error in opening the file--";
        flag=1;
    }
    if(flag==0){
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&p1, sizeof(p1))){
            if(p1.get_id()==id_to_search){
                p1.Person::display();
                p1.Patient::display();
                flag=1;
                break;
            }
        }
    }
    fileObj.close();

    if(!flag){
        cout<<"\n\n--No matching record found--";
    }
}

void delete_Patient_info(string id_to_delete){
    Patient p1;
    int flag=0;
    ifstream fin;
    ofstream fout;
    fin.open("Patient.txt",ios::in|ios::binary);
    if(!fin){
        cout<<"\n\n--Error in opening the file--";
    }
    else{
    fout.open("tempPat.txt",ios::app|ios::binary);
    while(fin.read((char*)&p1,sizeof(p1)))
    {

        if(p1.get_id()==id_to_delete){
            flag++;
        }
        else{
            fout.write((char*)&p1,sizeof(p1));
        }
    }
         fout.close();
         fin.close();
         if(flag==0){
            remove("tempPat.txt");
            cout<<"\n\n--No matching record found--";
         }
         else{
            remove("Patient.txt");
            rename("tempPat.txt","Patient.txt");
            cout<<endl<<"Deletion from file successfully done.....";
         }
    }
}

void Patient_Database(){
    int choice;
    do{
    cout.width(72);
    cout<<"PATIENT'S DATABASE"<<endl;
    cout.width(103);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout.width(58);
    cout<<"1. Add new Patient Information"<<endl;
    cout.width(67);
    cout<<"2. Search Information of Patient Via ID"<<endl;
    cout.width(57);
    cout<<"3. Edit Patient's Information"<<endl;
    cout.width(59);
    cout<<"4. Delete Patient's Information"<<endl;
    cout.width(62);
    cout<<"5. Display Entire Patient Database"<<endl;
    cout.width(40);
    cout<<"6. Main Menu"<<endl;
    cout.width(35);
    cout<<"7. Exit"<<endl;
    cout.width(103);
    cout<<"-----------------------------------------------------------------------------------"<<endl<<endl;
    cout.width(72);
    cout<<"Enter the choice from the above features :  ";
    cin>>choice;
    int count;
    string id;
    string assigned_id;;
    Patient p1,pTemp;
    ifstream fileIn;
    ofstream fileObj;
    switch (choice){
    case 1:{
    system("cls");
                cout.width(74);
                cout<<"....Add Patient detail's...."<<endl<<endl<<endl;
                count=0;
                fileIn.open("Patient.txt",ios::in | ios::binary);
                while(fileIn.read((char*)&pTemp,sizeof(pTemp))){
                    count++;
                }
                fileIn.close();
                assigned_id="P"+to_string(count+1);
                p1=add_patient_record(assigned_id);
                fileObj.open("Patient.txt",ios::app | ios::binary);
                fileObj.write((char*)&p1, sizeof(p1));
                fileObj.close();
                cout<<endl<<setw(44)<<"ASSIGNED ID = "<<assigned_id;
                cout<<"\n\n.... New Patient profile created successfully ....";
    break;
    }
    case 2:{
        system("cls");
        cout.width(81);
        cout<<"....Search Patient's Information...."<<endl<<endl<<endl;
        cout.width(61);
        cout<<"Enter ID of Patient's to search : ";cin>>id;
        search_Patient_info(id);
        break;
    }
    case 3:{
        system("cls");
        cout.width(80);
        cout<<"....Edit Patient's Information...."<<endl<<endl<<endl;
        cout.width(60);
        cout<<"Enter ID of Patient's to Edit : ";cin>>id;
        update_Patient_info(id);
        break;
    }
    case 4:{
        system("cls");
        cout.width(81);
        cout<<"....Delete Patient's Information...."<<endl<<endl<<endl;
        cout.width(62);
        cout<<"Enter ID of Patient's to Delete : ";cin>>id;
        delete_Patient_info(id);
        break;
    }
    case 5:{
        system("cls");
        cout.width(78);
        cout<<"....Entire Patient Database....";
        display_Paitent_record();
    break;
    }
    case 6:{
        system("cls");
        break;
    }
    case 7:{
        exit(0);
        break;
    }
    default:{
    cout.width(53);
    cout<<"!! Enter a valid input !!"<<endl;
    break;
    }
    }
    if(choice==1||choice==2||choice==3||choice==4||choice==5){
    cout<<"\n\n\n\n"<<setw(65)<<"Enter 1 to return to Patient Database"<<endl;
    cout<<setw(58)<<"Enter 2 to return to Main Menu"<<endl<<setw(43)<<"Enter 3 to Exit"<<endl<<setw(31)<<">> ";
    int choice2;
    cin>>choice2;
    system("cls");
    if(choice2==1){
        choice=6;
    Patient_Database();
    }
    else if(choice2==2){
    break;
    }
    else
    exit(0);
    }
    }while(choice!=6);
    return;
 }

int main(){
    system("color B0");
    cout.setf(ios::right,ios::adjustfield);
    cout.width(80);
    cout<<"-------------------------------------"<<endl;
    cout.setf(ios::right,ios::adjustfield);
    cout.width(80);
    cout<<"WELCOME TO HOSPITAL MANAGEMENT SYSTEM"<<endl;
    cout.setf(ios::right,ios::adjustfield);
    cout.width(80);
    cout<<"-------------------------------------"<<"\n\n\n";
    cout.setf(ios::right,ios::adjustfield);
    cout.width(40);
    cout<<"1. Main Menu"<<endl;
    cout.setf(ios::right,ios::adjustfield);
    cout.width(35);
    cout<<"2. Exit"<<"\n\n";
    cout.setf(ios::right,ios::adjustfield);
    cout.width(46);
    cout<<"Enter your choice:";
    int choice;
    cin>>choice;
    switch(choice){
    case 1:
    {
        cout.setf(ios::right,ios::adjustfield);
        cout.width(43);
        cout<<"Enter Password:";
        password temp;
        temp.getpass();
        if(temp.checkpass()){
              mainMenu();
        }
        else{
            cout<<"\n\n";
            cout.setf(ios::right,ios::adjustfield);
            cout.width(42);
            cout<<"WRONG PASSWORD"<<endl;
            cout.setf(ios::right,ios::adjustfield);
            cout.width(42);
            cout<<"ACCESS DENIED!"<<endl;
            exit(0);
        }
        break;
    }
    case 2:{
        exit(0);
        break;
    }
    }
    return 0;
}

