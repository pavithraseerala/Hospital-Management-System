# Hospital-Management-System
The Hospital Management System is designed for hospitals, to replace their existing manual paper based system. The purpose of this system is to maintain the details of various patients,doctors,medicines and other details regarding the hospital. The system also generates a final bill for both the inpatients and outpatients.

The system verifies user authentication and diaplays a menu that performs the following functions:
1. Insertion of inpatient details
2. Insertion of outpatient details
3. Generation of Bill

The program creates binary files that stores patient details, the medicines purchased and the surgeries undergone by the patient. The final bill is generated for inpatients which is inclusive of consultation fee, room rent, medicines purchased and the surgeries undergone.

## User Defined Functions used in the Project
* **docname(char\*)**

  **Prototype:** char\* docname(char\*);
  
  This function returns the name of the doctor, according to the type of specialist the patient needs. The patient is allocated to the doctor, whose name is returned by the **docname(char\*)** function. 
* **pharmacy(char\*)**

  **Prototype:** int pharmacy(char\*);
  
  This function returns the cost of medicines purchased by the patient and the function is called during the generation of the bill.
* **labdetail(char\*)**

  **Prototype:** long labdetail(char\*);
  
  This function returns the cost of tests taken in the lab by the patient and the function is called during the generation of the bill.
* **surgery(char\*)**

  **Prototype:** long surgery(char\*);
  
  This function returns the cost of the surgery undergone by the patient and the function is called during the generation of the bill.
## Files Used in the Project
* **inpatient.dat**
  
  This binary file holds the details of all the inpatients.
* **outpatient.dat**

  This binary file holds the details of all the outpatients.
* **pharmacy.dat**

  This binary file holds the details of medicines purchased by all the patients.
* **surgery.dat**

  This binary file holds the details of surgeries undergone by all the patients.
* **lab.dat**

  This binary file holds the details of all the tests taken in the lab by the patients.
  
