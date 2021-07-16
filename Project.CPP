#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip.h>
struct dt
	{ int d,m,y;};
struct idetail       //for inpatient
	{ char iname[20],iadd[40];
	long iphno;
	long iid;
	dt age;
	char g;
	char mh[100];
	float h;
	float w;
	int days;
	char specialist[30];
	char doctorname[30];
	int discharge;
	dt dtadmit; //date of admit
	int roomno;
	};
struct odetail       //for outpatient
	{ char oname[20],oadd[40];
	long ophno;
	long oid;
	dt age;
	char g;
	char mh[100];
	float h;
	float w;
	char speciality[30];
	char doctorname[30];
	};
struct pharm
{	long pid;
	char med[40];
};
struct lab
{	long lid;
	char lb[40];
};
struct sur
{	long sid;
	char sr[40];
};
char* docname(char* sp)
{	if(strcmpi(sp,"orthopaedics")==0)
	return "Dr.NAVALADI SHANKAR A";
	if(strcmpi(sp,"cardiology")==0)
	return "Dr.PRAMOD KUMAR K P";
	if(strcmpi(sp,"gynaecology")==0)
	return "Dr.REKHA SUDAKARAN";
	return 0;
}
int pharmacy(char* ph)
{	if(strcmpi(ph,"liptor")==0)
	return 21;
	if(strcmpi(ph,"nexium")==0)
	return 32;
	if(strcmpi(ph,"plavix")==0)
	return 42;
	if(strcmpi(ph,"advair")==0)
	return 19;
	if(strcmpi(ph,"abilify")==0)
	return 28;
	if(strcmpi(ph,"seroquel")==0)
	return 38;
	if(strcmpi(ph,"singulair")==0)
	return 15;
	if(strcmpi(ph,"crestor")==0)
	return 29;
	if(strcmpi(ph,"actos")==0)
	return 35;
	if(strcmpi(ph,"epogen")==0)
	return 41;
	if(strcmpi(ph,"crocin")==0)
	return 10;
	if(strcmpi(ph,"becosules")==0)
	return 9;
	if(strcmpi(ph,"calpol")==0)
	return 11;
	if(strcmpi(ph,"domstal")==0)
	return 12;
	if(strcmpi(ph,"lisinopril")==0)
	return 27;
	return 0;
}
long labdetail(char*l)
{	if(strcmpi(l,"fasting blood sugar")==0)
	return 200;
	if(strcmpi(l,"ECG")==0)
	return 400;
	if(strcmpi(l,"thyroid function test")==0)
	return 900;
	if(strcmpi(l,"haemogram")==0)
	return 450;
	if(strcmpi(l,"lipid profile")==0)
	return 640;
	if(strcmpi(l,"postprandal blood sugar")==0)
	return 200;
	return 0;
}
long surgery(char*s)
{	if(strcmpi(s,"cataract surgery")==0)
	return 50000;
	if(strcmpi(s,"corneal transplantation")==0)
	return 60000;
	if(strcmpi(s,"heart valve repair")==0)
	return 300000;
	if(strcmpi(s,"coronary artery bypass surgery")==0)
	return 350000;
	if(strcmpi(s,"open-knee surgery")==0)
	return 90000;
	if(strcmpi(s,"valve replacement")==0)
	return 400000;
	if(strcmpi(s,"anorectal surgery")==0)
	return 100000;
	if(strcmpi(s,"dental restoration")==0)
	return 80000;
	if(strcmpi(s,"gastric bypass")==0)
	return 200000;
	return 0;
}

void main()
{ clrscr();
  char a[20]; int i=0;
  //   HOSPITAL NAME AT THE CENTER
  cout<<"Enter password:";
  a[i]=getch();

  while(isalnum(a[i]))
  {
	cout<<"*";
	i++;
	a[i]=getch();
   }
   a[i]='\0';
   int b;
   if(strcmp(a,"hospital")==0)
   {
     b=1;}
 if(b==1)
 {
int ch;
do{
	clrscr();
	//   MENU
	cout<<"1.INPATIENT\n2.OUTPATIENT\n3.BILL\n4.EXIT";
	cout<<"\nEnter choice";
	cin>>ch;
	if(ch==1)          //menu choice 1
	{ 	clrscr();
		int p;
		cout<<"1.NEW PATIENT\n2.OLD  PATIENT";
		cout<<"\nEnter choice:";
		cin>>p;
		if(p==1)
		{	clrscr();
			fstream f1;
			f1.open("inpatient.dat",ios::app|ios::binary);
			idetail in;
			cout<<"Name:";
			gets(in.iname);
			cout<<"Address:";
			gets(in.iadd);
			cout<<"Phone number:";
			cin>>in.iphno;
			cout<<"Date of birth:";
			cout<<"\nDay:";
			cin>>in.age.d;
			cout<<"Month:";
			cin>>in.age.m;
			cout<<"Year:";
			cin>>in.age.y;
			cout<<"Gender:";
			cin>>in.g;
			cout<<"Height:";
			cin>>in.h;
			cout<<"Weight:";
			cin>>in.w;
			cout<<"Speciality:";
			gets(in.specialist);
			strcpy(in.doctorname,docname(in.specialist));
			cout<<"Medical details:";
			gets(in.mh);
			cout<<"Date of admit:";
			cout<<"\nDay:";
			cin>>in.dtadmit.d;
			cout<<"Month:";
			cin>>in.dtadmit.m;
			cout<<"Year:";
			cin>>in.dtadmit.y;
			cout<<"No. of days of admit:";
			cin>>in.days;
			in.discharge=0;
			randomize();
			in.iid=random(99999-10001+1)+10001;
			clrscr();
			cout<<"Patient id:"<<in.iid;
			getch();
			f1.write((char*)&in,sizeof(in));
			f1.close();
		}  //p-1
		if(p==2)
		{	clrscr();
			long id;
			clrscr();
			cout<<"1.MEDICINE PUCHASED\n2.SURGERY UNDERGONE\n3.LAB\n4.Forgot patient id";
			int ex;
			cout<<"\nEnter choice:";
			cin>>ex;
			if(ex==1)
			{       fstream f3;
				f3.open("pharmacy.dat",ios::app|ios::binary);
				char md[40];
				cout<<"\nPatient ID:";
				cin>>id;
				do{     clrscr();
					cout<<"MEDICINE:";
					gets(md);
					if(strcmpi(md,"exit")!=0)
					{ pharm ph;
					  ph.pid=id;
					  strcpy(ph.med,md);
					f3.write((char*)&ph,sizeof(ph));   }
				   }while(strcmpi(md,"exit")!=0);
				f3.close();
			 }      //ex-1
			 if(ex==2)
			 {	fstream f4;
				f4.open("surgery.dat",ios::app|ios::binary);
				char sy[40];
				cout<<"\nPatient ID:";
				cin>>id;
				do{     clrscr();
					cout<<"SURGERY:";
					gets(sy);
					if(strcmpi(sy,"exit")!=0)
					{ sur sd;
					  sd.sid=id;
					  strcpy(sd.sr,sy);
					f4.write((char*)&sd,sizeof(sd)); }
				   }while(strcmpi(sy,"exit")!=0);
				f4.close();
			  }       //ex-2
			  if(ex==3)
			  {	fstream f5;
				f5.open("lab.dat",ios::app|ios::binary);
				char labn[40];
				cout<<"\nPatient ID:";
				cin>>id;
				do{     clrscr();
					cout<<"ENTER:";
					gets(labn);
					if(strcmpi(labn,"exit")!=0)
					{ lab ld;
					  ld.lid=id;
					  strcpy(ld.lb,labn);
					f5.write((char*)&ld,sizeof(ld));}
				   }while(strcmpi(labn,"exit")!=0);
				f5.close();
			   }  //ex-3
			   if(ex==4)
			   { 	fstream f1;
				idetail ck;
				char na[20],ad[50];
				long no;
				f1.open("inpatient.dat",ios::in|ios::binary);
				cout<<"Name:";
				gets(na);
				cout<<"Address:";
				gets(ad);
				cout<<"Phone number:";
				cin>>no;
				while(f1.read((char*)&ck,sizeof(ck)))
				{	if(strcmpi(ck.iname,na)==0)
					if(ck.iphno==no)
					if(strcmpi(ck.iadd,ad)==0)
					{ cout<<"Patient id:"<<ck.iid;
					  getch(); }
				}
				f1.close();
			   }
		}    //p-2
	}    //menu choice 1
	if(ch==2)      //outpatient details(menu choice 2)
	{	clrscr();
		fstream f2;
		f2.open("outpatient.dat",ios::app|ios::binary);
		odetail out;
		cout<<"Name:";
		gets(out.oname);
		cout<<"Address:";
		gets(out.oadd);
		cout<<"Phone number:";
		cin>>(out.ophno);
		cout<<"Date of birth:";
		cout<<"\nDay:";
		cin>>out.age.d;
		cout<<"Month:";
		cin>>out.age.m;
		cout<<"Year:";
		cin>>out.age.y;
		cout<<"Gender:";
		cin>>out.g;
		cout<<"Height:";
		cin>>out.h;
		cout<<"Weight:";
		cin>>out.w;
		cout<<"Speciality:";
		gets(out.speciality);
		strcpy(out.doctorname,docname(out.speciality));
		cout<<"Medical details:";
		gets(out.mh);
		randomize();
		out.oid=random(99999-10001+1)+10001;
		clrscr();
		cout<<"Patient id:"<<out.oid;
		getch();
		f2.write((char*)&out,sizeof(out));
		f2.close();
	}  //menu chice 2
	if(ch==3)
	{       clrscr();
		int b,billid;
		fstream f1,f2,f3,f4,f5;
		cout<<"1.INPATIENT\n2.OUTPATIENT\n3.Forgot Patient id";
		cout<<"\nEnter choice:";
		cin>>b;
		if(b==1)
		{       clrscr();
			cout<<"Patient ID:";
			cin>>billid;
			f1.open("inpatient.dat",ios::in|ios::binary);
			f3.open("pharmacy.dat",ios::in|ios::binary);
			f4.open("surgery.dat",ios::in|ios::binary);
			f5.open("lab.dat",ios::in,ios::binary);
			idetail ibill;
			idetail ibil;
			int ib=0;
			int b=0;
			while(f1.read((char*)&ibil,sizeof(ibil)))
			{ if(ibil.iid==billid)
			  if(ibil.discharge==1)
			  ib=1;
			}
			f1.close();
			f1.open("inpatient.dat",ios::in|ios::binary);
			if(ib==1)
			{ cout<<"Patient is discharged";
			  getch();
			}
			if(ib==0)
			{
			int sno=1;
			clrscr();
			int menu;
			cout<<"1.PHARMACY BILL\n2.SURGERY BILL\n3.FINAL INTERIM BILL";
			cin>>menu;
			if(menu==1)
			{	pharm pb;
				f3.read((char*)&pb,sizeof(pb));
				int cost;
				double tcost=0;
				int co=0;
				clrscr();
				while(f1.read((char*)&ibill,sizeof(ibill)))
				{	if(ibill.iid==billid)
					{	cout<<setw(100)<<"BILL";
						cout<<"\nName:"<<ibill.iname<<"\nAddress:"<<ibill.iadd;
						cout<<"\nPhone number"<<ibill.iphno;
						cout<<"\nDate of birth:"<<ibill.age.d<<"/"<<ibill.age.m<<"/"<<ibill.age.y;
						cout<<"\nGender:"<<ibill.g<<"\nHeight:"<<ibill.h<<"\nWeight:"<<ibill.w<<endl;
					}
				}
				cout<<setw(5)<<"SNO."<<setw(50)<<"MEDICINES"<<setw(20)<<"COST\n";
				f3.seekg(0);
				while(f3.read((char*)&pb,sizeof(pb)))
				{      	if(pb.pid==billid)
					{	cout<<setw(5)<<sno++<<setw(50)<<pb.med;
						cost=pharmacy(pb.med);
						tcost+=cost;
						cout<<setw(20)<<cost<<"\n";
						co++;
					}
				}
				cout<<setw(55)<<"Total amount:"<<setw(20)<<tcost;
				getch();
				if(co==0)
				{clrscr();
				 cout<<"INVALID PATIENT ID";
				 getch();
				}
			} //menu-1
			if(menu==2)
			{	sur sb;
				f4.read((char*)&sb,sizeof(sb));
				float cost;
				double tcost=0;
				int co=0;
				clrscr();
				while(f1.read((char*)&ibill,sizeof(ibill)))
				{	if(ibill.iid==billid)
					{	cout<<setw(100)<<"BILL";
						cout<<"\nName:"<<ibill.iname<<"\nAddress:"<<ibill.iadd;
						cout<<"\nPhone number"<<ibill.iphno;
						cout<<"\nDate of birth:"<<ibill.age.d<<"/"<<ibill.age.m<<"/"<<ibill.age.y;
						cout<<"\nGender:"<<ibill.g<<"\nHeight:"<<ibill.h<<"\nWeight:"<<ibill.w<<endl;
					}
				}
				cout<<setw(5)<<"SNO."<<setw(50)<<"SURGERY"<<setw(20)<<"COST\n";
				f4.seekg(0);
				while(f4.read((char*)&sb,sizeof(sb)))
				{      	if(sb.sid==billid)
					{	cout<<setw(5)<<sno++<<setw(50)<<sb.sr;
						cost=surgery(sb.sr);
						tcost+=cost;
						cout<<setw(20)<<cost<<"\n";
						co++;

					}
				}
				cout<<setw(55)<<"Total amount:"<<setw(20)<<tcost;
				getch();
				if(co==0)
				{clrscr();
				 cout<<"INVALID PATIENT ID";
				 getch();
				}
			} //menu-2
			if(menu==3)
			{
				pharm pb;
				dt did;
				lab lbill;
				sur sb;
				lab lbi;
				cout<<"\nDischarge date:";
				cout<<"\nDate:";
				cin>>did.d;
				cout<<"\nMonth:";
				cin>>did.m;
				cout<<"\nYear:";
				cin>>did.y;
				clrscr();
				int inv=0;
				double ctotal=0;
				double rtotal=0;
				f1.seekg(0);
				while(f1.read((char*)&ibill,sizeof(ibill)))   //while-1
				{	if(ibill.iid==billid)                 //if-1
					{       if(did.y<ibill.dtadmit.y)
						{ clrscr();
						  cout<<"Invalid discharge date";
						  inv=1;
						  getch();
						}
						else if((did.y==ibill.dtadmit.y&&did.m<ibill.dtadmit.m)||(did.y==ibill.dtadmit.y&&did.m==ibill.dtadmit.m&&did.d<ibill.dtadmit.d))
						{ clrscr();
						  cout<<"Invalid discharge date";
						  inv=1;
						  getch();
						}
						else
						{
						cout<<setw(100)<<"FINAL INTERIM BILL";
						cout<<"\nName:"<<ibill.iname<<"\nAddress:"<<ibill.iadd;
						cout<<"\nPhone number"<<ibill.iphno;
						cout<<"\nDate of birth:"<<ibill.age.d<<"/"<<ibill.age.m<<"/"<<ibill.age.y;
						cout<<"\nGender:"<<ibill.g<<"\nHeight:"<<ibill.h<<"\nWeight:"<<ibill.w;
						cout<<"\nDoctor Name:"<<ibill.doctorname;
						cout<<"\nDate of admit"<<ibill.dtadmit.d<<"/"<<ibill.dtadmit.m<<"/"<<ibill.dtadmit.y;
						cout<<"Discharge date:"<<did.d<<"/"<<did.m<<"/"<<did.y;
						if(ibill.dtadmit.y<did.y)
						{ for(int i=ibill.dtadmit.m,k=0;i<=12;i++,k++)
						  { if(i==12&&k==0)
						    { rtotal+=(31-ibill.dtadmit.d)*4000;
						      ctotal+=(31-ibill.dtadmit.d)*4000;
						    }
						    else
						    { int days;
						      if(i==2)
						  { if(ibill.dtadmit.y%4==0)
						    days=29;
						    else
						    days=28;
						  }
						  switch(i)
						  { case 1:
						    case 3:
						    case 5:
						    case 7:
						    case 8:
						    case 10:
						    case 12:days=31;break;
						    case 4:
						    case 6:
						    case 9:
						    case 11:days=30;break;
						  }
						if(k==0)
						{ rtotal+=(days-ibill.dtadmit.d)*4000;
						  ctotal+=(days-ibill.dtadmit.d)*4000;
						}
						else
						{ rtotal+=days*4000;
						  ctotal+=days*4000;
						}
						}
						}
						for(int j=1;j<=did.m;j++)
						{

						     int days;
						      if(j==2)
						  { if(did.y%4==0)
						    days=29;
						    else
						    days=28;
						  }
						  switch(j)
						  { case 1:
						    case 3:
						    case 5:
						    case 7:
						    case 8:
						    case 10:
						    case 12:days=31;break;
						    case 4:
						    case 6:
						    case 9:
						    case 11:days=30;break;
						  }
						if(j==did.m)
						{ rtotal+=did.d*4000;
						  ctotal+=did.d*4000;
						}
						else
						{ rtotal+=days*4000;
						  ctotal+=days*4000;

						}
						}
						}
						if(ibill.dtadmit.y==did.y)
						{if(ibill.dtadmit.m==did.m)        //if-2
						{ rtotal+=(did.d-ibill.dtadmit.d)*4000;
						  ctotal+=(did.d-ibill.dtadmit.d)*4000; }  //if-2
						else                              //  else-2
						{ int days; int months=did.m-ibill.dtadmit.m;
						  int month=ibill.dtadmit.m;
						  if(ibill.dtadmit.m==2)
						  { if(ibill.dtadmit.y%4==0)
						    days=29;
						    else
						    days=28;
						  }
						  switch(ibill.dtadmit.m)
						  { case 1:
						    case 3:
						    case 5:
						    case 7:
						    case 8:
						    case 10:
						    case 12:days=31;break;
						    case 4:
						    case 6:
						    case 9:
						    case 11:days=30;break;
						  }
						  ctotal+=(days-ibill.dtadmit.d)*4000;
						  rtotal+=(days-ibill.dtadmit.d)*4000;
						  while(months)  //while-2
						  {
						  if(month==2)
						  { if(month%4==0)
						    days=29;
						    else
						    days=28;
						  }
						  switch(month)
						  { case 1:
						    case 3:
						    case 5:
						    case 7:
						    case 8:
						    case 10:
						    case 12:days=31;break;
						    case 4:
						    case 6:
						    case 9:
						    case 11:days=30;break;
						  }
						  if(month==did.m)
						  { ctotal+=(days-did.d)*4000;
						    rtotal+=(days-did.d)*4000;}
						  else
						  { rtotal+=days*4000;
						    rtotal+=days*4000;}
						  month+=1;
						  months--;
						  }  //while-2
						} //else-2
						}
						}
					} //if-1
				}  //while-1
				double ptotal=0;
				double stotal=0;
				double ltotal=0;
				double cost;
				while(f3.read((char*)&pb,sizeof(pb)))
				{	if(pb.pid==billid)
					{cost=pharmacy(pb.med);
					 ptotal+=cost;}
				}
				while(f4.read((char*)&sb,sizeof(sb)))
				{	if(sb.sid==billid)
					{cost=surgery(sb.sr);
					 stotal+=cost;}
				}
				while(f5.read((char*)&lbi,sizeof(lbi)))
				{	if(lbi.lid==billid)
					{cost=labdetail(lbi.lb);
					 ltotal+=cost;
					}
				}
				if(inv==0)
				{
				cout<<setw(5)<<"\nS.No."<<setw(50)<<"Service"<<setw(20)<<"Amount\n";
				cout<<setw(5)<<"\n1."<<setw(50)<<"Consultation"<<setw(20)<<ctotal;
				cout<<setw(5)<<"\n2."<<setw(50)<<"Surgery"<<setw(20)<<stotal;
				cout<<setw(5)<<"\n3."<<setw(50)<<"Pharmacy"<<setw(20)<<ptotal;
				cout<<setw(5)<<"\n4."<<setw(50)<<"Lab service"<<setw(20)<<ltotal;
				cout<<setw(5)<<"\n5."<<setw(50)<<"Room rent"<<setw(20)<<rtotal;
				cout<<setw(55)<<"\nTotal Interim Bill Amount Till Date:"<<setw(20)<<ctotal+rtotal+ptotal+stotal+ltotal;
				b=1;
				getch();
				}
			}  //menu-3
			}
				idetail dibill;
				f1.close();
				if(b==1)
				{
				f1.open("inpatient.dat",ios::in|ios::out|ios::binary);
				int p=sizeof(dibill);
				while(f1.read((char*)&dibill,sizeof(dibill)))
				{ if(dibill.iid==billid)
				  { dibill.discharge=1;
				    f1.seekp(-p,ios::cur);
				    f1.write((char*)&dibill,sizeof(dibill));
				  }
				}
				f1.close();
				}


			f3.close();
			f4.close();
			f5.close();
		}    //b-1
		if(b==2)
		{ clrscr();
		  odetail obill;
		  cout<<"Patient ID:";
		  cin>>billid;
		  f2.open("outpatient.dat",ios::in|ios::binary);
		  while(f2.read((char*)&obill,sizeof(obill)))
		  {	if(obill.oid==billid)
			{	cout<<setw(100)<<"FINAL INTERIM BILL";
				cout<<"\nName:"<<obill.oname<<"\nAddress:"<<obill.oadd;
				cout<<"\nPhone number"<<obill.ophno;
				cout<<"\nDate of birth:"<<obill.age.d<<"/"<<obill.age.m<<"/"<<obill.age.y;
				cout<<"\nGender:"<<obill.g<<"\nHeight:"<<obill.h<<"\nWeight:"<<obill.w;
				cout<<"\nDoctor Name:"<<obill.doctorname<<endl;
				cout<<setw(5)<<"S.No."<<setw(50)<<"Service"<<setw(20)<<"Amount\n";
				cout<<setw(5)<<"1."<<setw(50)<<"Consultation"<<setw(20)<<"700";
				cout<<setw(55)<<"Total Amount"<<setw(20)<<"700";
				getch();;
				break;
			}
		  f2.close();
		  }
		} //b-2
		if(b==3)
		{       int check;
			cout<<"1.Inpatient\n2.Outpatient";
			cin>>check;
			if(check==1)
			{ 	fstream f1;
				idetail ck;
				char na[20],ad[50];
				long no;
				f1.open("inpatient.dat",ios::in|ios::binary);
				cout<<"Name:";
				gets(na);
				cout<<"Address:";
				gets(ad);
				cout<<"Phone number:";
				cin>>no;
				while(f1.read((char*)&ck,sizeof(ck)))
				{	if(strcmpi(ck.iname,na)==0)
					if(ck.iphno==no)
					if(strcmpi(ck.iadd,ad)==0)
					{cout<<"Patient id:"<<ck.iid;
					 getch(); }
				}
				f1.close();
			}
			if(check==2)
			{ 	fstream f2;
				odetail ck;
				char na[20],ad[50];
				long no;
				f2.open("outpatient.dat",ios::in|ios::binary);
				cout<<"Name:";
				gets(na);
				cout<<"Address:";
				gets(ad);
				cout<<"Phone number:";
				cin>>no;
				while(f2.read((char*)&ck,sizeof(ck)))
				{	if(strcmpi(ck.oname,na)==0)
					if(ck.ophno==no)
					if(strcmpi(ck.oadd,ad)==0)
					{ cout<<"Patient id:"<<ck.oid;
					  getch(); }
				}
				f2.close();
			}
		}   //b-3
	}  //menu choice 3
	if(ch==4)
	{ clrscr();
	  cout<<"Exiting.........................";
	}  //menu choice 4
  }while(ch!=4);
 } //password
 getch();
}  //main()